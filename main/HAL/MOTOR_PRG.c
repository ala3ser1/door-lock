/*
 * motor_int.c
 *
 * Created: 4/23/2024 6:46:13 PM
 *  Author: melaa
 */ 

#include "MOTOR_INT.h"
#include "..\CFG\MOTOR_CFG.h"
#include "MOTOR_PRIVATE.h"
#define MOTOR_PIN_NUM 2
RET_T MotorCW(Motor_t motor)
{
	RET_T ret=NOK;
	DIO_Pin_t IN1=(motor*MOTOR_PIN_NUM);
	if((IN1)>=(motornum*MOTOR_PIN_NUM))
	{
		
	}
	else{
		ret=OK;
		DIO_WritePin(MotoArray[IN1],HIGH);
		DIO_WritePin(MotoArray[IN1+1],LOW);
	}
	return ret;
}
RET_T MotorCCW(Motor_t motor)
{
	RET_T ret=NOK;
	DIO_Pin_t IN1=(motor*MOTOR_PIN_NUM);
	if((IN1)>=(motornum*MOTOR_PIN_NUM))
	{
		
	}
	else{
		ret=OK;
		DIO_WritePin(MotoArray[IN1],LOW);
		DIO_WritePin(MotoArray[IN1+1],HIGH);	
	}
	return ret;
}
RET_T MotorStop(Motor_t motor)
{
	RET_T ret=NOK;
	DIO_Pin_t IN1=(motor*MOTOR_PIN_NUM);
	if((IN1)>=(motornum*MOTOR_PIN_NUM))
	{
		
	}
	else{
		ret=OK;
		DIO_WritePin(MotoArray[IN1],LOW);
		DIO_WritePin(MotoArray[IN1+1],LOW);
	}
	return ret;
}