typedef int element;
typedef struct cell2 {
	element data;
	struct cell2* next;
}cell2;
typedef struct {
	cell2* front, * rear;
} Queue;