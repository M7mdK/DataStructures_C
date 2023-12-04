#include"Type_Queue.h"
#include<stdlib.h>
#include<stdio.h>

extern queue createQueue();
extern int isEmptyQueue(queue q);
extern int isFullQueue(queue q);
extern int enqueue(queue* q, element e);
extern int dequeue(queue* q);
extern int front(queue q, element* e);
extern void printQueue(queue q);