#include<stdio.h>
#include<stdlib.h>
typedef struct node{
int data;
struct node *next,*prev;
}node;



void print(node*head){
node*p=head;
if(p)
{
    printf("%d \t",p->data);
    print(head->next);
}
}


void dpush(node**head,int a){
node*p;
p=(node*)malloc(sizeof(node));
if(!p){exit(1);}
p->data=a;
p->prev=NULL;
p->next=*head;
if(*head){
    (*head)->prev=p;
}
*head=p;
}
void dpushtest(){
node*head=NULL;
dpush(&head,3);
dpush(&head,2);
dpush(&head,1);
print(head);
}




node * buildlist()
{
    int i;
    node*head=NULL;
    int a[]={1,8,3,5,4};
    for(i=sizeof(a)/sizeof(int)-1;i>=0;i--)
    {
        dpush(&head,a[i]);
    }
    return head;
}
void buildlisttest()
{
    node*head=buildlist();
    print(head);
}




void reverse(node*head){
node *temp,*p;
if(head){
    for(p=head;p;p=p->prev){
    temp=p->next;
    p->next=p->prev;
    p->prev=temp;
}
}


}
void reversetest(){
node*p;
node*head=NULL;
reverse(head);
//fena nemshi p->prev 4ade wntba3 ldata
for(p=head;p->prev;p=p->prev);
for(;p;p=p->next){
    printf("%d \t",p->data);
}
}




main()
{
    reversetest();
}
