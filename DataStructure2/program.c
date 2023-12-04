#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"Stack.h"
#include "Queue.h"
#include"Type_Tree.h"
/*
//TREES Assignment:
//Ex2:
Btree construct(element e, Btree left, Btree right) {
	Btree b = (Btree)malloc(sizeof(struct node));
	if (!b)return NULL;
	b->data = e;
	b->left = left;
	b->right = right;
	return b;
}
//EX3:
void printPreOrder(Btree b) {
	if (b) {
		printf("%d ", b->data);
		printPreOrder(b->left);
		printPreOrder(b->right);
	}
}
void printPostOrder(Btree b) {
	if (b) {
		printPreOrder(b->left);
		printPreOrder(b->right);
		printf("%d ", b->data);
	}
}
void printInOrder(Btree b) {
	if (b) {
		printPreOrder(b->left);
		printf("%d ", b->data);
		printPreOrder(b->right);
	}
}
//EX4:

void printInterval(Btree b, int x, int y) {
	if (b) {
		if (b->data > x && b->data < y)
			printf("%d ", b->data);
		printInterval(b->left, x, y);
		printInterval(b->right, x, y);
	}
}

int sumTree(Btree b) {
	if (!b)return 0;
	return b->data + sumTree(b->left) + sumTree(b->right);
}

int height(Btree b) {
	if (!b)return 0;
	if (b->left == NULL && b->right == NULL)
		return 1;
	return 1 + max(height(b->left), height(b->right));
}

int countNonLeaf(Btree b) {
	if (!b || (b->left == NULL && b->right == NULL))
		return 0;
	if (b->left || b->right)
		return 1 + countNonLeaf(b->left) + countNonLeaf(b->right);
}

int balanced(Btree b) {
	//Mesh drori dayman 3ala !b ykon return 0
}

void changeNodeValue(Btree* b) {

	//3am 8ayer bel data so ma fe de3e la double pointer
	//law 3am 8ayer bel struct kena ba3atneha double
	//Eza kena me7teejen masalan b=b->left hay t8yeer bel structure

}

void printIterQueue(Btree b) {	//RK: Ma fe de3e 7ot temp Tree w3abe feha front wkaza la2n law da3et l b l2sleye ma fe mshkle la2n 2ni mesh mst5dem double pointer
	Queue q = createQueue();
	enQueue(&q, b);
	while (front(q, &b)) {
		//Fena n7ot if(!b) metel ma 7ala 7aidar la2n lmshkle feha heye...
		printf("%d ", b->data);
		if (b->left)
			enQueue(&q, b->left);
		if (b->right)
			enQueue(&q, b->right);
		deQueue(&q);
	}
}

void reverseIterTree(Btree b) {
	Btree temp;
Queue q = createQueue();
enQueue(&q, b);
while (front(q, &b)) {
	
	temp = b->left;
	b->left = b->right;
	b->right = temp;

	if (b->left)
		enQueue(&q, b->left);
	if (b->right)
		enQueue(&q, b->right);
	deQueue(&q);
}
}

void reverseTree(Btree b) {
	Btree temp;
	if (!b)return;

	temp = b->left;
	b->left = b->right;
	b->right = temp;

	reverseTree(b->left);
	reverseTree(b->right);
}


//

void maxWidth(Btree b){
	if (!b)return;
	Queue q = createQueue();
	enQueue(&q, b);
	while (front(q, &b)) {
		
		
		if (b->left)
			enQueue(&q, b->left);
		if (b->right)
			enQueue(&q, b->right);
		deQueue(&q);
	}
}

main() {

	Btree b = construct(2, NULL, NULL);
	b->left = construct(7, NULL, NULL);
	b->left->left = construct(2, NULL, NULL);
	b->left->right = construct(6, NULL, NULL);
	b->left->right->left = construct(5, NULL, NULL);
	b->left->right->right = construct(11, NULL, NULL);
	b->right = construct(5, NULL, NULL);
	b->right->right = construct(9, NULL, NULL);
	b->right->right->left = construct(4, NULL, NULL);
	printInOrder(b);
	
	printIterQueue(b);
	printf("\n");
	reverseIterTree(b);
	printIterQueue(b);
	
}
*/