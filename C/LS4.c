#include<stdio.h>
#include<math.h>
#include<stdlib.h>


typedef struct//ex1
{
int x;
int y;
}point;


void printpoint(point a)//ex2
{
    printf("[%d,%d] \n",a.x,a.y);
}

void printpointtest()
{
    point a={2,3};
    printpoint(a);

}


double distance(point a,point b)//ex3
{
    return sqrt(pow(b.x-a.x,2)+pow(b.y-a.y,2));
}

void distancetest()
{
  point a={1,1},b={5,1};
  float d=distance(a,b);
  printf("\ndistance=%f \n\n",d);
}


typedef struct//ex4
{
    point s[4];
}quad;


void printquad(point s[4])//ex5
{
    int i;
    for(i=0;i<4;i++)
    {
        printpoint(s[i]);
    }

}

void printquadtest()
{
point s[4]={{1,2},{3,4},{5,6},{7,8}};
printquad(s);
}

float perimeter(point s[4])//ex6
{
    float d1,d2,d3,d4;
    d1=distance(s[0],s[1]);
    d2=distance(s[1],s[2]);
    d3=distance(s[2],s[3]);
    d4=distance(s[3],s[0]);
    printf("\n lengths of the sides:%f \t %f \t %f \t %f \n\n\n",d1,d2,d3,d4);
    return d1+d2+d3+d4;
}

void perimetertest()
{
   point s[4]={{1,1},{2,1},{2,2},{1,2}};
   float p=perimeter(s);
   printf("perimeter=%f \n\n\n",p);
}


int issquare(point s[4])//ex7
{
    if(s[0].x==s[3].x && s[1].x==s[2].x && s[0].y==s[1].y && s[2].y==s[3].y)
    {
        return 1;
    }
    return 0;
}

void issquaretest()
{
    point s[4]={{1,1},{2,1},{2,2},{1,2}};
    point a[4]={{0,0},{2,1},{2,2},{1,2}};
    if(issquare(s)==1&&issquare(a)!=1)
    {
        printf("quad s is sequare \n quad a is not sequare \n\n\n");
    }
}



int isinsidesquare(point s[4],point a)//ex8
{
    if(issquare(s)==1)
    {
        if(a.x<s[1].x&&a.x>s[0].x && a.y<s[2].y&&a.y>s[0].y)
        {
            return 1;
        }
        else{return 0;}
    }
    else
    {
        return -1;
    }
}

void isinsidesquaretest()
{
    point s[4]={{1,1},{4,1},{4,4},{1,4}};
    point q[4]={{0,0},{2,1},{2,2},{1,2}};
    point a={2,2},b={5,5};

    if(isinsidesquare(q,a)==-1)
    {
        printf("This quad is not square\n");
    }
    if(isinsidesquare(s,a)==1)
    {
        printf("Point a is inside the square s\n");
    }
    if(isinsidesquare(s,b)==0)
    {
        printf("Point b is outside the square s \n");
    }
}



main()
{
printpointtest();
distancetest();
printquadtest();
perimetertest();
issquaretest();
isinsidesquaretest();
}
