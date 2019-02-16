#include "CircularQueue.h"

/** 
 * \brief 				Function for creating pointer to instance of 
 *					structure MyCircularQueue.
 *					At the beginning the front, rear, currentSize
 *					values are set to default value. size is set by user,
 *					with the input parameter sizeVal.
 * \param[in]				const int16_t sizeVal for size of buffer. 
 * \return 				pointer to instance of structure MyCircularQueue.
 */
 
MyCircularQueue * myCircularQueueCreate(const int16_t sizeVal){
	MyCircularQueue * cirQue = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
	
	cirQue->buffer = (int16_t *)malloc(sizeof(int16_t)*sizeVal);
	
	cirQue->front  = 0;
	cirQue->rear   = -1;
	cirQue->size   = sizeVal;
	cirQue->currentSize = 0;

	return cirQue;	
}


/** 
 * \brief				Function for checking whether queue is empty
 *					or not.
 * \param[in]				Pointer to structure MyCircularQueue
 * \return             		        Enumeration type err_code. SUCCESS if it is ok,
 *					otherwise it is FAILED. 
 */           
err_code myCircularQueueIsEmpty(MyCircularQueue *obj){
	
	return(obj->currentSize == 0 ? SUCCESS : FAILED);

}



/** 
 * \brief				Function for checking whether queue is full
 *					or not.
 * \param[in]				Pointer to structure MyCircularQueue
 * \return              		Enumeration type err_code. SUCCESS if it is ok,
 *					otherwise it is FAILED.        
 */
err_code myCircularQueueIsFull(MyCircularQueue *obj){
	if(obj->currentSize == obj->size){
		return SUCCESS;
	}
	return FAILED;
	
}

/** 
 * \brief				Function for obtaining the front element
 *					of queue.
 * \param[in]				Pointer to structure MyCircularQueue
 * \return             			If queue is empty, return -1. Otherwise,
 *					return the front element.     
 */
int16_t myCircularQueueFront(MyCircularQueue* obj){
	if(myCircularQueueIsEmpty(obj) == SUCCESS){
		return -1;
	}
	else{
		return obj->buffer[obj->front];
	}
	

}

/** 
 * \brief				Function for obtaining the rear element
 *					of queue.
 * \param[in]				Pointer to structure MyCircularQueue
 * \return             			If queue is empty, return -1. Otherwise,
 *					return the rear element.       
 */
int16_t myCircularQueueRear(MyCircularQueue* obj) {
	 if(myCircularQueueIsEmpty(obj) == SUCCESS){
	 	return -1;
	 }
	 return obj->buffer[obj->rear];
    
}

/** 
 * \brief				Function for inserting the element
 *					to the queue.
 * \param[in]				Pointer to structure MyCircularQueue
 * \param[in]          		        value to be inserted.
 * \return             		        If queue is not full, shift the rear element
 *                      		insert the value to new rear position and return
 *					SUCCESS, if it is full, return FAILED.
 *					return the rear element.       
 */
err_code myCircularQueueEnQueue(MyCircularQueue* obj, int value){
	if(!myCircularQueueIsFull(obj)){
		
		obj->rear++;
		
		obj->rear = obj->rear % obj->size;
		obj->buffer[obj->rear] = value;
		
		obj->currentSize++;
		
		return SUCCESS;
	}
	
	return FAILED;
	
}


/** 
 * \brief				Function for deleting the element
 *					from the queue.
 * \param[in]				Pointer to structure MyCircularQueue
 * \return              		If queue is not empty, shift the front element,
 *                      		shrink the current size, return SUCCESS
 *					if it is empty, return FAILED.          
 */
err_code myCircularQueueDeQueue(MyCircularQueue* obj) {
   
    if(!myCircularQueueIsEmpty(obj)){
    	
    	obj->front++;
    	obj->front = obj->front % obj->size;
    	obj->currentSize--;
    	return SUCCESS;
    
    }
    return FAILED;
}


/** 
 * \brief				Function for freeing the memory
 *					allocated by dynamic memory allocation.
 * \param[in]				Pointer to structure MyCircularQueue
 * 					First free the buffer then the instance.
 */
void myCircularQueueFree(MyCircularQueue* obj) {
	 
    free(obj->buffer);
    obj->buffer = NULL;
    free(obj);
    obj = NULL;
}
