#include<stdio.h>
#define N 9

typedef int hashtable[N];

int hf(int e) {
	return e % N;
}

void reset(hashtable h) {
	int i;
	for (i = 0; i < N; i++)
		h[i] = -2;
}

void print(hashtable h) {
	int i;
	for (i = 0; i < N; i++)
		if(h[i]!=-2)
		printf("%d", h[i]);
}

int add(hashtable h, int e) {
	int z = hf(e);
	if (h[z] == -2) {
		h[z] = e;
		return 1;
	}
	if (h[z] == e)
		return 0;
}

main() {
	hashtable h;
	reset(h);
	int A[] = { 1,2,2,3,7,4,2,5,6,5 };
	int i;
	for (i = 0; i < N; i++) {
		add(h, A[i]);
	}
	print(h);
}