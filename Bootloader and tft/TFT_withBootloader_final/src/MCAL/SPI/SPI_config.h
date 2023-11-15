/*
 * SPI_config.h
 *
 *  Created on: Sep 20, 2023
 *      Author: Basel Ibrahim
 */

#ifndef MCAL_SPI_SPI_CONFIG_H_
#define MCAL_SPI_SPI_CONFIG_H_


#define MSP1_STATUS          MSPI_ENABLE

#define MSPI1_CLOCK_MODE     MSPI_MODE3

#define MSPI1_MASTER_SLAVE   MSPI_MASTER

#define MSPI1_PRESCALLER     MSPI_FPCLK_DIVIDED_BY_4

#define MSPI1_DATA_ORDER     MSPI_MSB_FIRST

#define MSPI1_SS_MANAGE      SW_SLAVE_MANAGEMENT

#define MSPI1_DATA_SIZE      MSPI_8BIT_DATA

#define MSPI1_INT_STATUS     MSPI_INT_DISABLE



#endif /* MCAL_SPI_SPI_CONFIG_H_ */
