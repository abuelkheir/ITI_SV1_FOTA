/*
 * RCC_Private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: omara
 */

#ifndef MCAL_RCC_RCC_PRIVATE_H_
#define MCAL_RCC_RCC_PRIVATE_H_

//#DEFINE BASE ADRESS
//#define ((volatile RCC*)0x40023800)

typedef struct
{
    volatile u32 RCC_CR;
    volatile u32 RCC_PLLCFGR;
    volatile u32 RCC_CFGR;
    volatile u32 RCC_CIR;
    volatile u32 RCC_AHB1RSTR;
    volatile u32 RCC_AHB2RSTR;
    //RESERVE REGISTERS
    volatile u32 RESERV1;
    volatile u32 RESERV2;
    volatile u32 RCC_APB1RSTR;
    volatile u32 RCC_APB2RSTR;
    //RESERVE REGISTERS
    volatile u32 RESERV3;
    volatile u32 RESERV4;
    volatile u32 RCC_AHB1ENR;
    volatile u32 RCC_AHB2ENR;
    //RESERVE REGISTERS
    volatile u32 RESERV5;
    volatile u32 RESERV6;
    volatile u32 RCC_APB1ENR;
    volatile u32 RCC_APB2ENR;
    //RESERVE REGISTERS
    volatile u32 RESERV7;
    volatile u32 RESERV8;
    volatile u32 RCC_AHB1LPENR;
    volatile u32 RCC_AHB2LPENR;
    //RESERVE REGISTERS
    volatile u32 RESERV9;
    volatile u32 RESERV10;
    volatile u32 RCC_APB1LPENR;
    volatile u32 RCC_APB2LPENR;
    //RESERVE REGISTERS
    volatile u32 RESERV11;
    volatile u32 RESERV12;
    volatile u32 RCC_BDCR;
    volatile u32 RCC_CSR;
    //RESERVE REGISTERS
    volatile u32 RESERV13;
    volatile u32 RESERV14;
    volatile u32 RCC_SSCGR;
    volatile u32 RCC_PLLI2SCFGR;
    //RESERVE REGISTERS
    volatile u32 RESERV15;
    volatile u32 RCC_DCKCFGR;
}RCC;//20 REG

#define MRCC ((volatile RCC *)0x40023800)

//CR
         //RESERVED        //
#define CR_PLL_I2SRDY      27
#define CR_PLL_I2SON       26
#define CR_PLL_RDY         25
#define CR_PLL_ON          24
//#define Reserved         //
#define CR_CSSON           19
#define CR_HSEBYP          18
#define CR_HSERDY          17
#define CR_HSEON           16
#define CR_HSICAL_7        15
#define CR_HSICAL_6        14
#define CR_HSICAL_5        13
#define CR_HSICAL_4        12
#define CR_HSICAL_3        11
#define CR_HSICAL_2        10
#define CR_HSICAL_1        9
#define CR_HSICAL_0        8
#define CR_HSITRIM_4       7
#define CR_HSITRIM_3       6
#define CR_HSITRIM_2       5
#define CR_HSITRIM_1       4
#define CR_HSITRIM_0       3
#define CR_Reserved        2
#define CR_HSIRDY          1
#define CR_HSION           0
//-------------------------------------
//CFGR
#define CFGR_MCO2_1      31
#define CFGR_MCO2_0      30
#define CFGR_MCO2PRE2    29
#define CFGR_MCO2PRE1    28
#define CFGR_MCO2PRE0    27
#define CFGR_MCO1PRE2    26
#define CFGR_MCO1PRE1    25
#define CFGR_MCO1PRE0    24
#define CFGR_I2SSRC      23
#define CFGR_MCO1_1      22
#define CFGR_MCO1_0      21
#define CFGR_RTCPRE_4    20
#define CFGR_RTCPRE_3    19
#define CFGR_RTCPRE_2    18
#define CFGR_RTCPRE_1    17
#define CFGR_RTCPRE_0    16
#define CFGR_PPRE2_2     15
#define CFGR_PPRE2_1     14
#define CFGR_PPRE2_0     13
#define CFGR_PPRE1_2     12
#define CFGR_PPRE1_1     11
#define CFGR_PPRE1_0     10
//#define CFGR_Reserved  //
#define CFGR_HPRE_3      7
#define CFGR_HPRE_2      6
#define CFGR_HPRE_1      5
#define CFGR_HPRE_0      4
#define CFGR_SWS_1       3
#define CFGR_SWS_0       2
#define CFGR_SW_1        1
#define CFGR_SW_0        0
//-----------------------------
#define AHB1   1
#define AHB2   2
#define APB1   3
#define APB2   4
#define AHB1LP 5
//---------------
#define HSI     1
#define HSE     2
#define PLL     3
#endif /* MCAL_RCC_RCC_PRIVATE_H_ */
