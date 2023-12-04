#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Queue.h"

typedef struct {
	int V;
	int E;
	int **Adj; 
} Graph;

void adjacencyMatrix() {
	int i, j, u, v;
	int b1,b2,s=5;
	char n1[50],n2[50];
	int* indeg;
	char** bev;
	int* inq = (int *)malloc(sizeof(int)* g->V);
	Graph* G = (Graph*)malloc(sizeof(Graph));
	printf("Enter the number of Beverages: ");
	scanf("%d", &G->V);
	G->Adj = (int **)malloc(G->V * sizeof(int*));
	bev = (char **) malloc(sizeof(char*) * (G->V));
	indeg = (int *) malloc(sizeof(int) * (G->V));

	for (i = 0; i < G->V; i++) {
		bev[i] = malloc(50 * sizeof(char));
		indeg[i] = 0;
		inq[i] = 0;
	}

	for (u = 0; u < G->V; u++)
		G->Adj[u] = (int *)malloc(G->V * sizeof(int));

	for (u = 0; u<G->V; u++)
		for (v = 0; v<G->V; v++)
			G->Adj[u][v] = 0;

	for (i = 0; i < G->V; i++) {
		printf("Enter beverage %d: ",i);
		scanf("%s", n1);
		strcpy(bev[i],n1);
	}
	
	printf("Enter the number of relations between beverages: ");
	scanf("%d", &G->E);

	for (i = 0; i < G->E; i++) {
		printf("Enter 2 beverages: ");
		scanf("%s %s", n1, n2);

		for (j=0;j<G->V;j++){
			if (strcmp(n1,bev[j]) == 0) b1 = j;
			if (strcmp(n2,bev[j]) == 0) b2 = j;
		}

		G->Adj[b1][b2] = 1;
		indeg[b2] += 1;
	}

	printf("Should drink: ");

	while (s > 0){
		s = 0;
		for (i=0;i<g->V;i++) {
			s += deg[i];
			if (deg[i] == 0 && inq[i] == 0) {
				printf(" %s ",bev[i]);
				inq[i]=1;
				for (j=0;j<g->V;j++) if (g->Adj[i][j] == 1 && deg[j]>0) deg[j]--;
			}
		}
	}
}

void main()
{
	adjacencyMatrix();
}
