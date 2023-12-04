#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct heap{
	int* A;
	int cap, count;//RK: 2e5er element mwjod 3ala h->count -1
}*heap;
//la3adel 3ala single pointer *A me7taaj double pointer heap *h
//bel heap 2ktareyet lshe8el *heap (y3ni double pointer), metel lstack , we use single pointer only int case bade 23ml shi metel search 

//VERY IMPORTANT: bel java mn3ml new class wmn3ml constructor , hon mn3ml new typedef wmn3mlo ft create "sha8leta t3ml MALLOC LAL struct"
					//and t3ml malloc la dynamic things b2lb l struct w intialize lal variables
heap createHeap(int capacity) {
	heap h;
	h = (heap)malloc(sizeof(struct heap));
	if (!h)return NULL;
	h->cap = capacity;
	h->count = 0;
	h->A = (int*)malloc(sizeof(int) * h->cap);
	if (!(h->A))return NULL;
	return h;
}

void printHeap(heap h) {
	int i;
	if (!h)return;
	for (i = 0; i < h->count; i++) {
		printf("%d ", h->A[i]);
	}
	printf("\n");
}

int getParent(heap h , int i) {
	if (i <= 0 || i >= h->count)return -1;
	return (i - 1) / 2;
}

int getLC(heap h ,int i) {
	int l = 2 * i + 1;
	if (l <= 0 || l >= h->count)return -1;
	return l;
}

int getRC(heap h , int i) {
	int r = 2 * i + 2;
	if (r <= 0 || r >= h->count)return -1;
	return r;
}

void percolateDown(heap* h, int i) {
	int m, l, r, temp;
	l = getLC(*h, i);
	r = getRC(*h, i);
	if (l != -1 && (*h)->A[i] < (*h)->A[l]) m = l;
	else m = i;
	if (r != -1 && (*h)->A[m] < (*h)->A[r]) m = r;
	if (m != i) {
		temp = (*h)->A[m];
		(*h)->A[m] = (*h)->A[i];
		(*h)->A[i] = temp;
		percolateDown(h, m);
	}
}

void percolateUp(heap* h, int i) {
	int  p, temp;
	p = getParent(*h, i);
	if (p != -1 && (*h)->A[p] < (*h)->A[i]) {
		temp = (*h)->A[p];
		(*h)->A[p] = (*h)->A[i];
		(*h)->A[i] = temp;
		percolateUp(h, p);
	}
}

int getMax(heap h) {
	if (h->count == 0)return -1;
	return h->A[0];
}

//use getMax then call deleteMax
void deleteMax(heap* h) {
	if ((*h)->count != 0) {
		(*h)->A[0] = (*h)->A[(*h)->count - 1];
		(*h)->count--;
		percolateDown(h, 0);
	}
}
//OR:
int removeMax(heap* h) {
	int data;
	if ((*h)->count == 0)return -1;
	data = (*h)->A[0];
	deleteMax(h);
	return data;
}

int destroyHeap(heap* h) {
	if (!h)return 0;	//h == NULL <==> *h == NULL
	free((*h)->A);
	free(*h);			//free(*h) <=/=> free(h)
	return 1;
}

void resizeHeap(heap* h) {
	int i;
	int* old = (*h)->A;
	(*h)->A = (int*)malloc(sizeof(int) *2*(*h)->cap);
	if (!(*h)->A)return;
	for (i = 0; i < (*h)->cap; i++) {
		(*h)->A[i] = old[i];
	}
	(*h)->cap = (*h)->cap * 2;
	free(old);
}

void buildHeap(heap* h, int a[], int n) {//Build heap from an array
	int i;
	if (h == NULL)return;//we must use createHeap first
	while (n > (*h)->cap)
		resizeHeap(h);
	for (i = 0; i < n; i++)
		(*h)->A[i] = a[i];
	(*h)->count = n;
	for (i = (n - 1) / 2; i >= 0; i--)
		percolateDown(h, i);
}

void insert(heap *h,int e) {
	int i, p;
	if (!h)return;
	i = (*h)->count;
	(*h)->count++;
	if (i == (*h)->cap)
		resizeHeap(h);
	p = getParent(*h, i);
	while (p != -1 && (*h)->A[p] < e) {
		(*h)->A[i] = (*h)->A[p];
		i = p;
		p = getParent(*h, i);
	}
	(*h)->A[i] = e;
	
	/*
	//2nd Method using pecolateUp ft
	int i = (*h)->count;
	if (i == (*h)->cap)
		resizeHeap(h);
	(*h)->A[i] = e;
	(*h)->count++;//EZA MN7OT L COUNT T7T 8ALAT , BTSER getParent t3ml return -1
	percolateUp(h, i);
	*/
}
/*
int searchHeap(heap h , int e , int i) {
	int r, l;
	if (h == NULL || h->count == 0)
		return 0;
	if (h->A[i] == e)
		return 1;
	l = getLC(h, i);
	r = getRC(h, i);
	
	if (l == -1 && r == -1)
		return 0;
	
	if (l != -1 && h->A[l] == e)
		return 1;
	if (r != -1 && h->A[r] == e)
		return 1;
	if (l != -1)
		searchHeap(h, e, l);
	if (r != -1)
		searchHeap(h, e, r);
}
*/
void delete(heap *h , int i) {
	if ((*h)->count > 0) {
		(*h)->A[i] = (*h)->A[(*h)->count - 1];
		(*h)->count--;
		//if((*h)->A[i]> getParent(*h,i))
			percolateUp(h, i);
		//else
			percolateDown(h, i);
	}
}

/*
Very important:
IN CASE, heap kello 5arban wbade zabto
lazabet l heap perculating UP lezem zabet men fo2 la ta7et y3ni 2awal shi wlad l root b3den wledon and so on
lfekra eno hon bkon 3am zabet kel element wel faw2o mazbouteen , otherwise eza lfw2o mesh mzboteen howi ma ra7 yzbat
ex:3na 2 4 6 5 verticaly, eza bbalesh men 5 ma ra7 ybdela bl 6 m32n lfo2 6 2z8ar men 5 ,so lezem 23ml 4 then 6 w2osal la 6 4 2 5 then bzbet 5
AND SAME IDEA:
lazabet l heap perculating DOWN lezem blesh mn lvl l2bel leaf nodes level zabto ma3 wledo be leaf lvl ,2rja3 lefaw2o and so on l2osal lal root
*/
void fixHeap1(heap* h) {
	int i,n;
	n = (*h)->count;
	for (i = (n - 1)/2; i >= 0; i--)//All NON-leaf nodes mwjodeen before (n-1)/2 , w 2ni mesh be7aje 23ml percolateDown la leaf nodes!
		 percolateDown(h, i);
	/*THIS IS WRONG:
	for (i = 0; i < (*h)->count; i++)
		percolateDown(h, i);
	*/
}

void fixHeap2(heap* h) {
	int i;
	for (i = 1; i < (*h)->count; i++)
		percolateUp(h, i);
	/*THIS IS WRONG:
	for (i = (n - 1)/2; i >= 0; i--)
		 percolateUp(h, i);
	*/
}

void inOrder(heap h , int i) {
	int l, r;
	l = getLC(h, i);
	r = getRC(h, i);
	if(l!=-1 )
		inOrder(h, l);
	printf("%d ", h->A[i]);
	if(r!=-1)
		inOrder(h, r);
}


main() {
	int i,l,a;
	heap h = createHeap(1000);
	do {
		scanf("%d", &l);
	} while (l >= 1000 || l < 0);
	for (i = 0; i < l; i++) {
		scanf(" ADD %d", &a);
		insert(&h, a);
		inOrder(h, 0);
		printf("\n");
	}

	/*heap h = createHeap(20);
	insert(&h, 1);
	insert(&h, 5);
	insert(&h, 6);
	insert(&h, 2);
	insert(&h, 4);
	insert(&h, 7);
	insert(&h, 3);
	insert(&h, 9);
	printHeap(h);
	delete(&h, 1);
	printHeap(h);*/
	/*
	int i;
	heap h = createHeap(20);
	insert(&h, 1);
	insert(&h, 5);
	insert(&h, 6);
	insert(&h, 2);
	insert(&h, 4);
	insert(&h, 7);
	insert(&h, 3);
	insert(&h, 9);
	insert(&h, 8);
	insert(&h, 10);
	insert(&h, 11);
	insert(&h, 12);
	insert(&h, 13);
	insert(&h, 14);
	insert(&h, 15);
	insert(&h, 16);
	insert(&h, -2);
	insert(&h, -3);
	insert(&h, -4);
	printHeap(h);
	for (i = 1; i <= 16; i++)
		printf("%d ",i);
	printf("\n");
	printf("%d ", searchHeap(h, 1, 0));
	printf("%d ", searchHeap(h, 2, 0));
	printf("%d ", searchHeap(h, 3, 0));
	printf("%d ", searchHeap(h, 4, 0));
	printf("%d ", searchHeap(h, 5, 0));
	printf("%d ", searchHeap(h, 6, 0));
	printf("%d ", searchHeap(h, 7, 0));
	printf("%d ", searchHeap(h, 8, 0));
	printf("%d ", searchHeap(h, 9, 0));
	printf("%d ", searchHeap(h, 10, 0));
	printf("%d ", searchHeap(h, 11, 0));
	printf("%d ", searchHeap(h, 12, 0));
	printf("%d ", searchHeap(h, 13, 0));
	printf("%d ", searchHeap(h, 14, 0));
	printf("%d ", searchHeap(h, 15, 0));
	printf("%d ", searchHeap(h, 16, 0));
	printf("%d ", searchHeap(h, -2, 0));
	printf("%d ", searchHeap(h, -3, 0));
	printf("\ncount is %d", h->count);
	printf("\n%d", getRC(h, 8));
	*/
}



