#include "Matrix.hpp"
#include "gtest/gtest.h"
#include "stdio.h"
#include "math.h"
namespace  {
    TEST(TestsMatrix,TestAddToKnot)
    {
        knot *head=NULL;
        AddToBegin(&head,5);
        AddToBegin(&head,6);
        AddToBegin(&head,7);
        //PrintList(head);
        ASSERT_EQ(head->value,7);
        DeleteHead(&head);
    }
    TEST(TestsMatrix,TestDeleteFromKnot)
    {
        knot *head=NULL;
        AddToBegin(&head,5);
        AddToBegin(&head,6);
        AddToBegin(&head,7);
        DeleteFromBegin(&head);
        //PrintList(head);
        ASSERT_EQ(head->value,6);
        DeleteHead(&head);
    }
    TEST(TestsMatrix,TestGetNumber)
    {
        knot *head=NULL;
        AddToBegin(&head,5);
        AddToBegin(&head,6);
        AddToBegin(&head,7);
        knot *head1=GetNumber(head,1);
        //PrintList(head);
        ASSERT_EQ(head1->value,6);
        DeleteHead(&head);
    }
    TEST(TestsMatrix,TestGetSize)
    {
        knot *head=NULL;
        AddToBegin(&head,5);
        AddToBegin(&head,6);
        AddToBegin(&head,7);
        int size;
        size=GetSize(head);
        ASSERT_EQ(size,3);
        DeleteHead(&head);
    }
    TEST(TestsMatrix,TestMakeList)
    {
        knot *head=NULL;
        int *array;
        array=(int*)malloc(sizeof(int)*5);
        array[0]=5;
        array[1]=6;
        array[2]=7;
        array[3]=8;
        array[4]=9;
        MakeListFromArray(&head,array,5);
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
        free(array);
    }
    TEST(TestsMatrix,TestMatrixMultiplication1)
    {
        int array1[4]={1,2,3,4};
        int array2[4]={5,6,7,8};
        int array3[4]={9,5,4,3};
        int array4[5]={9,8,7,6,5};
        int array5[5]={4,3,2,1,1};
        int array6[5]={2,3,4,5,6};
        int array7[5]={9,8,7,6,5};
        int exp[3][5]={{59,55,51,47,45},{155,143,131,119,113},{136,123,110,97,89}};
        knot *head1=NULL;
        knot *head2=NULL;
        knot *head3=NULL;
        knot *head4=NULL;
        knot *head5=NULL;
        knot *head6=NULL;
        knot *head7=NULL;
        knotknot *list1=NULL;
        knotknot *list2=NULL;
        knotknot *list3=NULL;
        MakeListFromArray(&head1,array1,4);
        MakeListFromArray(&head2,array2,4);
        MakeListFromArray(&head3,array3,4);
        MakeListFromArray(&head4,array4,5);
        MakeListFromArray(&head5,array5,5);
        MakeListFromArray(&head6,array6,5);
        MakeListFromArray(&head7,array7,5);
        AddToBeginList(head3,&list1);
        AddToBeginList(head2,&list1);
        AddToBeginList(head1,&list1);
        AddToBeginList(head7,&list2);
        AddToBeginList(head6,&list2);
        AddToBeginList(head5,&list2);
        AddToBeginList(head4,&list2);
       // printf("colimn1 %d string2 %d ",GetSize((GetNumberList(list1,1))->rootknot),GetSizeList(list2));
        MatrixMultiplication(list1,list2,&list3);
        for (int i=0;i<3;i++)
        {
            knotknot *helphelp=GetNumberList(list3,i);
            for(int j=0;j<5;j++)
            {
                
                knot *help=GetNumber(helphelp->rootknot,j);
                ASSERT_EQ(help->value,exp[i][j]);
            }
        }
        DeleteHeadList(&list1);
        DeleteHeadList(&list2);
        DeleteHeadList(&list3);
    }
    TEST(TestsMatrix,TestMatrixMultiplication2)
    {
        int array1[3]={0,5,7};
        int array2[3]={3,5,0};
        int array3[3]={8,7,5};
        int array4[3]={2,4,8};
        int array5[3]={6,1,0};
        int array6[3]={20,6,4};
        int exp[3][3]={{170,47,28},{36,17,24},{158,69,84}};
        knot *head1=NULL;
        knot *head2=NULL;
        knot *head3=NULL;
        knot *head4=NULL;
        knot *head5=NULL;
        knot *head6=NULL;
        knotknot *list1=NULL;
        knotknot *list2=NULL;
        knotknot *list3=NULL;
        MakeListFromArray(&head1,array1,3);
        MakeListFromArray(&head2,array2,3);
        MakeListFromArray(&head3,array3,3);
        MakeListFromArray(&head4,array4,3);
        MakeListFromArray(&head5,array5,3);
        MakeListFromArray(&head6,array6,3);
        AddToBeginList(head3,&list1);
        AddToBeginList(head2,&list1);
        AddToBeginList(head1,&list1);
        AddToBeginList(head6,&list2);
        AddToBeginList(head5,&list2);
        AddToBeginList(head4,&list2);
        // printf("colimn1 %d string2 %d ",GetSize((GetNumberList(list1,1))->rootknot),GetSizeList(list2));
        MatrixMultiplication(list1,list2,&list3);
        for (int i=0;i<3;i++)
        {
            knotknot *helphelp=GetNumberList(list3,i);
            for(int j=0;j<3;j++)
            {
                
                knot *help=GetNumber(helphelp->rootknot,j);
                ASSERT_EQ(help->value,exp[i][j]);
            }
        }
        DeleteHeadList(&list1);
        DeleteHeadList(&list2);
        DeleteHeadList(&list3);
    }
    TEST(TestsMatrix,TestTransposeSquareMatrix1)
    {
        int array1[3]={1,2,3};
        int array2[3]={4,5,6};
        int array3[3]={7,8,9};
        int exp[3][3]={{1,4,7},{2,5,8},{3,6,9}};
        knot *head1=NULL;
        knot *head2=NULL;
        knot *head3=NULL;
        knotknot *list1=NULL;
        MakeListFromArray(&head1,array1,3);
        MakeListFromArray(&head2,array2,3);
        MakeListFromArray(&head3,array3,3);
        AddToBeginList(head3,&list1);
        AddToBeginList(head2,&list1);
        AddToBeginList(head1,&list1);
        TransposeSquareMatrix(&list1);
        for (int i=0;i<3;i++)
        {
            knotknot *helphelp=GetNumberList(list1,i);
            for(int j=0;j<3;j++)
            {
                knot *help=GetNumber(helphelp->rootknot,j);
                ASSERT_EQ(help->value,exp[i][j]);
            }
        }
        DeleteHeadList(&list1);
    }
    TEST(TestsMatrix,TestTransposeMatrix1)
    {
        int array1[3]={1,2,3};
        int array2[3]={4,5,6};
        int array3[3]={7,8,9};
        int exp[3][3]={{1,4,7},{2,5,8},{3,6,9}};
        knot *head1=NULL;
        knot *head2=NULL;
        knot *head3=NULL;
        knotknot *list1=NULL;
        knotknot *list2=NULL;
        MakeListFromArray(&head1,array1,3);
        MakeListFromArray(&head2,array2,3);
        MakeListFromArray(&head3,array3,3);
        AddToBeginList(head3,&list1);
        AddToBeginList(head2,&list1);
        AddToBeginList(head1,&list1);
        TransposeMatrix(list1,&list2);
        for (int i=0;i<3;i++)
        {
            knotknot *helphelp=GetNumberList(list2,i);
            for(int j=0;j<3;j++)
            {
                knot *help=GetNumber(helphelp->rootknot,j);
                ASSERT_EQ(help->value,exp[i][j]);
            }
        }
        DeleteHeadList(&list1);
        DeleteHeadList(&list2);
    }
    TEST(TestsMatrix,TestTransporateMatrix2)
    {
        int array1[5]={0,11,22,33,55};
        int array2[5]={88,99,100,2,9};
        int array3[5]={30,45,60,75,90};
        int exp[5][3]={{0,88,30},{11,99,45},{22,100,60},{33,2,75},{55,9,90}};
        knot *head1=NULL;
        knot *head2=NULL;
        knot *head3=NULL;
        knotknot *list1=NULL;
        knotknot *list2=NULL;
        MakeListFromArray(&head1,array1,5);
        MakeListFromArray(&head2,array2,5);
        MakeListFromArray(&head3,array3,5);
        AddToBeginList(head3,&list1);
        AddToBeginList(head2,&list1);
        AddToBeginList(head1,&list1);
        TransposeMatrix(list1,&list2);
        for (int i=0;i<5;i++)
        {
            knotknot *helphelp=GetNumberList(list2,i);
            for(int j=0;j<3;j++)
            {
                knot *help=GetNumber(helphelp->rootknot,j);
                ASSERT_EQ(help->value,exp[i][j]);
            }
        }
        DeleteHeadList(&list1);
        DeleteHeadList(&list2);
    }
    TEST(TestsMatrix,TestTransporateMatrix3)
    {
        int array1[5]={1,2,3,4,5};
        int array2[5]={6,7,8,9,10};
        int array3[5]={11,12,13,14,15};
        int exp[5][3]={{1,6,11},{2,7,12},{3,8,13},{4,9,14},{5,10,15}};
        knot *head1=NULL;
        knot *head2=NULL;
        knot *head3=NULL;
        knotknot *list1=NULL;
        knotknot *list2=NULL;
        MakeListFromArray(&head1,array1,5);
        MakeListFromArray(&head2,array2,5);
        MakeListFromArray(&head3,array3,5);
        AddToBeginList(head3,&list1);
        AddToBeginList(head2,&list1);
        AddToBeginList(head1,&list1);
        TransposeMatrix(list1,&list2);
        for (int i=0;i<5;i++)
        {
            knotknot *helphelp=GetNumberList(list2,i);
            for(int j=0;j<3;j++)
            {
                knot *help=GetNumber(helphelp->rootknot,j);
                ASSERT_EQ(help->value,exp[i][j]);
            }
        }
        DeleteHeadList(&list1);
        DeleteHeadList(&list2);
    }
    TEST(TestsMatrix,TestTransporateMatrix4)
    {
        int array1[7]={1,2,3,4,5,6,7};
        int array2[7]={8,9,10,11,12,13,14};
        int array3[7]={15,16,17,18,19,20,21};
        int exp[7][3]={{1,8,15},{2,9,16},{3,10,17},{4,11,18},{5,12,19},{6,13,20},{7,14,21}};
        knot *head1=NULL;
        knot *head2=NULL;
        knot *head3=NULL;
        knotknot *list1=NULL;
        knotknot *list2=NULL;
        MakeListFromArray(&head1,array1,7);
        MakeListFromArray(&head2,array2,7);
        MakeListFromArray(&head3,array3,7);
        AddToBeginList(head3,&list1);
        AddToBeginList(head2,&list1);
        AddToBeginList(head1,&list1);
        TransposeMatrix(list1,&list2);
        for (int i=0;i<7;i++)
        {
            knotknot *helphelp=GetNumberList(list2,i);
            for(int j=0;j<3;j++)
            {
                knot *help=GetNumber(helphelp->rootknot,j);
                ASSERT_EQ(help->value,exp[i][j]);
            }
        }
        DeleteHeadList(&list1);
        DeleteHeadList(&list2);
    }
    TEST(TestsMatrix,TestGauss)
    {
        int rank;
        knotd *head=NULL;
        knotd *help;
        double eps=0.00001, det;
        double array1[3]={1,2,3};
        double array2[3]={4,5,6};
        double array3[3]={7,8,9};
        knotd *head1=NULL;
        knotd *head2=NULL;
        knotd *head3=NULL;
        knotknotd *list1=NULL;
        MakeListFromArrayD(&head1,array1,3);
        MakeListFromArrayD(&head2,array2,3);
        MakeListFromArrayD(&head3,array3,3);
        AddToBeginListD(head3,&list1);
        AddToBeginListD(head2,&list1);
        AddToBeginListD(head1,&list1);
        rank = GaussMethod(&list1, eps);
        int rankexp=2;
        ASSERT_EQ(rankexp,rank);
        det=Determinant(list1,eps);
        double detexp=0;
        det=ceil(det);
        ASSERT_EQ(detexp,det);
        DeleteHeadListD(&list1);
    }
    TEST(TestsMatrix,TestGauss1)
    {
        int rank;
        knotd *head=NULL;
        knotd *help;
        double eps=0.00001, det;
        double array1[4]={1,2,4,4};
        double array2[4]={5,6,7,8};
        double array3[4]={9,10,11,12};
        knotd *head1=NULL;
        knotd *head2=NULL;
        knotd *head3=NULL;
        knotknotd *list1=NULL;
        MakeListFromArrayD(&head1,array1,4);
        MakeListFromArrayD(&head2,array2,4);
        MakeListFromArrayD(&head3,array3,4);
        AddToBeginListD(head3,&list1);
        AddToBeginListD(head2,&list1);
        AddToBeginListD(head1,&list1);
        rank = GaussMethod(&list1, eps);
        det=Determinant(list1,eps);
        double detexp=-1;
        det=ceil(det);
        ASSERT_EQ(detexp,det);
        DeleteHeadListD(&list1);
    }
    TEST(TestsMatrix,TestGauss2)
    {
        int rank;
        knotd *head=NULL;
        knotd *help;
        double eps=0.00001, det;
        double array1[4]={1,2,4,4};
        double array2[4]={5,6,7,8};
        double array3[4]={9,10,11,12};
        double array4[4]={0,55,3,22};
        knotd *head1=NULL;
        knotd *head2=NULL;
        knotd *head3=NULL;
        knotd *head4=NULL;
        knotknotd *list1=NULL;
        MakeListFromArrayD(&head1,array1,4);
        MakeListFromArrayD(&head2,array2,4);
        MakeListFromArrayD(&head3,array3,4);
         MakeListFromArrayD(&head4,array4,4);
        AddToBeginListD(head4,&list1);
        AddToBeginListD(head3,&list1);
        AddToBeginListD(head2,&list1);
        AddToBeginListD(head1,&list1);
        rank = GaussMethod(&list1, eps);
        int rankexp=4;
        ASSERT_EQ(rankexp,rank);
        det=Determinant(list1,eps);
        double detexp=572;
        det=ceil(det);
        ASSERT_EQ(detexp,det);
        DeleteHeadListD(&list1);
    }
    TEST(TestsMatrix,TestTrack)
    {
        int array1[3]={1,2,3};
        int array2[3]={4,5,6};
        int array3[3]={7,8,9};
        knot *head1=NULL;
        knot *head2=NULL;
        knot *head3=NULL;
        knotknot *list1=NULL;
        MakeListFromArray(&head1,array1,3);
        MakeListFromArray(&head2,array2,3);
        MakeListFromArray(&head3,array3,3);
        AddToBeginList(head3,&list1);
        AddToBeginList(head2,&list1);
        AddToBeginList(head1,&list1);
        int track=TraceOfMatrix(list1);
        ASSERT_EQ(track,15);
        DeleteHeadList(&list1);
    }
    TEST(TestsMatrix,TestTrack1)
    {
        int array1[2]={0,11};
        int array2[2]={55,77};
        knot *head1=NULL;
        knot *head2=NULL;
        knot *head3=NULL;
        knotknot *list1=NULL;
        MakeListFromArray(&head1,array1,2);
        MakeListFromArray(&head2,array2,2);
        AddToBeginList(head2,&list1);
        AddToBeginList(head1,&list1);
        int track=TraceOfMatrix(list1);
        ASSERT_EQ(track,77);
        DeleteHeadList(&list1);
    }
    TEST(TestsMatrix,TestTrack2)
    {
        int array1[3]={1,2,3};
        int array2[3]={4,5,6};
        int array3[3]={7,8,9};
        int array4[3]={10,11,12};
        knot *head1=NULL;
        knot *head2=NULL;
        knot *head3=NULL;
        knot *head4=NULL;
        knotknot *list1=NULL;
        MakeListFromArray(&head1,array1,3);
        MakeListFromArray(&head2,array2,3);
        MakeListFromArray(&head3,array3,3);
        MakeListFromArray(&head4,array4,3);
        AddToBeginList(head4,&list1);
        AddToBeginList(head3,&list1);
        AddToBeginList(head2,&list1);
        AddToBeginList(head1,&list1);
        int track=TraceOfMatrix(list1);
        ASSERT_EQ(track,-1);
        DeleteHeadList(&list1);
    }
}
//g++ -std=c++11 -stdlib=libc++  Matrix.cpp  Matrix_Tests.cpp Matrix_main.cc -lgtest -lpthread -o MatrixTests
//valgrind --leak-check=full --leak-resolution=high ./MatrixTests
