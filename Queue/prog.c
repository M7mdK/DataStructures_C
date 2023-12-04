#include<stdio.h>
#include<stdlib.h>
#include "Queue.h"
/*
typedef int element;

typedef struct cell {
	element data;
	struct cell* next;
}*list;

int push(list *l, element e) {
	list temp;
	temp = (list)malloc(sizeof(struct cell));
	if (!temp)return 0;
	temp->data = e;
	temp->next = *l;
	*l = temp;
	return 1;
}

void print(list p) {
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
*/

main() {
	queue q = createQueue();
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	enqueue(&q, 4);
	enqueue(&q, 5);
	printQueue(q);
	printQueue(q);

	/*
	list l = NULL;
	list l2 = NULL;
	list temp;
	list temp2;
	push(&l, 11);
	push(&l, 10);
	push(&l, 3);
	push(&l, 2);
	push(&l, 1);

	push(&l2, 4);
	push(&l2, 5);

	for (temp = l; temp->data != 10; temp = temp->next);
	for (temp2=l2; temp2->next; temp2 = temp2->next);

	temp2->next = temp;
	print(l);
	print(l2);
	*/
}