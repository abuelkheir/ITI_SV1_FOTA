/******************************************************************************
 *

 *
 *******************************************************************************/

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

/*******************************************************************************
 *                           	   Definitions                                 *
 *******************************************************************************/

#include "RCC_private.h"

/* System Buses */
#define  RCC_AHB1    0
#define  RCC_AHB2 	 1
#define  RCC_APB1	 2
#define  RCC_APB2    3

/* System Peripherals */
/* RCC_AHB1 */
#define DMA2  			  DMA2EN
#define DMA1			  DMA1EN
#define CRC  		      CRCEN
#define GPIOH			  GPIOHEN
#define GPIOE			  GPIOEEN
#define GPIOD			  GPIODEN
#define GPIOC			  GPIOCEN
#define GPIOB			  GPIOBEN
#define GPIOA    		  GPIOAEN
/* RCC_AHB2 */
#define OTGFS			  OTGFSEN
/* RCC_APB1 */
#define PWR	   			  PWREN			  
#define I2C3 			  I2C3EN			  
#define I2C2		      I2C2EN			  
#define I2C1              I2C1EN			  
#define USART2     		  USART2EN		  
#define SPI3 			  SPI3EN		      
#define SPI2			  SPI2EN		      
#define WWDG			  WWDGEN			  
#define TIM5			  TIM5EN					  
#define TIM4			  TIM4EN
#define TIM3			  TIM3EN
#define TIM2			  TIM2EN
/* RCC_APB2 */
#define TIM11		      TIM11EN			 
#define TIM10			  TIM10EN			 
#define TIM9			  TIM9EN			 
#define SYSCFG			  SYSCFGEN		 
#define SPI4			  SPI4EN   		 
#define SPI1			  SPI1EN   		 
#define SDIO			  SDIOEN			 
#define ADC1		   	  ADC1EN			 
#define USART6		      USART6EN		 
#define USART1			  USART1EN		 
#define TIM1			  TIM1EN			 

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
 
void MRCC_voidInit(void);
/*
 * FUNCTION NAME:		  MRCC_voidInit
 * FUNCTION RETURN:		  nothing
 * FUNCTION ARGUMENTS:	  nothing
 * FUNCTION DESCRIPTION:  Initialization Function for RCC Driver
 */
 
void MRCC_voidEnablePeripheralClock(u8 cpy_u8BusId, u8 cpy_u8PerId);
/*
 * FUNCTION NAME:		  MRCC_voidEnablePeripheralClock
 * FUNCTION RETURN:		  nothing
 * FUNCTION ARGUMENTS:	  unsigned char (Bus ID), unsigned char (Peripheral ID)
 * FUNCTION DESCRIPTION:  Enable Clock for ARM Peripherals
 */

void MRCC_voidDisablePeripheralClock(u8 cpy_u8BusId, u8 cpy_u8PerId);
/*
 * FUNCTION NAME:		  MRCC_voidDisablePeripheralClock
 * FUNCTION RETURN:		  nothing
 * FUNCTION ARGUMENTS:	  unsigned char (Bus ID), unsigned char (Peripheral ID)
 * FUNCTION DESCRIPTION:  Disable Clock for ARM Peripherals
 */


#endif /* RCC_INTERFACE_H_ */
