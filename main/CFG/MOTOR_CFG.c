/*
 * MOTOR_CFG.c
 *
 * Created: 4/23/2024 6:48:07 PM
 *  Author: melaa
 */ 
#include "MOTOR_CFG.h"
#include "..\HAL\MOTOR_INT.h"


const u8 motornum=MOTOR_NUM;

const DIO_Pin_t MotoArray[MOTOR_ARR]={
	PINB0,/* in1 for motor0*/
	PINB1,/* in2 for motor0*/
// 	PIND2,/* in1 for motor1*/
// 	PIND3,/* in2 for motor1*/
// 	PIND4,/* in1 for motor2*/
// 	PIND5,/* in2 for motor2*/
// 	PIND6,/* in1 for motor3*/
// 	PIND7 /* in2 for motor3*/
};
	
	
	
	
