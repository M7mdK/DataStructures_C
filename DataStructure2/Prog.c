#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include"Type_Tree.h"
#include"Stack.h"
#include"Queue.h"

Btree construct(element e, Btree L, Btree R) {
	Btree b;
	b = (Btree)malloc(sizeof(struct node));
	if (!b)return NULL;
	b->data = e;
	b->left = L;
	b->right = R;
	return b;
}

void inOrder(Btree b) {
	if (b) {
		inOrder(b->left);
		printf("%d ", b->data);
		inOrder(b->right);
	}
}
void preOrder(Btree b) {
	if (b) {
		printf("%d ", b->data);
		preOrder(b->left);
		preOrder(b->right);
	}
}
void postOrder(Btree b) {
	if (b) {
		postOrder(b->left);
		postOrder(b->right);
		printf("%d ", b->data);
	}
}
void lvlOrder(Btree b) {
	Btree e;
	Queue q = createQueue();
	if (!b)return;
	enQueue(&q, b);
	while (front(q, &e)) {
		printf("%d ", e->data);
		deQueue(&q);
		if (e->left)
			enQueue(&q, e->left);
		if (e->right)
			enQueue(&q, e->right);
	}
	printf("\n");
}

int maxNode(Btree b) {
	if (!b)return -1;
	if (b->left == NULL && b->right == NULL)
		return b->data;
	return max(b->data, max(maxNode(b->left), maxNode(b->right)));
}

void printless(Btree b, int x) {
	if (!b)return;
	if (b->data < x)
		printf("%d ", b->data);
	printless(b->left,x);
	printless(b->right,x);
}

int sumTree(Btree b) {
	if (!b)return 0;
	/*if (b->left == NULL && b->right == NULL)
		return b->data;*/
	return b->data + sumTree(b->left) + sumTree(b->right);
}

int countNodes(Btree b) {
	if (!b)return 0;
	/*if (b->left == NULL && b->right == NULL)
		return 1;*/
	return 1 + countNodes(b->left) + countNodes(b->right);
}
int leaf(Btree b) {
	if (!b)return 0;
	if (b->left == NULL && b->right == NULL)
		return 1;
	return leaf(b->left) + leaf(b->right);
}
int NONLeaf(Btree b) {
	if (!b || (b->left == NULL && b->right ==NULL))
		return 0;
	return 1 + NONLeaf(b->left) + NONLeaf(b->right);
}

int searchBtree(Btree b , element e) {
	if (!b)return 0;
	if (b->data == e)
		return 1;
	return searchBtree(b->left,e) || searchBtree(b->right,e);
}

int searchBSTIter(Btree b ,element e) {
	if (!b)return 0;
	if (b->data == e)return 1;
	while (b) {
		if (e > b->data)
			b = b->right;
		else if(e < b->data)//bala else 8alat
			b = b->left;
		else //if(b->data == e)
			return 1;
	}
	return 0;
}
int searchBSTRec(Btree b, element e) {
	if (!b)return 0;
	if (b->data == e)
		return 1;
	if (e<b->data)
		return searchBSTRec(b->left, e);
	if (e>b->data)
		return searchBSTRec(b->right, e);
}
int insertBSTIter(Btree b, element e) {
	Btree t = (Btree)malloc(sizeof(struct node));
	t->data = e;
	t->right = t->left = NULL;
	if (!b) {
		b = t;
		return 1;
	}
	while (1) {
		if (b->data == e)
			return 0;
		if (e < b->data) {
			if(b->left)
				b = b->left;
			else {
				b->left = t;
				return 1;
			}
		}
		else if (e > b->data) {
			if(b->right)
				b = b->right;
			else {
				b->right = t;
				return 1;
			}
		}
	}
}
int insertBSTRec(Btree *b, element e) {
	if (!(*b)) {
		*b = (Btree)malloc(sizeof(struct node));
		(*b)->data = e;
		(*b)->left = (*b)->right = NULL;
		return 1;
	}
	if ((*b)->data == e)return 0;
	if (e > (*b)->data)
		return insertBSTRec(&(*b)->right, e);
	return insertBSTRec(&(*b)->left, e);
}

int isEqualBST(Btree b1 , Btree b2) {
	if (!b1 && !b2)return 1;
	if ((!b1 && b2) || (!b2 && b1))return 0;
	if (b1->data != b2->data)return 0;
	if ((b1->left && !b2->left) || (!b1->left && b2->left) ||
		(b1->right && !b2->right) || (!b1->right && b2->right))return 0;
	return isEqualBST(b1->left, b2->left) && isEqualBST(b1->right, b2->right);
}

int depth(Btree b) {//Maximum height
	if (!b)return 0;
	return 1 + max(depth(b->left), depth(b->right));
}
int isBalanced(Btree b) {
	if (!b || (b->left ==NULL && b->right == NULL))return 1;
	if (abs(depth(b->left) - depth(b->right)) > 1)return 0;
	return isBalanced(b->left) && isBalanced(b->right);
}

int isLeftComb(Btree b) {
	if (!b)return 0;
	if (b->left == NULL && b->right == NULL)
		return 1;
	if ((b->left && b->right == NULL) || (b->left == NULL && b->right))return 0;
	if (b->right->right || b->right->left)return 0;
	return isLeftComb(b->left);
}
void update(Btree b) { //node equal to sum of childern
	if (!b || (b->left == NULL && b->right == NULL))return;
	update(b->left);
	update(b->right);
	if (!b->left && b->right)
		b->data = b->right->data;
	if (!b->right && b->left)
		b->data = b->left->data;
	if (b->left && b->right)
		b->data = b->right->data + b->left->data;
}

void reverseTree(Btree b) {
	if (!b || (b->left == NULL && b->right ==NULL))return;
	Btree temp;
	temp = b->left;
	b->left = b->right;
	b->right = temp;
	reverseTree(b->left);
	reverseTree(b->right);
}

int lvlWidth(Btree b, int lvl) {
	if (!b)return 0;
	if (lvl == 1)return 1;
	return lvlWidth(b->left, lvl - 1) + lvlWidth(b->right, lvl - 1);
}

int maxWidth(Btree b) {
	int i,max,temp;
	if (!b)return -1;
	max = b->data;
	for (i = 0; i < depth(b); i++) {
		temp = lvlWidth(b, i);
		if (max < temp)
			max = temp;
	}
	return max;
}

int elementLevel(Btree b, element e) {
	eLvlHelper(b, e, 1);
}
int eLvlHelper(Btree b, element e, int lvl) {
	if (!b)return 0;
	if (b->data == e)
		return lvl;
	return eLvlHelper(b->left, e, lvl + 1) + eLvlHelper(b->right, e, lvl + 1);
}

int isBST(Btree b) {
	if (!b || b->left == NULL && b->right ==NULL)return 1;
	if (b->left && b->data < b->left->data)return 0;
	if (b->right && b->data > b->right->data)return 0;
	return isBST(b->left) && isBST(b->right);
}

/*
//max width of binary tree method 1 using queue
int maxWidth1(Btree b) {
	if(!b) return 0;
	Btree tmp;
	int max = 1, count = 0, w = 1;
	Queue q = createQueue();
	enQueue(&q, b);

	while(!isEmptyQueue(q)) {
		while(w--) {
			front(q, &tmp);
			if(tmp->left) {
				enQueue(&q, tmp->left);
				count++;
			}
			if(tmp->right) {
				enQueue(&q, tmp->right);
				count++;
			}
			deQueue(&q);
		}
		if(max < count) max = count;
		w = count;
		count = 0;
	}
	return max;
}
*/

void inOrderIter(Btree b) {
	stack s = createStack();
	Btree t = b;
	if (!b)return;
	push(&s, b);
	while (!isEmptyStack(s)) {
		while (t->left) {
			t = t->left;
			push(&s, t);
		}
		top(s, &t);
		pop(&s);
		printf("%d ", t->data);
		if (t->right) {
			t = t->right;
			push(&s, t);
		}
	}
}
void preOrderIter(Btree b) {
	stack s = createStack();
	Btree t = b;
	if (!b)return;
	push(&s, b);
	printf("%d ", b->data);
	while (!isEmptyStack(s)) {
		while (t->left) {
			t = t->left;
			printf("%d ", t->data);
			push(&s, t);
		}
		top(s, &t);
		pop(&s);
		if (t->right) {
			t = t->right;
			printf("%d ", t->data);
			push(&s, t);
		}
	}
	printf("\n");
}
/*
void postOrderIter(Btree b) {
	Btree temp;
	stack s = createStack();
	Btree t = b;
	if (!b)return;
	push(&s, b);
	while (!isEmptyStack(s)) {
		while (t->left) {
			t = t->left;
			push(&s, t);
			if(!t->left)
				printf("%d ", t->data);
		}
		top(s, &t);
		pop(&s);
		temp = t;
		if (t->right) {
			t = t->right;
			printf("%d ", t->data);
			push(&s, t);
		}
		if (temp->left)
			printf("%d ", temp->data);
	}
	printf("\n");
}
*/

void zigzag(Btree b) {
	stack even, odd;
	Btree t;
	odd = createStack();
	even = createStack();
	if (!b)return;
	push(&odd, b);
	while (!isEmptyStack(odd) || !isEmptyStack(even)) {
		while (top(odd, &t)) {
			pop(&odd);
			printf("%d ", t->data);
			if (t->left)
				push(&even, t->left);
			if (t->right)
				push(&even, t->right);
		}
		while (top(even, &t)) {
			pop(&even);
			printf("%d ", t->data);
			if (t->right)
				push(&odd, t->right);
			if (t->left)
				push(&odd, t->left);
		}
	}
	printf("\n");
}

void printReverse(Btree b) {
	Btree t;
	Queue q = createQueue();
	stack s = createStack();
	if (!b)return;
	enQueue(&q, b);
	while (front(q, &t)) {
		deQueue(&q);
		push(&s, t);
		if (t->right)
			enQueue(&q, t->right);
		if (t->left)
			enQueue(&q, t->left);
	}
	while (top(s, &t)) {
		pop(&s);
		printf("%d ", t->data);
	}
	printf("\n");
}

void printDiagonal(Btree b) {
	Queue q = createQueue();
	Btree t = b;
	if (!b)return;
	enQueue(&q, b);
	while (t->right) {
		t = t->right;
		enQueue(&q, t);
	}
	while (front(q, &t)) {
		deQueue(&q);
		printf("%d ", t->data);
		if (t->left) {
			t = t->left;
			enQueue(&q, t);
			while (t->right) {
				t = t->right;
				enQueue(&q, t);
			}
		}
	}
}

int insert(Btree *b , element e) {
	if (!(*b)) {
		*b = (Btree)malloc(sizeof(struct node));
		if (!(*b))return 0;
		(*b)->data = e;
		(*b)->left = (*b)->right = NULL;
		return 1;
	}
	if (e == (*b)->data)return 0;
	if (e > (*b)->data)return insert(&(*b)->right, e);
	return insert(&(*b)->left, e);
}

void printpath(stack s) {
	while (s) {
		printf("%d", s->data);
		if (s->next) printf("->");
		s = s->next;
	}
	printf("\n");
}

void paths(Btree b , stack *s) {
	if (!b)return;
	push(&s, b);
	if (b->left == NULL && b->right == NULL)
		printpath(*s);
	paths(b->left, s);
	paths(b->right, s);
	pop(&s);
}

main() {
	int i,n,e;
	char t[5];
	stack s;
	Btree b;
	b = NULL;
	s = createStack();
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf(" ADD %d", &e);
		insert(&b, e);
	}
	scanf("%s", t);
	if (strcmp(t, "paths") == 0) {
		paths(b, &s);
	}
	/*
	5
ADD 5
ADD 3
ADD 2
ADD 7
ADD 6
paths
	*/

	/*
	Btree bst = construct(30, NULL, NULL);
	bst->left = construct(20, NULL, NULL);
	bst->right = construct(40, NULL, NULL);
	bst->left->left = construct(15, NULL, NULL);
	bst->left->right = construct(25, NULL, NULL);
	bst->right->left = construct(35, NULL, NULL);
	bst->right->right = construct(45, NULL, NULL);
	bst->left->right->left = construct(22, NULL, NULL);
	bst->left->right->right = construct(27, NULL, NULL);
	printDiagonal(bst);
	*/
}