#include<stdio.h>

//ex1
int sum(int a[],int n)
{
    int i,s=0;
    for(i=0;i<n;i++)
    {
        s+=a[i];
    }
    return s;
}

void sumtest()
{
    int a[5]={1,2,3,4,5};
    printf("%d \n",sum(a,5));
}





//ex2
int sumrec(int a[],int n)
{
    if(n==0)
    {
        return 0;
    }
    return a[n-1]+sumrec(a,n-1);
}

void sumrectest()
{
    int a[5]={1,2,3,4,5};
    printf("%d \n",sumrec(a,5));
}





//ex3
int srt(int a[],int n)
{
    return srthelp(a,n,0);
}
int srthelp(int a[],int n,int p)
{
    if(n==0)
    {
        return p;
    }
    p=p+a[n-1];
    return srthelp(a,n-1,p);
}
/*or helper:

if(p==n)
    {
       return 0;
    }
    return a[p]+srthelp(a,n,p+1);
    */

void srttest()
{
    int a[5]={1,2,3,4,5};
    printf("%d \n",srt(a,5));
}






//iterative merge
void mergeiter(int a[],int b[],int n,int s)
{
    int c[n+s],i=0,j=0,k=0;
    while(i<n||j<s)
    {
        if(i<n)
        {
            c[k]=a[i];
            k++;i++;
        }

        if(i==n&&j<s)
        {
            c[k]=b[j];
            k++;j++;
        }

    }

for(i=0;i<n+s;i++)
    {
        printf("%d \t",c[i]);
    }
}

void mergeitertest()
{
    int a[5]={1,2,3,4,5},b[4]={6,7,8,9};
    mergeiter(a,b,5,4);

}



main()
{
sumtest();
sumrectest();
srttest();
mergeitertest();
}
