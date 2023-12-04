#include<stdio.h>
int bs(int a[],int l,int r,int nb)
{
    int mid;
    if(r>=l)
    {
        mid=(l+r)/2;
        if(a[mid]==nb)
        {
            return mid;
        }
        if(a[mid]<nb)
        {
           return bs(a,mid+1,r,nb);
        }
        if(a[mid]>nb)
        {
            return bs(a,l,mid-1,nb);
        }
    }
    return -1;
}
void bstest()
{
    int a[6]={1,2,3,4,5,6};
    bs(a,1,6,3);
}
main()
{
  bstest();
}
/*#include<stdio.h>
void mergerec(int a[],int b[],int n,int s)
{
    mrhelp(a,b,n,s,0,0);
}
void mrhelp(int a[],int b[],int n,int s,int p,int q)
{

     if(p<n)
    {
        printf("%d \t",a[p]);
        mrhelp(a,b,n,s,p+1,q);
    }
    if(p>=n&&q<s)
    {
        printf("%d \t",b[s]);
        mrhelp(a,b,n,s,p,q+1);
    }
}
void mergerectest()
{
    int a[5]={1,2,3,4,5},b[4]={6,7,8,9};
    mergerec(a,b,5,4);

}
