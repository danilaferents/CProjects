    #include "String.hpp"
#include "String_Tests.hpp"
#include "gtest/gtest.h"
#include "stdio.h"
namespace  {
    TEST(StringTests,TestStringPrepending1)
    {
        string PreppendString;
        string NewString1;
        string NewString2;
        NewString1.len=6;
        NewString2.len=9;
        AddstringforTests(&NewString1);
        AddstringforTests(&NewString2);
        NewString1.str[0]='h';
        NewString1.str[1]='a';
        NewString1.str[2]='p';
        NewString1.str[3]='p';
        NewString1.str[4]='i';
        NewString1.str[5]='\0';
        PreppendString.len=1;
        AddstringforTests(&PreppendString);
        NewString2.str[0]='B';
        NewString2.str[1]='a';
        NewString2.str[2]='r';
        NewString2.str[3]='t';
        NewString2.str[4]='h';
        NewString2.str[5]='d';
        NewString2.str[6]='a';
        NewString2.str[7]='y';
        NewString2.str[8]='\0';
        int exp[6]={'h','a','p','p','i','\0'};
        StringPreppend(&PreppendString,NewString1);
        for (int i=0;i<PreppendString.len;i++)
        {
            //printf("1");
                ASSERT_EQ(PreppendString.str[i],exp[i]);
        }
        StringPreppend(&PreppendString,NewString2);
        int exp1[14]={'h','a','p','p','i','B','a','r','t','h','d','a','y','\0'};
        for (int i=0;i<PreppendString.len;i++)
        {
            //printf("2");
                ASSERT_EQ(PreppendString.str[i],exp1[i]);
        }
        RemovestringforTests(&PreppendString);
        RemovestringforTests(&NewString2);
        RemovestringforTests(&NewString1);
    }
    TEST(StringTests,TestStringPrepending2)
    {
        string PreppendString;
        string NewString1;
        string NewString2;
        NewString1.len=4;
        NewString2.len=2;
        AddstringforTests(&NewString1);
        AddstringforTests(&NewString2);
        NewString1.str[0]='g';
        NewString1.str[1]='o';
        NewString1.str[2]='o';
        NewString1.str[3]='\0';
        PreppendString.len=1;
        AddstringforTests(&PreppendString);
        NewString2.str[0]='l';
        NewString2.str[1]='\0';
        int exp[4]={'g','o','o','\0'};
        StringPreppend(&PreppendString,NewString1);
        for (int i=0;i<PreppendString.len;i++)
        {
            ASSERT_EQ(PreppendString.str[i],exp[i]);
        }
        StringPreppend(&PreppendString,NewString2);
        int exp1[5]={'g','o','o','l','\0'};
        for (int i=0;i<PreppendString.len;i++)
        {
            ASSERT_EQ(PreppendString.str[i],exp1[i]);
        }
        RemovestringforTests(&PreppendString);
        RemovestringforTests(&NewString2);
        RemovestringforTests(&NewString1);
    }
     TEST(StringTests,TestStringAppending1)
    {
        string AppendString;
        string NewString1;
        string NewString2;
        NewString1.len=4;
        NewString2.len=2;
        AddstringforTests(&NewString1);
        AddstringforTests(&NewString2);
        NewString1.str[0]='g';
        NewString1.str[1]='o';
        NewString1.str[2]='o';
        NewString1.str[3]='\0';
        NewString2.str[0]='l';
        NewString2.str[1]='\0';
        int exp[5]={'g','o','o','l','\0'};
        AppendString=StringAppend(NewString1,NewString2);
        for (int i=0;i<AppendString.len;i++)
        {
            ASSERT_EQ(AppendString.str[i],exp[i]);
        }
        RemovestringforTests(&AppendString);
        RemovestringforTests(&NewString2);
        RemovestringforTests(&NewString1);
    }
    TEST(StringTests,TestStringAppending2)
    {
        string AppendString;
        string NewString1;
        string NewString2;
        NewString1.len=3;
        NewString2.len=5;
        AddstringforTests(&NewString1);
        AddstringforTests(&NewString2);
        NewString1.str[0]='g';
        NewString1.str[1]='o';
        NewString1.str[2]='\0';
        NewString2.str[0]='a';
        NewString2.str[1]='w';
        NewString2.str[2]='a';
        NewString2.str[3]='y';
        NewString2.str[4]='\0';
        int exp[7]={'g','o','a','w','a','y','\0'};
        AppendString=StringAppend(NewString1,NewString2);
        for (int i=0;i<AppendString.len;i++)
        {
            ASSERT_EQ(AppendString.str[i],exp[i]);
        }
        RemovestringforTests(&AppendString);
        RemovestringforTests(&NewString2);
        RemovestringforTests(&NewString1);
    }
    TEST(StringTests,TestSearchString1)
    {
        string searchString;
        string NewString1;
        searchString.len=3;
        NewString1.len=5;
        AddstringforTests(&NewString1);
        AddstringforTests(&searchString);
        NewString1.str[0]='g';
        NewString1.str[1]='o';
        NewString1.str[2]='o';
        NewString1.str[3]='l';
        NewString1.str[4]='\0';
        searchString.str[0]='l';
        searchString.str[1]='\0';
        int index=SearchString(NewString1,searchString);
        ASSERT_EQ(index,3);
        RemovestringforTests(&searchString);
        RemovestringforTests(&NewString1);
    }
    
    TEST(StringTests,TestSplit)
    {
        string AppendString;
        string *sstring;
        string NewString3;
        NewString3.len=7;
        AddstringforTests(&NewString3);
        NewString3.str[0]='g';
        NewString3.str[1]='o';
        NewString3.str[2]='a';
        NewString3.str[3]='w';
        NewString3.str[4]='i';
        NewString3.str[5]='y';
        NewString3.str[6]='\0';
        int exp1[3]={'g','o','\0'};
        int exp2[4]={'w','i','y','\0'};
        char a='a';
        int count;
        sstring=Split(NewString3,a,&count);
        for (int i=0;i<sstring[0].len;i++)
        {
            //printf("%c",sstring[0].str[i]);
            ASSERT_EQ(sstring[0].str[i],exp1[i]);
        }
        printf("\n");
        for (int i=0;i<sstring[1].len;i++)
        {
           // printf("%c",sstring[1].str[i]);
            ASSERT_EQ(sstring[1].str[i],exp2[i]);
        }
        for (int i=0;i<count;i++)
        {
            RemovestringforTests(&sstring[i]);
        }
        RemovestringforTests(&NewString3);
        free(sstring);
    }
    TEST(StringTests,TestSearchString2)
    {
        string searchString;
        string NewString1;
        searchString.len=3;
        NewString1.len=5;
        AddstringforTests(&NewString1);
        AddstringforTests(&searchString);
        NewString1.str[0]='g';
        NewString1.str[1]='o';
        NewString1.str[2]='o';
        NewString1.str[3]='n';
        NewString1.str[4]='\0';
        searchString.str[0]='l';
        searchString.str[1]='\0';
        int index=SearchString(NewString1,searchString);
        ASSERT_EQ(index,-1);
        RemovestringforTests(&searchString);
        RemovestringforTests(&NewString1);
    }
    TEST(StringTests,TestLength)
    {
        string NewString1;
        NewString1.len=5;
        AddstringforTests(&NewString1);
        NewString1.str[0]='g';
        NewString1.str[1]='o';
        NewString1.str[2]='o';
        NewString1.str[3]='l';
        NewString1.str[4]='\0';
        int length=LengthString(NewString1);
        ASSERT_EQ(length,5);
        RemovestringforTests(&NewString1);
    }
    TEST(StringTests,Teststrcpy)
    {
        string NewString1;
        string NewString2;
        NewString1.len=5;
        NewString2.len=5;
        AddstringforTests(&NewString1);
        AddstringforTests(&NewString2);
        NewString1.str[0]='g';
        NewString1.str[1]='o';
        NewString1.str[2]='o';
        NewString1.str[3]='l';
        NewString1.str[4]='\0';
        Strcpy(NewString1,&NewString2);
        for (int i=0;i<NewString1.len;i++)
        {
            ASSERT_EQ(NewString2.str[i],NewString1.str[i]);
        }
        RemovestringforTests(&NewString2);
        RemovestringforTests(&NewString1);
    }
    TEST(StringTests,TestDelete)
    {
        string NewString1;
        string NewString2;
        NewString1.len=5;
        NewString2.len=3;
        AddstringforTests(&NewString1);
        AddstringforTests(&NewString2);
        NewString1.str[0]='g';
        NewString1.str[1]='o';
        NewString1.str[2]='o';
        NewString1.str[3]='l';
        NewString1.str[4]='\0';
        NewString2.str[0]='o';
        NewString2.str[1]='l';
        NewString2.str[2]='\0';
        Delete(&NewString1,NewString2);
        int exx[2]={'g','o'};
        for (int i=0;i<2;i++)
        {
            ASSERT_EQ(exx[i],NewString1.str[i]);
        }
        RemovestringforTests(&NewString1);
        RemovestringforTests(&NewString2);
     }
    TEST(StringTests,Testsubstr)
    {
        string NewString1;
        string NewString2;
        NewString1.len=5;
        AddstringforTests(&NewString1);
        NewString1.str[0]='g';
        NewString1.str[1]='o';
        NewString1.str[2]='o';
        NewString1.str[3]='l';
        NewString1.str[4]='\0';
        int begin=2;
        int end=3;
        NewString2=substr(NewString1,begin,end);
        int exp[2]={'o','l'};
        for (int i=0;i<NewString2.len;i++)
        {
            ASSERT_EQ(exp[i],NewString2.str[i]);
        }
        RemovestringforTests(&NewString1);
        RemovestringforTests(&NewString2);
    }
    TEST(StringTests,TestStringconc)
    {
        string ComparingString;
        string NewString1;
        string NewString2;
        NewString1.len=6;
        NewString2.len=9;
        AddstringforTests(&NewString1);
        AddstringforTests(&NewString2);
        NewString1.str[0]='h';
        NewString1.str[1]='a';
        NewString1.str[2]='p';
        NewString1.str[3]='p';
        NewString1.str[4]='i';
        NewString1.str[5]='\0';
        NewString2.str[0]='B';
        NewString2.str[1]='a';
        NewString2.str[2]='r';
        NewString2.str[3]='t';
        NewString2.str[4]='h';
        NewString2.str[5]='d';
        NewString2.str[6]='a';
        NewString2.str[7]='y';
        NewString2.str[8]='\0';
        int exp[14]={'h','a','p','p','i','B','a','r','t','h','d','a','y','\0'};
        ComparingString=Strconc(NewString1,NewString2);
        for (int i=0;i<ComparingString.len;i++)
        {
            ASSERT_EQ(ComparingString.str[i],exp[i]);
        }
        RemovestringforTests(&ComparingString);
        RemovestringforTests(&NewString2);
        RemovestringforTests(&NewString1);
    }
    TEST(StringTests,TestStringcmp)
    {
        string NewString1;
        string NewString2;
        NewString1.len=6;
        NewString2.len=6;
        AddstringforTests(&NewString1);
        AddstringforTests(&NewString2);
        NewString1.str[0]='h';
        NewString1.str[1]='a';
        NewString1.str[2]='p';
        NewString1.str[3]='p';
        NewString1.str[4]='y';
        NewString1.str[5]='\0';
        NewString2.str[0]='h';
        NewString2.str[1]='a';
        NewString2.str[2]='p';
        NewString2.str[3]='p';
        NewString2.str[4]='y';
        NewString2.str[5]='\0';
        int result;
        result=StrCmp(NewString1,NewString2);
        ASSERT_EQ(result,1);
        RemovestringforTests(&NewString2);
        RemovestringforTests(&NewString1);
    }
    TEST(StringTests,TestStringcmp1)
    {
        string NewString1;
        string NewString2;
        NewString1.len=6;
        NewString2.len=6;
        AddstringforTests(&NewString1);
        AddstringforTests(&NewString2);
        NewString1.str[0]='h';
        NewString1.str[1]='a';
        NewString1.str[2]='r';
        NewString1.str[3]='p';
        NewString1.str[4]='y';
        NewString1.str[5]='\0';
        NewString2.str[0]='h';
        NewString2.str[1]='a';
        NewString2.str[2]='p';
        NewString2.str[3]='p';
        NewString2.str[4]='y';
        NewString2.str[5]='\0';
        int result;
        result=StrCmp(NewString1,NewString2);
        ASSERT_EQ(result,50);
        RemovestringforTests(&NewString2);
        RemovestringforTests(&NewString1);
    }
    TEST(StringTests,TestStringcmp2)
    {
        string NewString1;
        string NewString2;
        NewString1.len=6;
        NewString2.len=6;
        AddstringforTests(&NewString1);
        AddstringforTests(&NewString2);
        NewString1.str[0]='a';
        NewString1.str[1]='a';
        NewString1.str[2]='a';
        NewString1.str[3]='p';
        NewString1.str[4]='y';
        NewString1.str[5]='\0';
        NewString2.str[0]='h';
        NewString2.str[1]='a';
        NewString2.str[2]='p';
        NewString2.str[3]='p';
        NewString2.str[4]='y';
        NewString2.str[5]='\0';
        int result;
        result=StrCmp(NewString1,NewString2);
        ASSERT_EQ(result,-50);
        RemovestringforTests(&NewString2);
        RemovestringforTests(&NewString1);
    }
    TEST(StringTests,TestStringcmp3)
    {
        string NewString1;
        string NewString2;
        NewString1.len=6;
        NewString2.len=7;
        AddstringforTests(&NewString1);
        AddstringforTests(&NewString2);
        NewString1.str[0]='a';
        NewString1.str[1]='a';
        NewString1.str[2]='a';
        NewString1.str[3]='p';
        NewString1.str[4]='y';
        NewString1.str[5]='\0';
        NewString2.str[0]='n';
        NewString2.str[1]='o';
        NewString2.str[2]='s';
        NewString2.str[3]='t';
        NewString2.str[4]='r';
        NewString2.str[5]='i';
        NewString2.str[6]='\0';
        int result;
        result=StrCmp(NewString1,NewString2);
        ASSERT_EQ(result,-1);
        RemovestringforTests(&NewString2);
        RemovestringforTests(&NewString1);
    }

}
//g++ -std=c++11 -stdlib=libc++  -g String_Tests.cpp  String.cpp String_main.cc -lgtest -lpthread -o StringTests
//valgrind --leak-check=full --leak-resolution=high ./StringTests
