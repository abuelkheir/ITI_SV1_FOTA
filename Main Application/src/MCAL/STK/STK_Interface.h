/*
 * STK_Interface.h
 *
 *  Created on: ??�/??�/????
 *      Author: omara
 */

#ifndef MCAL_STK_STK_INTERFACE_H_
#define MCAL_STK_STK_INTERFACE_H_


void MSTK_voidInit(void);

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks);

void MSTK_voidSetIntervalSingle (u32 Copy_u32Ticks , void (*Copy_Ptr)(void));

void MSTK_voidSetIntervalPeriodic (u32 Copy_u32Ticks , void (*Copy_Ptr)(void));

void MSTK_voidStopInterval(void);

u32 MSTK_u32GetElapsedTime(void);

u32 MSTK_u32GetRemainingTime(void);





#endif /* MCAL_STK_STK_INTERFACE_H_ */
