#include "Matrix.hpp"
#include "gtest/gtest.h"
#include "stdio.h"
#include "math.h"
namespace  {
    TEST(TestsMatrix,TestAddtoKnot)
    {
        knot *head=NULL;
        AddtoBegin(&head,5);
        AddtoBegin(&head,6);
        AddtoBegin(&head,7);
        //PrintList(head);
        ASSERT_EQ(head->value,7);
        DeleteHead(&head);
    }
    TEST(TestsMatrix,TestDeletefromKnot)
    {
        knot *head=NULL;
        AddtoBegin(&head,5);
        AddtoBegin(&head,6);
        AddtoBegin(&head,7);
        DeletefromBegin(&head);
        //PrintList(head);
        ASSERT_EQ(head->value,6);
        DeleteHead(&head);
    }
    TEST(TestsMatrix,TestGetNumber)
    {
        knot *head=NULL;
        AddtoBegin(&head,5);
        AddtoBegin(&head,6);
        AddtoBegin(&head,7);
        knot *Head=GetNumber(head,1);
        //PrintList(head);
        ASSERT_EQ(Head->value,6);
        DeleteHead(&head);
    }
    TEST(TestsMatrix,TestGetLast)
    {
        knot *head=NULL;
        AddtoBegin(&head,5);
        AddtoBegin(&head,6);
        AddtoBegin(&head,7);
        knot *Head=GetLast(head);
        ASSERT_EQ(Head->value,5);
        DeleteHead(&head);
    }
    
    TEST(TestsMatrix,TestGetSize)
    {
        knot *head=NULL;
        AddtoBegin(&head,5);
        AddtoBegin(&head,6);
        AddtoBegin(&head,7);
        int size;
        size=GetSize(head);
        ASSERT_EQ(size,3);
        DeleteHead(&head);
    }
    TEST(TestsMatrix,TestMakeList)
    {
        knot *head=NULL;
        int *Massife;
        Massife=(int*)malloc(sizeof(int)*5);
        Massife[0]=5;
        Massife[1]=6;
        Massife[2]=7;
        Massife[3]=8;
        Massife[4]=9;
        MakeListfromArray(&head,Massife,5);
        knot *help=GetNumber(head,0);
        ASSERT_EQ(help->value,5);
        help=help->next;
        ASSERT_EQ(help->value,6);
        help=help->next;
        ASSERT_EQ(help->value,7);
        help=help->next;
        ASSERT_EQ(help->value,8);
        help=help->next;
        ASSERT_EQ(help->value,9);
        DeleteHead(&head);
        free(Massife);
    }
    TEST(TestsMatrix,TestMatrixMultiplication1)
    {
        int size1=3,size2=4,size3=5;
        int Massife1[12]={1,2,3,4,5,6,7,8,9,5,4,3};
        int Massife2[15]={9,8,7,6,5,4,3,2,1,1,2,3,4,5,6};
        knot *list1=NULL;
        knot *list2=NULL;
        knot *list3=NULL;
        MakeListfromArray(&list1,Massife1,size1*size2);
        MakeListfromArray(&list2,Massife2,size1*size3);
        Matrixmultiplication(list1,list2,size2,size3,size1,&list3);
        int Massifeexp[4][5]={{23,23,23,23,25},{68,65,62,59,61},{113,107,101,95,97},{67,61, 55,49,47}};
        knot *help=NULL;
        for(int i=0;i<4;i++)
            for (int j=0;j<5;j++)
            {
                help=GetNumber(list3,i*5+j);
                ASSERT_EQ(help->value,Massifeexp[i][j]);
            }
        DeleteHead(&list1);
        DeleteHead(&list2);
        DeleteHead(&list3);
    }
    TEST(TestsMatrix,TestMatrixMultiplication2)
    {
        int size1=3,size2=3,size3=3;
        int Massife1[9]={0,5,7,3,5,0,8,7,5};
        int Massife2[9]={2,4,8,6,1,0,20,6,4};
        knot *list1=NULL;
        knot *list2=NULL;
        knot *list3=NULL;
        MakeListfromArray(&list1,Massife1,size1*size2);
        MakeListfromArray(&list2,Massife2,size1*size3);
        Matrixmultiplication(list1,list2,size2,size3,size1,&list3);
        int Massifeexp[3][3]={{170,47,28},{36,17,24},{158,69,84}};
        knot *help=NULL;
        for(int i=0;i<3;i++)
            for (int j=0;j<3;j++)
            {
                help=GetNumber(list3,i*3+j);
                ASSERT_EQ(help->value,Massifeexp[i][j]);
            }
        DeleteHead(&list1);
        DeleteHead(&list2);
        DeleteHead(&list3);
    }
    TEST(TestsMatrix,TestTransporateSquareMatrix1)
    {
        int size1=3,size2=3;
        int Massife1[9]={1,2,3,4,5,6,7,8,9};
        int Massife2[9]={1,4,7,2,5,8,3,6,9};
        knot *list1=NULL;
        knot *list2=NULL;
        MakeListfromArray(&list1,Massife1,size1*size2);
        MakeListfromArray(&list2,Massife2,size1*size2);
        //printfMatrix(list1,size2,size1);
        //printf("\n");
        TransporateSquareMatrix(&list1,size1,size2);
        //printfMatrix(list1,size2,size1);
        knot *help1=NULL;
        knot *help2=NULL;
        for(int i=0;i<3;i++)
            for (int j=0;j<3;j++)
            {
                help1=GetNumber(list1,i*3+j);
                help2=GetNumber(list2,i*3+j);
                ASSERT_EQ(help1->value,help2->value);
            }
        DeleteHead(&list1);
        DeleteHead(&list2);
    }
    TEST(TestsMatrix,TestTransporateMatrix1)
    {
        int size1=3,size2=3;
        int Massife1[9]={1,2,3,4,5,6,7,8,9};
        int Massife2[9]={1,4,7,2,5,8,3,6,9};
        knot *list1=NULL;
        knot *list2=NULL;
        knot *list3=NULL;
        CreatNewList(&list3,size1*size2);
        MakeListfromArray(&list1,Massife1,size1*size2);
        MakeListfromArray(&list2,Massife2,size1*size2);
        //printfMatrix(list1,size2,size1);
        //printf("\n");
        TransporateMatrix(list1,&list3,size1,size2);
        //printfMatrix(list1,size2,size1);
        knot *help1=NULL;
        knot *help2=NULL;
        for(int i=0;i<3;i++)
            for (int j=0;j<3;j++)
            {
                help1=GetNumber(list2,i*3+j);
                help2=GetNumber(list3,i*3+j);
                ASSERT_EQ(help1->value,help2->value);
            }
        DeleteHead(&list1);
        DeleteHead(&list2);
        DeleteHead(&list3);
    }
    TEST(TestsMatrix,TestTransporateMatrix2)
    {
        int size1=3,size2=5;
        int Massife1[15]={0,11,22,33,55,88,99,100,2,9,30,45,60,75,90};
        int Massife2[15]={0,88,30,11,99,45,22,100,60,33,2,75,55,9,90};
        knot *list1=NULL;
        knot *list2=NULL;
        knot *list3=NULL;
        CreatNewList(&list3,size1*size2);
        MakeListfromArray(&list1,Massife1,size1*size2);
        MakeListfromArray(&list2,Massife2,size1*size2);
        //printfMatrix(list1,size2,size1);
        //printf("\n");
        TransporateMatrix(list1,&list3,size1,size2);
        //printfMatrix(list1,size2,size1);
        knot *help1=NULL;
        knot *help2=NULL;
        for(int i=0;i<5;i++)
            for (int j=0;j<3;j++)
            {
                help1=GetNumber(list2,i*3+j);
                help2=GetNumber(list3,i*3+j);
                ASSERT_EQ(help1->value,help2->value);
            }
        DeleteHead(&list1);
        DeleteHead(&list2);
        DeleteHead(&list3);
    }
    TEST(TestsMatrix,TestTransporateMatrix3)
    {
        int size1=3,size2=5;
        int Massife1[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
        int Massife2[15]={1,4,7,10,13,2,5,8,11,14,3,6,9,12,15};
        knot *list1=NULL;
        knot *list2=NULL;
        knot *list3=NULL;
        CreatNewList(&list3,size1*size2);
        MakeListfromArray(&list1,Massife1,size1*size2);
        MakeListfromArray(&list2,Massife2,size1*size2);
        //printfMatrix(list1,size2,size1);
        //printf("\n");
        TransporateMatrix(list1,&list3,size2,size1);
        //printfMatrix(list1,size2,size1);
        knot *help1=NULL;
        knot *help2=NULL;
        for(int i=0;i<3;i++)
            for (int j=0;j<5;j++)
            {
                help1=GetNumber(list2,i*3+j);
                help2=GetNumber(list3,i*3+j);
                ASSERT_EQ(help1->value,help2->value);
            }
        DeleteHead(&list1);
        DeleteHead(&list2);
        DeleteHead(&list3);
    }
    TEST(TestsMatrix,TestTransporateMatrix4)
    {
        int size1=3,size2=7;
        int Massife1[21]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21};
        int Massife2[21]={1,8,15,2,9,16,3,10,17,4,11,18,5,12,19,6,13,20,7,14,21};
        knot *list1=NULL;
        knot *list2=NULL;
        knot *list3=NULL;
        CreatNewList(&list3,size1*size2);
        MakeListfromArray(&list1,Massife1,size1*size2);
        MakeListfromArray(&list2,Massife2,size1*size2);
        //printfMatrix(list1,size2,size1);
        //printf("\n");
        TransporateMatrix(list1,&list3,size1,size2);
        //printfMatrix(list1,size2,size1);
        knot *help1=NULL;
        knot *help2=NULL;
        for(int i=0;i<7;i++)
            for (int j=0;j<3;j++)
            {
                help1=GetNumber(list2,i*3+j);
                help2=GetNumber(list3,i*3+j);
                ASSERT_EQ(help1->value,help2->value);
            }
        DeleteHead(&list1);
        DeleteHead(&list2);
        DeleteHead(&list3);
    }
    TEST(TestsMatrix,TestGauss)
    {
        int m=3, n=3,rank;
        knotd *head=NULL;
        knotd *help;
        double eps=0.00001, det;
        double Massife[9]={1,2,4,4,5,6,7,8,9};
        MakeListfromArrayD(&head,Massife,9);
        rank = gaussMethod(m, n, &head, eps);
        int rankexp=3;
        ASSERT_EQ(rankexp,rank);
        det=Determinant(m,n,head,eps);
        double detexp=-3;
        det=ceil(det);
        ASSERT_EQ(detexp,det);
        DeleteHeadD(&head);
    }
    TEST(TestsMatrix,TestGauss1)
    {
        int m=3, n=4,rank;
        knotd *head=NULL;
        knotd *help;
        double eps=0.00001, det;
        double Massife[12]={1,2,4,4,5,6,7,8,9,10,11,12};
        MakeListfromArrayD(&head,Massife,12);
        rank = gaussMethod(m, n, &head, eps);
        det=Determinant(m,n,head,eps);
        double detexp=-1;
        det=ceil(det);
        ASSERT_EQ(detexp,det);
        DeleteHeadD(&head);
    }
    TEST(TestsMatrix,TestTrack)
    {
        int size1=3,size2=3,size3=0;
        int Massife1[9]={1,2,3,4,5,6,7,8,9};
        knot *list1=NULL;
        MakeListfromArray(&list1,Massife1,size1*size2);
        int track=TrackOfMatrix(list1,size1,size2);
        ASSERT_EQ(track,15);
        DeleteHead(&list1);
    }
    TEST(TestsMatrix,TestTrack1)
    {
        int size1=2,size2=2,size3=0;
        int Massife1[4]={0,11,55,77};
        knot *list1=NULL;
        MakeListfromArray(&list1,Massife1,size1*size2);
        int track=TrackOfMatrix(list1,size1,size2);
        ASSERT_EQ(track,77);
        DeleteHead(&list1);
    }
    TEST(TestsMatrix,TestTrack2)
    {
        int size1=4,size2=3,size3=0;
        int Massife1[9]={1,2,3,4,5,6,7,8,9};
        knot *list1=NULL;
        MakeListfromArray(&list1,Massife1,size1*size2);
        int track=TrackOfMatrix(list1,size1,size2);
        ASSERT_EQ(track,-1);
        DeleteHead(&list1);
    }
}
//g++ -std=c++11 -stdlib=libc++  Matrix.cpp  Matrix_Tests.cpp Matrix_main.cc -lgtest -lpthread -o MatrixTests
//valgrind --leak-check=full --leak-resolution=high ./MatrixTests
