typedef int element1;

typedef struct cell1 {
	element1 data;
	struct cell1* next;
}*stack;
/*
#define N1 20
typedef struct {
	element1 data[N1];
	int top;
} stack;
*/