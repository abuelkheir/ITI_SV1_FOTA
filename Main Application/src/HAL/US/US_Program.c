/*
 * US_Program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: omara
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/bit_macros.h"
#include "../../MCAL/GPIO/GPIO_Interface.h"
#include "../../MCAL/STK/STK_Interface.h"


//#include "../../MCAL/RCC/RCC_Interface.h"
//#include "../../MCAL/RCC/RCC_Config.h"

// MCAL COMPONENTS
#include "US_Config.h"
#include "US_Interface.h"


void HUS_voidInit(void)
{
	//enable GPIOB
	//MRCC_VoidEnablePeriphral(AHB1_BUS,US_PORT);
	//MRCC_VoidEnable_Priph(AHB1,US_PORT);



	MGPIO_voidSetPinMode(US_PORT,TRIGGER_PIN1,MGPIO_MODE_OUTPUT);  //for TRIGGER_PIN1  --> output
	MGPIO_voidSetOutPutMode(US_PORT,TRIGGER_PIN1,MGPIO_OUTPUT_TYPE_PUSH_PULL);
	MGPIO_voidSetOutPutSpeed(US_PORT,TRIGGER_PIN1,MGPIO_OUTPUT_SPEED_LOW);

	MGPIO_voidSetPinMode(US_PORT,ECHO_PIN1,MGPIO_MODE_INPUT);  //for ECHO_PIN1  --> input
	MGPIO_voidSetPullState(US_PORT,ECHO_PIN1,MGPIO_PULL_PULL_DOWN);
//-----------------------------------------------
	MGPIO_voidSetPinMode(US_PORT,TRIGGER_PIN2,MGPIO_MODE_OUTPUT);  //for TRIGGER_PIN2  --> output
	MGPIO_voidSetOutPutMode(US_PORT,TRIGGER_PIN2,MGPIO_OUTPUT_TYPE_PUSH_PULL);
	MGPIO_voidSetOutPutSpeed(US_PORT,TRIGGER_PIN2,MGPIO_OUTPUT_SPEED_LOW);

	MGPIO_voidSetPinMode(US_PORT,ECHO_PIN2,MGPIO_MODE_INPUT);  //for ECHO_PIN2 --> input
	MGPIO_voidSetPullState(US_PORT,ECHO_PIN2,MGPIO_PULL_PULL_DOWN);
//----------------------------------------------------------
	MGPIO_voidSetPinMode(US_PORT,TRIGGER_PIN3,MGPIO_MODE_OUTPUT);  //for TRIGGER_PIN3  --> output
	MGPIO_voidSetOutPutMode(US_PORT,TRIGGER_PIN3,MGPIO_OUTPUT_TYPE_PUSH_PULL);
	MGPIO_voidSetOutPutSpeed(US_PORT,TRIGGER_PIN3,MGPIO_OUTPUT_SPEED_LOW);

	MGPIO_voidSetPinMode(US_PORT,ECHO_PIN3,MGPIO_MODE_INPUT);  //for ECHO_PIN3  --> input
	MGPIO_voidSetPullState(US_PORT,ECHO_PIN3,MGPIO_PULL_PULL_DOWN);
//-------------------------------------------------------------------------
	MGPIO_voidSetPinMode(US_PORT,TRIGGER_PIN4,MGPIO_MODE_OUTPUT);  //for TRIGGER_PIN3  --> output
	MGPIO_voidSetOutPutMode(US_PORT,TRIGGER_PIN4,MGPIO_OUTPUT_TYPE_PUSH_PULL);
	MGPIO_voidSetOutPutSpeed(US_PORT,TRIGGER_PIN4,MGPIO_OUTPUT_SPEED_LOW);

	MGPIO_voidSetPinMode(US_PORT,ECHO_PIN4,MGPIO_MODE_INPUT);  //for ECHO_PIN3  --> input
	MGPIO_voidSetPullState(US_PORT,ECHO_PIN4,MGPIO_PULL_PULL_DOWN);
}


f32 HUS_f32CalcDistance (USNUM_t A_USNUM_t_Ultrasonic_Num)
{
	u32 L_u32TicksNumber = 0   ;
	f32 L_f32Distance    = 0.0 ;

	/*trig pulse to trigger pin
	 * 3us low
	 * 10us high
	 * then low
	 */
	switch(A_USNUM_t_Ultrasonic_Num)
	{
		case FORWARD_US :
			MGPIO_voidSetPinVal(US_PORT,TRIGGER_PIN1,MGPIO_LOW);
			MSTK_voidSetBusyWait(6) ;
			MGPIO_voidSetPinVal(US_PORT,TRIGGER_PIN1,MGPIO_HIGH);
			MSTK_voidSetBusyWait(20) ;
			MGPIO_voidSetPinVal(US_PORT,TRIGGER_PIN1,MGPIO_LOW);
			//MGPIO_voidSetPinVal()

			//wait to generate 8 pulses (40KHZ)/
			MSTK_voidSetBusyWait(500);

			//wait until generating rising edge for echo pin/
			while (MGPIO_u8GetPinVal(US_PORT, ECHO_PIN1) == 0);
			while (MGPIO_u8GetPinVal(US_PORT, ECHO_PIN1) == 1)
			{
				//each iteration takes 2.45 us/
				L_u32TicksNumber ++;
				MSTK_voidSetBusyWait(4);   // why busy wait ?
			}
			break;

		case LEFT_US :
			MGPIO_voidSetPinVal(US_PORT,TRIGGER_PIN2,MGPIO_LOW);
			MSTK_voidSetBusyWait(6) ;
			MGPIO_voidSetPinVal(US_PORT,TRIGGER_PIN2,MGPIO_HIGH);
			MSTK_voidSetBusyWait(20) ;
			MGPIO_voidSetPinVal(US_PORT,TRIGGER_PIN2,MGPIO_LOW);

			//wait to generate 8 pulses (40KHZ)/
			MSTK_voidSetBusyWait(500);

			//wait until generating rising edge for echo pin/
			while (MGPIO_u8GetPinVal(US_PORT, ECHO_PIN2) == 0);
			while (MGPIO_u8GetPinVal(US_PORT, ECHO_PIN2) == 1)
			{
				//each iteration takes 2.45 us/
				L_u32TicksNumber ++;
				MSTK_voidSetBusyWait(4);
			}
			break;

		case RIGHT_US:
			MGPIO_voidSetPinVal(US_PORT,TRIGGER_PIN3,MGPIO_LOW);
			MSTK_voidSetBusyWait(6) ;
			MGPIO_voidSetPinVal(US_PORT,TRIGGER_PIN3,MGPIO_HIGH);
			MSTK_voidSetBusyWait(20) ;
			MGPIO_voidSetPinVal(US_PORT,TRIGGER_PIN3,MGPIO_LOW);

			//wait to generate 8 pulses (40KHZ)/
			MSTK_voidSetBusyWait(500);

			//wait until generating rising edge for echo pin/
			while (MGPIO_u8GetPinVal(US_PORT, ECHO_PIN3) == 0);
			while (MGPIO_u8GetPinVal(US_PORT, ECHO_PIN3) == 1)
			{
				//each iteration takes 2.45 us/
				L_u32TicksNumber++;
				MSTK_voidSetBusyWait(4);
			}
			break;
		case last_US:
			MGPIO_voidSetPinVal(US_PORT,TRIGGER_PIN4,MGPIO_LOW);
			MSTK_voidSetBusyWait(6) ;
			MGPIO_voidSetPinVal(US_PORT,TRIGGER_PIN4,MGPIO_HIGH);
			MSTK_voidSetBusyWait(20) ;
			MGPIO_voidSetPinVal(US_PORT,TRIGGER_PIN4,MGPIO_LOW);

			//wait to generate 8 pulses (40KHZ)/
			MSTK_voidSetBusyWait(500);

			//wait until generating rising edge for echo pin/
			while (MGPIO_u8GetPinVal(US_PORT, ECHO_PIN4) == 0);
			while (MGPIO_u8GetPinVal(US_PORT, ECHO_PIN4) == 1)
			{
				//each iteration takes 2.45 us/
				L_u32TicksNumber++;
				MSTK_voidSetBusyWait(4);
			}
			break;

	}


	L_f32Distance = ((float)L_u32TicksNumber)*(6.125)*(0.0343) ;   // how to get time of iteration
	L_f32Distance = L_f32Distance / 2 ;

	//initialize L_u32TicksNumber for next read/
	L_u32TicksNumber = 0 ;
	return L_f32Distance ;
}
