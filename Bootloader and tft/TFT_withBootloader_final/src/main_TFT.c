/*
 * main_TFT.c
 *
 *  Created on: Nov 11, 2023
 *      Author: mayke
 */

#include "LIB/STD_TYPES.h"
#include "main_TFT.h"
#include "HAL/TFT/TFT_interface.h"

void writeBootLoaderModeInTFT(void)
{
	HTFT_voidSendString(120,155,"BOOTLOADER",Font_11x18,WHITE);
	HTFT_voidSendString(90,135,"MODE",Font_11x18,WHITE);


}

void writeFLASHINGModeInTFT(void)
{


	HTFT_voidSendString(110,100,"FLASHING",Font_11x18,WHITE);
	HTFT_voidSendString(90,80,"MODE",Font_11x18,WHITE);


}

void writeFLASHING_DONE(void)
{

	HTFT_voidSendString(110,100,"FLASHING",Font_11x18,WHITE);
	HTFT_voidSendString(90,80,"DONE",Font_11x18,WHITE);
	/*  switching  */



}

void Switch_To_Main_APP(void)
{

	HTFT_voidSendString(115,45,"SWITCHING",Font_11x18,WHITE);
	HTFT_voidSendString(125,25,"TO MAIN APP",Font_11x18,WHITE);
}


void Switch_To_Backup_APP(void)
{
	HTFT_voidSendString(115,45,"SWITCHING",Font_11x18,WHITE);
	HTFT_voidSendString(115,25,"TO BACKUP",Font_11x18,WHITE);

}


void ErrorInHex(void)
{
	HTFT_voidSetXPos(20,110);
	HTFT_voidSetYPos(80,111);
	HTFT_voidFillRectangle(BLACK);

	HTFT_voidSendString(110,100,"ERROR IN",Font_11x18,WHITE);
	HTFT_voidSendString(100,80,"HEXFILE",Font_11x18,WHITE);
}


