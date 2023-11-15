/*
 * SPI_priavte.h
 *
 *  Created on: Sep 20, 2023
 *      Author: Basel Ibrahim
 */

#ifndef MCAL_SPI_SPI_PRIAVTE_H_
#define MCAL_SPI_SPI_PRIAVTE_H_


typedef struct {

	volatile u32 SPI_CR1     ;
	volatile u32 SPI_CR2     ;
	volatile u32 SPI_SR      ;
	volatile u32 SPI_DR      ;
	volatile u32 SPI_CRCPR   ;
	volatile u32 SPI_RXCRCR  ;
	volatile u32 SPI_TXCRCR  ;
	volatile u32 SPI_I2SCFGR ;
	volatile u32 SPI_I2SPR   ;

}SPI;

#define MSPI1 ( ( volatile SPI* ) 0x40013000 )


#define HW_SLAVE_MANAGEMENT          0
#define SW_SLAVE_MANAGEMENT          1

#define MSPI_8BIT_DATA               0
#define MSPI_16BIT_DATA              1

#define MSPI_INT_DISABLE             0
#define MSPI_TXE_INT_ENABLE          1
#define MSPI_RXNE_INT_ENABLE         2


#define MSPI_DISABLE                 0
#define MSPI_ENABLE                  1

#define MSPI_MODE0                   0
#define MSPI_MODE1                   1
#define MSPI_MODE2                   2
#define MSPI_MODE3                   3

#define MSPI_MASTER                  0
#define MSPI_SLAVE                   1

#define MSPI_FPCLK_DIVIDED_BY_2      0b000
#define MSPI_FPCLK_DIVIDED_BY_4      0b001
#define MSPI_FPCLK_DIVIDED_BY_8      0b010
#define MSPI_FPCLK_DIVIDED_BY_16     0b011
#define MSPI_FPCLK_DIVIDED_BY_32     0b100
#define MSPI_FPCLK_DIVIDED_BY_64     0b101
#define MSPI_FPCLK_DIVIDED_BY_128    0b110
#define MSPI_FPCLK_DIVIDED_BY_256    0b111

#define MSPI_MSB_FIRST               0
#define MSPI_LSB_FIRST 				 1

#define HW_SLAVE_MANAGEMENT          0
#define SW_SLAVE_MANAGEMENT          1

#define MSPI_8BIT_DATA               0
#define MSPI_16BIT_DATA              1

#define MSPI_INT_DISABLE             0
#define MSPI_TXE_INT_ENABLE          1
#define MSPI_RXNE_INT_ENABLE         2


//CR1
#define DFF      11
#define RXONLY   10
#define SSM      9
#define SSI      8
#define LSBFIRST 7
#define SPE      6
#define BR2      5
#define BR1      4
#define BR0      3
#define MSTR     2
#define CPOL     1
#define CPHA     0

//SR
#define SPI_BSY 7

#endif /* MCAL_SPI_SPI_PRIAVTE_H_ */
