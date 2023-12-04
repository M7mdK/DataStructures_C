#include<stdio.h>
#include<stdlib.h>
#include "Queue.h"
Queue createQueue() {
	Queue q;
	q.front = q.rear = NULL;
	return q;
}

int enQueue(Queue* q, element e) {
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

int deQueue(Queue* q) {
	struct cell2* tmp;
	if (isEmptyQueue(*q)) return 0;
	tmp = q->front;
	q->front = q->front->next;
	free(tmp);
	if (q->front == NULL)
		q->rear = NULL;
	return 1;
}

int front(Queue q, element* e) {
	if (isEmptyQueue(q)) return 0;
	*e = q.front->data;
	return 1;
}

int isEmptyQueue(Queue q) {
	return (q.front == NULL);
}
