/*
 * SPI_Program.c
 *
 *  Created on: ??�/??�/????
 *      Author: omara
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/bit_macros.h"

// MCAL COMPONENTS
#include "SPI_Private.h"
#include "SPI_Interface.h"
#include "SPI_Config.h"


void MSPI_VoidInit(void)
{
    //CLOP & CLPH
    SET_BIT(SPI1->SPI_CR1,SPI_CPOL);
    SET_BIT(SPI1->SPI_CR1,SPI_CPHA);

    //MASTER SELCTE ==1  SLAVE ==0
    SET_BIT(SPI1->SPI_CR1,SPI_MSTR);

    //BUDE RATE //MUST CAN NOT BE 15 OR MORE 
    //!SET_BIT(SPI1->CR1,SPI_CPOL);
    //!SPI1->CR1=(SPI1->CR1 &~ 0X111<3) | BUDE_RATE //!COMPLETE BET MASKING
       SPI1->SPI_CR1=((SPI1->SPI_CR1 &~(0b111<<3))|BAUD_RATE<<3);
    //MSB MOST SIG BYTE
    CLR_BIT(SPI1->SPI_CR1,SPI_LSBFIRST);

    //EXTERN AND INTERN SS
    SET_BIT(SPI1->SPI_CR1,SPI_SSM);
    SET_BIT(SPI1->SPI_CR1,SPI_SSI);

    //RECEVE ONLY

    //DATA FORMATA 8 BIT DATA 
    CLR_BIT(SPI1->SPI_CR1,SPI_DFF);

    //SPI ENABLE 
    SET_BIT(SPI1->SPI_CR1,SPI_SPE);
}


u8 MSPI_Transevice(u8 Copy_u8Data)
{
    SPI1->SPI_DR=Copy_u8Data;
    while(GET_BIT(SPI1->SPI_SR,SPI_BSY)==1); //BSY
    return (u8) SPI1->SPI_DR;
}
