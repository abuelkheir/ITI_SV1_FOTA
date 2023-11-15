/******************************************************************************
 *
 * M
 *******************************************************************************/

/*******************************************************************************
 *                          	Standard Types                                 *
 *******************************************************************************/
 
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/*******************************************************************************
 *                          	MCAL Components                                 *
 *******************************************************************************/
#include "GPIO_interface.h"
#include "GPIO_private.h"

/*******************************************************************************
 *                          	APIs Implementation                            *
 *******************************************************************************/
 
// GPIO Driver is based on POST-BUILD (user can change the configuration during runtime)

void MGPIO_voidSetPinMode(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinMode) 
{
	/*
	User will enter Pin Mode: 
	GPIO_INPUT_MODE 
	GPIO_OUTPUT_MODE
	GPIO_ALTF_MODE  
	GPIO_ANALOG MODE
	*/
	
	if( Copy_u8PinNumber < 16)
	{
		switch(Copy_u8PortName) 
		{
			// every PIN configured with 2 bits 
			/*case GPIO_PORTA : MGPIOA->GPIO_MODER |= (u32)(Copy_u8PinMode << (2U * Copy_u8PinNumber));   break;
			case GPIO_PORTB : MGPIOB->GPIO_MODER |= (u32)(Copy_u8PinMode << (2U * Copy_u8PinNumber));   break;*/
		case GPIO_PORTA:MGPIOA->GPIO_MODER=(u32)((MGPIOA->GPIO_MODER&(~(3<<(Copy_u8PinNumber*2U))))|(Copy_u8PinMode<<(Copy_u8PinNumber*2U))); break;
		case GPIO_PORTB:MGPIOB->GPIO_MODER=(u32)((MGPIOB->GPIO_MODER&(~(3<<(Copy_u8PinNumber*2U))))|(Copy_u8PinMode<<(Copy_u8PinNumber*2U))); break;


			case GPIO_PORTC : if(Copy_u8PinNumber > 12 && Copy_u8PinNumber < 16) 
							  {
								MGPIOC->GPIO_MODER |= (u32)(Copy_u8PinMode << (2U * Copy_u8PinNumber));
							  }
							  else {
								 // report an error : port c pin number is out of boundary
							  }
							  break;
			//case GPIO_PORTD : MGPIOD->GPIO_MODER |= (u32)(Copy_u8PinMode << (2U * Copy_u8PinNumber));   break;
			//case GPIO_PORTE : MGPIOE->GPIO_MODER |= (u32)(Copy_u8PinMode << (2U * Copy_u8PinNumber));   break;
			//case GPIO_PORTH : MGPIOH->GPIO_MODER |= (u32)(Copy_u8PinMode << (2U * Copy_u8PinNumber));   break;
			
			default    :  /* report an error : name fault*/ break; 
			
		}
	}
	else {
		// report an error : pin number is out of boundary
	}	
}

void MGPIO_voidSetOutputMode(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8OutMode) 
{
	/*
	User will enter Output Type: 
	GPIO_OUTPUT_TYPE_PUSH_PULL  
	GPIO_OUTPUT_TYPE_OPEN_DRAIN	
	*/
	
	if(Copy_u8PinNumber < 16) {
		switch(Copy_u8PortName) 
		{
			// every PIN configured with 1 bit
			case GPIO_PORTA : MGPIOA->GPIO_OTYPER |= (u32)(Copy_u8OutMode << (Copy_u8PinNumber));   break;
			case GPIO_PORTB : MGPIOB->GPIO_OTYPER |= (u32)(Copy_u8OutMode << (Copy_u8PinNumber));   break;
			case GPIO_PORTC : if(Copy_u8PinNumber > 12 && Copy_u8PinNumber < 16) 
						 {
							MGPIOC->GPIO_OTYPER |= (u32)(Copy_u8OutMode << (Copy_u8PinNumber));
						 }
						 else {
							 // report an error : port c pin number is out of boundary
						 }
						 break;
			default    : break; 			
		}
	}
	else {
		// report an error
	}	
}

void MGPIO_voidSetOutputSpeed(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8OutSpeed) 
{
	/*
	User will enter Output Speed: 
	GPIO_OUTPUT_SPEED_LOW       
	GPIO_OUTPUT_SPEED_MEDIUM    
	GPIO_OUTPUT_SPEED_HIGH      
	GPIO_OUTPUT_SPEED_VERY_HIGH 
	*/
	
	if( Copy_u8PinNumber < 16) {
		switch(Copy_u8PortName) 
		{
			// every PIN configured with 2 bits 
			case GPIO_PORTA : MGPIOA->GPIO_OSPEEDR |= (u32)(Copy_u8OutSpeed << (2U * Copy_u8PinNumber));   break;
			case GPIO_PORTB : MGPIOB->GPIO_OSPEEDR |= (u32)(Copy_u8OutSpeed << (2U * Copy_u8PinNumber));   break;
			case GPIO_PORTC : if(Copy_u8PinNumber > 12 && Copy_u8PinNumber < 16) 
							  {
									MGPIOC->GPIO_OSPEEDR |= (u32)(Copy_u8OutSpeed << (2U * Copy_u8PinNumber));
							  }
							  else {
								 // report an error : port c pin number is out of boundary
							  }
						 break;
			default    : break; 
			
		}
	}
	else {
		// report an error
	}	
}

void MGPIO_voidSetPullState(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PullState) 
{
	/*
	User will enter Pull State: 
	GPIO_PULL_FLOATING
	GPIO_PULL_UP      
	GPIO_PULL_DOWN    
	*/
	
	if( Copy_u8PinNumber < 16) {
		switch(Copy_u8PortName) 
		{
			// every PIN configured with 2 bits 
			case GPIO_PORTA : MGPIOA->GPIO_PUPDR |= (u32)(Copy_u8PullState << (2U * Copy_u8PinNumber));   break;
			case GPIO_PORTB : MGPIOB->GPIO_PUPDR |= (u32)(Copy_u8PullState << (2U * Copy_u8PinNumber));   break;
			case GPIO_PORTC : if(Copy_u8PinNumber > 12 && Copy_u8PinNumber < 16) 
						 {
							MGPIOC->GPIO_PUPDR |= (u32)(Copy_u8PullState << (2U * Copy_u8PinNumber));
						 }
						 else {
							 // report an error : port c pin number is out of boundary
						 }
						 break;
			default    : break; 
			
		}
	}
	else {
		// report an error
	}	
}

u8 MGPIO_voidGetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber) 
{
	u8 L_u8PinValue;
	
	if(Copy_u8PinNumber < 16) {
		switch(Copy_u8PortName) 
		{
			// every PIN configured with 2 bits 
			case GPIO_PORTA : L_u8PinValue = GET_BIT(MGPIOA->GPIO_IDR, Copy_u8PinNumber);   break;
			case GPIO_PORTB : L_u8PinValue = GET_BIT(MGPIOB->GPIO_IDR, Copy_u8PinNumber);   break;
			case GPIO_PORTC : if(Copy_u8PinNumber > 12 && Copy_u8PinNumber < 16) 
						 {
							L_u8PinValue = GET_BIT(MGPIOC->GPIO_IDR, Copy_u8PinNumber);
						 }
						 else {
							 // report an error : port c pin number is out of boundary
						 }
						 break;
			default    : break; 
			
		}
	}
	else {
		// report an error
	}	
	
	return L_u8PinValue;
}

void MGPIO_voidSetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinValue) 
{
	/*
	User will enter Pin Value: 
	GPIO_HIGH 
	GPIO_LOW  
	*/
	
	if( Copy_u8PinNumber < 16)
	{
		if(Copy_u8PinValue == GPIO_HIGH) 
		{
			switch(Copy_u8PortName) 
			{
				// every PIN configured with 2 bits 
				case GPIO_PORTA : SET_BIT(MGPIOA->GPIO_ODR, Copy_u8PinNumber);  break;
				case GPIO_PORTB : SET_BIT(MGPIOB->GPIO_ODR, Copy_u8PinNumber);  break;
				case GPIO_PORTC : if(Copy_u8PinNumber > 12 && Copy_u8PinNumber < 16) 
							      {
									SET_BIT(MGPIOC->GPIO_ODR, Copy_u8PinNumber);
							      }
							    else {
								 // report an error : port c pin number is out of boundary
							    }
							 break;
				default    : break; 		
			}
		}
		else if(Copy_u8PinValue == GPIO_LOW) 
		{
			switch(Copy_u8PortName) 
			{
				// every PIN configured with 2 bits 
				case GPIO_PORTA : CLR_BIT(MGPIOA->GPIO_ODR, Copy_u8PinNumber);  break;
				case GPIO_PORTB : CLR_BIT(MGPIOB->GPIO_ODR, Copy_u8PinNumber);  break;
				case GPIO_PORTC : if(Copy_u8PinNumber > 12 && Copy_u8PinNumber < 16) 
							 {
								CLR_BIT(MGPIOC->GPIO_ODR, Copy_u8PinNumber);
							 }
							 else {
								 // report an error : port c pin number is out of boundary
							 }
						     break;
				default    : break; 		
			}
		}
		else {
			// report an error
		}
		
	}
	else {
		// report an error
	}	
}

void MGPIO_voidDirectSetReset(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8SetResetState) 
{
	/*
	User will enter Pin Value: 
	GPIO_HIGH 
	GPIO_LOW  
	*/
	
	// writing one to first 16 will set the pin, writing one to the last 16 will reset it
	// so if we wrote 0 , this will not affect the result, that's why casting (u32) will not affect other pins
	if( Copy_u8PinNumber < 16) {
		if(Copy_u8SetResetState == GPIO_HIGH)
		{
			switch(Copy_u8PortName) 
			{
				// write 1 to set the pin
				case GPIO_PORTA : MGPIOA->GPIO_BSRR = (u32)(1U << Copy_u8PinNumber);   break;
				case GPIO_PORTB : MGPIOB->GPIO_BSRR = (u32)(1U << Copy_u8PinNumber);   break;
				case GPIO_PORTC : if(Copy_u8PinNumber > 12 && Copy_u8PinNumber < 16) 
								  {
									MGPIOC->GPIO_BSRR = (u32)(1U << Copy_u8PinNumber);
								  }
								  else {
									 // report an error : port c pin number is out of boundary
								  }
							 break;
				default    : break; 
				
			}
		}
		else if(Copy_u8SetResetState == GPIO_LOW)
		{
			Copy_u8PinNumber+= 16; // to access higher 16 bits in the register
			switch(Copy_u8PortName) 
			{
				// write 1 to reset the pin 
				case GPIO_PORTA : MGPIOA->GPIO_BSRR = (u32)(1U << Copy_u8PinNumber);   break;
				case GPIO_PORTB : MGPIOB->GPIO_BSRR = (u32)(1U << Copy_u8PinNumber);   break;
				case GPIO_PORTC : if(Copy_u8PinNumber > 12 && Copy_u8PinNumber < 16) 
								  {
									MGPIOC->GPIO_BSRR = (u32)(1U << Copy_u8PinNumber);
								  }
								  else {
								 	 // report an error : port c pin number is out of boundary
								  }
						     break;
				default    : break; 			
			}
		}		
	}
	else {
		// report an error
	}	
}

void MGPIO_voidSetPortMode(u8 Copy_u8PortName, u8 Copy_u8PortMode)
{
	// to do
}

void MGPIO_voidSetPortValue(u8 Copy_u8PortName, u16 Copy_u16PortValue) 
{
	switch(Copy_u8PortName) 
	{
		case GPIO_PORTA : MGPIOA->GPIO_ODR = Copy_u16PortValue; break;
		case GPIO_PORTB : MGPIOB->GPIO_ODR = Copy_u16PortValue; break;
		case GPIO_PORTC : MGPIOC->GPIO_ODR = Copy_u16PortValue; break;
		default         : break;
	}
}

void MGPIO_voidPinLock(u8 Copy_u8PortName, u8 Copy_u8PinNumber)
{
	// to do
}

void MGPIO_voidSetPinAltFun(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8AltFun)
{
	/*
	User will enter Alternative Function Value: 
	GPIO_ALTFUN0  
    GPIO_ALTFUN1  
    GPIO_ALTFUN2  
    GPIO_ALTFUN3  
    GPIO_ALTFUN4  
    GPIO_ALTFUN5  
    GPIO_ALTFUN6  
    GPIO_ALTFUN7  
    GPIO_ALTFUN8  
    GPIO_ALTFUN9  
    GPIO_ALTFUN10 
    GPIO_ALTFUN11 
    GPIO_ALTFUN12 
    GPIO_ALTFUN13 
    GPIO_ALTFUN14 
    GPIO_ALTFUN15 
	*/
	
	if(Copy_u8PinNumber <= 7U) 
	{
		switch(Copy_u8PortName) 
		{
			// every PIN is configured with 4 bits in AFRL:
			case GPIO_PORTA : MGPIOA->GPIO_AFRL |= (Copy_u8AltFun << (4U * Copy_u8PinNumber));  break;
			case GPIO_PORTB : MGPIOB->GPIO_AFRL |= (Copy_u8AltFun << (4U * Copy_u8PinNumber));  break;
			case GPIO_PORTC : if(Copy_u8PinNumber > 12 && Copy_u8PinNumber < 16) 
							  {
								MGPIOC->GPIO_AFRL |= (Copy_u8AltFun << (4U * Copy_u8PinNumber));
							  }
							  else {
								 // report an error : port c pin number is out of boundary
							  }
					     break;
			default    : break; 		 
		}
	}
	
	else if(Copy_u8PinNumber > 7U && Copy_u8PinNumber <= 15) 
	{
		switch(Copy_u8PortName) 
		{
		     Copy_u8PinNumber=Copy_u8PinNumber-8;
			// every PIN is configured with 4 bits in AFRL:
			case GPIO_PORTA : MGPIOA->GPIO_AFRH |= (Copy_u8AltFun << (4U * Copy_u8PinNumber));  break;
			case GPIO_PORTB : MGPIOB->GPIO_AFRH |= (Copy_u8AltFun << (4U * Copy_u8PinNumber));  break;
			case GPIO_PORTC : if(Copy_u8PinNumber > 12 && Copy_u8PinNumber < 16) 
							  {
								MGPIOC->GPIO_AFRH |= (Copy_u8AltFun << (4U * Copy_u8PinNumber));
							  }
							  else {
								 // report an error : port c pin number is out of boundary
							  }
					     break;
			default    : break; 
		}
	}
	
	else {
		// report an error
	}
}
