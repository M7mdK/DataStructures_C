#include<stdio.h>
#pragma warning(disable : 4996)

int min(int a, int b) {
	if (a < b)return a;
	return b;
}

int minArray(int A[], int n) {
	int i;
	int m = A[0];
	for (i = 0; i < n; i++) {
		m = min(A[i], m);
	}
	return m;
}

int recMA(int A[], int n) {
	if (n == 1)return A[0];
	if (A[n - 1] < A[n - 2])
		A[n - 2] = A[n - 1];
	return recMA(A, n - 1);
}
void recMATest() {
	int a[] = { 3,6,2,1,5,7 };
	printf("%d", recMA(a, 6));
}

int sumn(int A[], int s, int n) {
	if (n<0 || n>s) return -1;
	if (n == 1)return A[0];
	return A[n - 1] + sumn(A, s, n - 1);
}
void sumnTest() {
	int a[] = { 1,2,3,4,5,6 };
	printf("%d", sumn(a, 6, 4));
}

void minmax(int* pmin, int* pmax, int A[], int n) {
	int i;
	*pmin = *pmax = A[0];
	for (i = 0; i < n; i++) {
		if (A[i] < *pmin)
			* pmin = A[i];
		if (A[i] > * pmax)
			* pmax = A[i];
	}
}

void minmaxTest() {
	int A[] = { 2,5,7,1,5,8,4 };
	int min = 0, max = 0;
	int* pmin, * pmax;
	pmin = &min;
	pmax = &max;
	minmax(pmin, pmax, A, 7);
	printf("max is %d \n min is %d", max, min);
}