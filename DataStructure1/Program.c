#include<stdio.h>
#include<stdlib.h>
#include"Stack.h"
#include "Queue.h"
#include "sStackEx5.h"
#include "Type_List.h"
#include "fStackLab4.h"
/*NOTES:
	stack howi 3ebara 3an linkedList (Set of nodes bedelo 3ala ba3d w fe pointer head bedel 3ala 2awal node)(RK: s howi l head)
	&s howi l address lal pointer head 3ala l stack (l address la2elo howi ka variable of type pointer)
	s howi l address la 2awal node of the linkedList in the memory (y3ni howi l value l3am yol2ato l pointer)
	*s bewaselne 3ala 2awal node of the LinkedList  (2ni laa2et l node bel *s , y3ni Top of the stack is (*s)->data) 
	**s heye 2awal node bel LinkedList (Heye sha5seyan y3ni mesh pointer 3lyha) [We are not interested]
*/

//Solving Stack&Queue assignment:
//Ex1: The implemantation and:

stack createTestStack() {
	stack s = createStack();
	push(&s, 10);
	push(&s,  0);
	push(&s, -20);
	push(&s, 57);
	push(&s, 7);
	push(&s, 5);
	return s;
}

void insertSorted(stack* s, element1 e) {
	element1 e1;
	if (!top(*s, &e1) || e1 <= e) {
		push(s, e);
		return;
	}
	pop(s);	//pop btshayek 3ala case l empty stack la7ala so ma fe de3e shayek 2ni
	insertSorted(s, e);
	push(s, e1);
}

//Ex2:
//iterative:
void filterOdd(stack *s) {
	element1 e;
	stack s2 = createStack();
	while (top(*s, &e)) {
		pop(s);
		if (e % 2 == 0)
			push(&s2, e);
	}
	while (top(s2, &e)) {
		pop(&s2);
		push(s, e);
	}
}
//Recursive:
void filterOddRec(stack *s) {
	element1 e;
	if (!isEmptyStack(*s)) {
		top(*s, &e);
		pop(s);
		filterOddRec(s);
		if (e % 2 == 0)
			push(s, e);
	}
}

//Ex3:
//iterrative
void sortStack(stack *s) {
	if (isEmptyStack(*s))return;
	stack s2 = createStack();
	stack s3 = createStack();
	element1 e,e2;
	top(*s, &e);
	pop(s);
	push(&s2, e);
	while (top(*s, &e)) {	//lfekra hon ka2ene 3am b3ml insertSorted 3ala s2 (kan feye st5dem l ft)
		pop(s);
		while (top(s2, &e2) && e2 < e) {
			pop(&s2);
			push(&s3, e2);
		}
		push(&s2, e);
		while (top(s3, &e2)) {
			pop(&s3);
			push(&s2, e2);
		}
	}
	while (top(s2, &e)) {
		pop(&s2);
		push(s, e);
	}
}
//Recursive:
/*
VERY IMP:
temporary stack lb3mlo be recursive function howi bel7a2e2a 3ebara 3an n stacks not a single stack... la2n kel ft 3am t3ml new stack
so ma feye st5dmo as if howi common between all the fts... 
feye stafeed meno be 7ale w7de eno 5alee yse3ed l stack l2sle btre2a m3ayani while we are in the same funtion w2erja3 fadee 2bl ma 2ente2el
3ala next funtion, otherwise ra7 yde3 l current temporary stack wyeje wa7ad fadi jded ma7alo bel next ft
(y3ni 2ejbere bel unwinding n3ml push back 3ala l stack l2sle lm2at3eeno bel ft,ma byenfa3 3ala temp stack)
EXAMPLE OF THE IDEA IS sortStackRec:
*/
void sortStackRec(stack* s) {
	element1 e, e2;
	stack s2 = createStack();
	if (isEmptyStack(*s))return;
	top(*s, &e);
	pop(s);
	sortStackRec(s);
	//insertSorted(s, e);
	while (top(*s, &e2) && e < e2) {
		push(&s2, e2);
		pop(s);
	}
	push(s, e);
	while (top(s2, &e2)) {
		push(s, e2);
		pop(&s2);
	}
}
//Ex4:
//iterative:
void reverseStack(stack *s){
	element1 e;
	stack s2 = createStack();
	stack s3 = createStack();
	while (top(*s, &e)) {
		pop(s);
		push(&s2, e);
	}
	while (top(s2, &e)) {
		pop(&s2);
		push(&s3, e);
	}
	while (top(s3, &e)) {
		pop(&s3);
		push(s, e);
	}
}
//Recursive:
/*VERY IMPORTANT REMARK:
l2shya lm7taaj 23mala intialize b2lb recursive funtion lmfrood 2esta5dema b3d recursive call lastafeed mena
2ama 2bl recursive call ra7 tdal kel mara t3ml intialize fa ra7 tayer values l2dama
y3ni bel recursive funtion ma feye 7aafez 3ala shi b2lb l funtion 2ela lbekono bel memory wbst5demon b3d recursive call
*/

void reverseStackRec(stack* s) {
	stack s2 = createStack();
	element1 e,e2;
	if (isEmptyStack(*s))return;
	top(*s, &e);
	pop(s);
	reverseStackRec(s);
	while (top(*s, &e2)) {
		push(&s2, e2);
		pop(s);
	}
	push(s, e);
	while (top(s2, &e2)) {
		push(s, e2);
		pop(&s2);
	}
}

//EX6:
int isWF(char *f) {
	stack s = createStack();
	int i;
	for (i = 0;f[i]!='\0'; i++) {
		if (f[i] == '(')
			push(&s, f[i]);
		if (f[i] == ')') {
			if (!isEmptyStack(s))
				pop(&s);
			else
				return 0;
		}
	}
	if(isEmptyStack(s))
		return 1;
	return 0;
}

//EX8-a
void insertBottom(stack* s, element1 e) {
	element1 temp;
	if (isEmptyStack(*s)) {
		push(s, e);
		return;
	}	
	top(*s, &temp);
	pop(s);
	insertBottom(s, e);
	push(s, temp);
}

//EX9:
queue createTestQueue() {
	queue q = createQueue();
	enQueue(&q, 14);
	enQueue(&q,13);
	enQueue(&q, 7);
	enQueue(&q, -2);
	enQueue(&q, 5);
	enQueue(&q, 10);
	return q;
}

//EX10:
void reverseQueue(queue* q) {
	element2 e;
	if (front(*q, &e)) {
		deQueue(q);
		reverseQueue(q);
		enQueue(q, e);
	}
}

//EX12:
void moveSQ(stack* s, queue* q) {
	element1 e;
	if (top(*s, &e)) {
		pop(s);
		enQueue(q, e);
		moveSQ(s, q);
	}
}

void moveQS(queue* q, stack* s) {
	element2 e;
	if (front(*q, &e)) {
		deQueue(q);
		moveQS(q, s);
		push(s, e);
	}
}

void mergeStacks(stack* s1, stack* s2) {
	element1 e;
	if (top(*s1, &e)) {
		pop(s1);
		mergeStacks(s1, s2);
		push(s2, e);
	}
}

void reverseQueueIter(queue* q) {
	element2 e;
	stack s = createStack();
	while (front(*q, &e)) {
		deQueue(q);
		push(&s, e);
	}
	while (top(s, &e)) {
		pop(&s);
		enQueue(q, e);
	}
}
void reverseStackIter(stack* s) {
	queue q = createQueue();
	element2 e;
	while (top(*s, &e)) {
		pop(s);
		enQueue(&q, e);
	}
	while (front(q, &e)) {
		deQueue(&q);
		push(s, e);
	}
}



//Dawraat Partial:
//2015-2016:
//EX3: sort distinct elements of queue , Even in same order at beginnig and Odd in reverse order at the end of the queue
void sortEvenOdd(queue* q) {
	queue q1 = createQueue();
	stack s = createStack();
	element e;
	while (front(*q, &e)) {
		deQueue(q);
		if (e % 2 == 0)
			enQueue(&q1, e);
		else
			push(&s, e);
	}
	while (front(q1, &e)) {
		deQueue(&q1);
		enQueue(q, e);
	}
	while (top(s, &e)) {
		pop(&s);
		enQueue(q, e);
	}
}



//LAB3:
//EX1:
//address of the point of intersection in inter
//nodes before intersection in both lists int c1 and c2
void listIntersection(list* l1, list* l2, struct node **inter , int* c1, int *c2) {
	element4 e1, e2;
	lstack s1 = lcreateStack();
	lstack s2 = lcreateStack();
	while (l1) {
		lpush(&s1, l1);
		l1 = l1->next;
	}
	while (l2) {
		lpush(&s2, l2);
		l2 = l2->next;
	}
	while (ltop(s1, &e1) && ltop(s2, &e2) && e1 == e2) {
		*inter = e1;
		lpop(&s1);
		lpop(&s2);
	}
	while (!lisEmptyStack(s1)) {
		(*c1)++;
		lpop(&s1);
	}
	while (!lisEmptyStack(s2)) {
		(*c2)++;
		lpop(&s2);
	}
}
//EX2:
void sortDecArray(int A[] , int n) {
	element1 e;
	stack s1 = createStack();
	stack s2 = createStack();
	int i;
	if (n > 0)
		push(&s1, A[0]);
	for (i = 1; i < n; i++) {
		while (top(s1, &e) && e > A[i]) {
			pop(&s1);
			push(&s2, e);
		}
		push(&s1, A[i]);
		while (top(s2, &e)) {
			pop(&s2);
			push(&s1, e);
		}
	}
	for (i = 0; i < n; i++) {
		top(s1, &e);
		pop(&s1);
		A[i] = e;
	}
}
void printArray(int A[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}

//LAB4:
//EX1:
//RK: HON element5 is float 

int isDigit(char c)
{
	return (c >= '0' && c <= '9');
}
float toDigit(char c)
{
	return (float)(c - '0');
}
float power(float X, float M)
{
	if (M == 0) return 1;
	if (M < 0) return (float) 1.0 / power(X, -M);
	return X * power(X, M - 1);
}
float operation(float nb1, char c, float nb2)
{
	switch (c)
	{
	case '+': return nb1 + nb2;
	case '-': return nb1 - nb2;
	case '*': return nb1 * nb2;
	case '/': return nb1 / nb2;
	case '$': return power(nb1, nb2);
	case '#': return -nb1;
	}
}

float result(char*exp) {
	fStack s = fCreateStack();
	int i;
	float e1, e2, r;
	for (i = 0; exp[i] != '\0'; i++) {
		if (isDigit(exp[i]))
			fPush(&s, toDigit(exp[i]));

		if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '$' || exp[i] == '#') {
			if (exp[i] == '#') {
				fTop(s, &e1);
				fPop(&s);
				r = operation(e1, exp[i], 0);
				fPush(&s, r);
			}
			else {
				fTop(s, &e1);
				fPop(&s);
				fTop(s, &e2);
				fPop(&s);
				r = operation(e2, exp[i], e1);	//Be careful e2 then e1 see the algorithm and the ft operation
				fPush(&s, r);
			}
		}
	}
	fTop(s, &r);
	return r;
}

//EX2:
//RK: HON element5 is char 
int isOperator(char c) {
	return (c == '*' || c == '-' || c == '/' || c == '+' || c == '$' || c == '#' || c == ')' || c == '(');
}

int stackable(char o1, char o2) {
	//o2 is the operation in the top of the stack (y3ni the one before l3am b3mla push lheye o1)
	//periority: # , $ , * / , + - , (
	//belnesbe la ')' n7na ma mn3mlo push 2slan...bas lama ybayen bade 2eem kel shi la le2e 2awal '(' b2emo kaman wbfel
	//lama t3ml return 1 y3ni push to the stack , eza return 0 motar dal 23ml top pop layotla3le return 1
	switch (o1)
	{
	case '(': return 1;
	case '+': case '-': return (o2 == '(');
	case '*':case '/': return (o2 == '(' || o2 == '+' || o2 == '-');
	case '$': return (o2 != '#' && o2 != '$');
	case '#': return (o2 != '#');
	case ')': return (o2 == '(');
	}
}

void inToPost(char * in , char* post) {	//infix to postfix
	int i,j=0;
	char e;
	fStack s = fCreateStack();
	for (i = 0; in[i] != '\0'; i++) {
		if (isDigit(in[i])) {
			post[j] = in[i];
			j++;
		}
		else if (isOperator(in[i])) {
			if (fIsEmptyStack(s))
				fPush(&s, in[i]);
			else {
				while (fTop(s,&e) && !stackable(in[i], e)) {
					post[j] = e;
					j++;
					fPop(&s);
				}
				if (in[i] == ')') {
					if (fIsEmptyStack(s)) {
						printf("Wrong expression \n");
						return;
					}
					fPop(&s);	//poping the '('
				}
				else
					fPush(&s, in[i]);
			}
		}
		else {
			printf("only digits and operators are allowed \n");
			return;
		}
	}
	while (fTop(s, &e)) {
		fPop(&s);
		post[j] = e;
		j++;
	}
}
/*
void filterOdd1(stack* s) {
	element1 e;
	stack s2 = createStack();
	while (top(*s, &e)) {
		pop(s);
		if (e % 2 == 0)
			push(&s2, e);
	}
	while (top(s2, &e)) {
		pop(&s2);
		push(s, e);
	}
}
void filterOdd2(stack s) {
	element1 e;
	stack s2 = createStack();
	while (top(s, &e)) {
		pop(&s);
		if (e % 2 == 0)
			push(&s2, e);
	}
	while (top(s2, &e)) {
		pop(&s2);
		push(&s, e);
	}
}

void filterOddRec1(stack* s) {
	element1 e;
	if (!isEmptyStack(*s)) {
		top(*s, &e);
		pop(s);
		filterOddRec1(s);
		if (e % 2 == 0)
			push(s, e);
	}
}
void filterOddRec2(stack s) {
	element1 e;
	if (!isEmptyStack(s)) {
		top(s, &e);
		pop(&s);
		filterOddRec2(s);
		if (e % 2 == 0)
			push(&s, e);
	}
}
*/

void destroyStack(stack* s) {
	while(!isEmptyStack(*s))
		pop(s);
}

main(){
	stack s = createStack();
	push(&s, 1);
	push(&s, 6);
	push(&s, 7);
	push(&s, 9);
	push(&s, 5);
	printStack(s);
	//reverseStack1(s);
	printStack(s);
	destroyStack(&s);
	printStack(s);

	/*
	//infix to postfix , then postfix to result value
	int i;
	char postfix[30];
	char infix[] = "((6-(2+3))*(3+8/2))$2+3";
	inToPost(infix, postfix);
	for (i = 0; postfix[i] != '\0'; i++) {
		printf("%c", postfix[i]);
	}
	*/
	/*
	char exp[] = "623+-382/+*2$3+";
	char* exp2 = "723+##2$-";
	printf("result is: %.1f \n", result(exp));
	printf("2nd result is: %.1f", result(exp2));
	*/
	/*
	fStack s = fCreateStack();
	element5 e;
	fPush(&s, 1.5);
	fPush(&s, 2.5);
	fPush(&s, 6.5);
	fPush(&s, 4.5);
	fTop(s, &e);
	fPop(&s);
	printf("top was: %f", e);
	fPrintStack(s);
	*/
	/*
	int A[] = { 5,0,2,1,7,1 };
	printArray(A, 6);
	sortDecArray(A,6);
	printArray(A, 6);
	*/
	/*
	//LAB3 EX1 TEST:
	list* l1 = NULL, * l2 = NULL;
	struct node *inter;
	int c1 = 0, c2 = 0;

	struct node* intpt = createNode(3);
	addNode(&intpt, createNode(4));

	addNode(&l1, createNode(1));
	addNode(&l1, createNode(2));
	addNode(&l1, intpt);

	addNode(&l2, createNode(5));
	addNode(&l2, createNode(6));
	addNode(&l2, createNode(7));
	addNode(&l2, intpt);

	listIntersection(l1, l2, &inter, &c1, &c2);

	printf("lists remains the same: \n");
	printList(l1);
	printList(l2);
	printf("c1: %d \nc2: %d \n\n", c1, c2);
	printf("intpt data: %d \ninter data: %d \n\n", intpt->data, inter->data);
	printf("intpt points to: %p \ninter  address : %p\n\n", intpt, inter);
	printf("next node of intpt: %p\nnext node of inter: %p\n", intpt->next,inter->next);
	*/
	/*
	element2 e;
	queue q = createQueue();
	enQueue(&q, 14);
	enQueue(&q, 13);
	enQueue(&q, 7);
	enQueue(&q, -2);
	enQueue(&q, 5);
	enQueue(&q, 10);
	printQueue(q);
	reverseQueue(&q);
	printQueue(q);
	*/
	/*
	sstack s = sCreateStack();
	element3 e;
	sPush(&s, 1);
	sPush(&s, 0);
	sPush(&s, 33);
	sPush(&s, 2);
	sPush(&s, 5);
	sPrint(s);
	sPrint(s);
	printf("\n%d ", getMax(s));
	*/
	/*
	stack s = createStack();
	element1 e;
	push(&s, 5);
	push(&s, 4);
	push(&s, 3);
	push(&s, 2);
	push(&s, 1);
	PT(s);
	PT(s);
	*/
}
/*
Quesion:
Mesh mafrood static w dynamic same ? le print using l stack wel queue functions bel static btzbat 2ama bel daynamic la2(bel dynamic must use LL)

filterOdd wel metla eza b3mlon iterative ma fe de3e la double pointer byozbat lt8yeer lesar 3adi sho wd3a ?!
bas eza recursive ma byemshi l7al (bt3te result m5telfe shway) 2ela double pointer..!? yemken la2n bade 2ate3 address la next recursive ft bel recursive call 
*/
/*
Answer:
La2n bel pop 3am n3ml free , eza 2emna l free men l pop byemshi 7al l ft PT using stack functions (Same idea bel queue lmshkle bel free in deQueue)
*/