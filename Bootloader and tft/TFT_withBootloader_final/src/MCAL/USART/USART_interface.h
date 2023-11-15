/*************************************************************************/
/******                                   ************/
/****** Driver: USART(MCAL)                                     ************/
/****** Date: 20 / 9 / 2023                                   ************/
/****** Version: 1.0 V                                        ************/
/*************************************************************************/


/*************************************************************************/
  /* ------------- Guard Of File Will Call One Time in .c ------------ */
/*************************************************************************/

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_




/*
*************************************************************************************************************************
*************************************************** FUNCTION_PROTOTYPES *************************************************
*************************************************************************************************************************
*/

/*
**************************************************************************************************************************
*****************************************  01 - MUSART1_voidInit()  ********************************************************

	1-  Function Description ->  Function Initialized USART1 Configuration
	2-  Options : 
				   
	3- Function Arguments : void 
							
	4- Function Return   ->  No Return(void)
	
**************************************************************************************************************************
**************************************************************************************************************************	
*/

void MUSART1_voidInit(void);


/*
**************************************************************************************************************************
*****************************************  02 - MUSART_voidTransmitData()  *************************************************

	1- Function Description ->   Function That TransmitData
 
	2- Function Arguments :      u8 *Copy_pu8TransmittedData 
							
	3- Function Return      ->   Variable With Data Type Of (8u)
	
**************************************************************************************************************************
**************************************************************************************************************************	
*/

void MUSART1_voidTransmitData(s8 *Copy_pu8TransmittedData);
/*
**************************************************************************************************************************
*****************************************  03 - MUSART_voidReceiveData()  *************************************************

	1- Function Description ->   Function That Received Data
 
	2- Function Arguments :      (void) 
							
	3- Function Return      ->   No Return(void)
	
**************************************************************************************************************************
**************************************************************************************************************************	
*/

u8 MUSART1_u8ReceiveData(u8 *Pointer_u8Data);

u8 MUSART1_u8ASynchReceiveData (u8 *Pointer_u8Data);


void MUSART1_voidDisable(void);

void MUSART1_voidEnable(void);
/* ---------------------------------------------------- SOME_REQUIRED_DEFINITIONS ------------------------------------------------------------ */

/* Oversampling mode */
#define UART_OVERSAMPLING_BY_16					0
#define UART_OVERSAMPLING_BY_8 					1

/* Data length */
#define UART_DATA_8BITS							0
#define UART_DATA_9BITS							1

/* Parity mode */
#define UART_PARITY_DISABLE						0
#define UART_PARITY_ENABLE						1

/* Parity selection */
#define UART_EVEN_PARITY						0
#define UART_ODD_PARITY							1

/* Interrupt state */
#define UART_DISABLE_INTERRUPT					0
#define UART_ENABLE_INTERRUPT					1

/* Transmitter & Receiver enable */
#define UART_DISABLE							0
#define UART_ENABLE								1

/* Stop bits */
#define UART_ONE_STOP_BIT		                0
#define UART_HALF_STOP_BIT                      1
#define UART_TWO_STOP_BIT						2
#define UART_ONE_AND_HALF_STOP_BIT				3

#endif
