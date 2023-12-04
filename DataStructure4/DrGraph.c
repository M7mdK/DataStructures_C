#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"
#include"Stack.h"

//RK: DFS AND BFS takes O(e+v) time
typedef struct {
	int** adj;
	int v, e;
}graph;

typedef struct node{
	int vn;//vertex number
	struct node* next;
}node;
typedef struct {
	int V,E;
	node** Adj;
}Graph;
Graph create() {
	int i,j,k;
	Graph G;
	node* temp,*p;
	scanf("%d", &G.V);
	scanf("%d", &G.E);
	G.Adj = (node**)malloc(G.V * sizeof(node*));
	for (i = 0; i < G.V; i++) {
		G.Adj[i] = (node*)malloc(G.V * sizeof(node));
		G.Adj[i]->next = G.Adj[i];
		G.Adj[i]->vn = i;
	}
	printf("enter [a,b]:\n");
	for (k = 0; k < G.E; k++) {
		scanf(" [%d,%d]", &i, &j);
		p = (node*)malloc(sizeof(node));
		p->vn = j;
		p->next = NULL;
		if (G.Adj[i]->next = G.Adj[i]) {
			p->next = G.Adj[i];
			G.Adj[i]->next = p;
		}
		else {
			temp = G.Adj[i];
			for (; temp->next != G.Adj[i]; temp = temp->next);
			p->next = temp->next;
			temp->next = p;
		}
		p->next = G.Adj[i];
	}
	return G;
}

void show(Graph G) {
	int i;
	node* temp;
	for (i = 0; i < G.V; i++) {
		printf("%d   ", i);
		for (temp = G.Adj[i] ; temp->next != G.Adj[i] ; temp = temp->next) {
			printf("%d ", temp->vn);
		}
		printf("\n");
	}
	printf("\n");
}

graph read() {
	graph g;
	int i, j, k;
	scanf("%d", &g.v);
	scanf("%d", &g.e);
	g.adj = (int**)malloc(g.v * sizeof(int*));
	for (i = 0; i < g.v; i++)
		g.adj[i] = (int*)malloc(g.v * sizeof(int));
	for (i = 0; i < g.v; i++)
		for (j = 0; j < g.v; j++)
			g.adj[i][j] = 0;

	printf("enter [a,b] for every edge ab:\n");
	for (k = 0; k < g.e; k++) {
		scanf(" [%d,%d]", &i, &j);
		g.adj[i][j] = 1;
	}
	return g;
}

void print(graph g) {
	int i, j;
	printf("  ");
	for (i = 0; i < g.v; i++)
		printf("%d ", i);
	printf("\n");
	for (i = 0; i < g.v; i++) {
		printf("%d ", i);
		for (j = 0; j < g.v; j++) {
			printf("%d ", g.adj[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void dfsHelper(graph* g, int* vis, int s) {
	int j;
	vis[s] = 1;
	printf("%d ", s);
	for (j = 0; j < g->v; j++) {
		if (!vis[j] && g->adj[s][j])
			dfsHelper(g, vis, j);
	}
}

void dfsiter(graph* g, int* vis, int i) {
	int j;
	stack s = createStack();
	push(&s, i);
	vis[i] = 1;
	while (top(s, &i)) {
		printf("%d ", i);
		for (j = 0; j < g->v; j++) {
			if (!vis[j] && g->adj[i][j]) {
				vis[j] = 1;
				push(&s, j);
				break;
			}
			else {
				pop(&s);
			}
		}
	}
}

void dfs(graph* g) {
	int i, * vis;
	vis = (int*)malloc(g->v * sizeof(int));
	for (i = 0; i < g->v; i++)
		vis[i] = 0;
	for (i = 0; i < g->v; i++)
		if (!vis[i])
			//dfsiter(g, vis, i);
			dfsHelper(g, vis, i);
}

void bfsHelper(graph* g, int* vis, int s) {
	int i,j;
	queue q = createQueue();
	enQueue(&q, s);
	vis[s] = 1;
	while (front(q, &i)) {
		deQueue(&q);
		printf("%d ", i);
		for (j = 0; j < g->v; j++) {
			if (!vis[j] && g->adj[i][j]) {
				vis[j] = 1;
				enQueue(&q, j);
			}	
		}
	}
}

void bfs(graph *g){
	int i, * vis;
	vis = (int*)malloc(sizeof(int) * g->v);
	for (i = 0; i < g->v; i++)
		vis[i] = 0;
	for (i = 0; i < g->v; i++)
		if (!vis[i])
			bfsHelper(g, vis, i);
}

void topologicalSort(graph* g) {
	int i,j,v, * deg;
	queue q = createQueue();
	deg = (int*)malloc(g->v * sizeof(int));
	for (i = 0; i < g->v; i++)
		deg[i] = 0;
	for (i = 0; i < g->v; i++)
		for (j = 0; j < g->v; j++)
			if (g->adj[i][j])
				deg[j]++;
	for (i = 0; i < g->v; i++)
		if (deg[i] == 0)
			enQueue(&q, i);
	while (front(q, &v)) {
		deQueue(&q);
		printf("%d ", v);
		for (j = 0; j < g->v; j++) {
			if (g->adj[v][j] && deg[j]) {
				deg[j]--;
				if (deg[j] == 0) {
					enQueue(&q, j);
				}
			}
		}
	}
}

/*
4
4
[0,1]
[0,2]
[0,3]
[3,2]
*/

main() {
	Graph G = create();
	show(G);
	printf("%d", G.Adj[0]->vn);

	//graph g = read();
	//print(g);
	//dfs(&g);
	//bfs(&g);
	//topologicalSort(&g);
}
