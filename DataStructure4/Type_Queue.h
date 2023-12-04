#define N 10
typedef int element2;
typedef struct cell2 {
	element2 data;
	struct cell2* next;
}cell2;
typedef struct {
	cell2* front, * rear;
} queue;

/*
typedef struct {
	element data[N];
	int front, rear;
}queue;
*/