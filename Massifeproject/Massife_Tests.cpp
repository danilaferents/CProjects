#include "Massife.hpp"
#include "gtest/gtest.h"
#include "stdio.h"
namespace  {
    TEST(MassifeTests,TestNegative1)
    {
        const int K=5;
        int SampleMassife[5]={1,2,3,4,5};
        int exp=CanthisCountbe(SampleMassife,0,4,K);
        ASSERT_EQ(0,exp);
    }
    TEST(MassifeTests,TestNegative2)
    {
        const int K=0;
        int SampleMassife[K]={};
        int exp=CanthisCountbe(SampleMassife,0,1,K);
        ASSERT_EQ(0,exp);
    }
    TEST(MassifeTests,TestNegative3)
    {
        const int K=0;
        int SampleMassife[K]={};
        int exp=CanthisCountbe(SampleMassife,0,0,K);
        ASSERT_EQ(1,exp);
    }
    TEST(MassifeTests,TestNegative4)
    {
        const int K=10;
        int SampleMassife[K]={1,5,7,4,9,10,55,3,0,100};
        int exp=CanthisCountbe(SampleMassife,0,126,K);
        ASSERT_EQ(0,exp);
    }
    TEST(MassifeTests,TestPositive1)
    {
        const int K=10;
        int SampleMassife[K]={1,5,7,4,9,10,55,3,0,100};
        int exp=CanthisCountbe(SampleMassife,0,125,K);
        ASSERT_EQ(1,exp);
    }
    TEST(MassifeTests,TestPositive2)
    {
        const int K=15;
        int SampleMassife[K]={1,5,7,4,9,10,55,3,0,100,2,5,600,549,44};
        int exp=CanthisCountbe(SampleMassife,0,725,K);
        ASSERT_EQ(1,exp);
    }
    TEST(MassifeTests,TestPositive3)
    {
        const int K=3;
        int SampleMassife[K]={100,200,300};
        int exp=CanthisCountbe(SampleMassife,0,600,K);
        ASSERT_EQ(1,exp);
    }
    TEST(MassifeTests,TestPositive4)
    {
        const int K=9;
        int SampleMassife[K]={0,8,10,3,9,33,55,44,69};
        int exp=CanthisCountbe(SampleMassife,0,231,K);
        ASSERT_EQ(1,exp);
    }
    
}
//g++ -std=c++11 -stdlib=libc++  Massife_Tests.cpp  Massife.cpp Massife_main.cc -lgtest -lpthread -o MassifeTests
