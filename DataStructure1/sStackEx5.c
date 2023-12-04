#include "sStackEx5.h"

sstack sCreateStack() {
	sstack s;
	s.top = -1;
	return s;
}

int sPush(sstack*s,element3 e) {
	if (sIsFullStack(*s))return 0;
	//
	if (sIsEmptyStack(*s)) {
		s->max = e;
	}
	else if (e > s->max) {
		s->max = e;
	}
	//
	s->top++;
	s->data[s->top] = e;
	return 1;
}

int sTop(sstack s , element3 *e) {
	if (sIsEmptyStack(s))return 0;
	*e = s.data[s.top];
	return 1;
}

int sPop(sstack *s) {
	if (sIsEmptyStack(*s))return 0;
	s->top--;
	return 1;
}

int sIsEmptyStack(sstack s) {
	return s.top == -1;
}
int sIsFullStack(sstack s) {
	return s.top == N-1;
}

void sPrint(sstack s) {
	element3 e;
	while (sTop(s, &e)) {
		printf("%d ", e);
		sPop(&s);
	}
}

int getMax(sstack s) {
	return s.max;
}