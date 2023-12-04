#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
char data;
struct node*next;
}node;


void print(node*head){
node*p=head;
if(p)
{
    printf("%c \t",p->data);
    print(head->next);
}
}




void push(node**head,char c){
node*p;
p=(node*)malloc(sizeof(node));
if(!p){exit(1);}
p->data=c;
p->next=*head;
*head=p;
}
void pushtest(){
node*head=NULL;
push(&head,'c');
push(&head,'b');
push(&head,'a');
print(head);
}




node * buildlist()
{
    int i;
    node*head=NULL;
    char a[]="abcada";
    for(i=strlen(a)-1;i>=0;i--)
    {
        push(&head,a[i]);
    }
    return head;
}
void buildlisttest()
{
    node*head=buildlist();
    print(head);
}




void removefirst(node**head){
node*p;
if(*head)
{
    p=*head;
    *head=(*head)->next;
    free(p);
}

}
void removefirsttest(){
node*head=buildlist();
removefirst(&head);
print(head);
}




void freelist(node**head){
node*p;
while(*head)
{
    p=*head;
    *head=(*head)->next;
    free(p);
}
//Recursive:
/*node*p=*head;
if(*head)
{
    *head=(*head)->next;
}
free(p);
freelist(head);*/
}
void freelisttest(){
node*head=buildlist();
print(head);
freelist(&head);
print(head);
}



int countnodes(node*head)
{
    if(!head){return 0;}
    return 1 + countnodes(head->next);

    /*if(!head){return 0;}
    int c=0;
    node*p=head;
    while(p)
    {
         p=p->next;
         c++;
    }
   return c;*/
}


void countnodestest(){
node*head=buildlist();
printf("%d",countnodes(head));
}




int countelement(node*head,char x)
{
    int c=0;
    node*p=head;
    while(p)
    {
        if(p->data==x){c++;}
        p=p->next;
    }
    return c;
}
void countelementtest()
{
    node*head=buildlist();
    print(head);
    printf("%d",countelement(head,'a'));
}





void addtail(node*head,char c){
node *p,*q;
if(!head){push(&head,&c);}
else{
    p=head;
    for(;p->next;p=p->next);
    q=(node*)malloc(sizeof(node));
    q->data=c;
    q->next=NULL;
    p->next=q;
}
}
void addtailtest(){
node*head=buildlist();
addtail(head,'m');
print(head);
}



void removelast(node*head){
node*p;
if(head){
    if(!(head->next)){removefirst(head);}
    p=head;
    for(;p->next->next;p=p->next);
    free(p->next);
    p->next=NULL;
}
}
/*OR:
void removelast(node*head){
node*p,*q;
if(head){
    p=head;
    for(;p->next->next;p=p->next);
    q=p;
    p=p->next;
    free(p);
    q->next=NULL;
}
}*/
void removelasttest(){
node*head=NULL;
removelast(head);
print(head);
}




void swaplist(node*head,int i ,int j){
node *p,*q;
int c=1;
char cur;
for(p=head;1;p=p->next){
    if(i==c){break;}
        c++;
}
c=1;
for(q=head;1;q=q->next){
    if(j==c){break;}
    c++;
}
cur=p->data;
p->data=q->data;
q->data=cur;
}
void swaplisttest(){
node*head=buildlist();
swaplist(head,2,3);
print(head);
}


main()
{
	addtailtest();
}
