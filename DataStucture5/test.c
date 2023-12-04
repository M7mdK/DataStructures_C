#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define n 3
typedef struct arr{
	int A[n];
}arr;

void scan(arr *a) {
	int i;
	printf("scan arr");
	for (i = 0; i < n; i++) {
		scanf("%d", &a->A[i]);
	}
}
void read(int A[]) {
	int i;
	printf("read array");
	for (i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
}
void print(arr a) {
	int i;
	printf("arr is:\t");
	for (i = 0; i < n; i++) {
		printf("%d ", a.A[i]);
	}
	printf("\n");
}
void show(int A[]) {
	int i;
	printf("array is:\t");
	for (i = 0; i< n; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}

void create(arr *a) {
	int i;
	for (i = 0; i < n; i++)
		a->A[i] = 3;
}
//to scan or create or do whatever to arr we needed a pointer (we need to pass by address otherwise it is pass by value)
//l Array lmn3refa heye special case la2n heye be7ad zeta pointer so pass by address 3atol
/*
main() {
	int A[n];
	arr a;
	scan(&a);
	read(A);
	print(a);
	show(A);
}
*/
/*
typedef struct cell {
	int* A;
	int count, cap;

}hp;
hp createHp(int capacity) {
	hp h;
	//h = (hp*)malloc(sizeof(hp));
	//if (!h)return NULL;
	h.cap = capacity;
	h.count = 0;
	h.A = (int*)malloc(sizeof(int) * h.cap);
	return h;
}

main() {
	hp h = createHp(5);
	h.A[0] = 1;
	printf("%d", h.A[0]);
}*/