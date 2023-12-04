typedef char element5;
typedef struct cell5 {
	element5 data;
	struct cell5* next;
}*fStack;

extern fStack fCreateStack();
extern int fIsEmptyStack(fStack s);
extern int fPush(fStack* s, element5 e);
extern int fPop(fStack* s);
extern int fTop(fStack s, element5* e);
extern void fPrintStack(fStack s);
