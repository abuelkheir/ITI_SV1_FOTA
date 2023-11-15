/*
 * RCC_Config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: omara
 */

#ifndef MCAL_RCC_RCC_CONFIG_H_
#define MCAL_RCC_RCC_CONFIG_H_


#define clock_type  HSI   //( HSI & HSE & PLL)
/*******************************************************************/
/*                       ClockType Maybe :                         */
/*                       1-HSI                                     */
/*                       2-HSE                                     */
/*                       3-PLL                                     */


//AHB1
#define RCC_GPIOA  0
#define RCC_GPIOB  1
#define RCC_GPIOC  2
#define RCC_CRC    12
#define RCC_DMA1   21
#define RCC_DMA2   22

//AHB2


//APB1
#define RCC_TIM2 0
#define RCC_TIM3 1
#define RCC_TIM4 2
#define RCC_TIM5 3
#define RCC_SPI2 14
#define RCC_SPI3 15



//APB2
#define RCC_SYSCFG  14
#define RCC_UART1    4
#define RCC_UART6    5
#define RCC_SPI1    12
#define RCC_SPI4    13

//AHB1LP
#define RCC_FLASH   15





#endif /* MCAL_RCC_RCC_CONFIG_H_ */
