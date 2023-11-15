/*
 * Main_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: omara
 */

#ifndef MAIN_INTERFACE_H_
#define MAIN_INTERFACE_H_
#include "LIB/bit_macros.h"
#include "LIB/STD_TYPES.h"

#include "MCAL/RCC/RCC_Interface.h"
#include "MCAL/GPIO/GPIO_Interface.h"

#include "MCAL/STK/STK_Interface.h"


#include "MCAL/STK/STK_Config.h"
#include "MCAL/STK/STK_Private.h"

#include "MCAL/RCC/RCC_Config.h"
#include "MCAL/RCC/RCC_Private.h"



#include "MCAL/GPIO/GPIO_Private.h"
#include "MCAL/GPIO/GPIO_Config.h"

//HAL

#include "MCAL/USART/USART_Interface.h"
#include "MCAL/USART/USART_Config.h"
#include "MCAL/USART/USART_Private.h"

//#include "HAL/TFT/TFT_Interface.h"
//#include "HAL/TFT/TFT_Config.h"
//#include "HAL/TFT/TFT_Private.h"


#include "MCAL/TIMER/TIMER_Interface.h"
#include "MCAL/TIMER/TIMER_Config.h"
#include "MCAL/TIMER/TIMER_Private.h"


#include "HAL/DCM/DCM_Interface.h"

void Main_voidInit(void);
//init rcc




#endif /* MAIN_INTERFACE_H_ */
