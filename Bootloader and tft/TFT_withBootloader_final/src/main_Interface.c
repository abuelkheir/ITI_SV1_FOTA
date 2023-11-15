/*
 * main_Interface.c
 *
 *  Created on: Nov 11, 2023
 *      Author: mayke
 */

#include "main_Interface.h"


void Main_voidInit(void)
{
	// Initialize the Reset and Clock Control (RCC)
	MRCC_voidInit();

	// Enable clock for GPIOA peripheral
	MRCC_voidEnablePeripheralClock(RCC_AHB1, GPIOAEN);

	// Enable clock for GPIOB peripheral
	MRCC_voidEnablePeripheralClock(RCC_AHB1, GPIOBEN);

	// Enable clock for SPI1 peripheral
	MRCC_voidEnablePeripheralClock(RCC_APB2, SPI1EN);

	// Enable clock for USART1 peripheral
	MRCC_voidEnablePeripheralClock(RCC_APB2, USART1EN);

	// Initialize the System Tick Timer
	MSTK_voidInit();

	/* Configure GPIOA pin 6 as Alternative Function for SPI1_MISO */
	MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN6, GPIO_ALTF_MODE);
	/* Set pin 6's Alternative Function to AF5 (SPI1) */
	MGPIO_voidSetPinAltFun(GPIO_PORTA, GPIO_PIN6, GPIO_ALTFUN5);

	/* Configure GPIOA pin 7 as Alternative Function for SPI1_MOSI */
	MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN7, GPIO_ALTF_MODE);
	/* Set pin 7's Alternative Function to AF5 (SPI1) */
	MGPIO_voidSetPinAltFun(GPIO_PORTA, GPIO_PIN7, GPIO_ALTFUN5);

	/* Configure GPIOA pin 5 as Alternative Function for SPI1_SCK */
	MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN5, GPIO_ALTF_MODE);
	/* Set pin 5's Alternative Function to AF5 (SPI1) */
	MGPIO_voidSetPinAltFun(GPIO_PORTA, GPIO_PIN5, GPIO_ALTFUN5);


	/* Set GPIOA pin 8 as Output, Push-Pull for A0 */
	/* Set Pin Mode */
	MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN8, GPIO_OUTPUT_MODE);
	/* Set Output Mode to Push-Pull */
	MGPIO_voidSetOutputMode(GPIO_PORTA, GPIO_PIN8, GPIO_OUTPUT_TYPE_PUSH_PULL);
	/* Set Output Speed to Low */
	MGPIO_voidSetOutputSpeed(GPIO_PORTA, GPIO_PIN8, GPIO_OUTPUT_SPEED_LOW);

	/* Set GPIOA pin 4 as Output, Push-Pull for RST */
	/* Set Pin Mode */
	MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN4, GPIO_OUTPUT_MODE);
	/* Set Output Mode to Push-Pull */
	MGPIO_voidSetOutputMode(GPIO_PORTA, GPIO_PIN4, GPIO_OUTPUT_TYPE_PUSH_PULL);
	/* Set Output Speed to Low */
	MGPIO_voidSetOutputSpeed(GPIO_PORTA, GPIO_PIN4, GPIO_OUTPUT_SPEED_LOW);


	/* Initialize SPI */
	MSPI_voidInit();
	/* Initialize TFT */
	HTFT_voidinit();
	/* Initialize USART1 */
	MUSART1_voidInit();
	/* Enable USART1 */
	MUSART1_voidEnable();

	/* Step 5: Set Pin Mode for Pins 6 and 7 as Alternative Function */
	MGPIO_voidSetPinMode(GPIO_PORTB, GPIO_PIN6, GPIO_ALTF_MODE); // TX -> USART1
	/* Step 6: Set Pin Alternative Function for Pins 6 and 7 */
	MGPIO_voidSetPinAltFun(GPIO_PORTB, GPIO_PIN6, GPIO_ALTFUN7);

	/* Set Pin Mode for Pins 6 and 7 as Alternative Function */
	MGPIO_voidSetPinMode(GPIO_PORTB, GPIO_PIN7, GPIO_ALTF_MODE); // RX -> USART1
	/* Set Pin Alternative Function for Pins 6 and 7 */
	MGPIO_voidSetPinAltFun(GPIO_PORTB, GPIO_PIN7, GPIO_ALTFUN7);



	/* Buzzer to Verify checksum *///led
	/* Set Pin Mode for GPIOB pin 12 as Output Mode (for buzzer) */
	MGPIO_voidSetPinMode(GPIO_PORTB, GPIO_PIN12, GPIO_OUTPUT_MODE);
	/* Set Output Mode for GPIOB pin 12 as Push-Pull (for buzzer) */
	MGPIO_voidSetOutputMode(GPIO_PORTB, GPIO_PIN12, GPIO_OUTPUT_TYPE_PUSH_PULL);
	/* Set Output Speed for GPIOB pin 12 as Low Speed (for buzzer) */
	MGPIO_voidSetOutputSpeed(GPIO_PORTB, GPIO_PIN12, GPIO_OUTPUT_SPEED_LOW);
	/* Button  to Enter Backup_Mode */

	/* Set Pin Mode for GPIOA pin 9 as Input Mode */
	MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN9, GPIO_INPUT_MODE);
	/* Set Output Mode for GPIOA pin 9 as Push-Pull */
	MGPIO_voidSetOutputMode(GPIO_PORTA, GPIO_PIN9, GPIO_OUTPUT_TYPE_PUSH_PULL);
	/* Set  PULL State For GPIOA pin 9 as PULL UP */
	MGPIO_voidSetPullState(GPIO_PORTA, GPIO_PIN9,GPIO_PULL_UP);

	/* Button  to Enter Directly to Main APP */
	/* Set Pin Mode for GPIOA pin 10 as Input Mode */
	MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN10, GPIO_INPUT_MODE);
	/* Set Output Mode for GPIOA pin 10 as Push-Pull */
	MGPIO_voidSetOutputMode(GPIO_PORTA, GPIO_PIN10, GPIO_OUTPUT_TYPE_PUSH_PULL);
	/* Set  PULL State For GPIOA pin 10 as PULL UP */
	MGPIO_voidSetPullState(GPIO_PORTA, GPIO_PIN10,GPIO_PULL_UP);

}
