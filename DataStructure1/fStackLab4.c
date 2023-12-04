#include "fStackLab4.h"
#include <stdlib.h>
#include<stdio.h>

fStack fCreateStack() {
	return NULL;
}

int fIsEmptyStack(fStack s) {
	return (s == NULL);
}

int fPush(fStack* s, element5 e) {
	fStack temp;
	temp = (fStack)malloc(sizeof(struct cell5));
	if (!temp)return 0;
	temp->data = e;
	temp->next = *s;
	*s = temp;
	return 1;
}

int fPop(fStack* s) {
	fStack temp;
	if (fIsEmptyStack(*s))return 0;
	temp = *s;
	*s = (*s)->next;
	free(temp);
	return 1;
}

int fTop(fStack s, element5* e) {
	if (fIsEmptyStack(s))return 0;
	*e = s->data;
	return 1;
}

void fPrintStack(fStack s) {
	while (s) {
		//printf("%.1f ", s->data);
		printf("%c ", s->data);
		s = s->next;
	}
	printf("\n");
}
