#include<stdio.h>
#include<stdlib.h>
typedef int element;
typedef struct node{
element data;
struct node *next;
}node;



int count(node*head){
int c=0;
node*p=head;
if(head){
    while(p!=head){
        p=p->next;
        c++;
    }
}
return c;
}

main()
{

}
