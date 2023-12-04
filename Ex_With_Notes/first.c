#include<stdio.h>
#include<stdlib.h>
//NOTES:
/*
metel ma fe 2oset pass by value w pass by address lal variables
same story for pointers:
la23ml pass by address bade double pointer layol2atle l pointer l2sle wbmare2 lal function ldouble pointer
*/

/*
2oset l call lal funtions lbye5do pointers as parameters, example:
void ft(int **q)...
Bel main lezem da5el address la yol2ato l double pointer q
*/

/*
VERRRRRYYY IMPORTANTTTT:
ma ten8ash be shakl void ft(int **q), hayda double pointer q mesh **q (y3ni mano l variable akid),
so bas badna n3ml call bade 3tee shi equivelent 3ala double pointer q y3ni masalan &p (where int *p;)
*/

/*
NOTE THAT:
Queue ma feha pointer be 2asas typedef bas stack feha 
*/

/*
7ata law typedef b2lbo pointer metel l stack bel she8el ma byefro2 lmawdo3, bas definition w declaration lbyfr2o
*/

typedef int element;
typedef struct cell {
	element data;
	struct cell* next;
}*stack;

stack createStack() {
	return NULL;
}

int isEmptyStack(stack s) {
	return s == NULL;
}

int push(stack* p, element data) {	//p heye double pointer 3ala l pointer s
	stack temp;
	temp = (stack)malloc(sizeof(struct cell));
	if (!temp)return -1;
	temp->data = data;
	temp->next = *p;
	*p = temp;
	return 1;
}

int pop(stack *p) {
	stack temp;
	if (isEmptyStack(*p))
		return 0;
	temp = *p;
	*p = (*p)->next;
	free(temp);
	return 1;
}

int top(stack s , element *e) {
	if (isEmptyStack(s))return 0;
	*e = s->data;
	return 1;
}

void print(stack p) {
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void printrec(stack p) {
	if (p) {
		printf("%d ", p->data);
		printrec(p->next);
	}
}
///////////////////////////////////////////////////
//HODI 8ALAT MA BYMSHI L7AL HEK BDAYE3 L STACK
/*void print2(stack s){
	element e;
	while (top(s, &e)) {
		printf("%d", e);
		pop(&s);}}
void printrec2(stack s){
	element e;
	if (top(s, &e)) {
		printf("%d ",e);
		pop(&s);
		printrec2(s);}}*/
//////////////////////////////////////////////////


//Second:
//S2 m2loobeen b2lbo we will solve it beljeed
/*stack removeOdd(stack s) {
	stack s2 = createStack();
	element e;
	while (top(s, &e)) {
		if (e % 2 == 0) 
			push(&s2, e);
		pop(&s);
	}
	return s2;
}*/
void removeOdd(stack* s) {

}

void recRemoveOdd(stack *s) {
	element e;
	if (top(*s, &e)) {
		pop(s);
		recRemoveOdd(s);
		if(e%2==0)
			push(s, e);
	}
}

main() {
	element e;
	stack s = createStack();
	push(&s, 10);
	push(&s, 0);
	push(&s, -20);
	push(&s, 57);
	push(&s, 7);
	push(&s, 5);
	printrec(s);
	printf("\n");
	pop(&s);
	print(s);
	/*
	stack s2 = removeOdd(s);
	print(s2);

	recRemoveOdd(&s);
	print(s);*/
}