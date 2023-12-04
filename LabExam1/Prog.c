//#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int element;
typedef struct cell {
	element data;
	struct cell* next;
}*stack;

typedef struct node {
	element data;
	struct node* left, * right;
}*Btree;


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

int top(stack s, element* e) {
	if (isEmptyStack(s))return 0;
	*e = s->data;
	return 1;
}


Btree construct(element e, Btree left, Btree right) {
	Btree b = (Btree)malloc(sizeof(struct node));
	if (!b)return NULL;
	b->data = e;
	b->left = left;
	b->right = right;
	return b;
}

int recursiveBstInsert(Btree* b, int e) {
	if (!(*b)) {
		Btree tmp = construct(e,NULL,NULL);
		*b = tmp;
		return 1;
	}
	if (e > (*b)->data) return recursiveBstInsert(&(*b)->right, e);
	if (e < (*b)->data) return recursiveBstInsert(&(*b)->left, e);
	return 1;
}

void print(stack s) {
	while (s) {
		if (s->next == NULL)
			printf("%d", s->data);
		else
			printf("%d->", s->data);
		s = s->next;
	}
	printf("\n");
}

void path(Btree b, stack* s) {
	if (!b)return;
	push(s, b->data);
	if (b->left == NULL && b->right == NULL)
		print(*s);
	path(b->left , s);
	path(b->right, s);
	pop(s);
}

main() {
	int i, N;
	char a[6];
	element e;
	Btree b=NULL;
	stack s = createStack();
	scanf("%d",&N);

	for (i = 0; i < N; i++) {
		scanf(" ADD %d", &e);
		recursiveBstInsert(&b, e);
	}
	scanf("%s", a);
	if (strcmp(a,"paths")==0)
		path(b, &s);
}