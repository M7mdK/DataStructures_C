#include<stdio.h>
void ex1()//ex1
{
    int x=5;
    int *px=&x;
    float y=13.4;
    float *py=&y;
    char z='m';
    char *pz=&z;

    printf("%d \n",*px);
    printf("%f \n",*py);
    printf("%c \n",*pz);
    printf("%p \n",px);
    printf("%p \n",py);
    printf("%p \n",pz);

    px=&y;
    printf("%d \n\n",*px);

}


void inc(int *i)//ex2
{
    *i=*i+5;
}

void inctest()
{
    int i=7;
    printf("%d \n",i);
    inc(&i);
    printf("%d \n\n",i);
}


void statarray(int a[] ,int n ,int *psum ,int *pmin , int *pmax , float *pavg)//ex3
{
   int i;
   for(i=0;i<n;i++)
   {
       *psum+=a[i];

       if(a[i]<*pmin)
        *pmin=a[i];

       if(a[i]>*pmax)
        *pmax=a[i];
   }
   *pavg=(float)*psum/n;
}
void statarraytest()
{
   int a[5]={2,3,1,6,5};
   int sum=0,min=a[0],max=a[0];
   float avg;
   statarray(a,5,&sum,&min,&max,&avg);
   printf("%d \n %d \n %d \n %f \n\n",sum,min,max,avg);
}




void recstatarray(int a[],int n,int *psum, int *pmin ,int *pmax)//ex4
{
    if(n>0)
    {
    *psum+=a[n-1];
    if(a[n-1]<*pmin)
    {
        *pmin=a[n-1];
    }
    if(a[n-1]>*pmax)
    {
        *pmax=a[n-1];
    }
    recstatarray(a,n-1,psum,pmin,pmax);
    }
}

void recstatarraytest()
{
    int a[5]={2,3,1,6,5};
    int sum=0,min=a[0],max=a[0];
   recstatarray(a,5,&sum,&min,&max);
   printf("%d \n %d \n %d",sum,min,max);
}

main()
{
//ex1();
//inctest();
//statarraytest();
//recstatarraytest();
}//done
