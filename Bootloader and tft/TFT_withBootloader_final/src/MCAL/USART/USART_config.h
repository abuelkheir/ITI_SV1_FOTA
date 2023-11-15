/*************************************************************************/
/******                                ************/
/****** Driver: USART(MCAL)                                     ************/
/****** Date: 20 / 9 / 2023                                   ************/
/****** Version: 1.0 V                                        ************/
/*************************************************************************/


/*************************************************************************/
  /* ------------- Guard Of File Will Call One Time in .c ------------ */
/*************************************************************************/

#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_


#define USART1_STATUS         USART1_ENABLE

#define USART1_BAUD_RATE      0x683

/* options:
 * 1- UART_DISABLE
 * 2- UART_ENABLE
 */
#define TRANSMITTER_ENABLE						UART_ENABLE

/* options:
 * 1- UART_DISABLE
 * 2- UART_ENABLE
 */
#define RECEIVER_ENABLE							UART_ENABLE

#define BAUD_FRACTION							3
#define BAUD_MINTASSA							104

/* options:
 * 1- UART_OVERSAMPLING_BY_16
 * 2- UART_OVERSAMPLING_BY_8
 */
#define OVERSAMPLING							UART_OVERSAMPLING_BY_16

/* options:
 * 1- UART_DATA_8BITS
 * 2- UART_DATA_9BITS
 */
#define DATA_LENGTH								UART_DATA_8BITS

/* options:
 * 1- UART_PARITY_DISABLE
 * 2- UART_PARITY_ENABLE
 */
#define PARITY_MODE								UART_PARITY_DISABLE

#if UART_PARITY_ENABLE == PARITY_MODE
	/* options:
	 * 1- UART_EVEN_PARITY
	 * 2- UART_ODD_PARITY
	 */
	#define PARITY_SELECTION					UART_EVEN_PARITY
#endif

/* options:
 * 1- UART_DISABLE_INTERRUPT
 * 2- UART_ENABLE_INTERRUPT
 */
#define TRANSMISSION_COMPELETE_INTERRUPT		UART_DISABLE_INTERRUPT

/* options:
 * 1- UART_DISABLE_INTERRUPT
 * 2- UART_ENABLE_INTERRUPT
 */
#define READ_DATA_REGISTER_EMPTY_INTERRUPT		UART_DISABLE_INTERRUPT

/* options
 * 1- UART_ONE_STOP_BIT
 * 2- UART_HALF_STOP_BIT
 * 3- UART_TWO_STOP_BIT
 * 4- UART_ONE_AND_HALF_STOP_BIT
 */
#define STOP_BITS								UART_ONE_STOP_BIT


#endif
