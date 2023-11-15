/*
 * SPI_program.c
 *
 *  Created on: Sep 20, 2023
 *      Author: Basel Ibrahim
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "SPI_priavte.h"
#include "SPI_config.h"
#include "SPI_interface.h"

void MSPI_voidInit(void)
{
#if   MSP1_STATUS == MSPI_ENABLE

#if		MSPI1_CLOCK_MODE == MSPI_MODE0

	CLR_BIT( MSPI1 -> SPI_CR1 , CPHA ); CLR_BIT( MSPI1 -> SPI_CR1 , CPOL );

#elif	MSPI1_CLOCK_MODE == MSPI_MODE1

	SET_BIT( MSPI1 -> SPI_CR1 , CPHA ); CLR_BIT( MSPI1 -> SPI_CR1 , CPOL );

#elif	MSPI1_CLOCK_MODE == MSPI_MODE2

	CLR_BIT( MSPI1 -> SPI_CR1 , CPHA ); SET_BIT( MSPI1 -> SPI_CR1 , CPOL );
#elif	MSPI1_CLOCK_MODE == MSPI_MODE3

	SET_BIT( MSPI1 -> SPI_CR1 , CPHA ); SET_BIT( MSPI1 -> SPI_CR1 , CPOL );

#endif

#if    MSPI1_MASTER_SLAVE == MSPI_MASTER

	SET_BIT( MSPI1 -> SPI_CR1 , MSTR );

#elif  MSPI1_MASTER_SLAVE == MSPI_SLAVE

	CLR_BIT( MSPI1 -> SPI_CR1 , MSTR );

#endif

#if   MSPI1_DATA_ORDER == MSPI_MSB_FIRST

	CLR_BIT( MSPI1 -> SPI_CR1 , LSBFIRST );

#elif MSPI1_DATA_ORDER == MSPI_LSB_FIRST

	SET_BIT( MSPI1 -> SPI_CR1 , LSBFIRST );

#endif

#if   MSPI1_SS_MANAGE  == HW_SLAVE_MANAGEMENT

	CLR_BIT( MSPI1 -> SPI_CR1 , SSM );

#elif MSPI1_SS_MANAGE == SW_SLAVE_MANAGEMENT

	SET_BIT( MSPI1 -> SPI_CR1 , SSM );
	SET_BIT( MSPI1->  SPI_CR1 , SSI );

#endif

#if   MSPI1_DATA_SIZE == MSPI_8BIT_DATA

	CLR_BIT( MSPI1 -> SPI_CR1 , DFF );

#elif MSPI1_DATA_SIZE == MSPI_16BIT_DATA

	SET_BIT( MSPI1 -> SPI_CR1 , DFF );

#endif

#if   MSPI1_INT_STATUS == MSPI_INT_DISABLE

	MSPI1 -> SPI_CR2 = 0 ;

#elif MSPI1_INT_STATUS == MSPI_TXE_INT_ENABLE

	SET_BIT( MSPI1 -> CR2 , 7 );

#elif MSPI1_INT_STATUS == MSPI_RXNE_INT_ENABLE

	SET_BIT( MSPI1 -> CR2 , 6 );

#endif

	/* Bit Masking For MSPI1_PRESCALLER Bits */
	/*MSPI1 -> SPI_CR1 &= 0xFFC7 ;
	MSPI1 -> SPI_CR1 |= ( MSPI1_PRESCALLER << BR0 ) ;*/

	SET_BIT( MSPI1 -> SPI_CR1 , SPE );

#elif MSP1_STATUS == MSPI_DISABLE
	CLR_BIT( MSPI1 -> SPI_CR1 , 6 );
#endif

}


u8 MSPI1_voidSendDataU8(u8 Copy_u8Data)
{

	MSPI1 -> SPI_DR = Copy_u8Data;

	while ( GET_BIT( MSPI1 -> SPI_SR , SPI_BSY) == 1 );

	return (u8) MSPI1 -> SPI_DR ;

}

/*void MSPI1_VidSetCallBack(void(*ptr)(void))
{

}*/


