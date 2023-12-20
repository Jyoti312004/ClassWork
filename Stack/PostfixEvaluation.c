#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int rear;
    int arr[100];
} MyQueue;
MyQueue q;


MyQueue* myQueueCreate() {
    q.rear = -1;
    return &q;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->rear = obj->rear + 1;
    obj->arr[obj->rear] = x;
    
}

int myQueuePop(MyQueue* obj) {
    int val = obj->arr[0];
    for(int i=1;i<=obj->rear;i++){
        obj->arr[i-1] = obj->arr[i];
    }

    obj->rear= obj->rear - 1;
    return val;
    
}

int myQueuePeek(MyQueue* obj) {
    return obj->arr[0];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->rear==-1?true:false;
}

void myQueueFree(MyQueue* obj) {
    obj->rear = -1;
    
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/