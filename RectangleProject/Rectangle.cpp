#include "stdio.h"
#include "stdlib.h"
#include  "time.h"
#include "Rectangle.hpp"
int **Putintocoordinates(int **Coordinates,int n);
int booling;
/*
int main()
{
    int n;
    printf("Input number:");
    scanf("%d",&n);
    Coordinates=Creat(n);
    Coordinates[1][1]=5;
    Putincoordinates(Coordinates,n);
    //Coordinates=Putintocoordinates(Coordinates,n);
    Printcoordinates(Coordinates,n);
    long int Amount;
    printf("\n");
    giveAmount(n,&Amount);
    printf("%ld",Amount);
    Erase(Coordinates,n);
}
 */
int **Creat(int n)
{
    int **Temp=(int**)malloc(sizeof(int*)*n);
    for (int i=0;i<n;i++)
    {
        Temp[i]=(int*)malloc(sizeof(int)*COUNTOFCOORDINATES);
    }
    return Temp;
}
void Erase(int **Coordinates,int n)
{
    for (int i=0;i<n;i++)
    {
        free(Coordinates[i]);
    }
    free(Coordinates);
    
}
int **Putintocoordinates(int **Coordinates,int n)
{
    srand((unsigned)time(NULL));
    int x;
    for(int i=0;i<n;i++)
    {
        for (int j=0;j<COUNTOFCOORDINATES;j++)
        {
            if(j<1)
            {
                x=0+rand()%20;
                Coordinates[i][j]=x;
            }
            else if(j<2)
            {
                x=40+rand()%20;
                Coordinates[i][j]=x;
            }
            else if(j<3)
            {
                x=20+rand()%20;
                Coordinates[i][j]=x;
            }
            else
            {
                x=60+rand()%20;
                Coordinates[i][j]=x;

            }
        }
    }
    return Coordinates;
}
void Putincoordinates(int **Coordinates,int n)
{
    srand((unsigned)time(NULL));
    int x;
    for(int i=0;i<n;i++)
    {
        for (int j=0;j<COUNTOFCOORDINATES;j++)
        {
            if(j<1)
            {
                x=0+rand()%20;
                Coordinates[i][j]=x;
            }
            else if(j<2)
            {
                x=40+rand()%20;
                Coordinates[i][j]=x;
            }
            else if(j<3)
            {
                x=20+rand()%20;
                Coordinates[i][j]=x;
            }
            else
            {
                x=60+rand()%20;
                Coordinates[i][j]=x;
            }

        }
    }
}
void Printcoordinates(int **Coordinates,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d.",i);
        for (int j=0;j<COUNTOFCOORDINATES;j++)
        {
            printf("%d ",Coordinates[i][j]);
        }
        printf("\n");
    }
}
void giveAmount(int n,long int *amount,int **Coordinates)
{
    if(n==0)
    {
        *amount=0;
        return;
    }
    *amount=1;
    for(int i=0;i<n;i++)
    {
        int  Abs=giveAbs(i,Coordinates);
        if(*amount<=2147483647)
        {
            *amount*=Abs;
             printf("");
           // printf("%d\n",Abs);
        }
        else
        {
            *amount=-1;
       //     printf("Too long...");
            break;
        }
    }
}
int giveAbs(int column,int **Coordinates)
{
    booling=1;
    int x1=Coordinates[column][0],x2=Coordinates[column][1],y1=Coordinates[column][2],y2=Coordinates[column][3];
    int maxx,minx,maxy,miny,difference,booling;
    (x1>x2)?(maxx=x1,minx=x2):(maxx=x2,minx=x1);
    (y1>y2)?(maxy=y1,miny=y2):(maxy=y2,miny=y1);
    if (maxx < miny ||  maxy < minx)
        booling = 0;
    
    if (booling)
    {
        if(maxy>maxx)
           {
               if(minx<miny)
               {
                   difference=maxx-miny;
               }
               else
               {
                   difference=maxx-minx;
               }
           }
           else
           {
               if(minx<miny)
               {
                   difference=maxy-miny;
               }
               else
               {
                   difference=maxy-minx;
               }
           }
        return difference;
    }
    else
    {
        difference=0;
        return difference;
    }
    
}
//g++ Rectangle.cpp -o Rectangle

