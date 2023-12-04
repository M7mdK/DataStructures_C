#include<stdio.h>
#define FALSE 0
#define TRUE 1
typedef enum{False , True} BOOLEAN;		//Boolean type was created

int w = 9;
void test() {
	printf("this is test \n");
	BOOLEAN B = TRUE;
	printf("%d", B);
}