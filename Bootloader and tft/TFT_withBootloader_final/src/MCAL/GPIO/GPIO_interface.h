/******************************************************************************
 *

 *
 *******************************************************************************/
 
#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

/*******************************************************************************
 *                           	 Port Macros                                   *
 *******************************************************************************/
 
#define GPIO_PORTA    0U
#define GPIO_PORTB    1U
#define GPIO_PORTC    2U  // we have only till PORTC
#define GPIO_PORTD    3U
#define GPIO_PORTE    4U
#define GPIO_PORTH    7U

/*******************************************************************************
 *                           	  Pin Macros                                   *
 *******************************************************************************/
#define GPIO_PIN0   	0  
#define GPIO_PIN1   	1  
#define GPIO_PIN2   	2  
#define GPIO_PIN3   	3  
#define GPIO_PIN4   	4  
#define GPIO_PIN5   	5  
#define GPIO_PIN6   	6  
#define GPIO_PIN7   	7  
#define GPIO_PIN8   	8  
#define GPIO_PIN9   	9  
#define GPIO_PIN10   	10  
#define GPIO_PIN11   	11  
#define GPIO_PIN12   	12  
#define GPIO_PIN13   	13  
#define GPIO_PIN14   	14  
#define GPIO_PIN15   	15  
  
/*******************************************************************************
 *                          	 Mode Macros                                   *
 *******************************************************************************/
// page 158 MODER BITS:

#define  GPIO_INPUT_MODE      (0b00)
#define  GPIO_OUTPUT_MODE	  (0b01)
#define  GPIO_ALTF_MODE       (0b10)
#define  GPIO_ANALOG MODE	  (0b11)

/*******************************************************************************
 *                          	Output Type Macros                             *
 *******************************************************************************/
// page 158 OT BITS:
#define GPIO_OUTPUT_TYPE_PUSH_PULL     (0U) 
#define GPIO_OUTPUT_TYPE_OPEN_DRAIN	   (1U)

/*******************************************************************************
 *                          	Output Speed Macros                            *
 *******************************************************************************/
// page 159 OSPEEDR BITS:
#define GPIO_OUTPUT_SPEED_LOW        (0b00) 
#define GPIO_OUTPUT_SPEED_MEDIUM     (0b01) 
#define GPIO_OUTPUT_SPEED_HIGH       (0b10) 
#define GPIO_OUTPUT_SPEED_VERY_HIGH  (0b11) 

/*******************************************************************************
 *                          	Pull State Macros                              *
 *******************************************************************************/
// page 160 PUPDR BITS:
#define GPIO_PULL_FLOATING     (0b00) 
#define GPIO_PULL_UP           (0b01) 
#define GPIO_PULL_DOWN         (0b10) 

/*******************************************************************************
 *                          	Write Data Macros                              *
 *******************************************************************************/
#define GPIO_HIGH    (1U) 
#define GPIO_LOW     (0U) 

/*******************************************************************************
 *                          	Alternative Functions Macros                   *
 *******************************************************************************/
 // page 162 AFRL BITS:
#define GPIO_ALTFUN0       (0b0000)
#define GPIO_ALTFUN1       (0b0001)
#define GPIO_ALTFUN2       (0b0010)
#define GPIO_ALTFUN3       (0b0011)
#define GPIO_ALTFUN4       (0b0100)
#define GPIO_ALTFUN5       (0b0101)
#define GPIO_ALTFUN6       (0b0110)
#define GPIO_ALTFUN7       (0b0111)
#define GPIO_ALTFUN8       (0b1000)
#define GPIO_ALTFUN9       (0b1001)
#define GPIO_ALTFUN10      (0b1010)
#define GPIO_ALTFUN11      (0b1011)
#define GPIO_ALTFUN12      (0b1100)
#define GPIO_ALTFUN13      (0b1101)
#define GPIO_ALTFUN14      (0b1110)
#define GPIO_ALTFUN15      (0b1111)

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
//SetPinMode
//SetOutputType
//SetOutputSpeedMode
//SetPullState -> l2en mmkn tkoon output aw input
//SetPinValue (ODR)
//DirectSetReset (BSRR)
//GetPinValue
//SetPinLCK -> pin lock
//SetPortMode (assignment)
//GetPortValue
//SetPinALF -> pin alternate function

void MGPIO_voidSetPinMode(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinMode);
/*
 * FUNCTION NAME:		  MGPIO_voidSetPinMode
 * FUNCTION RETURN:		  nothing
 * FUNCTION ARGUMENTS:	  unsigned char (Port Name) , unsigned char (Pin Number) , unsigned char (Pin Mode)
 * FUNCTION DESCRIPTION:  Set Pin Mode for GPIO Pins
 */
 
void MGPIO_voidSetOutputMode(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8OutMode);
/*
 * FUNCTION NAME:		  MGPIO_voidSetOutputMode
 * FUNCTION RETURN:		  nothing
 * FUNCTION ARGUMENTS:	  unsigned char (Port Name) , unsigned char (Pin Number) , unsigned char (Output Mode)
 * FUNCTION DESCRIPTION:  Set Output Mode for GPIO Pins
 */
 
void MGPIO_voidSetOutputSpeed(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8OutSpeed);
/*
 * FUNCTION NAME:		  MGPIO_voidSetOutputSpeed
 * FUNCTION RETURN:		  nothing
 * FUNCTION ARGUMENTS:	  unsigned char (Port Name) , unsigned char (Pin Number) , unsigned char (Output Speed)
 * FUNCTION DESCRIPTION:  Set Output Speed for GPIO Pins
 */

void MGPIO_voidSetPullState(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PullState);
/*
 * FUNCTION NAME:		  MGPIO_voidSetPullState
 * FUNCTION RETURN:		  nothing
 * FUNCTION ARGUMENTS:	  unsigned char (Port Name) , unsigned char (Pin Number) , unsigned char (Pull State)
 * FUNCTION DESCRIPTION:  Set Pull State for GPIO Pins
 */

u8 MGPIO_voidGetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber);
/*
 * FUNCTION NAME:		  MGPIO_voidGetPinValue
 * FUNCTION RETURN:		  unsigned char (Pin Value)
 * FUNCTION ARGUMENTS:	  unsigned char (Port Name) , unsigned char (Pin Number)
 * FUNCTION DESCRIPTION:  Get Pin Value for GPIO Pins
 */
 
void MGPIO_voidSetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinValue);
/*
 * FUNCTION NAME:		  MGPIO_voidSetPinValue
 * FUNCTION RETURN:		  nothing
 * FUNCTION ARGUMENTS:	  unsigned char (Port Name) , unsigned char (Pin Number) , unsigned char (Pin Value)
 * FUNCTION DESCRIPTION:  Set Pin Value for GPIO Pins
 */
 
void MGPIO_voidDirectSetReset(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8SetResetState);
/*
 * FUNCTION NAME:		  MGPIO_voidDirectSetReset
 * FUNCTION RETURN:		  nothing
 * FUNCTION ARGUMENTS:	  unsigned char (Port Name) , unsigned char (Pin Number) , unsigned char (Set/Reset State)
 * FUNCTION DESCRIPTION:  Set Pin Value for GPIO Pins using BSRR
 */
 
void MGPIO_voidSetPortMode(u8 Copy_u8PortName, u8 Copy_u8PortMode);
/*
 * FUNCTION NAME:		  MGPIO_voidSetPortMode
 * FUNCTION RETURN:		  nothing
 * FUNCTION ARGUMENTS:	  unsigned char (Port Name) , unsigned char (Port Mode)
 * FUNCTION DESCRIPTION:  Set Port Mode for GPIO Pins
 */ 
 
void MGPIO_voidSetPortValue(u8 Copy_u8PortName, u16 Copy_u16PortValue) ;
/*
 * FUNCTION NAME:		  MGPIO_voidSetPortValue
 * FUNCTION RETURN:		  nothing
 * FUNCTION ARGUMENTS:	  unsigned char (Port Name) , unsigned short (Port Value)
 * FUNCTION DESCRIPTION:  Set Port Value for GPIO Pins
 */
 
void MGPIO_voidPinLock(u8 Copy_u8PortName, u8 Copy_u8PinNumber);
/*
 * FUNCTION NAME:		  MGPIO_voidPinLock
 * FUNCTION RETURN:		  nothing
 * FUNCTION ARGUMENTS:	  unsigned char (Port Name) , unsigned char (Pin Number)
 * FUNCTION DESCRIPTION:  Set Pin Lock for GPIO Pins
 */

void MGPIO_voidSetPinAltFun(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8AltFun);
/*
 * FUNCTION NAME:		  MGPIO_voidSetPinAltFun
 * FUNCTION RETURN:		  nothing
 * FUNCTION ARGUMENTS:	  unsigned char (Port Name) , unsigned char (Pin Number) , unsigned char (Alternative Function)
 * FUNCTION DESCRIPTION:  Set Pin Value for GPIO Pins
 */
#endif /* GPIO_INTERFACE_H_ */
