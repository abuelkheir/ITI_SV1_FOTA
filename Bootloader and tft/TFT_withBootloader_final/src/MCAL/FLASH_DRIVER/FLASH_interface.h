/*************************************************************************/
/****** Author: Ahmed Atef                                    ************/
/****** Driver: FLASH(MCAL)                                   ************/
/****** Date: 27 / 9 / 2023                                   ************/
/****** Version: 1.0 V                                        ************/
/*************************************************************************/


/*************************************************************************/
  /* ------------- Guard Of File Will Call One Time in .c ------------ */
/*************************************************************************/

#ifndef FLASH_INTERFACE_H_
#define FLASH_INTERFACE_H_

#define FLASH_START_ADDRESS   0x08000000
#define FLASH_APP_ADDRESS     0x08004000

#define WRITE_HALF_WORD   1

void MFDI_voidEraseSector(u8 Copy_u8SectorNum);

void MFDI_voidFlashWrite(u32 Copy_u32Address, u16 *A_PtrData, u8 Copy_u8DataLength);

void MFDI_voidEraseAppArea(void);



#endif
