#include "LIst_Tests.hpp"
#include "gtest/gtest.h"
#include "stdio.h"
#include "List.hpp"
namespace  {
    TEST(ListTests,TestAddtoBegin)
    {
        list *TestList;
        TestList=CreatList();
        int Value=5;
        AddtoBegin(TestList,Value);
        ASSERT_EQ(TestList->begin->value,Value);
        ASSERT_EQ(TestList->end->value,Value);
        ASSERT_EQ(TestList->sizeknot,1);
        Deletelist(&TestList);
        
    }
    TEST(ListTests,TestDeletfromBegin)
    {
        list *TestList;
        TestList=CreatList();
        int Value=5;
        AddtoBegin(TestList,Value);
        int help=DeletefromBegin(TestList);
        ASSERT_EQ(help,Value);
        ASSERT_TRUE(TestList->begin==NULL);
        ASSERT_TRUE(TestList->end==NULL);
        ASSERT_EQ(TestList->sizeknot,0);
        Deletelist(&TestList);
    }
    TEST(ListTests,TestAddtoEnd)
    {
        list *TestList;
        TestList=CreatList();
        int Value=5;
        AddtoEnd(TestList,Value);
        ASSERT_EQ(TestList->begin->value,Value);
        ASSERT_EQ(TestList->end->value,Value);
        ASSERT_EQ(TestList->sizeknot,1);
        Deletelist(&TestList);
    }
    TEST(ListTests,TestDeletefromEnd)
    {
        list *TestList;
        TestList=CreatList();
        int Value=5;
        AddtoEnd(TestList,Value);
        int help=DeletefromEnd(TestList);
        ASSERT_EQ(help,Value);
        Deletelist(&TestList);
    }
    TEST(ListTests,TestGetNumber)
    {
        list *TestList;
        TestList=CreatList();
        int Value=5;
        AddtoEnd(TestList,Value);
        Value=6;
        AddtoEnd(TestList,Value);
        Value=7;
        AddtoEnd(TestList,Value);
        Value=8;
        AddtoEnd(TestList,Value);
        ASSERT_EQ(TestList->sizeknot,4);
        knot *Help=GetNumberKnot(TestList,1);
        ASSERT_EQ(Help->value,6);
        Deletelist(&TestList);
    }
    TEST(ListTests,TestSearchKnot)
    {
        list *TestList;
        TestList=CreatList();
        int Value=5;
        AddtoEnd(TestList,Value);
        Value=6;
        AddtoEnd(TestList,Value);
        Value=7;
        AddtoEnd(TestList,Value);
        Value=8;
        AddtoEnd(TestList,Value);
        ASSERT_EQ(TestList->sizeknot,4);
        int help=SerchString(TestList,7);
        ASSERT_EQ(3,help);
        Deletelist(&TestList);
    }
    TEST(ListTests,TestSearchKnot2)
    {
        list *TestList;
        TestList=CreatList();
        int Value=5;
        AddtoEnd(TestList,Value);
        Value=6;
        AddtoEnd(TestList,Value);
        Value=7;
        AddtoEnd(TestList,Value);
        Value=8;
        AddtoEnd(TestList,Value);
        ASSERT_EQ(TestList->sizeknot,4);
        int help=SerchString(TestList,2);
        ASSERT_EQ(-1,help);
        Deletelist(&TestList);
    }
    TEST(ListTests,TestSearchKnot3)
    {
        list *TestList;
        TestList=CreatList();
        int Value=5;
        AddtoEnd(TestList,Value);
        Value=6;
        AddtoEnd(TestList,Value);
        Value=7;
        AddtoEnd(TestList,Value);
        Value=8;
        AddtoEnd(TestList,Value);
        ASSERT_EQ(TestList->sizeknot,4);
        int help=SerchString(TestList,5);
        ASSERT_EQ(1,help);
        Deletelist(&TestList);
    }
    TEST(ListTests,AddtoKnot)
    {
        list *TestList;
        TestList=CreatList();
        int Value1=5;
        AddtoEnd(TestList,Value1);
        int Value2=6;
        AddtoEnd(TestList,Value2);
        int Value3=7;
        AddtoEnd(TestList,Value3);
        int Value4=8;
        AddtoEnd(TestList,Value4);
        int Value5=9;
        AddtoEnd(TestList,Value5);
        AddtoKnot(TestList,2,3);
        ASSERT_EQ(TestList->sizeknot,6);
        int help=SerchString(TestList,3);
        ASSERT_EQ(2,help);
        Deletelist(&TestList);
    }
    TEST(ListTests,Stick)
    {
        list *NewList;
        list *List1;
        list *List2;
        List1=CreatList();
        List2=CreatList();
        int Value1=5;
        int Value2=6;
        AddtoBegin(List1,Value1);
        AddtoBegin(List2,Value2);
        Value1=7;
        Value2=8;
        AddtoEnd(List1,Value1);
        AddtoEnd(List2,Value2);
        Value1=9;
        Value2=10;
        AddtoEnd(List1,Value1);
        AddtoEnd(List2,Value2);
        Value2=11;
        AddtoEnd(List2,Value2);
        NewList=Stick(List1,List2);
        for(int i=0,j=0,k=0;i<(NewList->sizeknot)-1;i++)
        {
            if (i%2==0)
            {
                ASSERT_EQ(GetNumberKnot(List1,j)->value,GetNumberKnot(NewList,i)->value);
                j++;
            }
            else
            {
                ASSERT_EQ(GetNumberKnot(List2,k)->value,GetNumberKnot(NewList,i)->value);
                k++;
            }
        }
        ASSERT_EQ(GetNumberKnot(NewList,6)->value,11);
        Deletelist(&List1);
        Deletelist(&List2);
        Deletelist(&NewList);
    }
    TEST(ListTests,SplitLists)
    {
        list *NewList;
        list *List1;
        list *List2;
        List1=CreatList();
        List2=CreatList();
        int Value1=5;
        int Value2=6;
        AddtoEnd(List1,Value1);
        AddtoEnd(List2,Value2);
        Value1=7;
        Value2=8;
        AddtoEnd(List1,Value1);
        AddtoEnd(List2,Value2);
        Value1=9;
        Value2=10;
        AddtoEnd(List1,Value1);
        AddtoEnd(List2,Value2);
        NewList=Stick(List1,List2);
        int Massife[2]={1,2};
        list **NewList1;
        knot *help1;
        knot *help2;
        help2=NewList->begin;
        NewList1=SplitLists(NewList,Massife);
        int j=0;
        for (int i=0;i<2;i++)
        {
            help1=(NewList1[i])->begin;
            for (int j=1;j<=Massife[i];j++)
            {
                ASSERT_EQ(help1->value,help2->value);
                help1=help1->next;
                help2=help2->next;
            }
        }
        Deletelist(&List1);
        Deletelist(&List2);
        Deletelist(&NewList);
        for(int i=0;i<2;i++)
        {
            Deletelist(&NewList1[i]);
        }
        free(NewList1);

    }
    
}//g++ -std=c++11 -stdlib=libc++ -g List.cpp  LIst_Tests.cpp List_main.cc -lgtest -lpthread -o ListTests
//valgrind --leak-check=full --leak-resolution=high ./ListTests
