/*
 * MOTOR_INT.h
 *
 * Created: 4/23/2024 6:47:11 PM
 *  Author: melaa
 */ 


#ifndef MOTOR_INT_H_
#define MOTOR_INT_H_
#include "..\INC\STD_TYPES.h"
#include "..\MCAL\DIO_INT.h"
#include "..\CFG\MOTOR_CFG.h"
typedef enum{
	MOTOR0,
	MOTOR1,
	MOTOR2,
	MOTOR3,
	MOTOR4,
	MOTOR5,
	MOTOR6,
	MOTOR7,
	MOTOR8,
	MOTOR9,
	MOTOR10,
	MOTOR11,
	MOTOR12,
	MOTOR13,
	MOTOR14,
	MOTOR15,
	MOTOR16,
	MOTOR17,
	MOTOR18,
	MOTOR19,
	MOTOR20,
	MOTOR21,
	MOTOR22,
	MOTOR23,
	MOTOR24,
	MOTOR25,
	MOTOR26,
	MOTOR27,
	MOTOR28,
	MOTOR29,
}Motor_t;

extern const DIO_Pin_t MotoArray[MOTOR_ARR];
extern const u8 motornum;
RET_T MotorCW(Motor_t motor);
RET_T MotorCCW(Motor_t motor);
RET_T MotorStop(Motor_t motor);



#endif /* MOTOR_INT_H_ */