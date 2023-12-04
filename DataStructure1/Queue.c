#include<stdio.h>
#include<stdlib.h>
#include "Queue.h"
queue createQueue() {
	queue q;
	q.front = q.rear = NULL;
	return q;
}

int enQueue(queue* q, element2 e) {
	struct cell2* tmp;
	tmp = (struct cell2*) malloc(sizeof(struct cell2));
	if (!tmp) return 0;
	tmp->data = e;
	tmp->next = NULL;
	if (q->rear == NULL)
		q->front = q->rear = tmp;
	else {
		q->rear->next = tmp;
		q->rear = tmp;
	}
	return 1;
}

int deQueue(queue* q) {
	struct cell2* tmp;
	if (isEmptyQueue(*q)) return 0;
	tmp = q->front;
	q->front = q->front->next;
	free(tmp);
	if (q->front == NULL)
		q->rear = NULL;
	return 1;
}

int front(queue q, element2* e) {
	if (isEmptyQueue(q)) return 0;
	*e = q.front->data;
	return 1;
}

int isEmptyQueue(queue q) {
	return (q.front == NULL);
}

void printQueue(queue q) {
	while (q.front) {
		printf("%d ", q.front->data);
		q.front = q.front->next;
	}
	printf("\n");
}

//STATIC:
/*
queue createQueue() {
	queue q;
	q.front = 1;
	q.rear = 0;
	return q;
}

int isEmptyQueue(queue q) {
		return q.front == (q.rear + 1)%N;
}

int isFullQueue(queue q) {
	return q.front == (q.rear + 2)%N;
}

int enqueue(queue* q, element e) {
	if (isFullQueue(*q))return 0;
	q->rear = (q->rear + 1) % N;
	q->data[q->rear] = e;
	return 1;
}

int dequeue(queue* q) {
	if (isEmptyQueue(*q))return 0;
	q->front = (q->front +1) % N;
	return 1;
}

int front(queue q , element *e) {
	if (isEmptyQueue(q))return 0;
	*e = q.data[q.front];
	return 1;
}

void printQueue(queue q) {
	element2 e;
	while (front(q, &e)) {
		printf("%d ", e);
		deQueue(&q);
	}
	printf("\n");
}
*/