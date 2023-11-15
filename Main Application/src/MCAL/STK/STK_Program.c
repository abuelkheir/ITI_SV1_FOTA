/*
 * STK_Program.c
 *
 *  Created on: ??�/??�/????
 *      Author: omara
 *
 *
 *      final v in 11/10/2023
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/bit_macros.h"

// MCAL COMPONENTS
#include "STK_Private.h"
#include "STK_Interface.h"
#include "STK_Config.h"

static void (*STK_SINGEL)(void)=0;
static void (*STK_PERIODIC)(void)=0;

//----------------------------------------------------------------FUNCTION-----------------------------------------------------------------
//----------------------------------------------------------------        ----------------------------------------------------------------

void MSTK_voidInit(void)
{
    //MSTK_REG->CTRL=((MSTK_REG->CTRL & 0XFFFFFFFB) | (STK_SOURCE << STK_CLKSOURCE));
    //CLR_BIT(MSTK_REG->CTRL,1);
    CLR_BIT(MSTK_REG->CTRL,STK_CLKSOURCE); //AHB8

}

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks)
{
    MSTK_REG->LOAD=Copy_u32Ticks;
    SET_BIT(MSTK_REG->CTRL,STK_ENABLE);

    while(GET_BIT(MSTK_REG->CTRL,STK_COUNTFLAG)==0);

    CLR_BIT(MSTK_REG->CTRL,STK_ENABLE);
    MSTK_REG->LOAD=0;
    MSTK_REG->VAL=0;
}

void MSTK_voidSetIntervalSingle (u32 Copy_u32Ticks , void (*Copy_Ptr)(void))
{

   // MSTK_REG->CTRL=((MSTK_REG->CTRL & 0XFFFFFFFD) | (STK_INTERRUPT << STK_TICKINT));
    MSTK_REG->VAL=0;
    MSTK_REG->LOAD=Copy_u32Ticks;
    SET_BIT(MSTK_REG->CTRL,1);
    SET_BIT(MSTK_REG->CTRL,STK_ENABLE);
    STK_SINGEL = Copy_Ptr;
}

void MSTK_voidSetIntervalPeriodic (u32 Copy_u32Ticks , void (*Copy_Ptr)(void))
{
    MSTK_REG->CTRL=((MSTK_REG->CTRL & 0XFFFFFFFD) | (STK_INTERRUPT << STK_TICKINT));
    MSTK_REG->LOAD=Copy_u32Ticks;
    SET_BIT(MSTK_REG->CTRL,STK_ENABLE);
    STK_PERIODIC = Copy_Ptr;
}

void MSTK_voidStopInterval(void)
{
    MSTK_REG->VAL=0;
    MSTK_REG->LOAD=0;
    STK_PERIODIC=0;
}

u32 MSTK_u32GetElapsedTime(void)
{
	u32 L_u32ElapsedTime=0;
	//calc elapsed time
	L_u32ElapsedTime=(MSTK_REG->LOAD-MSTK_REG->VAL);
	return L_u32ElapsedTime;
}

u32 MSTK_u32GetRemainingTime(void)
{
	return MSTK_REG->VAL;
}

//---------------------------------------------------------ISR----------------------------------------------------------------
//---------------------------------------------------------    ---------------------------------------------------------------

void SysTick_Handler(void)
{
    if (STK_SINGEL!=0)
    {
        STK_SINGEL();

        MSTK_REG->LOAD=0;
        MSTK_REG->VAL=0;

        STK_SINGEL=0;
    }
    else if (STK_PERIODIC!=0)
    {
        STK_PERIODIC();
    }
    
}



