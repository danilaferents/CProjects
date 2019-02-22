#include "Matrix.hpp"
#include "gtest/gtest.h"
#include "stdio.h"
#include "math.h"
namespace  {
    TEST(TestsMatrix,TestAddToBegin)
    {
        knot *head=NULL;
        int *int1,*int2,*int3;
        int1=(int*)malloc(sizeof(int));
        int2=(int*)malloc(sizeof(int));
        int3=(int*)malloc(sizeof(int));
        *int1=5;
        *int2=6;
        *int3=7;
        AddToBegin(&head,int1);
        AddToBegin(&head,int2);
        AddToBegin(&head,int3);
        ASSERT_EQ(*(int*)(head->value),7);
        free(int1);
        free(int2);
        free(int3);
        DeleteHead(&head);
    }
    TEST(TestsMatrix,TestAddToBeginList)
    {
        knot *head=NULL;
        knotknot *list=NULL;
        int *int1,*int2,*int3;
        int1=(int*)malloc(sizeof(int));
        int2=(int*)malloc(sizeof(int));
        int3=(int*)malloc(sizeof(int));
        *int1=5;
        *int2=6;
        *int3=7;
        AddToBegin(&head,int1);
        AddToBegin(&head,int2);
        AddToBegin(&head,int3);
        ASSERT_EQ(*(int*)(head->value),7);
        free(int1);
        free(int2);
        free(int3);
        DeleteHead(&head);
    }
    TEST(TestsMatrix,TestGetNumber)
    {
        knot *head=NULL;
        int *int1,*int2,*int3;
        int1=(int*)malloc(sizeof(int));
        int2=(int*)malloc(sizeof(int));
        int3=(int*)malloc(sizeof(int));
        *int1=5;
        *int2=6;
        *int3=7;
        AddToBegin(&head,int1);
        AddToBegin(&head,int2);
        AddToBegin(&head,int3);
        knot *head1=GetNumber(head,1);
        ASSERT_EQ(*(int*)(head1->value),6);
        free(int1);
        free(int2);
        free(int3);
        DeleteHead(&head);
    }
    TEST(TestsMatrix,TestGetSize)
    {
        knot *head=NULL;
        int *int1,*int2,*int3;
        int1=(int*)malloc(sizeof(int));
        int2=(int*)malloc(sizeof(int));
        int3=(int*)malloc(sizeof(int));
        *int1=5;
        *int2=6;
        *int3=7;
        AddToBegin(&head,int1);
        AddToBegin(&head,int2);
        AddToBegin(&head,int3);
        int size;
        size=GetSize(head);
        ASSERT_EQ(size,3);
        free(int1);
        free(int2);
        free(int3);
        DeleteHead(&head);
    }
    TEST(TestsMatrix,TestMakeList)
    {
        knot *head=NULL;
        int **array;
        array=(int**)malloc(sizeof(int*)*5);
        for (int i=0;i<5;i++) array[i]=(int*)malloc(sizeof(int));
        *array[0]=5;
        *array[1]=6;
        *array[2]=7;
        *array[3]=8;
        *array[4]=9;
        MakeListFromArray(&head,array,5);
        knot *help=GetNumber(head,0);
        ASSERT_EQ(*(int*)(help->value),5);
        help=help->next;
        ASSERT_EQ(*(int*)(help->value),6);
        help=help->next;
        ASSERT_EQ(*(int*)(help->value),7);
        help=help->next;
        ASSERT_EQ(*(int*)(help->value),8);
        help=help->next;
        ASSERT_EQ(*(int*)(help->value),9);
        DeleteHead(&head);
        for (int i=0;i<5;i++) free(array[i]);
        free(array);
    }
    TEST(TestsMatrix,TestMatrixMultiplication1)
    {
        int harray1[4]={1,2,3,4};
        int *array1[4]={&harray1[0],&harray1[1],&harray1[2],&harray1[3]};
        int harray2[4]={5,6,7,8};
        int *array2[4]={&harray2[0],&harray2[1],&harray2[2],&harray2[3]};
        int harray3[4]={9,5,4,3};
        int *array3[4]={&harray3[0],&harray3[1],&harray3[2],&harray3[3]};
        int harray4[5]={9,8,7,6,5};
        int *array4[5]={&harray4[0],&harray4[1],&harray4[2],&harray4[3],&harray4[4]};
        int harray5[5]={4,3,2,1,1};
        int *array5[5]={&harray5[0],&harray5[1],&harray5[2],&harray5[3],&harray5[4]};
        int harray6[5]={2,3,4,5,6};
        int *array6[5]={&harray6[0],&harray6[1],&harray6[2],&harray6[3],&harray6[4]};
        int harray7[5]={9,8,7,6,5};
        int *array7[5]={&harray7[0],&harray7[1],&harray7[2],&harray7[3],&harray7[4]};
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
        MatrixMultiplication(list1,list2,&list3);
        for (int i=0;i<3;i++)
        {
            knotknot *helphelp=GetNumberList(list3,i);
            for(int j=0;j<5;j++)
            {
                
                knot *help=GetNumber(helphelp->rootknot,j);
                ASSERT_EQ(*(int*)(help->value),exp[i][j]);
                free(help->value);
            }
        }
        DeleteHeadList(&list1);
        DeleteHeadList(&list2);
        DeleteHeadList(&list3);
    }
    TEST(TestsMatrix,TestMatrixMultiplication2)
    {
        int harray1[3]={0,5,7};
        int *array1[3]={&harray1[0],&harray1[1],&harray1[2]};
        int harray2[3]={3,5,0};
        int *array2[3]={&harray2[0],&harray2[1],&harray2[2]};
        int harray3[3]={8,7,5};
        int *array3[3]={&harray3[0],&harray3[1],&harray3[2]};
        int harray4[3]={2,4,8};
        int *array4[3]={&harray4[0],&harray4[1],&harray4[2]};
        int harray5[3]={6,1,0};
        int *array5[3]={&harray5[0],&harray5[1],&harray5[2]};
        int harray6[3]={20,6,4};
        int *array6[3]={&harray6[0],&harray6[1],&harray6[2]};
        int exp[3][3]={{170,47,28},{36,17,24},{158,69,84}};
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
        MatrixMultiplication(list1,list2,&list3);
        for (int i=0;i<3;i++)
        {
            knotknot *helphelp=GetNumberList(list3,i);
            for(int j=0;j<3;j++)
            {
                knot *help=GetNumber(helphelp->rootknot,j);
                ASSERT_EQ(*(int*)(help->value),exp[i][j]);
                free(help->value);
            }
        }
        DeleteHeadList(&list1);
        DeleteHeadList(&list2);
        DeleteHeadList(&list3);
    }
    TEST(TestsMatrix,TestTransposeSquareMatrix1)
    {
        int harray1[3]={1,2,3};
        int *array1[3]={&harray1[0],&harray1[1],&harray1[2]};
        int harray2[3]={4,5,6};
        int *array2[3]={&harray2[0],&harray2[1],&harray2[2]};
        int harray3[3]={7,8,9};
        int *array3[3]={&harray3[0],&harray3[1],&harray3[2]};
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
                ASSERT_EQ(*(int*)help->value,exp[i][j]);
            }
        }
        DeleteHeadList(&list1);
    }
    TEST(TestsMatrix,TestTransposeMatrix1)
    {
        int harray1[3]={1,2,3};
        int *array1[3]={&harray1[0],&harray1[1],&harray1[2]};
        int harray2[3]={4,5,6};
        int *array2[3]={&harray2[0],&harray2[1],&harray2[2]};
        int harray3[3]={7,8,9};
        int *array3[3]={&harray3[0],&harray3[1],&harray3[2]};
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
                ASSERT_EQ(*(int*)help->value,exp[i][j]);
            }
        }
        DeleteHeadList(&list1);
        DeleteHeadList(&list2);
    }
    TEST(TestsMatrix,TestTransporateMatrix2)
    {
        int harray1[5]={0,11,22,33,55};
        int *array1[5]={&harray1[0],&harray1[1],&harray1[2],&harray1[3],&harray1[4]};
        int harray2[5]={88,99,100,2,9};
        int *array2[5]={&harray2[0],&harray2[1],&harray2[2],&harray2[3],&harray2[4]};
        int harray3[5]={30,45,60,75,90};
        int *array3[5]={&harray3[0],&harray3[1],&harray3[2],&harray3[3],&harray3[4]};
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
                ASSERT_EQ(*(int*)help->value,exp[i][j]);
            }
        }
        DeleteHeadList(&list1);
        DeleteHeadList(&list2);
    }
    TEST(TestsMatrix,TestTransporateMatrix3)
    {
        int harray1[5]={1,2,3,4,5};
        int *array1[5]={&harray1[0],&harray1[1],&harray1[2],&harray1[3],&harray1[4]};
        int harray2[5]={6,7,8,9,10};
        int *array2[5]={&harray2[0],&harray2[1],&harray2[2],&harray2[3],&harray2[4]};
        int harray3[5]={11,12,13,14,15};
        int *array3[5]={&harray3[0],&harray3[1],&harray3[2],&harray3[3],&harray3[4]};
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
                ASSERT_EQ(*(int*)help->value,exp[i][j]);
            }
        }
        DeleteHeadList(&list1);
        DeleteHeadList(&list2);
    }
    TEST(TestsMatrix,TestTransporateMatrix4)
    {
        int harray1[7]={1,2,3,4,5,6,7};
        int *array1[7]={&harray1[0],&harray1[1],&harray1[2],&harray1[3],&harray1[4],&harray1[5],&harray1[6]};
        int harray2[7]={8,9,10,11,12,13,14};
        int *array2[7]={&harray2[0],&harray2[1],&harray2[2],&harray2[3],&harray2[4],&harray2[5],&harray2[6]};
        int harray3[7]={15,16,17,18,19,20,21};
        int *array3[7]={&harray3[0],&harray3[1],&harray3[2],&harray3[3],&harray3[4],&harray3[5],&harray3[6]};
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
                ASSERT_EQ(*(int*)help->value,exp[i][j]);
            }
        }
        DeleteHeadList(&list1);
        DeleteHeadList(&list2);
    }
    TEST(TestsMatrix,TestGauss)
    {
        int rank;
        knot *head=NULL;
        knot *help;
        double eps=0.00001, det;
        double harray1[3]={1,2,3};
        double *array1[3]={&harray1[0],&harray1[1],&harray1[2]};
        double harray2[3]={4,5,6};
        double *array2[3]={&harray2[0],&harray2[1],&harray2[2]};
        double harray3[3]={7,8,9};
        double *array3[3]={&harray3[0],&harray3[1],&harray3[2]};
        knot *head1=NULL;
        knot *head2=NULL;
        knot *head3=NULL;
        knotknot *list1=NULL;
        MakeListFromArrayD(&head1,array1,3);
        MakeListFromArrayD(&head2,array2,3);
        MakeListFromArrayD(&head3,array3,3);
        AddToBeginList(head3,&list1);
        AddToBeginList(head2,&list1);
        AddToBeginList(head1,&list1);
        rank = GaussMethod(&list1, eps);
        int rankexp=2;
        ASSERT_EQ(rankexp,rank);
        det=Determinant(list1,eps);
        double detexp=0;
        det=ceil(det);
        ASSERT_EQ(detexp,det);
        DeleteHeadList(&list1);
    }
    TEST(TestsMatrix,TestGauss1)
    {
        int rank;
        knot *head=NULL;
        knot *help;
        double eps=0.00001, det;
        double harray1[4]={1,2,4,4};
        double *array1[4]={&harray1[0],&harray1[1],&harray1[2],&harray1[3]};
        double harray2[4]={ 5,6,7,8};
        double *array2[4]={&harray2[0],&harray2[1],&harray2[2],&harray2[3]};
        double harray3[4]={9,10,11,12};
        double *array3[4]={&harray3[0],&harray3[1],&harray3[2],&harray3[3]};
        knot *head1=NULL;
        knot *head2=NULL;
        knot *head3=NULL;
        knotknot *list1=NULL;
        MakeListFromArrayD(&head1,array1,4);
        MakeListFromArrayD(&head2,array2,4);
        MakeListFromArrayD(&head3,array3,4);
        AddToBeginList(head3,&list1);
        AddToBeginList(head2,&list1);
        AddToBeginList(head1,&list1);
        rank = GaussMethod(&list1, eps);
        det=Determinant(list1,eps);
        double detexp=-1;
        det=ceil(det);
        ASSERT_EQ(detexp,det);
        DeleteHeadList(&list1);
    }
    TEST(TestsMatrix,TestGauss2)
    {
        int rank;
        knot *head=NULL;
        knot *help;
        double eps=0.00001, det;
        double harray1[4]={1,2,4,4};
        double *array1[4]={&harray1[0],&harray1[1],&harray1[2],&harray1[3]};
        double harray2[4]={ 5,6,7,8};
        double *array2[4]={&harray2[0],&harray2[1],&harray2[2],&harray2[3]};
        double harray3[4]={9,10,11,12};
        double *array3[4]={&harray3[0],&harray3[1],&harray3[2],&harray3[3]};
        double harray4[4]={0,55,3,22};
        double *array4[4]={&harray4[0],&harray4[1],&harray4[2],&harray4[3]};
        knot *head1=NULL;
        knot *head2=NULL;
        knot *head3=NULL;
        knot *head4=NULL;
        knotknot *list1=NULL;
        MakeListFromArrayD(&head1,array1,4);
        MakeListFromArrayD(&head2,array2,4);
        MakeListFromArrayD(&head3,array3,4);
         MakeListFromArrayD(&head4,array4,4);
        AddToBeginList(head4,&list1);
        AddToBeginList(head3,&list1);
        AddToBeginList(head2,&list1);
        AddToBeginList(head1,&list1);
        rank = GaussMethod(&list1, eps);
        int rankexp=4;
        ASSERT_EQ(rankexp,rank);
        det=Determinant(list1,eps);
        double detexp=572;
        det=ceil(det);
        ASSERT_EQ(detexp,det);
        DeleteHeadList(&list1);
    }
    TEST(TestsMatrix,TestTrack)
    {
        int harray1[3]={1,2,3};
        int *array1[3]={&harray1[0],&harray1[1],&harray1[2]};
        int harray2[3]={4,5,6};
        int *array2[3]={&harray2[0],&harray2[1],&harray2[2]};
        int harray3[3]={7,8,9};
        int *array3[3]={&harray3[0],&harray3[1],&harray3[2]};
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
        int* track=TraceOfMatrix(list1);
        ASSERT_EQ(*track,15);
        free(track);
        DeleteHeadList(&list1);
    }
    TEST(TestsMatrix,TestTrack1)
    {
        int harray1[2]={0,11};
        int *array1[2]={&harray1[0],&harray1[1]};
        int harray2[2]={55,77};
        int *array2[2]={&harray2[0],&harray2[1]};
        knot *head1=NULL;
        knot *head2=NULL;
        knot *head3=NULL;
        knotknot *list1=NULL;
        MakeListFromArray(&head1,array1,2);
        MakeListFromArray(&head2,array2,2);
        AddToBeginList(head2,&list1);
        AddToBeginList(head1,&list1);
        int *track=TraceOfMatrix(list1);
        ASSERT_EQ(*track,77);
        free(track);
        DeleteHeadList(&list1);
    }
    TEST(TestsMatrix,TestTrack2)
    {
        int harray1[3]={1,2,3};
        int *array1[3]={&harray1[0],&harray1[1],&harray1[2]};
        int harray2[3]={4,5,6};
        int *array2[3]={&harray2[0],&harray2[1],&harray2[2]};
        int harray3[3]={7,8,9};
        int *array3[3]={&harray3[0],&harray3[1],&harray3[2]};
        int harray4[3]={10,11,12};
        int *array4[4]={&harray4[0],&harray4[1],&harray4[2],&harray4[3]};
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
        int* track=TraceOfMatrix(list1);
        ASSERT_EQ(*track,-1);
        free(track);
        DeleteHeadList(&list1);
    }
}
//g++ -std=c++11 -stdlib=libc++  Matrix.cpp  Matrix_Tests.cpp Matrix_main.cc -lgtest -lpthread -o MatrixTests
//valgrind --leak-check=full --leak-resolution=high ./MatrixTests
