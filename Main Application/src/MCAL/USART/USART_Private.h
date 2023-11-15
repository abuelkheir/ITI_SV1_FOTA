/*
 * USART_Private.h
 *
 *  Created on: Sep 19, 2023
 *      Author: mayke
 */

#ifndef USART_USART_PRIVATE_H_
#define USART_USART_PRIVATE_H_


//#define BaudRateSpeed(Copy_u32BaudRate)			(f32)((Fclk)/(8*Copy_u32BaudRate)));
#define USART1EN			4U
#define USART6EN			5U
#define USART2EN			17U
#define USART1_BASE_ADDRESS  (0x40011000)
#define USART6_BASE_ADDRESS  (0x40011400)
#define USART2_BASE_ADDRESS  (0x40004400)
typedef struct
{
volatile u32 SR;
volatile u32 DR;
volatile u32 BRR;
volatile u32 CR1;
volatile u32 CR2;
volatile u32 GTPT;

}USART;

#define   USART1      ((volatile USART  *)USART1_BASE_ADDRESS)

#define   USART6      ((volatile USART  *)USART6_BASE_ADDRESS)

#define   USART2      ((volatile USART  *)USART2_BASE_ADDRESS)

#endif /* USART_USART_PRIVATE_H_ */
