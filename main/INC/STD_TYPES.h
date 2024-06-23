#ifndef STD_TYPES_H_
#define STD_TYPES_H_
typedef unsigned int u16;
typedef signed int   s16;
typedef signed char  s8;
typedef unsigned char u8;
typedef unsigned long long int u32;
typedef signed long long int s32;
typedef unsigned char* pu8;
typedef signed char*  ps8;
typedef unsigned int* pu16;
typedef signed int*   ps16;
typedef unsigned long long int* pu32;
typedef signed long long int* ps32;



typedef union{
	u8 byte;
	struct{
		u8 b0:1;
		u8 b1:1;
		u8 b2:1;
		u8 b3:1;
		u8 b4:1;
		u8 b5:1;
		u8 b6:1;
		u8 b7:1;
	};

}BIT_T;
#define F_CPU 8000000
#include <util/delay.h>



typedef enum{
	OK=0X55,
	NOK=0XAA,
	INPROGRESS
}RET_T;


#define SET_BIT(x,y) ((x)=((x)|(1<<(y))))
#define CLR_BIT(x,y) ((x)=((x)&(~(1<<(y)))))
#define GET_BIT(x,y) (((x)>>(y))&1)
#define TOG_BIT(x,y) ((x)=((x)^(1<<(y))))
#define ROTAT_R(x,y) ((x)=((x)<<y)|((x)>>(8-(y))))
#define ROTAT_L(x,y) ((x)=((x)>>y)|((x)<<(8-(y))))


#endif /* STD_TYPES_H_ */