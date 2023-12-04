#include<stdio.h>
#define capacity 20

typedef struct node {	//MAX HEAP 
	int* A;
	int count;
}*heap;

heap createHeap() {
	heap h;
	h = (heap)malloc(sizeof(struct node));
	if (!h)return NULL;
	h->count = 0;
	h->A = (int*)malloc(sizeof(int)*capacity);
	if (!(h->A))return NULL;
	return h;
}

int getParent(heap h, int i) {	//i is index of the child
	if (i <= 0 || i > h->count)
		return -1;
	return (i - 1) / 2;
}

int getLC(heap h , int i) {	//get left child of the parent in index i
	int L = 2 * i + 1;
	if (i<0 || L>h->count)
		return -1;
	return L;
}

int getRC(heap h , int i) {
	int R = 2 * i + 2;
	if (R > h->count || i < 0)
		return -1;
	return R;
}

int getMax(heap h) {
	if (h->count == 0)
		return -1;
	return h->A[0];
}

void percolateDown(heap* h, int i) {
	if ((*h)->count) {
		int L, R, max, t;
		max = i;
		L = getLC(*h, i);
		R = getRC(*h, i);
		if (L != -1 && (*h)->A[L] > (*h)->A[i])
			max = L;
		if (R != -1 && (*h)->A[R] > (*h)->A[max])
			max = R;
		if (max != i) {
			t = (*h)->A[i];
			(*h)->A[i] = (*h)->A[max];
			(*h)->A[max] = t;
			percolateDown(h, max);	//new position of heapified element ins at max
		}
	}
}

void Resize(heap* h) {
	int i;
	int* T = (*h)->A;
	(*h)->A = (int*)malloc(sizeof(int) *capacity * 2);
	if (!(*h))return -1;
	for (i = 0; i < capacity; i++)
		(*h)->A[i] = T[i];
	free(T);

}

int main() {



	return 0;
}