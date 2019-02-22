#include "Stack.hpp"
#include "gtest/gtest.h"
#include "stdio.h"
namespace  {
    TEST(StackTests,TestInitialize)
    {
        StackArray Stack;
        InitializeStackArray(&Stack);
        ASSERT_EQ(FALSEE,Stack.arrow);
        ASSERT_EQ(ErrorStackArray,FALSEE);
    }
    TEST(StackTests,TestPutIntoStackArray1)
    {
        StackArray Stack;
        BaseTypeofStackArray In=SAMPLEINPUT1;
        InitializeStackArray(&Stack);
        PutIntoStackArray(&Stack,In);
        ASSERT_EQ(SAMPLEINPUT1,Stack.buf[Stack.arrow-1]);
    }
    TEST(StackTests,TestPutIntoStackArray2)
    {
        StackArray Stack;
        BaseTypeofStackArray In=SAMPLEINPUT2;
        InitializeStackArray(&Stack);
        PutIntoStackArray(&Stack,In);
        ASSERT_EQ(SAMPLEINPUT2,Stack.buf[Stack.arrow-1]);
    }
    TEST(StackTests,TestTakeOutOfStackArray1)
    {
        StackArray Stack;
        BaseTypeofStackArray In=SAMPLEINPUT3;
        BaseTypeofStackArray Out;
        InitializeStackArray(&Stack);
        PutIntoStackArray(&Stack,In);
        TakeOutOfStackArray(&Stack,&Out);
        ASSERT_EQ(Out,SAMPLEINPUT3);
    }
    TEST(StackTests,TestTakeOutOfStackArray2)
    {
        StackArray Stack;
        BaseTypeofStackArray In=SAMPLEINPUT4;
        BaseTypeofStackArray Out;
        InitializeStackArray(&Stack);
        PutIntoStackArray(&Stack,In);
        TakeOutOfStackArray(&Stack,&Out);
        ASSERT_EQ(Out,SAMPLEINPUT4);
    }
    TEST(StackTests,TestFullStack)
    {
        StackArray Stack;
        InitializeStackArray(&Stack);
        BaseTypeofStackArray In=SAMPLEINPUT4;
        for(int i=0;i<101;i++)
        {
             PutIntoStackArray(&Stack,In);
        }
        ASSERT_EQ(ErrorStackArray,CHECKIFTHESTACKARRAYISFULL);
    }
    TEST(StackTests,TestEmptyStack)
    {
        StackArray Stack;
        InitializeStackArray(&Stack);
        BaseTypeofStackArray Out;
        TakeOutOfStackArray(&Stack,&Out);
        ASSERT_EQ(ErrorStackArray,CHECKIFTHESTACKARRAYISEMPTY);
    }
    TEST(StackTests,TestIsStackArrayEmpty1)
    {
        StackArray Stack;
        InitializeStackArray(&Stack);
        BaseTypeofStackArray Exp;
        Exp=IsStackArrayEmpty(&Stack);
        ASSERT_EQ(Exp,TRUEE);
    }
    TEST(StackTests,TestIsStackArrayEmpty2)
    {
        StackArray Stack;
        InitializeStackArray(&Stack);
        BaseTypeofStackArray Exp;
        BaseTypeofStackArray In=SAMPLEINPUT4;
        PutIntoStackArray(&Stack,In);
        Exp=IsStackArrayEmpty(&Stack);
        ASSERT_EQ(Exp,FALSEE);
    }
    TEST(StackTests,TestIsStackArrayFull1)
    {
        StackArray Stack;
        InitializeStackArray(&Stack);
        BaseTypeofStackArray In=SAMPLEINPUT4;
        BaseTypeofStackArray Exp;
        for(int i=0;i<101;i++)
        {
            PutIntoStackArray(&Stack,In);
        }
        Exp=IsStackArrayFull(&Stack);
        ASSERT_EQ(Exp,TRUEE);
    }
    TEST(StackTests,TestIsStackArrayFull2)
    {
        StackArray Stack;
        InitializeStackArray(&Stack);
        BaseTypeofStackArray Exp;
        Exp=IsStackArrayFull(&Stack);
        ASSERT_EQ(Exp,FALSEE);
    }
    
}
// g++ -std=c++11 -stdlib=libc++  Stack_Tests.cpp  Stack.cpp Stack_main.cc -lgtest -lpthread -o StackTests
