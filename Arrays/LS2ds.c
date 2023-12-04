#include<stdio.h>
#include<stdlib.h>
float power(float X, int N){            //EX1
	if(N==0) return 1;
	if(N<0) return 1/power(X,-N);
	return X*power(X,N-1);
}
void powerTest(){
    float p=power(2,-1);
    printf("%.4f",p);
}



int is_sorted(int tab[], int N){        //EX2
        if(N==1){return 1;}
        if(tab[N-1]<tab[N-2]){
            return 0;
        }
        is_sorted(tab,N-1);

}
void is_sortedTest(){
    int a[]={1,2,3};
    int b[]={3,1,2};
    if(is_sorted(a,3)==1 && is_sorted(b,3)==0){
        printf("a is sorted , b is not \n");
    }
}



int in_array(int tab[], int N, int element){        //EX3
    if(N==0){return 0;}
    if(tab[N-1]==element){
        return 1;
    }
    in_array(tab,N-1,element);
}
void in_arrayTest(){
    int a[]={5,1,0,-5};
    if(in_array(a,4,5)==1 && in_array(a,4,4)==0){
        printf("5 is in a , 4 is not \n");
    }
}



int nb_occurrence(int tab[], int N, int value){         //EX4
    if(N==0){return 0;}
    if(tab[N-1]==value){
        return nb_occurrence(tab,N-1,value) + 1;
    }
    nb_occurrence(tab,N-1,value);
}
void nb_occurrenceTest(){
    int a[]={1,2,1,1};
    printf("nb of occurrence is: %d \n",nb_occurrence(a,4,1));
}



void mirror(int tab[], int start , int end){        //EX5
   int temp;
    if(start<end){
        temp=tab[start];
        tab[start]=tab[end];
        tab[end]=temp;
        mirror(tab,start+1,end-1);
    }

}
void mirrorTest(){
    int i,a[]={5,12,0,-5};
    mirror(a,0,3);
    for(i=0;i<4;i++){
        printf("%d \t",a[i]);
    }
}




int closestHelper(int tab[] , int N , int X , int position){             //EX6
    if(N==0){return position;}
    if(abs(tab[N-1]-X)<position){       //Calculating minimal distance
        position=abs(tab[N-1]-X);
    }
    closestHelper(tab,N-1,X,position);
}
int closest(int tab[] , int N , int X , int position){ //To determine which element in tab[] corresponds
    if(X+position==tab[N-1]){                                // to the calculated distance
        return X+position;
    }
    if(X-position==tab[N-1]){
        return X-position;
    }
    closest(tab,N-1,X,position);
}

void closestTest(){
    int a[]={10,15,22,30,100},x=50,n=5,pos=abs(a[n-1]-x);
    pos=closestHelper(a,n,x,pos);
    printf("Closest element to %d is: %d",x,closest(a,n,x,pos));
}

main(){
    //powerTest();
    //is_sortedTest();
    //in_arrayTest();
    //nb_occurrenceTest();
    //mirrorTest();
    //closestTest();
}
