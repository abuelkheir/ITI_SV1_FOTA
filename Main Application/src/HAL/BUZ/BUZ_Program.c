/*
 * BUZ_Program.c
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

#include "BUZ_Interface.h"

//elmfrod howa sh3'aal 3la chanal 1 & 2
void BUZ_VoidInit()
{
	MRCC_VoidEnable_Priph(APB1,RCC_TIM3);
	//chanal 1 A0
	MGPIO_voidSetPinMode(MGPIOB_PORT,MGPIO_PIN4,MGPIO_MODE_ALTF);
	MGPIO_voidSetAltFun(MGPIOB_PORT,MGPIO_PIN4,MGPIO_ALTFN2);//MGPIO_ALTFN2 timer(3&4&5)
	//chanal 2 A1
	//MGPIO_voidSetPinMode(MGPIOA_PORT,MGPIO_PIN1,MGPIO_MODE_ALTF);
	//MGPIO_voidSetAltFun(MGPIOA_PORT,MGPIO_PIN1,MGPIO_ALTFN1);//MGPIO_ALTFN2 timer(3&4&5)
	MTMR_voidSetPrescaler(TMR_3,64);
	MTMR_voidSetARR(TMR_3,100000);
	MTMR_voidSetChannelOutput(TMR_3,PWM_MODE1,CH1);// 6 | 7 --> pwm mode

}

void BUZ_VoidStart(u8 copy_u8Speed)//1=10000 -> 4=2500
{
	u32 L_Speed;
	switch (copy_u8Speed)
	{
		case 1:
			L_Speed=100000;
	    break;
	    case 2:
			L_Speed=60000;
	    break;
	    case 3:
			L_Speed=50000;
	    break;
	    case 4:
			L_Speed=25000;
	    break;
	    default:
			L_Speed=99000;
			break;
	}
	MTMR_voidSetCMPVal(TMR_3,CH1,L_Speed);
	MTMR_voidStart(TMR_3);
}

void BUZ_VoidStop()
{
	MTMR_voidStop(TMR_3);

}


