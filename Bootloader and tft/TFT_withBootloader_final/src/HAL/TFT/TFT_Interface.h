/*
 * TFT_Interface.h
 *
 *  Created on: Sep 20, 2023
 *      Author: mayke
 */

#ifndef TFT_TFT_INTERFACE_H_
#define TFT_TFT_INTERFACE_H_


#include "TFT_Config.h"
#include "TFT_Private.h"
#include "Fonts.h"

#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF


void HTFT_voidinit();
void HTFT_Display(u16*array,u32 Copy_u32ArraySize);

void HTFT_voidSetXPos(u16 Copy_u16XStart,u16 Copy_u16XEnd);
void HTFT_voidSetYPos(u16 Copy_u16YStart,u16 Copy_u16YEnd);
void HTFT_voidFillRectangle(u16 Copy_u16Color);
void HTFT_voidFillBackground(u16 Copy_u16Color);


void HTFT_voidDrawLine(u16 x1,u16 y1,u16 x2,u16 y2);
void HTFT_voidDrawRectangle();
void HTFT_voidDrawtriangle();
void HTFT_voidDrawCircle(u16 r,u16 c1,u16 c2);

void HTFT_DisplayData(u16 Copy_u16Color);

void HTFT_voidSendChar(u16 x, u16 y, s8 ch, FontDef font, u16 color);
void HTFT_voidSendString(u16 x, u16 y, s8*str, FontDef font, u16 color);
void HTFT_voidSleepOut(void);
#endif /* TFT_TFT_INTERFACE_H_ */
