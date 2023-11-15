/*
 * SPI_Private.h
 *
 *  Created on: ??�/??�/????
 *      Author: omara
 */

#ifndef MCAL_SPI_SPI_PRIVATE_H_
#define MCAL_SPI_SPI_PRIVATE_H_


typedef struct 
{
    volatile u32 SPI_CR1;
    volatile u32 SPI_CR2;
    volatile u32 SPI_SR;
    volatile u32 SPI_DR;
    volatile u32 SPI_CRCPR;
    volatile u32 SPI_RXCRCR;
    volatile u32 SPI_TXCRCR;
    volatile u32 SPI_I2SCFGR;
    volatile u32 SPI_I2SPR;

}SPI_t;

#define SPI1 ((volatile SPI_t *)0x40013000) //APB2 PIN 12  // NVIC POS 35
#define SPI2 ((volatile SPI_t *)0x40003800) //APB1 PIN 14  //          36
#define SPI3 ((volatile SPI_t *)0x40003C00) //APB1 PIN 15              51
#define SPI4 ((volatile SPI_t *)0x40013400) //APB2 PIN 13              84

//CR1
#define SPI_DFF      11
#define SPI_RXONLY   10
#define SPI_SSM      9
#define SPI_SSI      8
#define SPI_LSBFIRST 7
#define SPI_SPE      6
#define SPI_BR2      5
#define SPI_BR1      4
#define SPI_BR0      3
#define SPI_MSTR     2
#define SPI_CPOL     1
#define SPI_CPHA     0

//SR
#define SPI_BSY 7





#endif /* MCAL_SPI_SPI_PRIVATE_H_ */
