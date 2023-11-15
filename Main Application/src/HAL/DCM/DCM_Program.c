/*
 * DCM_Program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: omara
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/bit_macros.h"

#include "../../MCAL/GPIO/GPIO_Interface.h"
#include "../../MCAL/TIMER/TIMER_Interface.h"
#include "../../MCAL/RCC/RCC_Interface.h"
#include "../../MCAL/RCC/RCC_Config.h"
#include "../../MCAL/RCC/RCC_Private.h"
#include "../../MCAL/STK/STK_Interface.h"

#include "DCM_Interface.h"
#include "DCM_Config.h"
#include "DCM_Private.h"


//void MOTOR_VoidInit(u8 copy_u8CH,)
void MOTOR_VoidInit()
{
	MRCC_VoidEnable_Priph(APB1,RCC_TIM2);
	//chanal 1 A0
	MGPIO_voidSetPinMode(MGPIOA_PORT,MGPIO_PIN0,MGPIO_MODE_ALTF);
	MGPIO_voidSetAltFun(MGPIOA_PORT,MGPIO_PIN0,MGPIO_ALTFN1);//MGPIO_ALTFN2 timer(3&4&5)
	//chanal 2 A1
	MGPIO_voidSetPinMode(MGPIOA_PORT,MGPIO_PIN1,MGPIO_MODE_ALTF);
	MGPIO_voidSetAltFun(MGPIOA_PORT,MGPIO_PIN1,MGPIO_ALTFN1);//MGPIO_ALTFN2 timer(3&4&5)
	//chanal 3 A2
	MGPIO_voidSetPinMode(MGPIOA_PORT,MGPIO_PIN2,MGPIO_MODE_ALTF);
	MGPIO_voidSetAltFun(MGPIOA_PORT,MGPIO_PIN2,MGPIO_ALTFN1);//MGPIO_ALTFN2 timer(3&4&5)
	//chanal 4 A3
	MGPIO_voidSetPinMode(MGPIOA_PORT,MGPIO_PIN3,MGPIO_MODE_ALTF);
	MGPIO_voidSetAltFun(MGPIOA_PORT,MGPIO_PIN3,MGPIO_ALTFN1);//MGPIO_ALTFN2 timer(3&4&5)
	//enable a
	MGPIO_voidSetPinMode(MGPIOC_PORT,MGPIO_PIN14,MGPIO_MODE_OUTPUT);
	MGPIO_voidSetOutPutMode(MGPIOC_PORT,MGPIO_PIN14,MGPIO_OUTPUT_TYPE_PUSH_PULL);
	MGPIO_voidSetOutPutSpeed(MGPIOC_PORT,MGPIO_PIN14,MGPIO_OUTPUT_SPEED_MEDIUM);
	//enable B
	MGPIO_voidSetPinMode(MGPIOC_PORT,MGPIO_PIN15,MGPIO_MODE_OUTPUT);
	MGPIO_voidSetOutPutMode(MGPIOC_PORT,MGPIO_PIN15,MGPIO_OUTPUT_TYPE_PUSH_PULL);
	MGPIO_voidSetOutPutSpeed(MGPIOC_PORT,MGPIO_PIN15,MGPIO_OUTPUT_SPEED_MEDIUM);


}

void MOTOR_voidStart()
{
	MTMR_voidSetPrescaler(TMR_2,64);
	MTMR_voidSetARR(TMR_2,10000);//100000

	//forward side
	//MTMR_voidSetCMPVal(TMR_2,CH1,1000);//50000 //forward  & right side
	//MTMR_voidSetCMPVal(TMR_2,CH2,1500);//50000 //backward & right  side
	//backward side
	//MTMR_voidSetCMPVal(TMR_2,CH3,1000);//50000  //forward  & lift side
	//MTMR_voidSetCMPVal(TMR_2,CH4,800);//50000  //backward & lift side

	//MTMR_voidSetChannelOutput(TMR_2,PWM_MODE1,CH1);// 6 | 7 --> pwm mode
	//MTMR_voidSetChannelOutput(TMR_2,PWM_MODE1,CH2);// 6 | 7 --> pwm mode
	//MTMR_voidSetChannelOutput(TMR_2,PWM_MODE1,CH3);// 6 | 7 --> pwm mode
	//MTMR_voidSetChannelOutput(TMR_2,PWM_MODE1,CH4);// 6 | 7 --> pwm mode

	MTMR_voidStart(TMR_2);
}

void MOTOR_Move()
{
	MGPIO_voidSetPinVal(MGPIOC_PORT,MGPIO_PIN14,MGPIO_HIGH);
	MGPIO_voidSetPinVal(MGPIOC_PORT,MGPIO_PIN15,MGPIO_HIGH);

}

void MOTOR_Stop()
{
	MGPIO_voidSetPinVal(MGPIOC_PORT,MGPIO_PIN14,MGPIO_LOW);
	MGPIO_voidSetPinVal(MGPIOC_PORT,MGPIO_PIN15,MGPIO_LOW);

}

void MOTOR_chanelStop(u8 Copy_u8Chanel)
{
	MTMR_voidSetChannelOutput(TMR_2,PWM_MODE1,Copy_u8Chanel);// 6 | 7 --> pwm mode
	MTMR_voidSetCMPVal(TMR_2,Copy_u8Chanel,0);//50000  //forward  & lift side
}

void MOTOR_AllchanelStop()
{
	MOTOR_chanelStop(1);
	MOTOR_chanelStop(2);
	MOTOR_chanelStop(3);
	MOTOR_chanelStop(4);
}

void MOTOR_chanelStart(u8 Copy_u8Chanel)
{
	MTMR_voidSetCMPVal(TMR_2,Copy_u8Chanel,Motor_speed);//50000  //forward  & lift side
	MTMR_voidSetChannelOutput(TMR_2,PWM_MODE1,Copy_u8Chanel);// 6 | 7 --> pwm mode
}


void MOTOR_Forward()
{
	//must close channel for backward first
	MOTOR_chanelStop(2);
	MOTOR_chanelStop(4);

	//start channel to forward
	MOTOR_chanelStart(1);
	MOTOR_chanelStart(3);
}

void MOTOR_Backward()
{
	//must close channel for forward first
	MOTOR_chanelStop(1);
	MOTOR_chanelStop(3);

	//start channel too backward
	MOTOR_chanelStart(2);
	MOTOR_chanelStart(4);
}

void MOTOR_Right()
{
	MOTOR_chanelStop(1);
	MOTOR_chanelStop(2);
	MOTOR_chanelStop(4);

	MOTOR_chanelStart(3);
}

void MOTOR_Lift()
{
	MOTOR_chanelStop(2);
	MOTOR_chanelStop(3);
	MOTOR_chanelStop(4);
	MOTOR_chanelStart(1);
}


void MOTOR_Park()
{
	//back & right
	MOTOR_AllchanelStop();
	MSTK_voidSetBusyWait(5000000);
	MOTOR_Move();
	MTMR_voidSetChannelOutput(TMR_2,PWM_MODE1,CH3);// 6 | 7 --> pwm mode
	MTMR_voidSetCMPVal(TMR_2,CH3,3000);//50000  //forward  & lift side
	MSTK_voidSetBusyWait(2000000);
	MOTOR_chanelStop(3);

	MSTK_voidSetBusyWait(5000000);// for sefty

	//back all
	MTMR_voidSetChannelOutput(TMR_2,PWM_MODE1,CH2);// 6 | 7 --> pwm mode
	MTMR_voidSetCMPVal(TMR_2,CH2,2000);//50000  //forward  & lift side
	MTMR_voidSetChannelOutput(TMR_2,PWM_MODE1,CH4);// 6 | 7 --> pwm mode
	MTMR_voidSetCMPVal(TMR_2,CH4,2000);//50000  //forward  & lift side
	MSTK_voidSetBusyWait(3000000);
	MOTOR_chanelStop(2);
	MOTOR_chanelStop(4);

	MSTK_voidSetBusyWait(5000000); //for sefty

	//azbot wshak
	MTMR_voidSetChannelOutput(TMR_2,PWM_MODE1,CH1);// 6 | 7 --> pwm mode
	MTMR_voidSetCMPVal(TMR_2,CH1,2000);//50000  //forward  & lift side
	MSTK_voidSetBusyWait(2500000);
	MOTOR_chanelStop(1);

	MOTOR_Stop();
}

void MOTOR_Park1()
{
	//back & right
	MOTOR_AllchanelStop();
	MSTK_voidSetBusyWait(5000000);
	MOTOR_Move();
	MTMR_voidSetChannelOutput(TMR_2,PWM_MODE1,CH3);// 6 | 7 --> pwm mode
	MTMR_voidSetCMPVal(TMR_2,CH3,3000);//50000  //forward  & lift side
	MSTK_voidSetBusyWait(3000000);
	MOTOR_chanelStop(3);
	MSTK_voidSetBusyWait(5000000);

	//back all
	MTMR_voidSetChannelOutput(TMR_2,PWM_MODE1,CH2);// 6 | 7 --> pwm mode
	MTMR_voidSetCMPVal(TMR_2,CH2,2000);//50000  //forward  & lift side
	MTMR_voidSetChannelOutput(TMR_2,PWM_MODE1,CH4);// 6 | 7 --> pwm mode
	MTMR_voidSetCMPVal(TMR_2,CH4,2000);//50000  //forward  & lift side
	MSTK_voidSetBusyWait(2300000);
	MOTOR_chanelStop(2);
	MOTOR_chanelStop(4);
	MSTK_voidSetBusyWait(5000000);

	MOTOR_Stop();
}

