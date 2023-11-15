/*
 * DCM_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: omara
 */

#ifndef HAL_DCM_DCM_INTERFACE_H_
#define HAL_DCM_DCM_INTERFACE_H_

void MOTOR_VoidInit();
void MOTOR_voidStart(void);
void MOTOR_Move();
void MOTOR_Stop();
void MOTOR_chanelStop(u8 Copy_u8Chanel);
void MOTOR_chanelStart(u8 Copy_u8Chanel);
void MOTOR_Forward();
void MOTOR_Backward();
void MOTOR_Right();
void MOTOR_Lift();
void MOTOR_Park();
void MOTOR_Park1();
void MOTOR_AllchanelStop();










#endif /* HAL_DCM_DCM_INTERFACE_H_ */
