/*
 * SPI_interface.h
 *
 *  Created on: Sep 20, 2023
 *      Author: Basel Ibrahim
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_






void MSPI_voidInit(void) ;

u8 MSPI1_voidSendDataU8(u8 Copy_u8Data) ;

void MSPI1_VidSetCallBack(void(*ptr)(void)) ;




#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
