/*
 * STK_Private.h
 *
 *  Created on: ??�/??�/????
 *      Author: omara
 */

#ifndef MCAL_STK_STK_PRIVATE_H_
#define MCAL_STK_STK_PRIVATE_H_

//#define EXTI_BASE_ADDRESS  0xE000E010

typedef struct 
{
    volatile u32 CTRL;
    volatile u32 LOAD;
    volatile u32 VAL;
    volatile u32 CALIB;
}STK_t;

#define MSTK_REG   ((volatile STK_t *)0xE000E010)
//------------------------------------------------------
//STK_CTRL BITS
#define STK_ENABLE     0
#define STK_TICKINT    1
#define STK_CLKSOURCE  2
#define STK_COUNTFLAG  16
//---------------------------------
#define CLOCK_AHB      1
#define CLOCK_AHB_8    0
//--------------------------------
#define STK_ENABLE_INTERRUPT   1
#define STK_DESABLE_INTERRUPT  0

#endif /* MCAL_STK_STK_PRIVATE_H_ */
