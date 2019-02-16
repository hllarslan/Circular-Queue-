/* Author : Halil Arslan
 * Date   : 24-01-2019
 * Topic  : Simple CircularQueue 
 */ 

#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

//Enumeration for err_code.
typedef enum {
	FAILED,			//FAILED for 0
	SUCCESS			//SUCCESS for
}err_code;

// Structure for CircularQueue 
typedef struct {
	int16_t  front;				 //Data to show index of front data
	int16_t  rear;			 	 //Data to show index of rear data
	int16_t  *buffer;		 	 //Buffer for holding given size of data
	int16_t  size;				 //The total size given by user
	int16_t  currentSize; 		 //The current size
}MyCircularQueue;


MyCircularQueue * myCircularQueueCreate(const int16_t sizeVal);


err_code myCircularQueueIsEmpty(MyCircularQueue *obj);


err_code myCircularQueueIsFull(MyCircularQueue *obj);


int16_t myCircularQueueFront(MyCircularQueue* obj);


int16_t myCircularQueueRear(MyCircularQueue* obj);


err_code myCircularQueueEnQueue(MyCircularQueue* obj, int value);


err_code myCircularQueueDeQueue(MyCircularQueue* obj);


void myCircularQueueFree(MyCircularQueue* obj); 


#endif
