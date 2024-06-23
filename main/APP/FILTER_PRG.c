#include "FILTER_INT.h"
#include "..\HAL\SENSORS_INT.h"
typedef enum{
	FULL,
	EMPTY,
    NOTFULL,
	NOTEMPTY
	
}QUEUE_t;
static u8 filter[SAMPLES_NUM];
s8 front;
s8 rear;
s8 numOfElements=0;
u16 filtersum;
u8 filteravg;
QUEUE_t is_full(void)
{
	QUEUE_t ret;
	if(numOfElements==SAMPLES_NUM)
	{
		ret=FULL;
	}
	else
	{
		ret=NOTFULL;
	}
	return ret;
}
QUEUE_t is_empty(void)
{
	QUEUE_t ret;
	if(numOfElements==0)
	{
		ret=EMPTY;
	}
	else
	{
		ret=NOTEMPTY;
	}
	return ret;
}
void enqueue(u8 data)
{
	if(is_full()==NOTFULL)
	{
		filter[rear++]=data;
		numOfElements++;
		rear=rear%SAMPLES_NUM;
	}
	else
	{
		;/*que is full but in my app I will deque before enq so it will always be no full*/
	}
}
u8 dequeue(void)
{
	u8 ret=0;

	if(is_empty()==NOTEMPTY)
	{
		ret=filter[front++];
		numOfElements--;
		front=front%SAMPLES_NUM;
	}
	else
	{
		;/*que is empty but in my app I will fill all queue before deq so it will always be no full*/
	}
	return ret;
}
void Filter_Inti(void)
{
	while(is_empty()==NOTEMPTY)
	{
		dequeue();
	}
//	enqueue(/*data*/)
	
}

void Filter_Runnable(void)
{
	u8 temp;
	if(is_full()==FULL)
	{
		temp=dequeue();
		filtersum-=temp;
		//temp=/*read*/
		filtersum+=temp;
		enqueue(temp);
	}
	else
	{
		//temp=/*read*/
		filtersum+=temp;
		enqueue(temp);
	}
	filteravg=filtersum/numOfElements;
}


u8 Filter_GetFiltered(void)
{
	return filteravg;
}


RET_T Filter_GetUnfiltered(u8*data)
{
	RET_T ret;
	if(is_empty()==NOTEMPTY)
	{
		*data=dequeue();
		ret =OK;
	}
	else
	{
		ret=NOK;
	}
	return ret;
}

