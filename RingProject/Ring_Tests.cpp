#include "gtest/gtest.h"
#include "Ring.hpp"
#include "Ring_Tests.hpp"
#include "stdio.h"
namespace  {
    TEST(RingTests,Testlong1)
    {
        int Ring[LENGTH1]={0,1,0,0,1};
        int exp[CHECKLENGTH1]={0,1,2,4,5,9,10,18,20};
        int *act=Return(Ring,LENGTH1);
        for (int i=0;i<CHECKLENGTH1;i++)
        {
            ASSERT_EQ(act[i],exp[i]);
        }
        free(act);
    }
    TEST(RingTests,Testshort1)
    {
        int Ring[LENGTH3]={0};
        int exp[CHECKLENGTH3]={0};
        int *act=Return(Ring,LENGTH3);
        for (int i=0;i<CHECKLENGTH3;i++)
        {
            ASSERT_EQ(act[i],exp[i]);
        }
        free(act);
    }
    TEST(RingTests,Testempty4)
    {
        int Ring[LENGTH4]={};
        int *exp;
        exp=(int*)malloc(sizeof(int)*LENGTH4);
        int *act=Return(Ring,LENGTH4);
        ASSERT_EQ(*act,*exp);
        free(exp);
        free(act);
    }
    TEST(RingTests,Testshort2)
    {
        int Ring[LENGTH5]={1,0};
        int exp[CHECKLENGTH5]={0,1,2};
        int *act=Return(Ring,LENGTH5);
        for (int i=0;i<CHECKLENGTH5;i++)
        {
            ASSERT_EQ(act[i],exp[i]);
        }
        free(act);
    }
    /*TEST(RingTests,Testshort3)
    {
        int Ring[LENGTH3]={1};
        int exp[CHECKLENGTH3]={1};
        int *act=Return(Ring,LENGTH3);
        for (int i=0;i<CHECKLENGTH3;i++)
        {
            ASSERT_EQ(act[i],exp[i]);
        }
        free(act);
    }*/
    TEST(RingTests,Testlong2)
    {
        int Ring[LENGTH2]={RING0};
        int exp[CHECKLENGTH2]={RINGEXP0};
        int *act=Return(Ring,LENGTH2);
        for (int i=0;i<CHECKLENGTH2;i++)
        {
            ASSERT_EQ(act[i],exp[i]);
        }
        free(act);
    }
    /*TEST(RingTests,Testlong3)
    {
        int Ring[LENGTH6]={RING1};
        int exp[CHECKLENGTH6]={RINGEXP1};
        int *act=Return(Ring,LENGTH6);
        for (int i=0;i<CHECKLENGTH6;i++)
        {
            ASSERT_EQ(act[i],exp[i]);
        }
        free(act);
    }*/
    TEST(RingTests,Testlong4)
    {
        int Ring[LENGTH7]={RING2};
        int exp[CHECKLENGTH7]={RINGEXP2};
        int *act=Return(Ring,LENGTH7);
        for (int i=0;i<CHECKLENGTH7;i++)
        {
            ASSERT_EQ(act[i],exp[i]);
        }
        free(act);
    }
    
}
//g++ -std=c++11 -stdlib=libc++  Ring_Tests.cpp  Ring.cpp Ring_tests_main.cc -lgtest -lpthread -o RingTests
