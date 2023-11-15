/******************************************************************************
 *

 *
 *******************************************************************************/
#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/*
																						_________
     (16MHZ RC)		HSI -------------------------------------------------------------->|  		 |
(4-26MHZ CRY OR RC)	HSE ----|--------------------------------------------------------->| SYS CLK |
						 |  |	  _____												-->|_________|
						 |  |--> | 	   |	  									   |
						 |-----> | PLL | -->  (/PLLM) --> (*PLLN) |----> (/PLLP) --|
								 |_____|	  	   				  |----> (/PLLQ) -----> USB OTG FS, SDIO
*/

/*
* Clock Type:
* RCC_HSI    
* RCC_HSE_CRY
* RCC_HSE_RC 
* RCC_PLL 
*/   

#define RCC_CLOCK_TYPE   RCC_HSI

/*
* Clock Type:
* RCC_HSI
* RCC_HSE_CRY
* RCC_HSE_RC
*/
#define RCC_PLL_SRC      RCC_HSI

/*
* PLL Type:
* PLL_P
* PLL_Q
*/
#define RCC_PLL_TYPE      PLL_P

/*
* PLLQ Value should be: 2 ≤PLLQ ≤15
* 0000: PLLQ = 0, wrong configuration
* 0001: PLLQ = 1, wrong configuration
* 0010: PLLQ = 2
* 0011: PLLQ = 3
* 0100: PLLQ = 4
* ...
* 1111: PLLQ = 15
*/
#define RCC_PLLQ    2

/*
* PLL Division Factor:
* PLLP_2
* PLLP_4
* PLLP_6
* PLLP_8
*/

#define RCC_PLLP  PLLP_2

/*
* PLLN Value should be: 192 ≤PLLN ≤432
* 000000000: PLLN = 0, wrong configuration
* 000000001: PLLN = 1, wrong configuration
* ....
* 110110000: PLLN = 432
* 110110001: PLLN = 433, wrong configuration
* ...
* 111111111: PLLN = 511, wrong configuration
*/
#define RCC_PLLN    192

/*
* PLLM Value should be: 2 ≤PLLM ≤63
* 000000: PLLM = 0, wrong configuration
* 000001: PLLM = 1, wrong configuration
* 000010: PLLM = 2
* 000011: PLLM = 3
* 000100: PLLM = 4
* ...
* 111110: PLLM = 62
* 111111: PLLM = 63
*/
#define RCC_PLLM    2

#endif /* RCC_CONFIG_H_ */
