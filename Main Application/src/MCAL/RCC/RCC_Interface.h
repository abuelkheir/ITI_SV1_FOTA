/*
 * RCC_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: omara
 */

#ifndef MCAL_RCC_RCC_INTERFACE_H_
#define MCAL_RCC_RCC_INTERFACE_H_

void MRCC_VoidInit();

void MRCC_VoidEnable_Priph(u8 copy_PriphBus,u8 copy_PriphNum);

void MRCC_VoidDesable_Priph(u8 copy_PriphBus,u8 copy_PriphNum);

#define HSI     1
#define HSE     2
#define PLL     3




#endif /* MCAL_RCC_RCC_INTERFACE_H_ */
