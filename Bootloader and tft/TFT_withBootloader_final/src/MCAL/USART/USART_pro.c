#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


#include "USART_private.h"
#include "USART_interface.h"
#include "USART_config.h"

void (*MUSART1_CallBack)(void);
/*
*************************************************************************************************************************
*************************************************** FUNCTION_PROTOTYPES *************************************************
*************************************************************************************************************************
*/

/*
**************************************************************************************************************************
*****************************************  01 - MUSART1_voidInit()  ********************************************************

	1-  Function Description ->  Function Initialized USART1 Configuration
	2-  Options : 
				   
	3- Function Arguments : void 
							
	4- Function Return   ->  No Return(void)
	
**************************************************************************************************************************
**************************************************************************************************************************	
*/

void MUSART1_voidInit(void)
{


	MUSART_1 -> BRR  = USART1_BAUD_RATE;  // Set The Baud Rate Value

		/* Set Oversampling value */
	    MUSART_1->CR1.OVER8 = OVERSAMPLING;
		/* Set Data length */
	    MUSART_1->CR1.M = DATA_LENGTH;
		/* Parity mode */
	    MUSART_1->CR1.PCE = PARITY_MODE;
		#if UART_ENABLE == PARITY_MODE
	    MUSART_1->CR1.PS = PARITY_SELECTION;
		#endif
		/* Transmission complete interrupt */
	    MUSART_1->CR1.TCIE = TRANSMISSION_COMPELETE_INTERRUPT;
		/* Read data register interrupt */
	    MUSART_1->CR1.RXNEIE = READ_DATA_REGISTER_EMPTY_INTERRUPT;
		/* Set stop bits */
	    MUSART_1->CR2 &= ~(MASK_2BITS << CR2_STOP0);
	    MUSART_1->CR2 |=  (STOP_BITS << CR2_STOP0);

	    MUSART_1->SR = 0;
}


/*
**************************************************************************************************************************
*****************************************  02 - MUSART_voidTransmitData()  *************************************************

	1- Function Description ->   Function That TransmitData
 
	2- Function Arguments :      u8 *Copy_pu8TransmittedData 
							
	3- Function Return      ->   Variable With Data Type Of (8u)
	
**************************************************************************************************************************
**************************************************************************************************************************	
*/

void MUSART1_voidTransmitData(s8 *Copy_pu8TransmittedData)
{
	u8 i = 0;
	while(Copy_pu8TransmittedData[i] != '\0')
   {
	   MUSART_1 -> DR = Copy_pu8TransmittedData[i];
	   while((GET_BIT((MUSART_1 -> SR), 6)) == 0);
	   i++;
    }

}
/*
**************************************************************************************************************************
*****************************************  03 - MUSART_voidReceiveData()  *************************************************

	1- Function Description ->   Function That Received Data
 
	2- Function Arguments :      (void) 
							
	3- Function Return      ->   No Return(void)
	
**************************************************************************************************************************
**************************************************************************************************************************	
*/
u8 MUSART1_u8ReceiveData (u8 *Pointer_u8Data)
{   u8 Local_u8ErrorStatus=1;
	if((GET_BIT(MUSART_1->SR, SR_RXNE)) == 1)
	{
	*Pointer_u8Data = MUSART_1->DR;
	}
	else
	{
		Local_u8ErrorStatus=0;
	}
	return Local_u8ErrorStatus;
}

u8 MUSART1_u8ASynchReceiveData (u8 *Pointer_u8Data)
{   static u16 TIME_OUT =0;
    u8 Local_u8ErrorStatus=1;
	while ((!GET_BIT(MUSART_1->SR, SR_RXNE)) && (TIME_OUT < 10000)){TIME_OUT++;};
	if(TIME_OUT>=10000){
		Local_u8ErrorStatus=0;
	}
	*Pointer_u8Data = (u8)MUSART_1->DR;
	return Local_u8ErrorStatus;
}





void MUSART1_voidEnable (void)
{
	/* Enable Transmitter */
	MUSART_1->CR1.TE = TRANSMITTER_ENABLE;
	/* Enable Receiver */
	MUSART_1->CR1.RE = RECEIVER_ENABLE;
	/* Enable USART */
	MUSART_1->CR1.UE = UART_ENABLE;
}

void MUSART1_voidDisable (void)
{
	/* Disable USART */
	MUSART_1->CR1.UE = UART_ENABLE;
}

