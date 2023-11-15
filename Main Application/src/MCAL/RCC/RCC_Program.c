/*
 * RCC_Program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: omara
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/bit_macros.h"
#include "RCC_Config.h"
#include "RCC_Private.h"


// INIT CLOCK WITH ANY SYSTEM FROM        //!         ( HSI | HSE | PLL)
void MRCC_VoidInit()
{
    #if clock_type == HSI
    //INTERNAL HIGH SPEED CLOCK ENABLE
    SET_BIT(MRCC->RCC_CR,CR_HSION);

	while(GET_BIT(MRCC->RCC_CR,CR_HSIRDY) == 0);
    // SYSTEM CLOCK SWITCH IN REG->CFGR BITS(0,1) SW_0 & SE_1
    CLR_BIT(MRCC->RCC_CFGR,CFGR_SW_0);
    CLR_BIT(MRCC->RCC_CFGR,CFGR_SW_1);
    #endif

    #if clock_type == HSE
    //EXTERNAL HIGH SPEED CLOCK ENABLE
    SET_BIT(MRCC->RCC_CR,CR_HSEON);
    // SYSTEM CLOCK SWITCH IN REG->CFGR BITS(0,1) SW_0 & SE_1
    SET_BIT(MRCC->RCC_CFGR,CFGR_SW_0);
    CLR_BIT(MRCC->RCC_CFGR,CFGR_SW_1);
    #endif

    #if clock_type == PLL
    //PPL CLOCK ENABLE
    SET_BIT(MRCC->RCC_CR,CR_PLL_ON);
    // SYSTEM CLOCK SWITCH IN REG->CFGR BITS(0,1) SW_0 & SE_1
    CLR_BIT(MRCC->RCC_CFGR,CFGR_SW_0);
    SET_BIT(MRCC->RCC_CFGR,CFGR_SW_1);
    #endif
}


void MRCC_VoidEnable_Priph(u8 copy_PriphBus,u8 copy_PriphPinNum) //AHB1=1 & AHB2=2 & APB1=3 & APB2=4 & AHB1LP=5
{															  //GPIOA = PIN 0 IN (RCC_AHB1RSTR)
    switch (copy_PriphBus)
    {
    case AHB1 :
        SET_BIT(MRCC->RCC_AHB1ENR,copy_PriphPinNum);
        break;
    case AHB2 :
        SET_BIT(MRCC->RCC_AHB2ENR,copy_PriphPinNum);
        break;
    case APB1 :
        SET_BIT(MRCC->RCC_APB1ENR,copy_PriphPinNum);
        break;
    case APB2 :
        SET_BIT(MRCC->RCC_APB2ENR,copy_PriphPinNum);
        break;
    case AHB1LP :
        SET_BIT(MRCC->RCC_AHB1LPENR,copy_PriphPinNum);
        break;
    default:
        break;
    }
}

void MRCC_VoidDesable_Priph(u8 copy_PriphBus,u8 copy_PriphNum)
{
    switch (copy_PriphBus)
    {
    case AHB1 :
        CLR_BIT(MRCC->RCC_AHB1ENR,copy_PriphNum);
        break;
    case AHB2 :
        CLR_BIT(MRCC->RCC_AHB2ENR,copy_PriphNum);
        break;
    case APB1 :
        CLR_BIT(MRCC->RCC_APB1ENR,copy_PriphNum);
        break;
    case APB2 :
        CLR_BIT(MRCC->RCC_APB2ENR,copy_PriphNum);
        break;
    default:
        break;
    }
}


