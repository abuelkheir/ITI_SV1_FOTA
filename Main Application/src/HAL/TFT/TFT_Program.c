/*
 * TFT_Program.c
 *
 *  Created on: ??�/??�/????
 *      Author: omara
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/bit_macros.h"
#include "../../MCAL/GPIO/GPIO_Interface.h"
#include "../../MCAL/STK/STK_Interface.h"
#include "../../MCAL/SPI/SPI_Interface.h"

// MCAL COMPONENTS
#include "TFT_Config.h"
#include "TFT_Interface.h"
#include "TFT_Private.h"

void TFT_WriteCommand(u8 cmd)
{
	MGPIO_voidSetPinVal(TFT_PORT,PINA0,MGPIO_LOW);//low
	MSPI_Transevice(cmd);
}

void TFT_WriteData(u8 Copy_u8Data)
{
	MGPIO_voidSetPinVal(TFT_PORT,PINA0,MGPIO_HIGH);//high
	MSPI_Transevice(Copy_u8Data);
}

void TFT_Reset()
{
	MGPIO_voidSetPinVal(TFT_PORT,PIN_RST,MGPIO_HIGH);//high
	MSTK_voidSetBusyWait(200);
	MGPIO_voidSetPinVal(TFT_PORT,PIN_RST,MGPIO_LOW);//low
	MSTK_voidSetBusyWait(3);
	MGPIO_voidSetPinVal(TFT_PORT,PIN_RST,MGPIO_HIGH);//high
	MSTK_voidSetBusyWait(200);
	MGPIO_voidSetPinVal(TFT_PORT,PIN_RST,MGPIO_LOW);//low
	MSTK_voidSetBusyWait(200);
	MGPIO_voidSetPinVal(TFT_PORT,PIN_RST,MGPIO_HIGH);//high
	MSTK_voidSetBusyWait(240000);//120ms
}

void TFT_VoidInit()
{
	TFT_Reset();
	TFT_WriteCommand(0x11);
	MSTK_voidSetBusyWait(20000);//10ms== 20 000 MICRO SEC
	TFT_WriteCommand(0x3A);
	TFT_WriteData(0X05);
	TFT_WriteCommand(0X29);
}

void TFT_VoidDisplay(u16 *img)
{

	//!SET X AXIS
	TFT_WriteCommand(0X2A);
	//START
	TFT_WriteData(0X00);
	TFT_WriteData(0X00);
	//END
	TFT_WriteData(0X00);
	TFT_WriteData(0X7F);
	//!SET Y AXISE
	TFT_WriteCommand(0X2B);
	//START Y
	TFT_WriteData(0X00);
	TFT_WriteData(0X00);
	//END Y 
	TFT_WriteData(0X00);
	TFT_WriteData(0X9F);
	// COMM (RAM WRITE)
	TFT_WriteCommand(0X2C);
		u8 Copy_LOW;
		u8 Copy_HIGH;
	for (u16 i = 0; i < 20480; i++)
	{
		Copy_LOW=(u8) img[i];
		Copy_HIGH=(u8) (img[i]>>8);
		TFT_WriteData(Copy_HIGH);
		TFT_WriteData(Copy_LOW);
	}
}


void TFT_VoidSetXpos(u16 xstart , u16 xend)
{
	//!SET X AXIS
		TFT_WriteCommand(0X2A);
		//START
		TFT_WriteData(0);
		TFT_WriteData(xstart);
		//END
		TFT_WriteData(0);
		TFT_WriteData(xend);
		//x_pos_start=xstart;
		//x_pos_end=xend;

}

void TFT_VoidSetYpos(u16 ystart , u16 yend)
{
	//!SET X AXIS
		TFT_WriteCommand(0X2B);
		//START
		TFT_WriteData(0);
		TFT_WriteData(ystart);
		//END
		TFT_WriteData(0);
		TFT_WriteData(yend);
		//y_pos_start=ystart;
		//y_pos_end=yend;
}


void TFT_VoidFillRectangle(u8 xstart,u8 xend,u8 ystart,u8 yend,u16 color)
{
	u16 NO_PIXEL=((xend - xstart)+1)*((yend - ystart)+1);//
	//SEND DATA
	TFT_WriteCommand(0X2C);
	u8 low=0,high=0;
	low=(u8) color;
	high=(u8) (color>>8);
	for (u16 i = 0; i < NO_PIXEL; i++)
	{
		TFT_WriteData(high);
		TFT_WriteData(low);
	}
}

void TFT_VoidFillBackGround(u16 color)
{
	//XPOS
	TFT_WriteData(0x2A);
	TFT_WriteData(0);
	TFT_WriteData(0);
	TFT_WriteData(0);
	TFT_WriteData(127);
	//ypos
	TFT_WriteData(0x2B);
	TFT_WriteData(0);
	TFT_WriteData(0);
	TFT_WriteData(0);
	TFT_WriteData(159);
	u8 low=0,high=0;
	low=(u8) color; //0x1234
	high=(u8) (color>>8);
	TFT_WriteCommand(0X2C);
	for (u16 i = 0; i < 20480; i++)
	{
		TFT_WriteData(high);
		TFT_WriteData(low);
	}
}

//! ////////////////////////////////////////////////////////////////////////////////////my api

void TFT_VoidDrowLine(u8 xstart,u8 xend ,u8 ystart , u8 yend,u16 color)
{
	//x
	TFT_VoidSetXpos(xstart,xend);
	//y
	TFT_VoidSetYpos(ystart,yend);
	//line
	u16 PIXEL=((xend - xstart)+1)*((yend - ystart)+1);//squre
	//SEND DATA
	TFT_WriteCommand(0X2C);
	u8 low=0,high=0;
	low=(u8) color;
	high=(u8) (color>>8);
	for (u16 i = 0; i < PIXEL; i++)
	{
		TFT_WriteData(high);
		TFT_WriteData(low);
	}
}

void TFT_VidDrawHLine ( u8 Xaxis , u8 Yaxis , u8 Copy_u8Length , u16 Copy_u8Color ) 
{
	for ( ; Copy_u8Length > 0 ; Copy_u8Length-- ){

		TFT_WriteCommand( 0X2A ); // set column range (x0,x1)

		TFT_WriteData   ( Xaxis );
		TFT_WriteData   ( Xaxis );

		TFT_WriteCommand( 0X2B ); // set row range (y0,y1)

		TFT_WriteData   ( Yaxis );
		TFT_WriteData   ( Yaxis );

		TFT_WriteCommand( RAMWR ); // memory write

		TFT_WriteData ( Copy_u8Color >> 8   ); // write hi byte
		TFT_WriteData ( Copy_u8Color & 0xFF ); // write lo byte

		Xaxis++;

	}
}

void TFT_VidDrawVLine ( u8 Xaxis , u8 Yaxis , u8 Copy_u8Length , u16 Copy_u8Color ) 
{
	for ( ; Copy_u8Length > 0 ; Copy_u8Length-- ){

		TFT_WriteCommand( 0X2A ); // set column range (x0,x1)

		TFT_WriteData   ( Xaxis );
		TFT_WriteData   ( Xaxis );

		TFT_WriteCommand( 0X2B ); // set row range (y0,y1)

		TFT_WriteData   ( Yaxis );
		TFT_WriteData   ( Yaxis );

		TFT_WriteCommand( RAMWR ); // memory write

		TFT_WriteData ( Copy_u8Color >> 8   ); // write hi byte
		TFT_WriteData ( Copy_u8Color & 0xFF ); // write lo byte

		Yaxis++;

	}
}

//char8
void TFT_VidWriteChar( u8 * Cop_u8Char , u8 Xaxis , u8 Yaxis , u16 Copy_u8Color )
{
	u8  LOC_u8Mask = 0x01 ;
	u8  LOC_u8DataMasked  ;
	u16 LOC_u8Pixel       ;

	for( u8 LOC_u8Iterator1 = 0 ; LOC_u8Iterator1 < 50 ; LOC_u8Iterator1++ ){

		for( u8 LOC_u8Iterator2 = 0 ; LOC_u8Iterator2 < 60 ; LOC_u8Iterator2++ ){

			// Set The Position Of 5x7 Character
			TFT_WriteCommand( XSET ); // set column range (x0,x1)

			TFT_WriteData( Xaxis +  LOC_u8Iterator1 );
			TFT_WriteData( Xaxis +  LOC_u8Iterator1 );

			TFT_WriteCommand( YSET ); // set row range (y0,y1)

			TFT_WriteData( Yaxis +  LOC_u8Iterator2 );
			TFT_WriteData( Yaxis +  LOC_u8Iterator2 );

			TFT_WriteCommand( RAMWR ); // memory write

			LOC_u8DataMasked = Cop_u8Char[ LOC_u8Iterator1 ] & LOC_u8Mask ;

			if( LOC_u8DataMasked == 0  ) { LOC_u8Pixel = 0x0000       ; }

			else                         { LOC_u8Pixel = Copy_u8Color ; }

			TFT_WriteData ( LOC_u8Pixel >> 8   ); // write hi byte
			TFT_WriteData ( LOC_u8Pixel & 0xFF ); // write lo byte

			LOC_u8Mask <<= 1 ;
		}
		LOC_u8Mask = 0x01 ;
	}
}

//////////////////////////////////////////////////////////////////////////////////////
//char16
void TFT_VidWriteChar16( u16 * Cop_u8Char , u8 Xaxis , u8 Yaxis , u16 Copy_u8Color )
{
	u16  LOC_u8Mask = 0x0001 ;
	u16  LOC_u8DataMasked  ;
	u16 LOC_u8Pixel       ;

	for( u8 LOC_u8Iterator1 = 0 ; LOC_u8Iterator1 < 13 ; LOC_u8Iterator1++ ){

		for( u8 LOC_u8Iterator2 = 0 ; LOC_u8Iterator2 < 17 ; LOC_u8Iterator2++ ){

			// Set The Position Of 5x7 Character
			TFT_WriteCommand( XSET ); // set column range (x0,x1)

			TFT_WriteData( Xaxis +  LOC_u8Iterator1 );
			TFT_WriteData( Xaxis +  LOC_u8Iterator1 );

			TFT_WriteCommand( YSET ); // set row range (y0,y1)

			TFT_WriteData( Yaxis +  LOC_u8Iterator2 );
			TFT_WriteData( Yaxis +  LOC_u8Iterator2 );

			TFT_WriteCommand( RAMWR ); // memory write

			LOC_u8DataMasked = Cop_u8Char[ LOC_u8Iterator1 ] & LOC_u8Mask ;

			if( LOC_u8DataMasked == 0  ) { LOC_u8Pixel = 0x0000       ; }

			else                         { LOC_u8Pixel = Copy_u8Color ; }

			TFT_WriteData ( LOC_u8Pixel >> 8   ); // write hi byte
			TFT_WriteData ( LOC_u8Pixel & 0xFF ); // write lo byte

			LOC_u8Mask <<= 1 ;
		}
		LOC_u8Mask = 0x01 ;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////
//char32
void TFT_VidWriteChar32( u32 * Cop_u8Char , u8 Xaxis , u8 Yaxis , u16 Copy_u8Color )
{
	u32  LOC_u8Mask = 0x00000001 ;
	u32  LOC_u8DataMasked  ;
	u32 LOC_u8Pixel       ;

	for( u8 LOC_u8Iterator1 = 0 ; LOC_u8Iterator1 < 17 ; LOC_u8Iterator1++ ){

		for( u8 LOC_u8Iterator2 = 0 ; LOC_u8Iterator2 < 20 ; LOC_u8Iterator2++ ){

			TFT_WriteCommand( XSET ); // set column range (x0,x1)

			TFT_WriteData( Xaxis +  LOC_u8Iterator1 );
			TFT_WriteData( Xaxis +  LOC_u8Iterator1 );

			TFT_WriteCommand( YSET ); // set row range (y0,y1)

			TFT_WriteData( Yaxis +  LOC_u8Iterator2 );
			TFT_WriteData( Yaxis +  LOC_u8Iterator2 );

			TFT_WriteCommand( RAMWR ); // memory write

			LOC_u8DataMasked = Cop_u8Char[ LOC_u8Iterator1 ] & LOC_u8Mask ;

			if( LOC_u8DataMasked == 0  ) { LOC_u8Pixel = 0x00000000       ; }

			else                         { LOC_u8Pixel = Copy_u8Color ; }

			TFT_WriteData ( LOC_u8Pixel >> 8   ); // write hi byte
			TFT_WriteData ( LOC_u8Pixel & 0xFF ); // write lo byte

			LOC_u8Mask <<= 1 ;
		}
		LOC_u8Mask = 0x00000001 ;
	}
}


