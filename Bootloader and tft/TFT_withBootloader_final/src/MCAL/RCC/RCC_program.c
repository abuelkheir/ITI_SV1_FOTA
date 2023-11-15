/******************************************************************************
 *

 *
 *******************************************************************************/
 
/*******************************************************************************
 *                          	Standard Types                                 *
 *******************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/*******************************************************************************
 *                          	MCAL Components                                 *
 *******************************************************************************/
#include "RCC_config.h"
#include "RCC_interface.h"
#include "RCC_private.h"

/*******************************************************************************
 *                          	APIs Implementation                            *
 *******************************************************************************/

/*
																						_________
     (16MHZ RC)		HSI -------------------------------------------------------------->|  		 |
(4-26MHZ CRY OR RC)	HSE ----|--------------------------------------------------------->| SYS CLK |
						 |  |	  _____												-->|_________|
						 |  |--> | 	   |	  									   |
						 |-----> | PLL | -->  (/PLLM) --> (*PLLN) |----> (/PLLP) --|
								 |_____|	  	   				  |----> (/PLLQ) -----> USB OTG FS, SDIO
*/



void MRCC_voidInit(void) 
{
	#if CLOCK_TYPE == RCC_HSI
	
		// set HSION bit in CR Register
		SET_BIT(MRCC->RCC_CR,HSION); 	
		// wait until HSI ready flag is on
		while(GET_BIT(MRCC->RCC_CR,HSIRDY) == 0);
		// switch system clock to HSI 
		CLR_BIT(MRCC->RCC_CFGR,SW0);
		CLR_BIT(MRCC->RCC_CFGR,SW1);
			
	#elif CLOCK_TYPE == RCC_HSE_CRY
	
		// set HSEON bit in CR Register	
		SET_BIT(MRCC->RCC_CR,HSEON);	
		// wait until HSE ready flag is on
		while(GET_BIT(MRCC->RCC_CR,HSERDY) == 0);
		// switch system clock to HSE
		SET_BIT(MRCC->RCC_CFGR,SW0);    // set SW bit 0 in CFGR to turn on HSE
		CLR_BIT(MRCC->RCC_CFGR,SW1);  // clear SW bit 1 in CFGR to turn on HSE
		 	  	
	#elif CLOCK_TYPE == RCC_HSE_RC
	
		// enable HSE clock bypass 
		SET_BIT(MRCC->RCC_CR,HSEBYP);		
		// set HSEON bit in CR Register	
		SET_BIT(MRCC->RCC_CR,HSEON);
		// wait until HSE ready flag is on
		while(GET_BIT(MRCC->RCC_CR,HSERDY) == 0);
		// switch system clock to HSE
		SET_BIT(MRCC->RCC_CFGR,SW0);    // set SW bit 0 in CFGR to turn on HSE
		CLR_BIT(MRCC->RCC_CFGR,SW1);  // clear SW bit 1 in CFGR to turn on HSE
		 	  	
	#elif CLOCK_TYPE == RCC_PLL
	
		// PLL must be off while setting its configurations
		CLR_BIT(MRCC->RCC_CR,PLLON);
		
		#if RCC_PLL_SRC == RCC_HSI
		// set HSION bit in CR Register
		SET_BIT(MRCC->RCC_CR,HSION); 
		// wait until HSI ready flag is on
		while(GET_BIT(MRCC->RCC_CR,HSIRDY) == 0);
		// select HSI to PLL source
		CLR_BIT(MRCC->RCC_PLLCFGR,PLLSRC);
		
		#elif RCC_PLL_SRC == RCC_HSE_CRY
		// set HSEON bit in CR Register
		SET_BIT(MRCC->RCC_CR,HSEON); 
		// wait until HSE ready flag is on
		while(GET_BIT(MRCC->RCC_CR,HSERDY) == 0);
		// select HSE to PLL source
		SET_BIT(MRCC->RCC_PLLCFGR,PLLSRC); 
		
		#elif RCC_PLL_SRC == RCC_HSE_RC
		// enable HSE clock bypass 
		SET_BIT(MRCC->RCC_CR,HSEBYP);		
		// set HSEON bit in CR Register
		SET_BIT(MRCC->RCC_CR,HSEON); 
		// wait until HSE ready flag is on
		while(GET_BIT(MRCC->RCC_CR,HSERDY) == 0);
		// select HSE to PLL source
		SET_BIT(MRCC->RCC_PLLCFGR,PLLSRC); 
		#endif
		
		// set PLLM value
		MRCC->RCC_PLLCFGR = (MRCC->RCC_PLLCFGR & 0xFFFFFFC0) | (RCC_PLLM << PLLM0);
		// set PLLN value
		MRCC->RCC_PLLCFGR = (MRCC->RCC_PLLCFGR & 0xFFFF803F) | (RCC_PLLN << PLLN0);
		
		#if RCC_PLL_TYPE == PLL_P
		// set PLLP value
		MRCC->RCC_PLLCFGR = (MRCC->RCC_PLLCFGR & 0xFFFCFFFF) | (RCC_PLLP << PLLP0);
		
		#elif RCC_PLL_TYPE == PLL_Q
		// set PLLQ value
		MRCC->RCC_PLLCFGR = (MRCC->RCC_PLLCFGR & 0xF0FFFFFF) | (RCC_PLLQ << PLLQ0);
		#endif
		
		// turn on PLL
		SET_BIT(MRCC->RCC_CR,PLLON);
		// wait until PLL ready flag is on
		while(GET_BIT(MRCC->RCC_CR,PLLRDY) == 0);
		
	#endif
	
}


void MRCC_voidEnablePeripheralClock(u8 cpy_u8PeripheralBus, u8 cpy_u8PeripheralNumber)
{
	// validate peripheral inputs
	 if(cpy_u8PeripheralNumber <= 31) {
		 switch(cpy_u8PeripheralBus) {
		 	 	case RCC_AHB1 : SET_BIT(MRCC->RCC_AHB1ENR, cpy_u8PeripheralNumber); break;
				case RCC_AHB2 : SET_BIT(MRCC->RCC_AHB2ENR, cpy_u8PeripheralNumber); break;
				case RCC_APB1 : SET_BIT(MRCC->RCC_APB1ENR, cpy_u8PeripheralNumber); break;
				case RCC_APB2 : SET_BIT(MRCC->RCC_APB2ENR, cpy_u8PeripheralNumber); break;
				default       : break;// return error
		 }
	 }

	 else {
		 // return error
	 }
}

void MRCC_voidDisablePeripheralClock(u8 cpy_u8PeripheralBus, u8 cpy_u8PeripheralNumber)
{
	// validate peripheral inputs
	 if(cpy_u8PeripheralNumber <= 31) {
		 switch(cpy_u8PeripheralBus) {
		 	 	case RCC_AHB1 : CLR_BIT(MRCC->RCC_AHB1ENR, cpy_u8PeripheralNumber); break;
				case RCC_AHB2 : CLR_BIT(MRCC->RCC_AHB2ENR, cpy_u8PeripheralNumber); break;
				case RCC_APB1 : CLR_BIT(MRCC->RCC_APB1ENR, cpy_u8PeripheralNumber); break;
				case RCC_APB2 : CLR_BIT(MRCC->RCC_APB2ENR, cpy_u8PeripheralNumber); break;
				default       : break;// return error
		 }
	 }

	 else {
		 // return error
	 }
}
