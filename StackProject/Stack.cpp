#include "Stack.hpp"
#include <stdio.h>
int ErrorStackArray;
void InitializeStackArray(StackArray *Stack)
{
    Stack->arrow=0;
    ErrorStackArray=NORMALSTACKARRAY;
}
void PutIntoStackArray(StackArray *Stack, BaseTypeofStackArray Input)
{
    if(IsStackArrayFull(Stack))
    {
        //printf("Error Stack Array is full");
        return;
    }
    Stack->buf[Stack->arrow]=Input;
    Stack->arrow++;
}
void TakeOutOfStackArray(StackArray *Stack, BaseTypeofStackArray *Output)
{
    if(IsStackArrayEmpty(Stack))
    {
        //printf("Error StackArray is Empty");
        return ;
    }
    *Output=Stack->buf[Stack->arrow-1];
    Stack->arrow--;
}
int IsStackArrayFull(StackArray *Stack)
{
    if (Stack->arrow==STACKSIZE)
    {
        ErrorStackArray = CHECKIFTHESTACKARRAYISFULL;
        return 1;
    }
    return 0;
}
int IsStackArrayEmpty(StackArray *Stack)
{
    if(Stack->arrow==0)
    {
        ErrorStackArray=CHECKIFTHESTACKARRAYISEMPTY;
        return 1;
    }
    return 0;
}
/*
 int main()
{
    StackArray S;
    BaseTypeofStackArray a;
    InitializeStackArray(&S);
    PutIntoStackArray(&S,50);
    PutIntoStackArray(&S,100);
    PutIntoStackArray(&S,150);
    PutIntoStackArray(&S,200);
    TakeOutOfStackArray(&S,&a);
    printf("Stack gave:%d\n",a);
    TakeOutOfStackArray(&S,&a);
    printf("Stack gave:%d\n",a);
    TakeOutOfStackArray(&S,&a);
    printf("Stack gave:%d\n",a);
    TakeOutOfStackArray(&S,&a);
    printf("Stack gave:%d\n",a);
}*/

