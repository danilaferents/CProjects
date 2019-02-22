#include "Rectangle_Tests.hpp"
#include "Rectangle.hpp"
#include "gtest/gtest.h"
#include "stdio.h"
namespace  {
    TEST(RectangleTests,TestgiveAbs1)
    {
        int n=SIZE1;
        int **Coordinates=Creat(n);
        int Coordinates1[SIZE1][COUNTOFCOORDINATES]={{5,15,10,25}};
        for(int i=0;i<n;i++)
        {
            for (int j=0;j<COUNTOFCOORDINATES;j++)
            {
                Coordinates[i][j]=Coordinates1[i][j];
                printf("");
            }
        }
        int exp=giveAbs(0,Coordinates);
        ASSERT_EQ(5,exp);
        Erase(Coordinates,n);
    }
    TEST(RectangleTests,TestgiveAbs2)
    {
        int n=SIZE1;
        int **Coordinates=Creat(n);
        int Coordinates1[SIZE1][COUNTOFCOORDINATES]={{0,10,15,20}};
        for(int i=0;i<n;i++)
        {
            for (int j=0;j<COUNTOFCOORDINATES;j++)
            {
                Coordinates[i][j]=Coordinates1[i][j];
                printf("");
            }
        }
        int exp=giveAbs(0,Coordinates);
        ASSERT_EQ(0,exp);
        Erase(Coordinates,n);
    }
    TEST(RectangleTests,TestgiveAbs3)
    {
        int n=SIZE1;
        int **Coordinates=Creat(n);
        int Coordinates1[SIZE1][COUNTOFCOORDINATES]={{50,20,15,100}};
        for(int i=0;i<n;i++)
        {
            for (int j=0;j<COUNTOFCOORDINATES;j++)
            {
                Coordinates[i][j]=Coordinates1[i][j];
                printf("");
            }
        }
        int exp=giveAbs(0,Coordinates);
        ASSERT_EQ(30,exp);
        Erase(Coordinates,n);
    } TEST(RectangleTests,TestgiveAbs4)
    {
        int n=SIZE1;
        int **Coordinates=Creat(n);
        int Coordinates1[SIZE1][COUNTOFCOORDINATES]={{0,0,0,0}};
        for(int i=0;i<n;i++)
        {
            for (int j=0;j<COUNTOFCOORDINATES;j++)
            {
                Coordinates[i][j]=Coordinates1[i][j];
                printf("");
            }
        }
        int exp=giveAbs(0,Coordinates);
        ASSERT_EQ(0,exp);
        Erase(Coordinates,n);
    }
    TEST(RectangleTests,TestgiveAmount1)
    {
        int n=SIZE2;
        int **Coordinates=Creat(n);
        int Coordinates1[SIZE2][COUNTOFCOORDINATES]={{18,59,24,69 },{9,47,28,70 },{16,56,36,79},{0,45,25,69}};
        for(int i=0;i<n;i++)
        {
            for (int j=0;j<COUNTOFCOORDINATES;j++)
            {
                Coordinates[i][j]=Coordinates1[i][j];
                printf("");
            }
        }
        long int exp;
        giveAmount(n,&exp,Coordinates);
        ASSERT_EQ(266000,exp);
        Erase(Coordinates,n);
    }
    TEST(RectangleTests,TestgiveAmount2)
    {
        int n=SIZE3;
        int **Coordinates=Creat(n);
        int Coordinates1[SIZE3][COUNTOFCOORDINATES]={{13,54,39,71},{19,57,31,76},{0,51,34,65},{11,59,36,71},{14,59,31,69},{11,58,28,68},{0,41,22,66},{9,40,23,60}};
        for(int i=0;i<n;i++)
        {
            for (int j=0;j<COUNTOFCOORDINATES;j++)
            {
                Coordinates[i][j]=Coordinates1[i][j];
                printf("");
            }
        }
        long int exp;
        giveAmount(n,&exp,Coordinates);
        ASSERT_EQ(-1,exp);
        Erase(Coordinates,n);
    }
    TEST(RectangleTests,TestgiveAmount3)
    {
        int n=SIZE4;
        int **Coordinates=Creat(n);
        int Coordinates1[SIZE4][COUNTOFCOORDINATES]={};
        long int exp;
        giveAmount(n,&exp,Coordinates);
        ASSERT_EQ(0,exp);
        Erase(Coordinates,n);
    }
    TEST(RectangleTests,TestgiveAmount4)
    {
        int n=SIZE5;
        int **Coordinates=Creat(n);
        int Coordinates1[SIZE5][COUNTOFCOORDINATES]={{10,50,39,60},{13,51,32,66},{5,41,39,66}};
        for(int i=0;i<n;i++)
        {
            for (int j=0;j<COUNTOFCOORDINATES;j++)
            {
                Coordinates[i][j]=Coordinates1[i][j];
                printf("");
            }
        }
        long int exp;
        giveAmount(n,&exp,Coordinates);
        ASSERT_EQ(418,exp);
        Erase(Coordinates,n);
    }
}
//g++ -std=c++11 -stdlib=libc++  Rectangle_Tests.cpp  Rectangle.cpp Rectangle_main.cc -lgtest -lpthread -o RectangleTests
