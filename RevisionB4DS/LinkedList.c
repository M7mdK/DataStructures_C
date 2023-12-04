#include <stdio.h>
#include<stdlib.h>
typedef int element;
typedef struct node {
	element data;
	struct node* next;
}list;
//RK: fena n7ota *list men 2sl l typedef 3ade btzbat bas bser bde zabet l prototypes wel declarations t7t

int push(list** head, element e) {
	list *temp = (list*)malloc(sizeof(list));
	if (!temp)return 0;
	temp->data = e;
	temp->next = *head;
	*head = temp;
	return 1;
}
void printList(list* l) {
	for (; l; l=l->next) {
			printf("%d ", l->data);
	}
}
void printListRec(list *l) {
	if (l) {
		printf("%d ", l->data);
		printListRec(l->next);
	}
}

int addLast(list** l, element e) {
	if (!(*l))push(l, e);
	list* t = *l;
	list* temp = (list*)malloc(sizeof(list));
	if (!temp)return 0;
	temp->data = e;
	temp->next = NULL;
	for (; t->next; t = t->next);
	t->next = temp;
	return 1;
}

void addAfter(list**l , list*afterThis , element e) {
	if (!afterThis) {
		push(l, e);
		return;
	}
	list* temp = (list*)malloc(sizeof(list));
	temp->data = e;
	temp->next = afterThis->next;
	afterThis->next = temp;
}

void removeFirst(list** l) {
	if (*l) {
		list* temp = *l;
		*l = (*l)->next;
		free(temp);
	}
}

void removeLast(list** l) {
	if ((*l)->next == NULL) {
		removeFirst(l);
		return;
	}
	list* temp1, * temp2;
	temp1 = *l;
	temp2 = (*l)->next;
	while (temp2->next) {
		temp1 = temp2;
		temp2 = temp2->next;
	}
	temp1->next = NULL;
	free(temp2);
}

void destroyLL(list** l) {
	list *temp;
	while (*l) {
		temp = *l;
		(*l) = (*l)->next;
		free(temp);
	}
}