#define N 10
typedef int element;

typedef struct node {
	element data;
	struct node* next;
}node;
typedef struct {
	node* front, * rear;
}queue;
/*
typedef struct {
	element data[N];
	int front, rear;
}queue;
*/