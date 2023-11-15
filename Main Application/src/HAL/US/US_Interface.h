/*
 * US_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: omara
 */

#ifndef HAL_US_US_INTERFACE_H_
#define HAL_US_US_INTERFACE_H_

typedef enum
{
	FORWARD_US=1,
	LEFT_US,
	RIGHT_US,
	last_US
}USNUM_t;




void HUS_voidInit(void);
f32 HUS_f32CalcDistance (USNUM_t A_USNUM_t_Ultrasonic_Num);


#endif /* HAL_US_US_INTERFACE_H_ */
