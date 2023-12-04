#include "Stack.h"
#include <stdlib.h>
#include<stdio.h>

stack createStack() {
	return NULL;
}

int isEmptyStack(stack s) {
	return (s == NULL);
}

int push(stack* s, element1 e) {
	stack temp;
	temp = (stack)malloc(sizeof(struct cell1));
	if (!temp)return 0;
	temp->data = e;
	temp->next = *s;
	*s = temp;
	return 1;
}

int pop(stack* s) {
	stack temp;
	if (isEmptyStack(*s))return 0;
	temp = *s;
	*s = (*s)->next;
	free(temp);
	return 1;
}

int top(stack s, element1 *e) {
	if (isEmptyStack(s))return 0;
	*e = s->data;
	return 1;
}

int stackSize(stack s) {
	if (isEmptyStack(s))
		return 0;
	pop(&s);
	return 1 + stackSize(s);
}

void printStack(stack s) {
	while (s) {
		printf("%d ", s->data);
		s = s->next;
	}
	printf("\n");
}

void printStackRec(stack s) {
	if (s) {
		printf("%d ", s->data);
		printStackRec(s->next);
	}
	if (!s)
		printf("\n");
}
/*
//Static:
stack createStack() {
	stack s;
	s.top = -1;
	return s;
}
int push(stack* p, element1 e) {
	if (isFullStack(*p)) return 0;
	p->top += 1;
	p->data[p->top] = e;
	return 1;
}
int pop(stack* p) {
	if (isEmptyStack(*p)) return 0;
	p->top -= 1;
	return 1;
}
int top(stack p, element1* e) {
	if (isEmptyStack(p)) return 0;
	*e = p.data[p.top];
	return 1;
}
int isEmptyStack(stack p) {
	return (p.top == -1);
}
int isFullStack(stack p) {
	return (p.top == N2 - 1);
}
void printStack(stack s){
	element1 e;
	while (top(s, &e)) {
		printf("%d ", e);
		pop(&s);
	}
	printf("\n");
}
*/