



#include "CircularQueue.h"

int main(){

	/**Create buffer with size of 3 and obtain the pointer
	 * to this instance
	 */
	MyCircularQueue* circularQueue = myCircularQueueCreate(3);
	
	//insert 1, return SUCCESS, since queue is empty
	if(myCircularQueueEnQueue(circularQueue, 1)){
		printf("Succesfull\n");
		printf("%d\n", myCircularQueueFront(circularQueue));
		printf("%d\n", myCircularQueueRear(circularQueue));
	}else{
		printf("Failed\n");
	}
	
	//insert 2, return SUCCESS, since queue is empty
	if(myCircularQueueEnQueue(circularQueue, 2)){  // return true
		printf("Succesfull\n");
		printf("%d\n", myCircularQueueFront(circularQueue));
		printf("%d\n", myCircularQueueRear(circularQueue));
	}else{
		printf("Failed\n");
	}
	
	//insert 3, return SUCCESS, since queue is empty
	if(myCircularQueueEnQueue(circularQueue,3)){
		printf("Succesfull\n");
		printf("%d\n", myCircularQueueFront(circularQueue));
		printf("%d\n", myCircularQueueRear(circularQueue));
	}else{
		printf("Failed\n");
	}
	
	//insert 4, return FAILED, since queue is full
	if(	myCircularQueueEnQueue(circularQueue,4)){
		printf("Succesfull\n");
		printf("%d\n", myCircularQueueFront(circularQueue));
		printf("%d\n", myCircularQueueRear(circularQueue));
	}else{
		printf("Failed\n");
	}
	
	//Check whether it is full or not
	if(myCircularQueueIsFull(circularQueue)){
		printf("Full\n");
	}else{
		printf("Is not full\n");
	}
	
	//Dequeue the front element for inserting new element
	myCircularQueueDeQueue(circularQueue);  
	
	//Insert 7. 
	myCircularQueueEnQueue(circularQueue,7);  
	



}
