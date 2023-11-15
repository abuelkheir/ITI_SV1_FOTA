/*************************************************************************/
/****** Author: Ahmed Atef                                    ************/
/****** Driver: FLASH(MCAL)                                   ************/
/****** Date: 27 / 9 / 2023                                   ************/
/****** Version: 1.0 V                                        ************/
/*************************************************************************/


/*************************************************************************/
  /* ------------- Guard Of File Will Call One Time in .c ------------ */
/*************************************************************************/

#ifndef FLASH_PRIVATE_H_
#define FLASH_PRIVATE_H_

#define MFDI_BASE_ADDRESS    0x40023C00

typedef struct
{
	volatile u32 ACR;
	volatile u32 KEYR;
	volatile u32 OPTKEYR;
	volatile u32 SR;
	volatile u32 CR;
	volatile u32 OPTCR;
	
}MFDI_t;

#define CR_LOCK            31       
#define CR_ERRIE           25
#define CR_EOPIE           24
#define CR_STRT            16
#define CR_PSIZE           8
#define CR_SNB             3 
#define CR_MER             2
#define CR_SER             1
#define CR_PG              0


#define SR_BSY             16


#define OPTKEY1  0x45670123
#define OPTKEY2  0xCDEF89AB



#define MFDI      ((MFDI_t*)MFDI_BASE_ADDRESS)

#endif
