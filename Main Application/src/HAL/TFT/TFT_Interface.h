/*
 * TFT_Interface.h
 *
 *  Created on: ??�/??�/????
 *      Author: omara
 */

#ifndef HAL_TFT_TFT_INTERFACE_H_
#define HAL_TFT_TFT_INTERFACE_H_

//me
void TFT_WriteCommand(u8 cmd);
void TFT_WriteData(u8 Copy_u8Data);
void TFT_Reset();
void TFT_VoidInit();
void TFT_VoidDisplay(u16 *img);
//instractor
void TFT_VoidSetXpos(u16 xstart , u16 xend);
void TFT_VoidSetYpos(u16 ystart , u16 yend);
void TFT_VoidFillRectangle(u8 xstart,u8 xend,u8 ystart,u8 yend,u16 color);
void TFT_VoidFillBackGround(u16 color);
//me
void TFT_VoidDrowLine(u8 xstart,u8 xend ,u8 ystart , u8 yend,u16 color);

//OTHER
void TFT_VidDrawVLine ( u8 Xaxis , u8 Yaxis , u8 Copy_u8Length , u16 Copy_u8Color );
void TFT_VidDrawHLine ( u8 Xaxis , u8 Yaxis , u8 Copy_u8Length , u16 Copy_u8Color );
void TFT_VidWriteChar( u8 * Cop_u8Char , u8 Xaxis , u8 Yaxis , u16 Copy_u8Color );

void TFT_VidWriteChar16( u16 * Cop_u8Char , u8 Xaxis , u8 Yaxis , u16 Copy_u8Color );

void TFT_VidWriteChar32( u32 * Cop_u8Char , u8 Xaxis , u8 Yaxis , u16 Copy_u8Color );





#endif /* HAL_TFT_TFT_INTERFACE_H_ */
