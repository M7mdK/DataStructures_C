#define N6 11
typedef int element6;
typedef struct {
	int T1[N6];
	int T2[N6];
}hash6;

int H1(element6 k) {
	return k % N6;
}

int H2(element6 k) {
	return (k / N6) % N6;
}

hash6 createHash6() {
	int i;
	hash6 h;
	for (i = 0; i < N6; i++) {
		h.T1[i] = -1;
		h.T2[i] = -1;
	}
	return h;
}
/*
//OR:
void createHash6(hash6 *h) {
	int i;
	for (i = 0; i < N6; i++) {
		h->T1[i] = -1;
		h->T2[i] = -1;
	}
}
*/
void printHash6(hash6 h) {
	int i;
	printf("index\tT1 T2\n");
	for (i = 0; i < N6; i++) {
		printf("%d\t%d  %d\n", i, h.T1[i], h.T2[i]);
	}
	printf("\n");
}
