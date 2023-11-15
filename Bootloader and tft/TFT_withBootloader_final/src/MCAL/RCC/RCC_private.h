/******************************************************************************
 *

 *
 *******************************************************************************/

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

/*******************************************************************************
 *                           	   Definitions                                 *
 *******************************************************************************/

/* System Clock Type */
#define RCC_HSI      0
#define RCC_HSE_CRY  1
#define RCC_HSE_RC   2
#define RCC_PLL      3

/* System PLL Type */
#define PLL_P        0
#define PLL_Q        1

/* PLLP Division Factor */
#define PLLP_2       0b00
#define PLLP_4       0b01
#define PLLP_6       0b10
#define PLLP_8       0b11

/*******************************************************************************
 *                           	   RCC Register Map                            *
 *******************************************************************************/

#define BASE_ADDRESS 		 (0x40023800) 
typedef struct {

volatile u32 RCC_CR;         // RCC clock control register
volatile u32 RCC_PLLCFGR;    // RCC PLL configuration register
volatile u32 RCC_CFGR;       // RCC clock configuration register
volatile u32 RCC_CIR;        // RCC clock interrupt register
volatile u32 RCC_AHB1RSTR;   // RCC AHB1 peripheral reset register
volatile u32 RCC_AHB2RSTR;   // RCC AHB2 peripheral reset register
volatile u32 RCC_RESERVED1;  // you must include reserved registers, because struct is block-based
volatile u32 RCC_RESERVED2;  // reserved
volatile u32 RCC_APB1RSTR;   // RCC APB1 peripheral reset register
volatile u32 RCC_APB2RSTR;   // RCC APB2 peripheral reset register
volatile u32 RCC_RESERVED3;  // reserved
volatile u32 RCC_RESERVED4;  // reserved
volatile u32 RCC_AHB1ENR;    // RCC AHB1 peripheral clock enable register
volatile u32 RCC_AHB2ENR;    // RCC AHB2 peripheral clock enable register
volatile u32 RCC_RESERVED5;  // reserved
volatile u32 RCC_RESERVED6;  // reserved
volatile u32 RCC_APB1ENR;    // RCC APB1 peripheral clock enable register
volatile u32 RCC_APB2ENR;  	// RCC APB2 peripheral clock enable register
volatile u32 RCC_RESERVED7;  // reserved
volatile u32 RCC_RESERVED8;  // reserved
volatile u32 RCC_AHB1LPENR;  // RCC AHB1 peripheral clock enable in low power mode register
volatile u32 RCC_AHB2LPENR;  // RCC AHB2 peripheral clock enable in low power mode register
volatile u32 RCC_RESERVED9;  // reserved
volatile u32 RCC_RESERVED10; // reserved
volatile u32 RCC_APB1LPENR;  // RCC APB1 peripheral clock enable in low power mode register
volatile u32 RCC_APB2LPENR;  // RCC APB2 peripheral clock enable in low power mode register
volatile u32 RCC_RESERVED11; // reserved
volatile u32 RCC_RESERVED12; // reserved
volatile u32 RCC_BDCR;       // RCC Backup domain control register
volatile u32 RCC_CSR;  		// RCC clock control & status register
volatile u32 RCC_RESERVED13; // reserved
volatile u32 RCC_RESERVED14; // reserved
volatile u32 RCC_SSCGR;      //  RCC spread spectrum clock generation register
volatile u32 RCC_PLLI2SCFGR; // RCC PLLI2S configuration register
volatile u32 RCC_RESERVED15; // reserved
volatile u32 RCC_DCKCFGR;    // RCC Dedicated Clocks Configuration Register
	
}RCC;
// we don't need to make object, we will use pointer to struct to loop on them only 

#define MRCC    ((volatile RCC*)(BASE_ADDRESS)) // pointer to first element in RCC struct starting from BASE_ADDRESS
// to access struct : MRCC->RCC_CR = value   or *(MRCC.RCC_CR) = value

/* RCC_CR Register */
#define PLLI2SRDY         27U
#define PLLI2SON		  26U
#define PLLRDY			  25U
#define PLLON			  24U
#define CSSON			  19U
#define HSEBYP			  18U
#define HSERDY			  17U
#define HSEON			  16U
#define HSICAL7 		  15U
#define HSICAL6 		  14U
#define HSICAL5 		  13U
#define HSICAL4 		  12U
#define HSICAL3 		  11U
#define HSICAL2 		  10U
#define HSICAL1 		  9U
#define HSICAL0 		  8U
#define HSITRIM4          7U
#define HSITRIM3          6U
#define HSITRIM2          5U
#define HSITRIM1          4U
#define HSITRIM0          3U
#define HSIRDY 			  1U
#define HSION			  0U

/* RCC_PLLCFGR Register */
#define PLLQ3			  27U
#define PLLQ2			  26U
#define PLLQ1			  25U
#define PLLQ0			  24U
#define PLLSRC			  22U
#define PLLP1			  17U
#define PLLP0			  16U
#define PLLN8			  14U
#define PLLN7			  13U
#define PLLN6			  12U
#define PLLN5			  11U
#define PLLN4			  10U
#define PLLN3			  9U
#define PLLN2			  8U
#define PLLN1			  7U
#define PLLN0			  6U
#define PLLM5			  5U
#define PLLM4			  4U
#define PLLM3			  3U
#define PLLM2			  2U
#define PLLM1			  1U
#define PLLM0			  0U

/* RCC_CFGR Register */
#define MCO21 			  31U
#define MC020			  30U
#define MCO2PRE2		  29U
#define MCO2PRE1		  28U
#define MCO2PRE0		  27U
#define MCO1PRE2		  26U
#define MCO1PRE1		  25U
#define MCO1PRE0		  24U
#define I2SSCR			  23U
#define MCO11			  22U
#define MCO10			  21U
#define RTCPRE4			  20U
#define RTCPRE3			  19U
#define RTCPRE2			  18U
#define RTCPRE1			  17U
#define RTCPRE0			  16U
#define PPRE22			  15U
#define PPRE21			  14U
#define PPRE20			  13U
#define PPRE12			  12U
#define PPRE11			  11U
#define PPRE10			  10U
#define HPRE3			  7U
#define HPRE2			  6U
#define HPRE1			  5U
#define HPRE0			  4U
#define SWS1			  3U
#define SWS0			  2U
#define SW1				  1U
#define SW0  			  0U

/* RCC_AHB1ENR Register */
#define DMA2EN			  22U
#define DMA1EN			  21U
#define CRCEN			  12U
#define GPIOHEN			  7U
#define GPIOEEN			  4U
#define GPIODEN			  3U
#define GPIOCEN			  2U
#define GPIOBEN			  1U
#define GPIOAEN			  0U

/* RCC_AHB2ENR Register */
#define OTGFSEN 		  7

/* RCC_APB1ENR Register */
#define PWREN			  28U
#define I2C3EN			  23U
#define I2C2EN			  22U
#define I2C1EN			  21U
#define USART2EN		  17U
#define SPI3EN		      15U
#define SPI2EN		      14U
#define WWDGEN			  11U
#define TIM5EN			  3U
#define TIM4EN			  2U
#define TIM3EN			  1U
#define TIM2EN			  0U

/* RCC_APB2ENR Register */
#define TIM11EN			  18U
#define TIM10EN			  17U
#define TIM9EN			  16U
#define SYSCFGEN		  14U
#define SPI4EN   		  13U
#define SPI1EN   		  12U
#define SDIOEN			  11U
#define ADC1EN			  8U
#define USART6EN		  5U
#define USART1EN		  4U
#define TIM1EN			  0U

#endif /* RCC_PRIVATE_H_ */
