/*
 * main_Interface.h
 *
 *  Created on: Nov 11, 2023
 *      Author: mayke
 */

#ifndef MAIN_INTERFACE_H_
#define MAIN_INTERFACE_H_

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/RCC/RCC_interface.h"
#include "MCAL/GPIO/GPIO_interface.h"
#include "MCAL/MSTK/MSTK_Interface.h"
#include "MCAL/SPI/SPI_interface.h"
#include "MCAL/USART/USART_interface.h"
#include "MCAL/FLASH_DRIVER/FLASH_interface.h"
#include"SERVICES/PARSING/HEX_PARSE.h"
#include "Bootloader_config.h"
#include "HAL/TFT/TFT_interface.h"
#include "main_TFT.h"

void Main_voidInit(void);



#endif /* MAIN_INTERFACE_H_ */
