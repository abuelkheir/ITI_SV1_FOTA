/*
 * Main_Interface.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: omara
 */



#include"Main_Interface.h"

void Main_voidInit(void)
{
	MRCC_VoidInit();
		MRCC_VoidEnable_Priph(AHB1,RCC_GPIOA);//AHP1 BUS enable gpioA    0 IS NUMBER OF GPIO IN TABLE PAGE 38 &
		MRCC_VoidEnable_Priph(AHB1,RCC_GPIOB);//AHP1 BUS enable gpioA    0 IS NUMBER OF GPIO IN TABLE PAGE 38 &
		MRCC_VoidEnable_Priph(AHB1,RCC_GPIOC);//AHP1 BUS enable gpioA    0 IS NUMBER OF GPIO IN TABLE PAGE 38 &

		// ENABLE syscfg 2
		MRCC_VoidEnable_Priph(APB2,RCC_SYSCFG);//ABP2 BUS enable SYSCFG  0 IS NUMBER OF GPIO IN TABLE
		//ENABLE UART1
		//MRCC_VoidEnable_Priph(APB2,RCC_UART1);//ABP2 BUS enable UART1
		MRCC_VoidEnable_Priph(APB2,RCC_UART6);
		//timers
		//MRCC_VoidEnable_Priph(APB1,RCC_TIM2);
		//MRCC_VoidEnable_Priph(APB1,RCC_TIM4);
		//MRCC_VoidEnable_Priph(APB1,RCC_TIM5);
		//MRCC_VoidEnable_Priph(APB1,RCC_TIM3);

	//GPIO
		//RX for uart
		MGPIO_voidSetPinMode(MGPIOA_PORT,MGPIO_PIN12,MGPIO_MODE_ALTF);
		MGPIO_voidSetAltFun(MGPIOA_PORT,MGPIO_PIN12,MGPIO_ALTFN8);
		//TX for uart
		MGPIO_voidSetPinMode(MGPIOA_PORT,MGPIO_PIN11,MGPIO_MODE_ALTF);
		MGPIO_voidSetAltFun(MGPIOA_PORT,MGPIO_PIN11,MGPIO_ALTFN8);


		//CODE

		//MSTK_voidInit();
		MOTOR_VoidInit();
		USART_voidInit(BAUDRATE);
		USART_voidEnable();
		MOTOR_voidStart();

}
