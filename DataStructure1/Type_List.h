typedef int element;
typedef struct node {
	element data;
	struct node* next;
}list;
//RK: fena n7ota *list men 2sl l typedef 3ade btzbat bas bser bde zabet l prototypes wel declarations t7t

int pushL (list** head, element e) {
	list* temp = (list*)malloc(sizeof(list));
	if (!temp)return 0;
	temp->data = e;
	temp->next = *head;
	*head = temp;
	return 1;
}
void printList(list* l) {
	for (; l; l = l->next) {
		printf("%d ", l->data);
	}
	printf("\n");
}
/*
void printListRec(list* l) {
	if (l) {
		printf("%d ", l->data);
		printListRec(l->next);
	}
	printf("\n");
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

void addAfter(list** l, list* afterThis, element e) {
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
*/

//FOR LAB3 EX1:

list* createNode(element data) {
	list* l = (list*)malloc(sizeof(list));
	if (!l)return NULL;
	l->data = data;
	l->next = NULL;
	return l;
}

void addNode(list** l, struct node* nd) {
	list* temp;
	temp = *l;
	if (!temp) {
		*l = nd;
		return;
	}
	for (; temp->next; temp = temp->next);
	temp->next = nd;
}

typedef struct node* element4;
typedef struct cell4 {
	element4 data;
	struct cell4* next;
}*lstack;


lstack lcreateStack() {
	return NULL;
}

int lisEmptyStack(lstack s) {
	return (s == NULL);
}

int lpush(lstack* s, element4 e) {
	lstack temp;
	temp = (lstack)malloc(sizeof(struct cell4));
	if (!temp)return 0;
	temp->data = e;
	temp->next = *s;
	*s = temp;
	return 1;
}

int lpop(lstack* s) {
	lstack temp;
	if (lisEmptyStack(*s))return 0;
	temp = *s;
	*s = (*s)->next;
	free(temp);
	return 1;
}

int ltop(lstack s, element4* e) {
	if (lisEmptyStack(s))return 0;
	*e = s->data;
	return 1;
}
/*
void lprintStack(lstack s) {
	while (s) {
		printf("%d ", s->data->data);
		s = s->next;
	}
	printf("\n");
}*/