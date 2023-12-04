#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"Stack.h"
#include"Queue.h"

/*
6
5
a
b
c
d
e
f
[0,1]
[1,2]
[0,4]
[1,3]
[2,5]
*/

typedef struct {
	char c;
	int lvl;
}cell;

typedef struct {
	int** adj;
	cell* data;
	int v, e;
}graph;

graph createGraph() {
	graph g;
	int i,j,k;
	printf("enter the nb of verticies:\n");
	scanf("%d", &g.v);
	printf("enter nb of edges:\n");
	scanf("%d", &g.e);

	g.adj = (int**)malloc(sizeof(int*) * g.v);
	if (!g.adj)return;
	for (i = 0; i < g.v; i++) {
		g.adj[i] = (int*)malloc(sizeof(int) * g.v);
		if (!g.adj[i])return;
	}
	for (i = 0; i < g.v; i++) {
		for (j = 0; j < g.v; j++) {
			g.adj[i][j] = 0;
		}
	}

	g.data = (cell*)malloc(sizeof(cell) * g.v);
	if (!g.data)return;
	for (i = 0; i < g.v; i++) {
		printf("enter data of position %d", i);
		scanf(" %c", &g.data[i].c);
	}

	printf("enter [a,b] for every edge ab\n");
	for (k = 0; k < g.e; k++) {
		scanf(" [%d,%d]", &i, &j);
		g.adj[i][j] = 1;
		//g.adj[j][i] = 1;  //for Undirected
	}
	return g;
}

void printMatrix(graph g) {
	int i, j;
	printf("  ");
	for (i = 0; i < g.v; i++)
		printf("%c ", g.data[i].c);
	printf("\n");
	for (i = 0; i < g.v; i++) {
		printf("%c ", g.data[i].c);
		for (j = 0; j < g.v; j++) {
			printf("%d ", g.adj[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void DFSHelper(graph* g, int* vis, int s) {
	int j;
	if (!vis[s]) {
		vis[s] = 1;
		printf("%d ", s);
	}
	for (j = 0; j < g->v; j++)
		if (!vis[j] && g->adj[s][j])
			DFSHelper(g, vis, j);
}

void DFS(graph* g) {
	int i;
	int* vis;
	vis = (int*)malloc(g->v * sizeof(int));
	for (i = 0; i < g->v; i++)
		vis[i] = 0;
	for (i = 0; i < g->v; i++)
		if (!vis[i])
			DFSHelper(g, vis, i);
}

void BFSHelper(graph *g,int *vis,int s) {
	int i, j,clvl=0;
	queue q = createQueue();
	g->data[s].lvl = 0;
	enQueue(&q, s);
	while (front(q, &i)) {
		deQueue(&q);
		vis[i] = 1;
		if (clvl == g->data[i].lvl) {
			printf("\nlevel %d: ", g->data[i].lvl);
			clvl++;
		}
		printf("%c ", g->data[i].c);
		for (j = 0; j < g->v; j++) {
			if (!vis[j] && g->adj[i][j]) {
				g->data[j].lvl = g->data[i].lvl + 1;
				enQueue(&q, j);
			}
		}
	}
}
void BFS(graph *g) {
	int i, * vis;
	vis = (int*)malloc(g->v * sizeof(int));
	for (i = 0; i < g->v; i++)
		vis[i] = 0;
	for (i = 0; i < g->v; i++)
		if (!vis[i])
			BFSHelper(g, vis, i);
}
/*
main() {
	graph g = createGraph();
	//printMatrix(g);
	BFS(&g);
}
*/
/*
adj list
DFS: (ex: cycle , cycle pacing thow... , path exists between ...?)
Topological sort
*/

//Partial Ex:
/*
RK1:
law n7ot return badal x+ = call kena 5sorna 5aaseyet DFS , y3ni ma ra7 y3ml unwinding w2ta , ne7na mesh hek bdna
RK2:
	++i;
	ft2(i);
	AND
	ft2(++i);
	ARE BOTH THE SAME 

typedef struct {
	int v, e;
	char* automata;
}automata;
*/