#define N 10
typedef int element3;
typedef struct cell3 {
	element3 data[N];
	int top;
	element3 max;
}sstack;

extern sstack sCreateStack();
extern int sIsEmptyStack(sstack s);
extern int sIsFullStack(sstack s);
extern int sPush(sstack* s, element3 e);
extern int sPop(sstack* s);
extern int sTop(sstack s, element3* e);

extern void sPrint(sstack s);
extern int getMax(sstack s);
