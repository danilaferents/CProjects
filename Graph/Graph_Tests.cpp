#include "Graph_Tests.hpp"
#include "Graph.hpp"
#include "gtest/gtest.h"
#include "stdio.h"
namespace  {
    TEST(TestsGraph,TestAddtoBegin)
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
    TEST(TestsGraph,TestDeletefromKnot)
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
    TEST(TestsGraph,TestGetNumber)
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
    TEST(TestsGraph,TestGetLast)
    {
        knot *head=NULL;
        AddtoBegin(&head,0);
        AddtoBegin(&head,3);
        //PrintList(head);
        knot *Head=GetLast(head);
        ASSERT_EQ(Head->value,0);
        DeleteHead(&head);
    }
    
    TEST(TestsGraph,TestGetSize)
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
    TEST(TestsGraph,TestMakeList)
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
}
//g++ -std=c++11 -stdlib=libc++  -g Graph_Tests.cpp  Graph.cpp Graph_main.cc -lgtest -lpthread -o GraphTests
//valgrind --leak-check=full --leak-resolution=high ./GraphTests
