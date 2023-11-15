/**
 * @mainpage Bootloader Application
 *
 * @brief This file contains the main application code for the bootloader.
 *
 * It initializes peripherals, handles bootloader logic, and interacts with TFT display.
 * The bootloader supports switching between main and backup applications.
 * Additional functions for TFT display manipulation and error handling are included.
 *
 * @version 1.0
 * @date Sep 20, 2023
 * @author Basel Ibrahim
 *
 * @section address Address
 * You can find more information about this bootloader on the project's GitHub page:
 * https://github.com/your_username/your_project
 *
 * @section details Detailed Description
 * This bootloader is designed to provide a reliable and flexible mechanism for updating and switching
 * between main and backup applications. It includes functionality for initializing peripherals, managing
 * communication, and displaying information on a TFT screen. Error handling and detailed TFT manipulation
 * functions are also implemented.
 */


#include"main_interface.h"

/**
 * @brief Flag to indicate timeout status
 */
u8 u8_TimeoutFlag = 0;

/**
 * @brief Buffer for receiving data
 */
u8 RecieveBuffer[100];

/**
 * @brief Counter for received data
 */
u8 u8RecCounter = 0;

/**
 * @brief Flag to indicate a write request
 */
u8 u8WriteReq = 1;

/**
 * @brief Flag to indicate an update request
 */
u8 u8UPdateRequest = 1;

/**
 * @brief External variable declaration for the first flash address
 */
extern u32 Frist_FLASH_ADDRESS;

/**
 * @brief Define the Vector Table Offset Register address
 */
#define SCB_VTOR *((volatile u32 *)0xE000ED08)

/**
 * @brief Define a function pointer type for the application call
 */
typedef void (*APP_CALL)(void);

/**
 * @brief Initialize the function pointer to NULL
 */
APP_CALL ADD_TO_CALL_1 = 0;


/**
 * @brief Application section 1 function
 *
 * If the first flash address is the backup, switch to the backup application.
 * If the first flash address is the main, switch to the main application.
 *
 * @param None
 * @return None
 */
void APP_SECTION_1()
{
	if (Frist_FLASH_ADDRESS == FIRST_FLASH_ADDRESS_BACKUP)
	{
		/* Show Switch to the backup application In TFT */
		Switch_To_Backup_APP();

		/* Set timeout flag */
		u8_TimeoutFlag = 1;

		/* Set the vector table offset to the first address in sector 2 */
		SCB_VTOR = VECTOR_TABLE_OFFSET_SECTOR2;

		/* Set the function pointer to the startup code's first address */
		ADD_TO_CALL_1 = *(APP_CALL *)(VECTOR_TABLE_OFFSET_SECTOR2 + 4);

		/* Set GPIOA pin 10 to LOW */
		MGPIO_voidSetPinValue(GPIOA, GPIO_PIN11, GPIO_LOW);

		/* Call the application part */
		ADD_TO_CALL_1();
	}
	else if (Frist_FLASH_ADDRESS == FIRST_FLASH_ADDRESS_MAIN)
	{
		/* Show Switch to the MAIN application In TFT */
		Switch_To_Main_APP();

		/* Set timeout flag */
		u8_TimeoutFlag = 1;

		/* Set the vector table offset to the first address in sector 1 */
		SCB_VTOR = VECTOR_TABLE_OFFSET_SECTOR1;

		/* Set the function pointer to the startup code's first address */
		ADD_TO_CALL_1 = *(APP_CALL *)(VECTOR_TABLE_OFFSET_SECTOR1 + 4);

		/* Set GPIOA pin 10 to LOW */
		MGPIO_voidSetPinValue(GPIOA, GPIO_PIN11, GPIO_LOW);

		/* Call the application part */
		ADD_TO_CALL_1();
	}
	else
	{
		/* Do nothing if the first flash address is neither backup nor main */
	}
}


/**
 * @brief Main function
 *
 * Initializes peripherals, sets up communication, and handles bootloader logic.
 *
 * @param None
 * @return Integer value indicating the exit status (typically 0 for success)
 */
int main()
{

	Main_voidInit();

	/* Fill TFT with black color */
	HTFT_voidFillBackground(BLACK);

	/* Write bootloader mode on TFT */
	writeBootLoaderModeInTFT();



	/* Initialize a status variable */
	u8 L_u8RecStatus = 0;



	/* ******************************************************** */
	const u8 Local_Button_Backup=0;




	// Main loop that runs as long as the timeout flag is not set
while(u8_TimeoutFlag == 0)
{
    // Check if the Backup button is pressed
    if(MGPIO_voidGetPinValue(GPIO_PORTA, GPIO_PIN9) == Local_Button_Backup)
    {
        // Set the first flash address to the backup address
        Frist_FLASH_ADDRESS = 0x08000000;
        // Call the application section 1 function
        APP_SECTION_1();
    }
    // Check if the Directly to Main APP button is pressed
    else if(MGPIO_voidGetPinValue(GPIO_PORTA, GPIO_PIN10) == Local_Button_Backup)
    {
        // Set the first flash address to the main address
        Frist_FLASH_ADDRESS = 0x08020000;
        // Call the application section 1 function
        APP_SECTION_1();
    }

    // Receive data from USART1
    L_u8RecStatus = MUSART1_u8ReceiveData(&RecieveBuffer[u8RecCounter]);

    // Check if data is received
    if(L_u8RecStatus == 1)
    {
        // Make the TFT display sleep out
        HTFT_voidSleepOut();

        // Check if an update request is pending and the received data is '1'
        if((u8UPdateRequest == 1) && (RecieveBuffer[u8RecCounter] == '1'))
        {
            // Clear the update request flag
            u8UPdateRequest = 0;
            // Transmit "ok" over USART1
            MUSART1_voidTransmitData("ok");
            // Continue to the next iteration of the loop
            continue;
        }
        // Check if an update request is pending and the received data is '0'
        else if((u8UPdateRequest == 1) && (RecieveBuffer[u8RecCounter] == '0'))
        {
            // Clear the update request flag
            u8UPdateRequest = 0;
            // Transmit "ok" over USART1
            MUSART1_voidTransmitData("ok");
            // Call the application section 1 function
            APP_SECTION_1();
        }
        else
        {
            // Additional logic can be added here based on the received data
        }

        // Check if the end of record is reached
        if(RecieveBuffer[u8RecCounter] == '\n')
        {
            // Parse the received record
            APARSER_voidParseRecord(RecieveBuffer);

            // Check if a write request is pending
            if(u8WriteReq == 1)
            {
                // Check the first flash address
                if(Frist_FLASH_ADDRESS == 0x08020000)
                {
                    // Erase sector 5 of the flash memory
                    MFDI_voidEraseSector(5);
                    // Clear the write request flag
                    u8WriteReq = 0;
                    // Display FLASHING mode on the TFT
                    writeFLASHINGModeInTFT();
                }
                else if(Frist_FLASH_ADDRESS == 0x08000000)
                {
                    // Erase sector 3 and 4 of the flash memory
                    MFDI_voidEraseSector(3);
                    MFDI_voidEraseSector(4);
                    // Clear the write request flag
                    u8WriteReq = 0;
                    // Display FLASHING mode on the TFT
                    writeFLASHINGModeInTFT();
                }
                else
                {
                    // Additional logic can be added here based on the first flash address
                }
            }

            // Transmit "ok" over USART1
            MUSART1_voidTransmitData("ok");
            // Reset the receive counter
            u8RecCounter = 0;

            // Check the checksum of the received data
            if (APARSER_u8VerifyChecksum(RecieveBuffer))
            {
                // Set the buzzer GPIO pin low
                MGPIO_voidSetPinValue(GPIO_PORTB, GPIO_PIN9, GPIO_LOW);
            }
            else
            {
                // Handle error and set the buzzer GPIO pin high
                ErrorInHex();

                MGPIO_voidSetPinValue(GPIO_PORTB, GPIO_PIN9, GPIO_HIGH);

                // Check and switch the first flash address for error recovery
                if (Frist_FLASH_ADDRESS == 0x08020000)
                {
                    Frist_FLASH_ADDRESS = 0x08000000;
                    APP_SECTION_1();
                }
                else if(Frist_FLASH_ADDRESS == 0x08000000)
                {
                    Frist_FLASH_ADDRESS = 0x08020000;
                    APP_SECTION_1();
                }
            }
        }
        else
        {
            // Increment the receive counter
            u8RecCounter++;
        }

        // Check if the flashing is done (indicated by the 9th character)
        if(RecieveBuffer[8] == '1')
        {
            // Set the LED GPIO pin low
            MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN11, GPIO_LOW);
            // Display FLASHING DONE message on the TFT
            writeFLASHING_DONE();
            // Transmit "ok" over USART1
            MUSART1_voidTransmitData("ok");
            // Switch to application section 1
            APP_SECTION_1();
        }
    }
}
return 0;

}

