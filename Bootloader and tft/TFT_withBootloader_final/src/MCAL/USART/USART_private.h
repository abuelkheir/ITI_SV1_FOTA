/*************************************************************************/
/******                                    ************/
/****** Driver: USART(MCAL)                                     ************/
/****** Date: 20 / 9 / 2023                                   ************/
/****** Version: 1.0 V                                        ************/
/*************************************************************************/


/*************************************************************************/
/* ------------- Guard Of File Will Call One Time in .c ------------ */
/*************************************************************************/

#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_

/* Base Address Of USART_1 Of stm32F401CC */
#define USART1_BASE_ADDRESS  0x40011000

/* Base Address Of USART_2 Of stm32F401CC */
#define USART2_BASE_ADDRESS  0x40004400

/* Base Address Of USART_3 Of stm32F401CC */
#define USART3_BASE_ADDRESS  0x40011400


/*  USART_CR1 Register bits definitions  */
typedef struct
{
	u32 SBK : 1;
	u32 RWU : 1;
	u32 RE : 1;
	u32 TE : 1;
	u32 IDLEIE : 1;
	u32 RXNEIE : 1;
	u32 TCIE : 1;
	u32 TXEIE : 1;
	u32 PEIE : 1;
	u32 PS : 1;
	u32 PCE : 1;
	u32 WAKE : 1;
	u32 M : 1;
	u32 UE : 1;
	u32 RESERVED : 1;
	u32 OVER8 : 1;
	u32 RESERVED1 : 16;
}tstrCR1;

/* This Strcut define The Offset Of USART Registers In The Mapped Memory Of stm32F401cc */
typedef struct {

	volatile u32 SR  ;
	volatile u32 DR  ;
	volatile u32 BRR ;
	volatile tstrCR1 CR1 ;
	volatile u32 CR2 ;
	volatile u32 CR3 ;
	volatile u32 GTPR;

}USART_t;

#define MUSART_1 ( ( volatile USART_t* ) USART1_BASE_ADDRESS ) // Declare Struct USART_1 of Registers



#define MUSART_2 ( ( volatile USART_t* ) USART2_BASE_ADDRESS ) // Declare Struct USART_1 of Registers


#define MUSART_3 ( ( volatile USART_t* ) USART3_BASE_ADDRESS ) // Declare Struct USART_1 of Registers






/*  USART_SR Register bits definitions  */
#define SR_CTS      9  /*CTS: CTS flag -> This bit is set by hardware when the CTS input toggles, if the CTSE bit is set. It is cleared by 
                        software (by writing it to 0). An interrupt is generated if CTSIE=1 in the USART_CR3 register.
                        Note: 0: No change occurred on the CTS status line
                              1: A change occurred on the CTS status line*/
#define SR_LBD      8 /*LIN break detection flag -> This bit is set by hardware when the LIN break is detected. It is cleared by software (by writing it to 0). An interrupt is generated if LBDIE = 1 in the USART_CR2 register.
                              0: LIN Break not detected
                              1: LIN break detected
                              Note: An interrupt is generated when LBD=1 if LBDIE=1*/
#define SR_TXE      7 /* TXE:Transmit data register empty,This bit is set by hardware 
                         An interrupt is generated if the TXEIE bit =1 in the USART_CR1 register.
						 It is cleared by a write to the USART_DR register.
                              0: Data is not transferred to the shift register
                              1: Data is transferred to the shift register)
                              Note: This bit is used during single buffer transmission*/
#define SR_TC       6  /*TC: Transmission complete-> This bit is set by hardware if the transmission of a frame containing data is complete and if TXE is set. An interrupt is generated if TCIE=1 in the USART_CR1 register. It is cleared by
                             a software sequence (a read from the USART_SR register followed by a write to the USART_DR register).
                              The TC bit can also be cleared by writing a '0' to it. This clearing sequence is recommended only for multibuffer communication.
                             0: Transmission is not complete
                             1: Transmission is complete*/
#define SR_RXNE     5  /*RXNE: Read data register not empty -> This bit is set by hardware when the content of the RDR shift register has been transferred to the USART_DR register.
                         An interrupt is generated if RXNEIE=1 in the USART_CR1 register.
                         It is cleared by a read to the USART_DR register. The RXNE flag can also be cleared by writing a zero to it.
                          This clearing sequence is recommended only for multibuffer communication.
                             0: Data is not received
                             1: Received data is ready to be read*/
#define SR_IDLE     4  /*IDLE: IDLE line detected-> This bit is set by hardware when an Idle Line is detected. An interrupt is generated if the IDLEIE=1 in the USART_CR1 register.
                         It is cleared by a software sequence (an read to the USART_SR register followed by a read to the USART_DR register).
                             0: No Idle Line is detected
                             1: Idle Line is detected
                       Note: The IDLE bit will not be set again until the RXNE bit has been set itself (i.e. a new idle line occurs)*/
#define SR_ORE      3 /*ORE: Overrun error
                            This bit is set by hardware when the word currently being received in the shift register is
                            ready to be transferred into the RDR register while RXNE=1. An interrupt is generated if
                            RXNEIE=1 in the USART_CR1 register. It is cleared by a software sequence (an read to the
                            USART_SR register followed by a read to the USART_DR register).
                            0: No Overrun error
                            1: Overrun error is detected
                            Note: When this bit is set, the RDR register content will not be lost but the shift register will be
                            overwritten. An interrupt is generated on ORE flag in case of Multi Buffer
                            communication if the EIE bit is set.
 */
#define SR_NF       2 /*2 NF: Noise detected flag
                         This bit is set by hardware when noise is detected on a received frame. It is cleared by a
                         software sequence (an read to the USART_SR register followed by a read to the
                         USART_DR register).
                            0: No noise is detected
                            1: Noise is detected*/
#define SR_FE       1 /*1 FE: Framing error
                       This bit is set by hardware when a de-synchronization, excessive noise or a break character
                       is detected. It is cleared by a software sequence (an read to the USART_SR register
                       followed by a read to the USART_DR register).
                            0: No Framing error is detected
                            1: Framing error or break character is detected*/
#define SR_PE       0 /*PE: Parity error
                       This bit is set by hardware when a parity error occurs in receiver mode. It is cleared by a
                       software sequence (a read from the status register followed by a read or write access to the
                       USART_DR data register). The software must wait for the RXNE flag to be set before
                       clearing the PE bit.An interrupt is generated if PEIE = 1 in the USART_CR1 register.
                           0: No parity error
                           1: Parity error*/


/* CR2 Bits */
#define CR2_STOP0						12

/* Mask */
#define MASK_2BITS						0b11


#endif
