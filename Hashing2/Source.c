#include<stdio.h>
#include<string.h>
#define N 20

typedef int hashtable[N];

int hf(int e) {
	return e % 5;
}

void reset(hashtable h ) {
	int i;
	for (i = 0; i < N; i++)
		h[i] = -2;
}

void print(hashtable h) {
	int i;
	for (i = 0; i < N; i++)
		printf("%d \n", h[i]);
}

int add(hashtable h, int e) {
	int z = hf(e);
	int k=1,a;

	if (h[z] == -2) {
		h[z] = e;
		return 1;
	}
	a = z;
	while (h[a]!=-2) {
		if (k > N / 2)
			return 0;
		a = (z + k * k) % N;
		k++;
	}
	h[a] = e;

	return 1;
}

int delete(hashtable h, int e) {
	int z = hf(e);
	int k = 1;
	int x, y;
	if (h[z] == -2)
		return 0;

	x = z;
	while (h[x] != e && k<=N/2) {
		x = (z + k * k) % N;
		k++;
	}

	if (k >N / 2)
		return 0;
	if (k == N / 2) {  //ana 2e5er wa7ad 2bl N/2 y3ni ma fe shi b3di
		h[x] = -2;
		return 1;
	}
	y = (x + k * k) % N;
	while (k<=N/2) {
		
		if (hf(h[y]) == z) {
			h[x] = h[y];
			x = y;
		}
		y = (z + k * k) % N;
		k++;
	}
	h[x] = -2;
	return 1;
}

main() {
	hashtable h;
	reset(h);
	add(h, 7);
	add(h, 2);
	add(h, 12);
	add(h, 3);
	add(h, 8);
	printf("%dis out",delete(h, 3));
	print(h);
}