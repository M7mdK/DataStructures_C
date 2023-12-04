//typedef of the element and table ,  HashFt , createTable , printTable
#define N1 13
#define N2 11
#include<stdio.h>
typedef struct {
	char e[2];
	int v;	//hay la2n ma 3ende hash function 3ende cte indecies howi 3aatene yehon fa ma b3ml hash ft b3tehon hek d8re bel struct
}element1;
typedef element1 element2;
typedef element1 hash1[N1];
typedef element2 hash2[N2];

//Linear Probing:
void createHash1(hash1 h) {
	int i;
	for (i = 0; i < N1; i++) {
		h[i].e[0] = '\0';
		h[i].v = -1;
	}
}
void printHash1(hash1 h) {
	int i;
	for (i = 0; i < N1; i++) {
		printf("%d\t%s\t%d\n",i,h[i].e,h[i].v);
	}
	printf("\n");
}

//Quadratic Probing:
void createHash2(hash2 h) {
	int i;
	for (i = 0; i < N2; i++) {
		h[i].e[0] = '\0';
		h[i].v = -1;
	}
}
void printHash2(hash2 h) {
	int i;
	for (i = 0; i < N2; i++) {
		printf("%d\t%s\t%d\n", i, h[i].e, h[i].v);
	}
	printf("\n");
}