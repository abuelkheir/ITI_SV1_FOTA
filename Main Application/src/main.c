/*
AUTHOR : OMAR

VERSION : V 2.0

LAST UPDATE : 10:30 PM  10/11/2023

*/

#include "Main_Interface.h"
int main()
{
//rcc
	Main_voidInit();
	u8 receivedData;


	//MSTK_voidSetIntervalPeriodic(20000,distance);
	while(1)
	{

		//Receive data from USART
		receivedData = USART_u8Recieve();

		if (receivedData == 'S')
		{
			MOTOR_Stop();
			MOTOR_AllchanelStop();
		}
		if (receivedData == 'F')
		{

			MOTOR_Forward();
			MOTOR_Move();
		}
		if (receivedData == 'B')
		{
			MOTOR_Move();
			MOTOR_Backward();
		}
		if (receivedData == 'L')
		{

			MOTOR_Move();
			MOTOR_Lift();
		}
		if (receivedData == 'R')
		{

			MOTOR_Move();
			MOTOR_Right();
		}

	}//while
	return 0;
}//main

