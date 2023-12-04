#include<stdio.h>

extern int w;	//variable m3rfeno be file tene wbdna nst3mlo nfso hon mn3mlo extern 
extern void test();	//law ma 3mlnela extern mesh mshkkle, 3lyha warning only ,NO error

typedef int element;
typedef struct node {
	element data;
	struct node* next;
}list;


extern void printList(list* l);
extern void printListRec(list* l);
extern int push(list** head, element e);
extern int addLast(list** l, element e);
extern int removeFirst(list** l);
extern void removeLast(list** l);
extern void addAfter(list** l, list* afterThis, element e);
extern void destroyLL(list* l);

main() {

	list *l=NULL;	//DON'T FORGET to initialize to NULL , Hay badal createStack() wkaza...
	push(&l, 3);
	push(&l, 2);
	push(&l, 1);
	addLast(&l, 4);
	addLast(&l, 5);
	removeLast(&l);
	removeFirst(&l);
	addAfter(&l, l->next, 9);
	printList(l);
	destroyLL(l);
	printList(l);
	/*
	//Testing extern:
	w++;
	printf("%d \n", w);
	//Testing boolean type:
	test();	
	*/
}

