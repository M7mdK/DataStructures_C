#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int element;
typedef struct node {
	element data;
	struct node* left, * right;
}*Btree;


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
		Btree tmp = construct(e, NULL, NULL);
		*b = tmp;
		return 1;
	}
	if (e > (*b)->data) return recursiveBstInsert(&(*b)->right, e);
	if (e < (*b)->data) return recursiveBstInsert(&(*b)->left, e);
	return 1;
}
/*
void printPreOrder(Btree b) {
	if (b) {
		printf("%d ", b->data);
		printPreOrder(b->left);
		printPreOrder(b->right);
	}
}
*/
/*
void find(Btree b, int x , int* floor, int* ceil) {

	if (!b)return;

	if (b->data == x) {
		*floor = *ceil = b->data;
		return;
	}

	if (b->data < x && b->data > * floor)
		* floor = b->data;

	if (b->data > x && b->data < *ceil)
		* ceil = b->data;

	if(x<b->data)
		 find(b->left, x, floor, ceil);
	if(x>b->data)
		 find(b->right, x, floor, ceil);
}
*/
void find(Btree b, int x, int* floor, int* ceil) {
	if (!b)return;
	if (b->data == x) {
		*floor = *ceil = b->data;
	}
	else if (x < b->data) {
		*ceil = b->data;
		find(b->left, x, floor, ceil);
	}
	else {
		*floor = b->data;
		find(b->right, x, floor, ceil);
	}
}

main() {
	int i, N, e, ceil, floor;
	int a[4];
	int max, min ,flag=0;
	Btree b = NULL;
	do {
		scanf("%d", &N);
	} while (N<4);

	for (i = 1; i < N; i++) {
		scanf(" ADD %d", &e);	//lfr2 byna wben %s eno honik beda5el lbdo ya wb3ml compare wkaza 2ama honmajboor yd5el l pattern nfsa 2w ma byo2ra e
		ceil = floor = e;
		if (flag == 0) {
			max = min = e;
		}
		recursiveBstInsert(&b, e);
	}
	scanf(" find %d %d %d %d", &a[0], &a[1], &a[2], &a[3]);//space b2awal scanf 3atol 
	for (i = 0; i < 4; i++) {
		find(b, a[i], &floor, &ceil);


	}
}