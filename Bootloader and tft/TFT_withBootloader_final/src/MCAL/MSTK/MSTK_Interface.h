

#ifndef STK_MSTK_INTERFACE_H_
#define STK_MSTK_INTERFACE_H_

#include "MSTK_Config.h"
#include "MSTK_Private.h"



void MSTK_voidInit(void);
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks);
void MSTK_SetIntervalSingle(u32 Copy_u32Ticks,void(*Copy_ptr)(void));
void MSTK_SetIntervalPeriodic(u32 Copy_u32Ticks,void(*Copy_ptr)(void));
void MSTK_StopInterval(void);
u32 MSTK_u32GetElapsedTime(void);
u32 MSTK_u32GetRemainingTime(void);


#endif /* STK_MSTK_INTERFACE_H_ */
