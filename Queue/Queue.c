#include "Queue.h"
queue createQueue() {
	queue q;
	q.front = q.rear = NULL;
	return q;
}

isEmptyQueue(queue q) {
	return q.front ==NULL;
}

int enqueue(queue* q, element e) {
	node* temp;
	temp = (node*)malloc(sizeof(node));
	if (!temp)return 0;
	temp->data = e;
	temp->next = NULL;
	if (q->rear == NULL)
		q->rear = q->front = temp;
	else {
		q->rear->next = temp;
		q->rear = temp;
	}
	return 1;
}

int dequeue(queue* q) {
	node* temp;
	if (isEmptyQueue(*q))return 0;
	temp = q->front;
	q->front = q->front->next;
	if (q->front->next == NULL)
		q->rear = NULL;
	free(temp);
	return 1;
}

int front(queue q, element* e) {
	if (isEmptyQueue(q))return 0;
	*e = q.front->data;
	return 1;
}

void printQueue(queue q) {
	while(q.front){
		printf("%d ", q.front->data);
		q.front = q.front->next;
	}
	printf("\n");
}

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
	element e;
	while (front(q, &e)) {
		printf("%d ", e);
		dequeue(&q);
	}
	printf("\n");
}*/