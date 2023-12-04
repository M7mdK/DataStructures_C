#include<stdio.h>
#include<stdlib.h>
#define N3 10
typedef int element3;
typedef struct node{
	element3 data;
	struct node* next;
}*list;
typedef list hash3[N3];

int hf3(element3 e) {
	return e % N3;
}

void createHash3(hash3 h) {
	int i;
	for (i = 0; i < N3; i++) {
		h[i] = NULL;
	}
}

void printHash3(hash3 h) {
	int i;
	list temp;
	for (i = 0; i < N3; i++) {
		temp = h[i];
		printf("%d   ", i);
		while (temp) {
			printf("%d", temp->data);
			if (temp->next)
				printf("->");
			temp = temp->next;
		}
		printf("\n");
	}
}

int pushList(list *l,element3 e) {
	list temp;
	temp = (list)malloc(sizeof(struct node));
	if (!temp)return 0;
	temp->data = e;
	temp->next =*l;
	*l = temp;
	return 1;
}
int searchList(list l, element3 e) {
	while(l) {
		if (l->data == e)
			return 1;
		l = l->next;
	}
	return 0;
}
int Remove(list* l, element3 e) {
	list temp1, temp2;
	temp1 = *l;
	if (!temp1)return 0;
	if (temp1->data == e) {
			*l = temp1->next;
			free(temp1);
			return 1;
	}
	temp2 = temp1->next;
	while (temp2) {
		if (temp2->data == e) {
			temp1->next = temp2->next;
			free(temp2);
			return 1;
		}
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	return 0;
}