/*
 * TFT_Prog.c
 *
 *  Created on: Sep 20, 2023
 *      Author: mayke
 */

#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_Interface.h"
#include "../../MCAL/MSTK/MSTK_Interface.h"
#include "../../HAL/TFT/TFT_Interface.h"
#include "../../MCAL/SPI/SPI_Interface.h"
//reset seq
//send command
//send data
volatile u8 x_start=0,x_end=0,y_start=0,y_end=0;
volatile u16 Bg_Color=0;
void Reset_Seq(void)
{

    /* Reset Puls To Initializing All registers*/
	MGPIO_voidSetPinValue( TFT_RST_PORT , TFT_RST_PIN , GPIO_HIGH );
	MSTK_voidSetBusyWait(200);
	MGPIO_voidSetPinValue( TFT_RST_PORT , TFT_RST_PIN , GPIO_LOW );
	MSTK_voidSetBusyWait(1);
	MGPIO_voidSetPinValue( TFT_RST_PORT , TFT_RST_PIN , GPIO_HIGH );
	MSTK_voidSetBusyWait(200);
	MGPIO_voidSetPinValue( TFT_RST_PORT , TFT_RST_PIN , GPIO_LOW );
	MSTK_voidSetBusyWait(200);
	MGPIO_voidSetPinValue( TFT_RST_PORT , TFT_RST_PIN , GPIO_HIGH );
	MSTK_voidSetBusyWait(220000);
}
void Send_Command(u8 Copy_u8Command)
{
	/* Set Pin AO in TFT to 0 Send Command */
			MGPIO_voidSetPinValue(TFT_AO_PORT,TFT_AO_PIN,GPIO_LOW);

			/* Send Data using SPI  */
			MSPI1_voidSendDataU8(Copy_u8Command);
}
void Send_Data(u8 Copy_u8Data)
{
	 /* Set Pin AO in TFT to 1 Send Data */
		MGPIO_voidSetPinValue(TFT_AO_PORT,TFT_AO_PIN,GPIO_HIGH);

		/* Send Data using SPI  */
		MSPI1_voidSendDataU8(Copy_u8Data);
}
void HTFT_voidinit()
{
	//step 1 reset seq
	Reset_Seq();
	//step2 send command(0x11);
	Send_Command(0x11);
	//step3 busywait 10 ms
	MSTK_voidSetBusyWait(20000);//10 ms
	//step 4 write command(0x3A)
	Send_Command(0x3A);
	//step 5 send data(0x05)color mode
	Send_Data(0x05);
	//send command (0X29)
	Send_Command(0x29);
}

void HTFT_Display(u16*array,u32 Copy_u32ArraySize)
{//sending most significant byte first
	/*step 1 set x axis
	 *write command(0x2A);
	 *write data(0x0);//start
	 *write data(0x0);
	 *
	 *write data(0x0);//end
	 *write data(0x127);
	 */

	Send_Command(0x2A);
	Send_Data(0x0);
	Send_Data(0x0);

	Send_Data(0x00);
	Send_Data(0x7F);
	/*step 2 set y axis
	 * write command(0x2A);
	 *write data(0x0);//start
	 *write data(0x0);
	 *
	 *write data(0x0);//end
	 *write data(0x159);
	 */
	Send_Command(0x2B);
	Send_Data(0x00);
	Send_Data(0x00);

	Send_Data(0x00);
	Send_Data(0x9F);
	/*step 3 command Ram Write
	 *write command (0x2c)
	 */
	Send_Command(0x2C);
	/*step 4 for loop to display array
	 *for(i=0;i<20480;i++)
	 *u8 low;// i send 2 bytes
	 *u8 high;
	 *
	 *low=(u8)array[i];
	 *high=((u8)array[i]>>8);
	 *
	 *write data(high)
	 *write data(low)
	 *
	 *
	 */
	for(u32 i=0;i<Copy_u32ArraySize;i++)
	{
		u8 low=0,high=0;
		low=(u8)array[i];
		high=(u8)(array[i]>>8);
		Send_Data(high);
		Send_Data(low);
	}


}

void HTFT_voidSetXPos(u16 Copy_u16XStart,u16 Copy_u16XEnd)
{
	x_start=Copy_u16XStart;
	x_end=Copy_u16XEnd;
	Send_Command(0x2A);
	Send_Data(0x0);
	Send_Data(Copy_u16XStart);

	Send_Data(0x00);
	Send_Data(Copy_u16XEnd);

}
void HTFT_voidSetYPos(u16 Copy_u16YStart,u16 Copy_u16YEnd)
{
	y_start=Copy_u16YStart;
	y_end=Copy_u16YEnd;
	Send_Command(0x2B);
	Send_Data(0x00);
	Send_Data(Copy_u16YStart);

	Send_Data(0x00);
	Send_Data(Copy_u16YEnd);

}
void HTFT_DisplayData(u16 Copy_u16Color)
{
	u8 low=0,high=0;
	low=(u8)Copy_u16Color;
	high=(u8)(Copy_u16Color>>8);
	Send_Command(0x2C);

//		for(u16 i=0;i<Copy_u32ArraySize;i++)
//		{
	Send_Data(high);
	Send_Data(low);
	//}
}
void HTFT_voidFillRectangle(u16 Copy_u16Color)
{
	u16 NbOfPixels=((x_end-x_start)+1)*((y_end-y_start)+1);
	Send_Command(0x2C);
	u8 low=0,high=0;
	low=(u8)Copy_u16Color;
	high=(u8)(Copy_u16Color>>8);
	for(u16 i=0;i<NbOfPixels;i++)
	{
		Send_Data(high);
		Send_Data(low);
	}

}
void HTFT_voidFillBackground(u16 Copy_u16Color)
{
	HTFT_voidSetXPos(0,127);
	HTFT_voidSetYPos(0,159);
	HTFT_voidFillRectangle(Copy_u16Color);
	Bg_Color=Copy_u16Color;

}
/*
 * 					font options
 * 					1-7x10
 * 					2-11x18
 * 					3-16x26
 */
void HTFT_voidSendChar(u16 x, u16 y,s8 ch, FontDef font, u16 color)
{
	volatile s8 character=ch;
	volatile u32 i=0,j=0,b=0;

	for (i=0;i<font.height;i++)
	{

		b=font.data[(((character-32)*(font.height))+i)];
		for(j=0;j<font.width;j++)
		{
			HTFT_voidSetXPos(x-j,x+font.width-1);
			HTFT_voidSetYPos(y-i,y+font.height-1);
			if(((b<<j)&0x8000))
			{
				HTFT_DisplayData(color);
			}
			else
			{
				HTFT_DisplayData(Bg_Color);
			}
		}
	}

}
void HTFT_voidSendString(u16 x, u16 y,s8*str, FontDef font, u16 color)
{
	volatile s8*string=str;
	while(*string)
	{
		if(x - font.width <= 0) {
			x = 127;
			y -= font.height;
			if(y - font.height <= 0) {
				break;
			}

		}
		HTFT_voidSendChar(x,y,*string,font,color);
			string++;
			x-=font.width;
	}
}
void HTFT_voidSleepOut(void)
{
	Send_Command(0x11);
}
