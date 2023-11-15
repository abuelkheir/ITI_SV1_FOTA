/**
 * @file TMR_prog.c
 * @author Abdelrahman Mourad (abdelrahman.k212@gmail.com)
 * @brief  functions implementations
 * @version 0.2
 * @date 2023-05-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */
/*******************************************************************************
 *                          	Standard Types                                 *
 *******************************************************************************/

//#include "../../LIB/ITI_STD_TYPES.h"
//#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/bit_macros.h"

/*******************************************************************************
 *                          	MCAL Components                                 *
 *******************************************************************************/
#include "TIMER_interface.h"
#include "TIMER_private.h"


/**
 * @brief this function is used to start the timer
 * 
 * @param Copy_uddtTMR_no [TMR2 - TMR3 - TMR4 - TMR5]
 * @return void
 */
void MTMR_voidStart(TMRN_t Copy_uddtTMR_no)
{
	switch(Copy_uddtTMR_no)
	{
	case TMR_2:
		/* Enable Timer */
		SET_BIT(TMR2 -> CR1, CEN_BIT);
		break;
	case TMR_3:
		/* Initialize all the registers */
		//SET_BIT(TMR3 -> EGR, 0);
		/* Enable Timer */
		SET_BIT(TMR3 -> CR1, CEN_BIT);
		break;
	case TMR_4:
		/* Initialize all the registers */
		//SET_BIT(TMR4 -> EGR, 0);
		/* Enable Timer */
		SET_BIT(TMR4 -> CR1, CEN_BIT);
		break;
	case TMR_5:
		/* Initialize all the registers */
		//SET_BIT(TMR5 -> EGR, 0);                                              //
		/* Enable Timer */
		SET_BIT(TMR5 -> CR1, CEN_BIT);
		break;

	default  : 								break;
	}
}


void MTMR_voidStop(TMRN_t Copy_uddtTMR_no)
{
	switch(Copy_uddtTMR_no)
	{
		case TMR_2: CLR_BIT(TMR2 -> CR1, CEN_BIT); break;
		case TMR_3: CLR_BIT(TMR3 -> CR1, CEN_BIT); break;
		case TMR_4: CLR_BIT(TMR4 -> CR1, CEN_BIT); break;
		case TMR_5: CLR_BIT(TMR5 -> CR1, CEN_BIT); break;
		default  : 									  break;
	}
}


void MTMR_voidSetPrescaler(TMRN_t Copy_uddtTMR_no, u16 Copy_u16Value)
{
	switch(Copy_uddtTMR_no)
	{
		case TMR_2: /* Clear all bits*/
				   Clr_ALL_BITS(TMR2 -> PSC);
				   /* Set prescaler value */
				   TMR2 -> PSC |= Copy_u16Value - 1;
				   break;
		case TMR_3: /* Clear all bits*/
				   Clr_ALL_BITS(TMR3 -> PSC);
				   /* Set prescaler value */
				   TMR3 -> PSC |= Copy_u16Value - 1;
				   break;
		case TMR_4: /* Clear all bits*/
					Clr_ALL_BITS(TMR4 -> PSC);
					 /* Set prescaler value */
					TMR4 -> PSC |= Copy_u16Value - 1;
					break;
		case TMR_5: /* Clear all bits*/
			       Clr_ALL_BITS(TMR5 -> PSC);
			       /* Set prescaler value */
			       TMR5 -> PSC |= Copy_u16Value - 1;
			       break;
		default  :									 break;
	}
}


/*void TMR_voidEnableOPM(TMRN_t Copy_uddtTMR_no)
{
	switch(Copy_uddtTMR_no)
	{
	case TMR2:
		SET_BIT(TMR2 -> CR1, OPM_BIT);
		break;
	default:                               break;
	}
}*/

/**
 * @brief this function is used to set the timer mode when generating a signal
 * 
 * @param Copy_uddtTMR_no timer number [TMR2 - TMR3 - TMR4 - TMR5]
 * @param Copy_uddtFn timer mode [FROZEN - ACTIVE - INACTIVE - TOGGLE - INACTIVE_FORCE - ACTIVE_FORCE - PWM_MODE1 - PWM_MODE2]
 * @param Copy_uddtChNo Channel number [CH1 ~ CH4]
 * @return void
 */
void MTMR_voidSetChannelOutput(TMRN_t Copy_uddtTMR_no, CMPFn_t Copy_uddtFn,
		CHN_t Copy_uddtChNo) {
	switch (Copy_uddtTMR_no) {
	case TMR_2:
		switch (Copy_uddtChNo) {
		case CH1: /* Set Capture/Compare 1 as output */
			CLR_BIT(TMR2 -> CCMR1, 1);
			CLR_BIT(TMR2 -> CCMR1, 0);
			//Clr_BITS(TMR2 -> CCMR1, 0x00000073);
			/* Output Compare 1 pre-load enable */
			SET_BIT(TMR2 -> CCMR1, 3);
			/* Select Output Compare 1 */
			//TMR2 -> CCMR1 |= (Copy_uddtFn << OC1M_SHIFT);
			TMR2->CCMR1 = ((TMR2->CCMR1) & (0xFFFFFF8F))
							| (Copy_uddtFn << OC1M_SHIFT);
			/* Select Capture/Compare 1 output polarity active high */
			//CLR_BIT(TMR2 -> CCER, 1);
			/* Initialize all the registers (ana kda bn2l el compare value we el auto reload value we el prescaler ll shadow reg 34an tt7t fe elregister bta3tha ) */
			SET_BIT(TMR2 -> EGR, 0);
			/* Enable Capture/Compare 1 output */
			SET_BIT(TMR2 -> CCER, CC1EN_BIT);
			break;

		case CH2:
			/* Set Capture/Compare 1 as output */
			CLR_BIT(TMR2 -> CCMR1, 8);
			CLR_BIT(TMR2 -> CCMR1, 9);
			//Clr_BITS(TMR2 -> CCMR1, 0x00000073);
			/* Output Compare 1 pre-load enable */
			SET_BIT(TMR2 -> CCMR1, 11);
			/* Select Output Compare 1 */
			//TMR2 -> CCMR1 |= (Copy_uddtFn << OC2M_SHIFT);
			TMR2->CCMR1 = ((TMR2->CCMR1) & (0xFFFF8FFF)) | (Copy_uddtFn << 12);
			/* Initialize all the registers (ana kda bn2l el compare value we el auto reload value we el prescaler ll shadow reg 34an tt7t fe elregister bta3tha ) */
			SET_BIT(TMR2 -> EGR, 0);
			/* Enable Capture/Compare 1 output */
			SET_BIT(TMR2 -> CCER, 4);
			break;

		case CH3:
			/* Set Capture/Compare 1 as output */
			CLR_BIT(TMR2 -> CCMR2, 0);
			CLR_BIT(TMR2 -> CCMR2, 1);
			//Clr_BITS(TMR2 -> CCMR1, 0x00000073);
			/* Output Compare 1 pre-load enable */
			SET_BIT(TMR2 -> CCMR2, 3);
			/* Select Output Compare 1 */
			//TMR2 -> CCMR1 |= (Copy_uddtFn << OC3M_SHIFT);
			TMR2->CCMR2 = ((TMR2->CCMR2) & (0xFFFFFF8F)) | (Copy_uddtFn << 4);
			/* Initialize all the registers (ana kda bn2l el compare value we el auto reload value we el prescaler ll shadow reg 34an tt7t fe elregister bta3tha ) */
			SET_BIT(TMR2 -> EGR, 0);
			/* Enable Capture/Compare 1 output */
			SET_BIT(TMR2 -> CCER, 8);
			break;

		case CH4:
			/* Set Capture/Compare 1 as output */
			CLR_BIT(TMR2 -> CCMR2, 8);
			CLR_BIT(TMR2 -> CCMR2, 9);
			//Clr_BITS(TMR2 -> CCMR1, 0x00000073);
			/* Output Compare 1 pre-load enable */
			SET_BIT(TMR2 -> CCMR2, 11);
			/* Select Output Compare 1 */
			//TMR2 -> CCMR1 |= (Copy_uddtFn << OC4M_SHIFT);
			TMR2->CCMR2 = ((TMR2->CCMR2) & (0xFFFF8FFF)) | (Copy_uddtFn << 12);
			/* Initialize all the registers (ana kda bn2l el compare value we el auto reload value we el prescaler ll shadow reg 34an tt7t fe elregister bta3tha ) */
			SET_BIT(TMR2 -> EGR, 0);
			/* Enable Capture/Compare 1 output */
			SET_BIT(TMR2 -> CCER, 12);
			break;
		}
		break;
		//--------------------------------------------
		case TMR_5:
			switch (Copy_uddtChNo) {
			case CH1: /* Set Capture/Compare 1 as output */
				CLR_BIT(TMR5 -> CCMR1, 1);
				CLR_BIT(TMR5 -> CCMR1, 0);
				//Clr_BITS(TMR2 -> CCMR1, 0x00000073);
				/* Output Compare 1 pre-load enable */
				SET_BIT(TMR5 -> CCMR1, 3);
				/* Select Output Compare 1 */
				//TMR2 -> CCMR1 |= (Copy_uddtFn << OC1M_SHIFT);
				TMR5->CCMR1 = ((TMR5->CCMR1) & (0xFFFFFF8F))
							| (Copy_uddtFn << OC1M_SHIFT);
				/* Select Capture/Compare 1 output polarity active high */
				//CLR_BIT(TMR2 -> CCER, 1);
				/* Initialize all the registers (ana kda bn2l el compare value we el auto reload value we el prescaler ll shadow reg 34an tt7t fe elregister bta3tha ) */
				SET_BIT(TMR5 -> EGR, 0);
				/* Enable Capture/Compare 1 output */
				SET_BIT(TMR5 -> CCER, CC1EN_BIT);
				break;

			case CH2:
				/* Set Capture/Compare 1 as output */
				CLR_BIT(TMR5 -> CCMR1, 8);
				CLR_BIT(TMR5 -> CCMR1, 9);
				//Clr_BITS(TMR2 -> CCMR1, 0x00000073);
				/* Output Compare 1 pre-load enable */
				SET_BIT(TMR5 -> CCMR1, 11);
				/* Select Output Compare 1 */
				//TMR2 -> CCMR1 |= (Copy_uddtFn << OC2M_SHIFT);
				TMR5->CCMR1 = ((TMR5->CCMR1) & (0xFFFF8FFF)) | (Copy_uddtFn << 12);
				/* Initialize all the registers (ana kda bn2l el compare value we el auto reload value we el prescaler ll shadow reg 34an tt7t fe elregister bta3tha ) */
				SET_BIT(TMR5 -> EGR, 0);
				/* Enable Capture/Compare 1 output */
				SET_BIT(TMR5 -> CCER, 4);
				break;

			case CH3:
				/* Set Capture/Compare 1 as output */
				CLR_BIT(TMR5 -> CCMR2, 0);
				CLR_BIT(TMR5 -> CCMR2, 1);
				//Clr_BITS(TMR2 -> CCMR1, 0x00000073);
				/* Output Compare 1 pre-load enable */
				SET_BIT(TMR5 -> CCMR2, 3);
				/* Select Output Compare 1 */
				//TMR2 -> CCMR1 |= (Copy_uddtFn << OC3M_SHIFT);
				TMR5->CCMR2 = ((TMR5->CCMR2) & (0xFFFFFF8F)) | (Copy_uddtFn << 4);
				/* Initialize all the registers (ana kda bn2l el compare value we el auto reload value we el prescaler ll shadow reg 34an tt7t fe elregister bta3tha ) */
				SET_BIT(TMR5 -> EGR, 0);
				/* Enable Capture/Compare 1 output */
				SET_BIT(TMR5 -> CCER, 8);
				break;

			case CH4:
				/* Set Capture/Compare 1 as output */
				CLR_BIT(TMR5 -> CCMR2, 8);
				CLR_BIT(TMR5 -> CCMR2, 9);
				//Clr_BITS(TMR2 -> CCMR1, 0x00000073);
				/* Output Compare 1 pre-load enable */
				SET_BIT(TMR5 -> CCMR2, 11);
				/* Select Output Compare 1 */
				//TMR2 -> CCMR1 |= (Copy_uddtFn << OC4M_SHIFT);
				TMR5->CCMR2 = ((TMR5->CCMR2) & (0xFFFF8FFF)) | (Copy_uddtFn << 12);
				/* Initialize all the registers (ana kda bn2l el compare value we el auto reload value we el prescaler ll shadow reg 34an tt7t fe elregister bta3tha ) */
				SET_BIT(TMR5 -> EGR, 0);
				/* Enable Capture/Compare 1 output */
				SET_BIT(TMR5 -> CCER, 12);
				break;
			}
			break;
			//---------------------------------------------------
			//---------------------------------------------------

			case TMR_4:
				switch (Copy_uddtChNo) {
				case CH1: /* Set Capture/Compare 1 as output */
					CLR_BIT(TMR4 -> CCMR1, 1);
					CLR_BIT(TMR4 -> CCMR1, 0);
					//Clr_BITS(TMR2 -> CCMR1, 0x00000073);
					/* Output Compare 1 pre-load enable */
					SET_BIT(TMR4 -> CCMR1, 3);
					/* Select Output Compare 1 */
					//TMR2 -> CCMR1 |= (Copy_uddtFn << OC1M_SHIFT);
					TMR4->CCMR1 = ((TMR4->CCMR1) & (0xFFFFFF8F))
											| (Copy_uddtFn << OC1M_SHIFT);
					/* Select Capture/Compare 1 output polarity active high */
					//CLR_BIT(TMR2 -> CCER, 1);
					/* Initialize all the registers (ana kda bn2l el compare value we el auto reload value we el prescaler ll shadow reg 34an tt7t fe elregister bta3tha ) */
					SET_BIT(TMR4 -> EGR, 0);
					/* Enable Capture/Compare 1 output */
					SET_BIT(TMR4 -> CCER, CC1EN_BIT);
					break;

				case CH2:
					/* Set Capture/Compare 1 as output */
					CLR_BIT(TMR4 -> CCMR1, 8);
					CLR_BIT(TMR4 -> CCMR1, 9);
					//Clr_BITS(TMR2 -> CCMR1, 0x00000073);
					/* Output Compare 1 pre-load enable */
					SET_BIT(TMR4 -> CCMR1, 11);
					/* Select Output Compare 1 */
					//TMR2 -> CCMR1 |= (Copy_uddtFn << OC2M_SHIFT);
					TMR4->CCMR1 = ((TMR4->CCMR1) & (0xFFFF8FFF)) | (Copy_uddtFn << 12);
					/* Initialize all the registers (ana kda bn2l el compare value we el auto reload value we el prescaler ll shadow reg 34an tt7t fe elregister bta3tha ) */
					SET_BIT(TMR4 -> EGR, 0);
					/* Enable Capture/Compare 1 output */
					SET_BIT(TMR4 -> CCER, 4);
					break;

				case CH3:
					/* Set Capture/Compare 1 as output */
					CLR_BIT(TMR4 -> CCMR2, 0);
					CLR_BIT(TMR4 -> CCMR2, 1);
					//Clr_BITS(TMR2 -> CCMR1, 0x00000073);
					/* Output Compare 1 pre-load enable */
					SET_BIT(TMR4 -> CCMR2, 3);
					/* Select Output Compare 1 */
					//TMR2 -> CCMR1 |= (Copy_uddtFn << OC3M_SHIFT);
					TMR4->CCMR2 = ((TMR4->CCMR2) & (0xFFFFFF8F)) | (Copy_uddtFn << 4);
					/* Initialize all the registers (ana kda bn2l el compare value we el auto reload value we el prescaler ll shadow reg 34an tt7t fe elregister bta3tha ) */
					SET_BIT(TMR4 -> EGR, 0);
					/* Enable Capture/Compare 1 output */
					SET_BIT(TMR4 -> CCER, 8);
					break;

				case CH4:
					/* Set Capture/Compare 1 as output */
					CLR_BIT(TMR4 -> CCMR2, 8);
					CLR_BIT(TMR4 -> CCMR2, 9);
					//Clr_BITS(TMR2 -> CCMR1, 0x00000073);
					/* Output Compare 1 pre-load enable */
					SET_BIT(TMR4 -> CCMR2, 11);
					/* Select Output Compare 1 */
					//TMR2 -> CCMR1 |= (Copy_uddtFn << OC4M_SHIFT);
					TMR4->CCMR2 = ((TMR4->CCMR2) & (0xFFFF8FFF)) | (Copy_uddtFn << 12);
					/* Initialize all the registers (ana kda bn2l el compare value we el auto reload value we el prescaler ll shadow reg 34an tt7t fe elregister bta3tha ) */
					SET_BIT(TMR4 -> EGR, 0);
					/* Enable Capture/Compare 1 output */
					SET_BIT(TMR4 -> CCER, 12);
					break;
				}
				break;
				//---------------------------------------------//
				case TMR_3:
					switch (Copy_uddtChNo) {
					case CH1: /* Set Capture/Compare 1 as output */
						CLR_BIT(TMR3 -> CCMR1, 1);
						CLR_BIT(TMR3 -> CCMR1, 0);
						//Clr_BITS(TMR2 -> CCMR1, 0x00000073);
						/* Output Compare 1 pre-load enable */
						SET_BIT(TMR3 -> CCMR1, 3);
						/* Select Output Compare 1 */
						//TMR2 -> CCMR1 |= (Copy_uddtFn << OC1M_SHIFT);
						TMR3->CCMR1 = ((TMR3->CCMR1) & (0xFFFFFF8F))
												| (Copy_uddtFn << OC1M_SHIFT);
						/* Select Capture/Compare 1 output polarity active high */
						//CLR_BIT(TMR2 -> CCER, 1);
						/* Initialize all the registers (ana kda bn2l el compare value we el auto reload value we el prescaler ll shadow reg 34an tt7t fe elregister bta3tha ) */
						SET_BIT(TMR3 -> EGR, 0);
						/* Enable Capture/Compare 1 output */
						SET_BIT(TMR3 -> CCER, CC1EN_BIT);
						break;

					case CH2:
						/* Set Capture/Compare 1 as output */
						CLR_BIT(TMR3 -> CCMR1, 8);
						CLR_BIT(TMR3 -> CCMR1, 9);
						//Clr_BITS(TMR2 -> CCMR1, 0x00000073);
						/* Output Compare 1 pre-load enable */
						SET_BIT(TMR3 -> CCMR1, 11);
						/* Select Output Compare 1 */
						//TMR2 -> CCMR1 |= (Copy_uddtFn << OC2M_SHIFT);
						TMR3->CCMR1 = ((TMR3->CCMR1) & (0xFFFF8FFF)) | (Copy_uddtFn << 12);
						/* Initialize all the registers (ana kda bn2l el compare value we el auto reload value we el prescaler ll shadow reg 34an tt7t fe elregister bta3tha ) */
						SET_BIT(TMR3 -> EGR, 0);
						/* Enable Capture/Compare 1 output */
						SET_BIT(TMR3 -> CCER, 4);
						break;

					case CH3:
						/* Set Capture/Compare 1 as output */
						CLR_BIT(TMR3 -> CCMR2, 0);
						CLR_BIT(TMR3 -> CCMR2, 1);
						//Clr_BITS(TMR2 -> CCMR1, 0x00000073);
						/* Output Compare 1 pre-load enable */
						SET_BIT(TMR3 -> CCMR2, 3);
						/* Select Output Compare 1 */
						//TMR2 -> CCMR1 |= (Copy_uddtFn << OC3M_SHIFT);
						TMR3->CCMR2 = ((TMR3->CCMR2) & (0xFFFFFF8F)) | (Copy_uddtFn << 4);
						/* Initialize all the registers (ana kda bn2l el compare value we el auto reload value we el prescaler ll shadow reg 34an tt7t fe elregister bta3tha ) */
						SET_BIT(TMR3 -> EGR, 0);
						/* Enable Capture/Compare 1 output */
						SET_BIT(TMR3 -> CCER, 8);
						break;

					case CH4:
						/* Set Capture/Compare 1 as output */
						CLR_BIT(TMR3 -> CCMR2, 8);
						CLR_BIT(TMR3 -> CCMR2, 9);
						//Clr_BITS(TMR2 -> CCMR1, 0x00000073);
						/* Output Compare 1 pre-load enable */
						SET_BIT(TMR3 -> CCMR2, 11);
						/* Select Output Compare 1 */
						//TMR2 -> CCMR1 |= (Copy_uddtFn << OC4M_SHIFT);
						TMR3->CCMR2 = ((TMR3->CCMR2) & (0xFFFF8FFF)) | (Copy_uddtFn << 12);
						/* Initialize all the registers (ana kda bn2l el compare value we el auto reload value we el prescaler ll shadow reg 34an tt7t fe elregister bta3tha ) */
						SET_BIT(TMR3 -> EGR, 0);
						/* Enable Capture/Compare 1 output */
						SET_BIT(TMR3 -> CCER, 12);
						break;
					}
					break;

					default:
						break;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////
void MTMR_voidSetCMPVal(TMRN_t Copy_uddtTMR_no, CHN_t Copy_uddtChNo, u32 cmpValue)
{
	switch (Copy_uddtTMR_no) {
	case TMR_2:
		switch (Copy_uddtChNo) {
		case CH1: /* Set Compare Value*/
			TMR2->CCR1 = cmpValue;
			break;
		case CH2: /* Set Compare Value*/
			TMR2->CCR2 = cmpValue;
			break;
		case CH3: /* Set Compare Value*/
			TMR2->CCR3 = cmpValue;
			break;
		case CH4: /* Set Compare Value*/
			TMR2->CCR4 = cmpValue;
			break;
		default:
			break;
		}
		break;
	case TMR_5:
		switch (Copy_uddtChNo) {
		case CH1: /* Set Compare Value*/
			TMR5->CCR1 = cmpValue;
			break;
		case CH2: /* Set Compare Value*/
			TMR5->CCR2 = cmpValue;
			break;
		case CH3: /* Set Compare Value*/
			TMR5->CCR3 = cmpValue;
			break;
		case CH4: /* Set Compare Value*/
			TMR5->CCR4 = cmpValue;
			break;
		default:
			break;
		}
		break;
		case TMR_4:
			switch (Copy_uddtChNo) {
			case CH1: /* Set Compare Value*/
				TMR4->CCR1 = cmpValue;
				break;
			case CH2: /* Set Compare Value*/
				TMR4->CCR2 = cmpValue;
				break;
			case CH3: /* Set Compare Value*/
				TMR4->CCR3 = cmpValue;
				break;
			case CH4: /* Set Compare Value*/
				TMR4->CCR4 = cmpValue;
				break;
			default:
				break;
			}
			break;
			case TMR_3:
				switch (Copy_uddtChNo) {
				case CH1: /* Set Compare Value*/
					TMR3->CCR1 = cmpValue;
					break;
				case CH2: /* Set Compare Value*/
					TMR3->CCR2 = cmpValue;
					break;
				case CH3: /* Set Compare Value*/
					TMR3->CCR3 = cmpValue;
					break;
				case CH4: /* Set Compare Value*/
					TMR3->CCR4 = cmpValue;
					break;
				default:
					break;
				}
				break;
			default: 										break;
	}
}

void MTMR_voidSetARR(TMRN_t Copy_uddtTMR_no, u32 Copy_u32Value)
{
	// enabling auto reload pre-load
	SET_BIT(TMR2->CR1,7);
	// set auto reload value
	switch(Copy_uddtTMR_no)
	{
	case TMR_2: /* Set Auto-reload Value*/
		TMR2 -> ARR = Copy_u32Value;
		break;
	case TMR_3: /* Set Auto-reload Value*/
		TMR3 -> ARR = Copy_u32Value;
		break;
	case TMR_4: /* Set Auto-reload Value*/
		TMR4 -> ARR = Copy_u32Value;
		break;
	case TMR_5: /* Set Auto-reload Value*/
		TMR5 -> ARR = Copy_u32Value;
		break;
	default:   							break;
	}
}

/**
 * @brief this function is used to reset count (clear the CNT_REG)
 * 
 * @param Copy_uddtTMR_no timer number [TMR2 - TMR3 - TMR4 - TMR5]
 * @return void
 */
void MTMR_voidClearCount(TMRN_t Copy_uddtTMR_no)
{
	switch(Copy_uddtTMR_no)
	{
	case TMR_2:
		TMR2 -> CNT = 0;
		break;
	case TMR_3:
		TMR3 -> CNT = 0;
		break;
	case TMR_4:
		TMR4 -> CNT = 0;
		break;
	case TMR_5:
		TMR5 -> CNT = 0;
		break;
	default:                               break;
	}
}

/**
 * @brief this function is used to enable the input capture unit - ICU
 * 
 * @param Copy_uddtTMR_no timer number [TMR2 - TMR3 - TMR4 - TMR5]
 */



/*void MTMR_voidEnableICUInt(TMRN_t Copy_uddtTMR_no)
{
	switch(Copy_uddtTMR_no)
	{
	case TMR_2:
		SET_BIT(TMR2 -> DIER, 1);
		break;
	case TMR_3:
		SET_BIT(TMR3 -> DIER, 1);
		break;
	case TMR_4:
		break;
	case TMR_5:
		SET_BIT(TMR5 -> DIER, 1);
		break;
	}
}*/



/**
 * @brief this function is used to select the channel to use as input
 * 
 * @param Copy_uddtTMR_no timer number [TMR2 - TMR3 - TMR4 - TMR5]
 * @param Copy_uddtCH_no Channel number [CH1 ~ CH4]
 */



/*void MTMR_voidSetChannelInput(TMRN_t Copy_uddtTMR_no, CHN_t Copy_uddtCH_no)
{
	switch(Copy_uddtTMR_no)
	{
	case TMR_2:

		break;
	case TMR_3:
		switch(Copy_uddtCH_no)
		{
		case CH1:
			Clr_BITS(TMR3 -> CCMR1, 0x00000003);
			SET_BIT(TMR3 -> CCMR1, CC1S_SHIFT);

			SET_BIT(TMR3 -> CCER, CC1P_BIT);
			SET_BIT(TMR3 -> CCER, CC1NP_BIT);

			SET_BIT(TMR3 -> CCER, CC1EN_BIT);
			break;
		case CH2:
			break;
		case CH3:
			break;
		case CH4:
			break;
		}
		break;
		case TMR_4:
			break;
		case TMR_5:
			switch(Copy_uddtCH_no)
			{
			case CH1:
				Clr_BITS(TMR5 -> CCMR1, 0x00000003);
				SET_BIT(TMR5 -> CCMR1, CC1S_SHIFT);

				SET_BIT(TMR5 -> CCER, CC1P_BIT);
				SET_BIT(TMR5 -> CCER, CC1NP_BIT);

				SET_BIT(TMR5 -> CCER, CC1EN_BIT);
				break;
			case CH2:
				break;
			case CH3:
				Clr_BITS(TMR5 -> CCMR2, 0x00000003);
				SET_BIT(TMR5 -> CCMR2, CC1S_SHIFT);

				SET_BIT(TMR5 -> CCER, CC3P_BIT);
				SET_BIT(TMR5 -> CCER, CC3NP_BIT);

				SET_BIT(TMR5 -> CCER, CC3EN_BIT);
				break;
			case CH4:
				break;
			}
			break;
	}
}*/

/**
 * @brief this function is used to get the value of timer
 * 
 * @param Copy_uddtTMR_no timer number [TMR2 - TMR3 - TMR4 - TMR5]
 * @param Copy_uddtChNo Channel number [CH1 ~ CH4]
 * @return u32  value of timer count
 */


/*u32 MTMR_voidReadCapture(TMRN_t Copy_uddtTMR_no, CHN_t Copy_uddtChNo)
{
	u32 reading = 0;
	switch(Copy_uddtTMR_no)
	{
	case TMR_2:


		break;
	case TMR_3:
		switch(Copy_uddtChNo)
		{
		case CH1:
			reading = TMR3 -> CCR1;
			break;
		case CH2:
			reading = TMR3 -> CCR2;
			break;
		case CH3:
			reading = TMR3 -> CCR3;
			break;
		case CH4:
			reading = TMR3 -> CCR4;
			break;
		}
		break;
		case TMR_5:
			switch(Copy_uddtChNo)
			{
			case CH1:
				reading = TMR5 -> CCR1;
				break;
			case CH2:
				reading = TMR5 -> CCR2;
				break;
			case CH3:
				reading = TMR5 -> CCR3;
				break;
			case CH4:
				reading = TMR5 -> CCR4;
				break;
			}
			break;
			default:            break;
	}
	return reading;
}*/


/*void MTimer3_voidCapture_Compare_Init(void)
{
	DIER Register

	SET_BIT(TMR3 -> DIER , 1);	// Capture/Compare interrupt enable

	CCMR1 Register

	SET_BIT(TMR3 -> CCMR1 , 0);	// configure timer3 ch1 as input
	CLR_BIT(TMR3 -> CCMR1 , 1);

	CLR_BIT(TMR3 -> CCMR1 , 2);	// configure timer3 ch1 to capture at every edge detected
	CLR_BIT(TMR3 -> CCMR1 , 3);


	CLR_BIT(TMR3 -> CCMR1 , 6);
	CLR_BIT(TMR3 -> CCMR1 , 7);

	CCER Register

	SET_BIT(TMR3 -> CCER , 0);	// Capture Enabled


	SET_BIT(TMR3 -> CCER , 1);	// Capture/Compare channel captures on both edges (rising & falling)
	SET_BIT(TMR3 -> CCER , 3);

	TMR_voidSetPrescaler(TMR3,72);

	TMR3 -> ARR = 65535;
}*/


















/*
void TIM2TEST (void)
{
	//enabling auto reload pre-load
	SET_BIT(TMR2->CR1,7);
	//setting prescaler
	TMR2->PSC =63;
	//setting auto reload value
	TMR2->ARR =10000;
	//setting compare match value
	TMR2->CCR1 =2000;
	//choosing compare/capture 1 as o/p
	//TMR2->CCMR1 &= (~3)	;			//maybe problem
	CLR_BIT(TMR2->CCMR1,0);
	CLR_BIT(TMR2->CCMR1,1);

	//enabling o/p compare 1 pre-load
	SET_BIT(TMR2->CCMR1,3);
	//choosing PWM1 mode
	CLR_BIT(TMR2->CCMR1,4);
	SET_BIT(TMR2->CCMR1,5);
	SET_BIT(TMR2->CCMR1,6);
	//setting polarity for compare/capture 1 as high

	//initialize all the registers (important)
	SET_BIT(TMR2->EGR,0);
	//enable compare/capture 1 o/p
	SET_BIT(TMR2->CCER,0);
	//enable timer
	SET_BIT(TMR2->CR1,0);
}
*/




