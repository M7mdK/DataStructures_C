#include<stdio.h>

int sum(int n)
 {
     if(n==0)
     {
         return 0;
     }
     return n+sum(n-1);
 }
 void sumtest()
 {
     printf("%d \n",sum(6));
 }





void print(int a[],int n)
{
    if(n>0)
    {
      n--;
      print(a,n); //to display 1 2 3 4 5 we need to put the call here or we will have 5 4 3 2 1 instead
      printf("%d \n",a[n]);
    }


}
void printtest()
{
    int n=5;
    int a[]={1,2,3,4,5};
    print(a,n);
}




void tr(int n)
{
    if(n>0)
    {
        int i;
        tr(n-2);//3ashan yotla3o stars from 1 to 9 2w men7ot call bel2e5er btotla3 from 9 to 1
    for(i=1;i<=n;i++)
    {
        printf("*");
    }
    printf("\n");


    }
}

void trtest()
{
    tr(9);
}




main()
{
trtest();
}
