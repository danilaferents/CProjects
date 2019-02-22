#include "Turn_Tests.hpp"
#include "Turn.hpp"
#include "gtest/gtest.h"
#include "stdio.h"
namespace  {
    TEST(TestsTurn,TestAddtoBegin)
    {
        knot *head=NULL;
        knot *help=NULL;
        AddtoBegin(&head,6);
        AddtoBegin(&head,6);
        AddtoBegin(&head,3);
        help=head;
        //PrintList(head);
        ASSERT_EQ(help->value,3);
        help=help->next;
        ASSERT_EQ(help->value,6);
        help=help->next;
        ASSERT_EQ(help->value,6);
        DeleteHead(&head);
    }
    TEST(TestsTurn,TestDeletefromKnot)
    {
        knot *head=NULL;
        knot *help=NULL;
        AddtoBegin(&head,9);
        AddtoBegin(&head,3);
        AddtoBegin(&head,2);
        DeletefromBegin(&head);
        help=head;
        //PrintList(head);
        ASSERT_EQ(help->value,3);
        help=help->next;
        ASSERT_EQ(help->value,9);
        DeleteHead(&head);
    }
    TEST(TestsTurn,TestGetNumber)
    {
        knot *head=NULL;
        AddtoBegin(&head,6);
        AddtoBegin(&head,6);
        AddtoBegin(&head,3);
        knot *Head=GetNumber(head,1);
        //PrintList(head);
        ASSERT_EQ(Head->value,6);
        DeleteHead(&head);
    }
    TEST(TestsTurn,TestGetLast)
    {
        knot *head=NULL;
        AddtoBegin(&head,0);
        AddtoBegin(&head,3);
        //PrintList(head);
        knot *Head=GetLast(head);
        ASSERT_EQ(Head->value,0);
        DeleteHead(&head);
    }
    
    TEST(TestsTurn,TestGetSize)
    {
        knot *head=NULL;
        AddtoBegin(&head,9);
        AddtoBegin(&head,3);
        AddtoBegin(&head,2);
        AddtoBegin(&head,6);
        AddtoBegin(&head,6);
        AddtoBegin(&head,3);
        //PrintList(head);
        int size;
        size=GetSize(head);
        ASSERT_EQ(size,6);
        DeleteHead(&head);
    }
    TEST(TestsTurn,TestMakeList)
    {
        knot *head=NULL;
        int *Massife;
        Massife=(int*)malloc(sizeof(int)*8);
        Massife[0]=2;
        Massife[1]=3;
        Massife[2]=9;
        Massife[3]=3;
        Massife[4]=6;
        Massife[5]=6;
        Massife[6]=3;
        Massife[7]=0;
        MakeListfromArray(&head,Massife,8);
        knot *help=GetNumber(head,0);
        ASSERT_EQ(help->value,2);
        help=help->next;
        ASSERT_EQ(help->value,3);
        help=help->next;
        ASSERT_EQ(help->value,9);
        help=help->next;
        ASSERT_EQ(help->value,3);
        help=help->next;
        ASSERT_EQ(help->value,6);
        help=help->next;
        ASSERT_EQ(help->value,6);
        help=help->next;
        ASSERT_EQ(help->value,3);
        help=help->next;
        ASSERT_EQ(help->value,0);
        DeleteHead(&head);
        free(Massife);
    }
    TEST(TestsTurn,TestGetSizeList)
    {
        knotknot *list=NULL;
        knot *head1=NULL;
        knot *head2=NULL;
        knot *head3=NULL;
        knot *head4=NULL;
        knot *head5=NULL;
        int Massife1[4]={1,2,3,4};
        int Massife2[5]={7,8,9,10,11};
        int Massife3[5]={13,14,15,16,17};
        int Massife4[5]={19,20,21,22,23};
        MakeListfromArray(&head1,Massife1,4);
        MakeListfromArray(&head2,Massife2,5);
        MakeListfromArray(&head3,Massife3,5);
        MakeListfromArray(&head4,Massife4,5);
        MakeListfromArray(&head5,Massife4,5);
        AddToBeginList(head5,&list);
        AddToBeginList(head4,&list);
        AddToBeginList(head3,&list);
        AddToBeginList(head2,&list);
        AddToBeginList(head1,&list);
        int number=GetSizeList(list);
        ASSERT_EQ(number,5);
        DeleteHeadList(&list);
    }
    TEST(TestsTurn,TestSwapeKnots)
    {
        knotknot *list=NULL;
        knot *head1=NULL;
        knot *head2=NULL;
        int Massife1[4]={1,2,3,4};
        int Massife2[4]={4,3,2,1};
        MakeListfromArray(&head1,Massife1,4);
        MakeListfromArray(&head2,Massife2,4);
        Swapknots(&head1);
        for (int i=0;i<4;i++)
        {
            knot *help1=GetNumber(head1,i);
            knot *help2=GetNumber(head2,i);
            ASSERT_EQ(help1->value,help2->value);
        }
        DeleteHead(&head1);
        DeleteHead(&head2);
    }
    TEST(TestsTurn,TestSwapeKnots2)
    {
        knotknot *list=NULL;
        knot *head1=NULL;
        knot *head2=NULL;
        int Massife1[5]={1,2,3,4,5};
        int Massife2[5]={5,4,3,2,1};
        MakeListfromArray(&head1,Massife1,5);
        MakeListfromArray(&head2,Massife2,5);
        Swapknots(&head1);
        for (int i=0;i<5;i++)
        {
            knot *help1=GetNumber(head1,i);
            knot *help2=GetNumber(head2,i);
            ASSERT_EQ(help1->value,help2->value);
        }
        DeleteHead(&head1);
        DeleteHead(&head2);
    }
    TEST(TestsTurn,TestSwapeList1)
    {
        knotknot *list=NULL;
        knot *head1=NULL;
        knot *head2=NULL;
        knot *head3=NULL;
        knot *head4=NULL;
        int Massife1[5]={1,2,3,4,5};
        int Massife2[5]={7,8,9,10,11};
        int Massife3[5]={13,14,15,16,17};
        int Massife4[5]={19,20,21,22,23};
        int MassifeSec[4][5]={{23,22,21,20,19},{17,16,15,14,13},{11,10,9,8,7},{5,4,3,2,1}};
        MakeListfromArray(&head1,Massife1,5);
        MakeListfromArray(&head2,Massife2,5);
        MakeListfromArray(&head3,Massife3,5);
        MakeListfromArray(&head4,Massife4,5);
        AddToBeginList(head4,&list);
        AddToBeginList(head3,&list);
        AddToBeginList(head2,&list);
        AddToBeginList(head1,&list);
        SwapList(&list);
        for(int i=0;i<GetSizeList(list);i++)
        {
            knotknot *help=GetNumberList(list,i);
            for (int j=0;j<GetSize(help->rootknot);j++)
            {
                knot *help2=GetNumber((help->rootknot),j);
                ASSERT_EQ(help2->value,MassifeSec[i][j]);
                
            }
        }
        DeleteHeadList(&list);
    }
    TEST(TestsTurn,TestSwapeList2)
    {
        knotknot *list=NULL;
        knot *head1=NULL;
        knot *head2=NULL;
        knot *head3=NULL;
        knot *head4=NULL;
        knot *head5=NULL;
        int Massife1[4]={11,22,3,4};
        int Massife2[5]={7,8,9,10,11};
        int Massife3[3]={13,14,15};
        int Massife4[2]={19,20};
        int Massife5[1]={0};
        int MassifeSec[5][5]={{0},{20,19},{15,14,13},{11,10,9,8,7},{4,3,22,11}};
        MakeListfromArray(&head5,Massife5,1);
        MakeListfromArray(&head1,Massife1,4);
        MakeListfromArray(&head2,Massife2,5);
        MakeListfromArray(&head3,Massife3,3);
        MakeListfromArray(&head4,Massife4,2);
        AddToBeginList(head5,&list);
        AddToBeginList(head4,&list);
        AddToBeginList(head3,&list);
        AddToBeginList(head2,&list);
        AddToBeginList(head1,&list);
        SwapList(&list);
        for(int i=0;i<GetSizeList(list);i++)
        {
            knotknot *help=GetNumberList(list,i);
            for (int j=0;j<GetSize(help->rootknot);j++)
            {
                knot *help2=GetNumber((help->rootknot),j);
                ASSERT_EQ(help2->value,MassifeSec[i][j]);
            }
        }
        DeleteHeadList(&list);
    }
}
//g++ -std=c++11 -stdlib=libc++  -g Turn_Tests.cpp  Turn.cpp Turn_main.cc -lgtest -lpthread -o TurnTests
//valgrind --leak-check=full --leak-resolution=high ./TurnTests
