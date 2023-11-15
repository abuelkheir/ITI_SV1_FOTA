#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "FLASH_private.h"
#include "FLASH_interface.h"



void MFDI_voidEraseSector(u8 Copy_u8SectorNum)
{
	if((Copy_u8SectorNum == 0)||(Copy_u8SectorNum > 7))
	{
		// Send Report 
	}
	else{
		/* 1- Check Busy Flag Of SR is Set  */
		while( (GET_BIT( MFDI->SR, SR_BSY)) == 1);

		/* 2- Check The Authorized Of Configuration Operation */
		if((GET_BIT( MFDI->CR, CR_LOCK)) == 1)
		{
			// Unlock Sequence
			MFDI->KEYR = OPTKEY1;
			MFDI->KEYR = OPTKEY2;
		}

		MFDI->CR &=0xFFFFFF87; /* Clear Bits Of Sector Selection */

		MFDI->CR |= (Copy_u8SectorNum<<3); /* Set The Desired Sector */

		/* 3- Sector Erase Enable */
		SET_BIT(MFDI->CR, CR_SER);

		/* 4- Set Start Bit  */
		SET_BIT(MFDI->CR, CR_STRT);

		/* 5- Check Busy Flag Of SR is Set  */
		while( ( GET_BIT( (MFDI->SR), SR_BSY ) ) == 1);

		/* 6- Clear Bit Of Ending Operation */

		SET_BIT((MFDI->SR), 0);  // Set Bit Of 0 To Clear Flag Of EOP

		/* 7- Sector Erase Disable */
		CLR_BIT(MFDI->CR, CR_SER);

	}
}


void MFDI_voidFlashWrite(u32 Copy_u32Address, u16 *A_PtrData, u8 Copy_u8DataLength)
{
	volatile u16 Temp;
	// wait if busy bit is set 
	while ( (GET_BIT(MFDI->SR ,16)) == 1);

	// check if Authorized for configurations
	if ( (GET_BIT(MFDI-> CR , CR_LOCK )) == 1)
	{
		//Lock Sequence 
		MFDI->KEYR = OPTKEY1;
		MFDI->KEYR = OPTKEY2;
	}

	MFDI->CR &= 0xFFFFFCFF ;           // Clear Write Size Bits
	MFDI->CR |= WRITE_HALF_WORD << 8 ; // Flash Driver Writes (2Byte)16 bit every once

	for (u8 L_u8Iterator =0 ; L_u8Iterator < Copy_u8DataLength ; L_u8Iterator ++ )
	{
		Temp=A_PtrData[L_u8Iterator];
		// Activate Programming Flash
		SET_BIT(MFDI->CR,CR_PG);

		*((volatile u16*)Copy_u32Address)= Temp; // Get 2Byte Of Data ,Q1: however the address bus is 32 , we assign ptr to 16 ?
		Copy_u32Address += 2;

		// wait if busy bit is set till writing operation is ended
		while ( (GET_BIT(MFDI->SR , 16)) == 1);

		// Clear the EOP flag
		SET_BIT(MFDI->SR,0);

		// deactivate Programming Flash
		CLR_BIT(MFDI->CR,CR_PG);

	}

}



void MFDI_voidEraseAppArea(void)
{
	/* Loop To Erase Each Sector Of App Except Bootloader Sector 0 */
	for(u8 Local_u8Sectors=1;Local_u8Sectors<6;Local_u8Sectors++)
	{

		MFDI_voidEraseSector(Local_u8Sectors);

	}

}
