#include "Stack.h"
#include <stdlib.h>
#include<stdio.h>

stack createStack() {
	return NULL;
}

int isEmptyStack(stack s) {
	return (s == NULL);
}

int push(stack* s, element e) {
	stack temp;
	temp = (stack)malloc(sizeof(struct cell));
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

int top(stack s, element *e) {
	if (isEmptyStack(s))return 0;
	*e = s->data;
	return 1;
}


void print(stack s) {
	while (s) {
		printf("%d ", s->data);
		s = s->next;
	}
	printf("\n");
}

void printrec(stack s) {
	if (s) {
		printf("%d ", s->data);
		printrec(s->next);
	}
	if (!s)
		printf("\n");
}