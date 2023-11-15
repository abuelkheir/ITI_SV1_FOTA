/******************************************************************************
 *

 *
 *******************************************************************************/

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

typedef unsigned long  int u32;

/*******************************************************************************
 *                           	  GPIOx Base Addresses                         *
 *******************************************************************************/
#define GPIOA_BASE_ADDRESS    0x40020000
#define GPIOB_BASE_ADDRESS    0x40020400
#define GPIOC_BASE_ADDRESS    0x40020800
#define GPIOD_BASE_ADDRESS    0x40020C00
#define GPIOE_BASE_ADDRESS    0x40021000
#define GPIOH_BASE_ADDRESS    0x40021C00


/*******************************************************************************
 *                           	   GPIOx Register Map                           *
 *******************************************************************************/
// First Method: #define every register in every port separetly:
// #define GPIOA_MODER   (*((volatile u32*)GPIOA_BASE_ADDRESS + 0b00)) 

// Second Method : using struct: this will be much easier in large scales
typedef struct{

	volatile u32 GPIO_MODER;   // Address Offset  : 0x00  , GPIO Port Mode Register
	volatile u32 GPIO_OTYPER;  // Address Offset  : 0x04  , GPIO Port Output Type Register
	volatile u32 GPIO_OSPEEDR; // Address Offset  : 0x08  , GPIO Port Output Speed Register
	volatile u32 GPIO_PUPDR;   // Address Offset  : 0x0C  , GPIO Port Pull Up / Pull Down Register
	volatile u32 GPIO_IDR;     // Address Offset  : 0x10  , GPIO Port Input Data Register
	volatile u32 GPIO_ODR;	  // Address Offset  : 0x14  , GPIO Port Output Data Register
	volatile u32 GPIO_BSRR;    // Address Offset  : 0x18  , GPIO Port Set / Reset Register
	volatile u32 GPIO_LCKR;    // Address Offset  : 0x1C  , GPIO Port Lock Pin Register
	volatile u32 GPIO_AFRL;    // Address Offset  : 0x20  , GPIO Port Alternative Function Low Register
	volatile u32 GPIO_AFRH;    // Address Offset  : 0x24  , GPIO Port Alternative Function High Register

}GPIO;
// we don't need to make object, we will use pointer to struct to loop on them only 

#define MGPIOA ((volatile GPIO*)GPIOA_BASE_ADDRESS)  // pointer to first element in GPIO struct starting from this address
#define MGPIOB ((volatile GPIO*)GPIOB_BASE_ADDRESS)
#define MGPIOC ((volatile GPIO*)GPIOC_BASE_ADDRESS)
// to access struct : MGPIOA->CRL = value   or *(MGPIOA.CRL) = value

#endif /* GPIO_PRIVATE_H_ */
