
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int queue[1000];
    int front;
    int rear;
    int size;
} MyCircularQueue;
MyCircularQueue q;


MyCircularQueue* myCircularQueueCreate(int k) {
    q.front = -1;
    q.rear = -1;
    q.size = k;
    return &q;

}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return (obj->front==-1)?true:false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (((obj->rear+1)%obj->size)==obj->front);
    
}

int myCircularQueueFront(MyCircularQueue* obj) {

    if(myCircularQueueIsEmpty(obj)==true){
        return -1;
    }
    return (obj->queue[obj->front]);
}

int myCircularQueueRear(MyCircularQueue* obj) {

    if(myCircularQueueIsEmpty(obj)==true){
        return -1;
    }
    return (obj->queue[obj->rear]);
}




bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if( myCircularQueueIsFull(obj)){
        return false;
    }
    if(obj->front == -1 && obj->rear == -1){
        obj->rear=obj->rear+1;
        obj->front = 0;
        obj->queue[obj->rear] = value;
        return true;
    }
    obj->rear = (obj->rear+1)%obj->size;
    obj->queue[obj->rear] = value;
    return true;
   

    
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)==true){
        return false;
    }
    if(obj->front == obj->rear){
        obj->front = -1;
        obj->rear = -1;
        return true;
    }
    obj->front = (obj->front+1)%obj->size;
    return true;
}



void myCircularQueueFree(MyCircularQueue* obj) {
    obj->front = -1;
    obj->rear = -1;
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/