/*
 * GPIO_Interface.h
 *
 *  Created on: ??�/??�/????
 *      Author: omara
 */

#ifndef MCAL_GPIO_GPIO_INTERFACE_H_
#define MCAL_GPIO_GPIO_INTERFACE_H_

//*******************************************************************************************************
//*********************************1-MGPIO_voidSetPinMode************************************************



//*******************************************************************************************************
void MGPIO_voidSetPinMode(u8 Copy_8uPortName , u8 Copy_u8PinNum , u8 Copy_u8Mode); // u8 A_u8port name (argment) 

void MGPIO_voidSetPortMode    (u8 Copy_8uPortName , u32 Copy_u32Mode); // u8 A_u8port name (argment) 

void MGPIO_voidSetOutPutMode  (u8 Copy_8uPortName , u8 Copy_u8PinNum , u8 Copy_u8OutPutMode);

void MGPIO_voidSetOutPutSpeed (u8 Copy_8uPortName , u8 Copy_u8PinNum , u8 Copy_u8OutPutSpeed);

void MGPIO_voidSetPullState   (u8 Copy_8uPortName , u8 Copy_u8PinNum , u8 Copy_u8PullState);

u8   MGPIO_u8GetPinVal        (u8 Copy_8uPortName , u8 Copy_u8PinNum);

void MGPIO_voidSetPinVal      (u8 Copy_8uPortName , u8 Copy_u8PinNum , u8 Copy_u8PinVal);

void MGPIO_voidDirectSetReset (u8 Copy_8uPortName , u8 Copy_u8PinNum , u8 Copy_u8SetResetState);

void MGPIO_voidSetPortVal     (u8 Copy_8uPortName , u16 Copy_u16PortVal);

void MGPIO_voidSetPinLock     (u8 Copy_8uPortName , u8 Copy_u8PinNum);

void MGPIO_voidSetAltFun      (u8 Copy_8uPortName , u8 Copy_PinNum , u8 Copy_u8AltFun);

//************************************************************
//port macros
#define MGPIOA_PORT 0U
#define MGPIOB_PORT 1U
#define MGPIOC_PORT 2U
#define MGPIOD_PORT 3U
#define MGPIOE_PORT 4U
#define MGPIOH_PORT 5U
//***********************************************************
//PIN MACROS
#define MGPIO_PIN0  0
#define MGPIO_PIN1  1
#define MGPIO_PIN2  2
#define MGPIO_PIN3  3
#define MGPIO_PIN4  4 
#define MGPIO_PIN5  5
#define MGPIO_PIN6  6
#define MGPIO_PIN7  7
#define MGPIO_PIN8  8
#define MGPIO_PIN9  9
#define MGPIO_PIN10 10
#define MGPIO_PIN11 11
#define MGPIO_PIN12 12
#define MGPIO_PIN13 13
#define MGPIO_PIN14 14
#define MGPIO_PIN15 15 
//************************************************************
//MODE MACROS
#define MGPIO_MODE_INPUT  0b00
#define MGPIO_MODE_OUTPUT 0b01
#define MGPIO_MODE_ALTF   0b10
#define MGPIO_MODE_ANALOG 0b11
//************************************************************
//type macros 
#define MGPIO_OUTPUT_TYPE_PUSH_PULL   0
#define MGPIO_OUTPUT_TYPE_OPEN_DRAIN  1
//************************************************************
//SPEED MACROS 
#define MGPIO_OUTPUT_SPEED_LOW       0B00
#define MGPIO_OUTPUT_SPEED_MEDIUM    0B01
#define MGPIO_OUTPUT_SPEED_HIGH      0B10
#define MGPIO_OUTPUT_SPEED_VERY_HIGH 0B11
//************************************************************
//PULL STATE MACROS
#define MGPIO_PULL_FLOATING  0B00
#define MGPIO_PULL_PULL_UP   0B01
#define MGPIO_PULL_PULL_DOWN 0B10
//************************************************************
//WRITE DATA MACROS
#define MGPIO_HIGH  1
#define MGPIO_LOW   0
//************************************************************
//ALTERNATE FUNCTION
#define MGPIO_ALTFN0  0b0000
#define MGPIO_ALTFN1  0b0001
#define MGPIO_ALTFN2  0b0010 //tmr5
#define MGPIO_ALTFN3  0b0011
#define MGPIO_ALTFN4  0b0100
#define MGPIO_ALTFN5  0b0101
#define MGPIO_ALTFN6  0b0110
#define MGPIO_ALTFN7  0b0111
#define MGPIO_ALTFN8  0b1000
#define MGPIO_ALTFN9  0b1001
#define MGPIO_ALTFN10 0b1010
#define MGPIO_ALTFN11 0b1011
#define MGPIO_ALTFN12 0b1100
#define MGPIO_ALTFN13 0b1101
#define MGPIO_ALTFN14 0b1110
#define MGPIO_ALTFN15 0b1111
//************************************************************
//base addresses for gpiox
#define GPIOA_BASE_ADDRESS   0X40020000
#define GPIOB_BASE_ADDRESS   0X40020400
#define GPIOC_BASE_ADDRESS   0X40020800
#define GPIOD_BASE_ADDRESS   0X40020C00
#define GPIOE_BASE_ADDRESS   0X40021000
#define GPIOH_BASE_ADDRESS   0X40021C00
//************************************************************

//! MOMKEN A ACSSESS EL REGISTER BE AL4KL DH 
//! BS HTA5D W2T KTEEEER 
//! 3NDY 
//GPIOA REGISTER MAP
// #define GPIO_MODER  (*((volatile u32 *)(GPIOA_BASE_ADDRESS + 0x00)))
//.
//.
//.

//************************************************************

//GPIO(X) REGISTER MAP (REGISTER DEFINITION)
typedef struct 
{
    volatile u32 MODER;    // GPIO PORT MODE                    REGISTER ADDRESS OFFCITE : 0X00
    volatile u32 OTYPER;   // GPIO PORT OUTPUT                  REGISTER ADDRESS OFFCITE : 0X04
    volatile u32 OSPEEDR;  // GPIO PORT OUTPUT SPEED            REGISTER ADDRESS OFFCITE : 0X08
    volatile u32 PUPDR;    // GPIO PORT PULL UP/DOWN            REGISTER ADDRESS OFFCITE : 0X0C
    volatile u32 IDR;      // GPIO PORT INPUT DATA              REGISTER ADDRESS OFFCITE : 0X10
    volatile u32 ODR;      // GPIO PORT OUTPUT DATA             REGISTER ADDRESS OFFCITE : 0X14 
    volatile u32 BSRR;     // GPIO PORT BIT SET/RESET           REGISTER ADDRESS OFFCITE : 0X18
    volatile u32 LCKR;     // GPIO PORT LOCK PIN                REGISTER ADDRESS OFFCITE : 0X1C
    volatile u32 AFRL;     // GPIO PORT ALTERNATE FUNCTION LOW  REGISTER ADDRESS OFFCITE : 0X20
    volatile u32 AFRH;     // GPIO PORT ALTERNATE FUNCTION HIGH REGISTER ADDRESS OFFCITE : 0X24
}GPIOx_R;

// STRUCT BASE ADDRESS FOR GPIOA
#define MGPIOA ((GPIOx_R*)GPIOA_BASE_ADDRESS)

// STRUCT BASE ADDRESS FOR GPIOB
#define MGPIOB ((GPIOx_R*)GPIOB_BASE_ADDRESS)

// STRUCT BASE ADDRESS FOR GPIOC
#define MGPIOC ((GPIOx_R*)GPIOC_BASE_ADDRESS)

//************************************************************

#endif /* MCAL_GPIO_GPIO_INTERFACE_H_ */
