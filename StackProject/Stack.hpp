#ifndef Stack_hpp
#define Stack_hpp
#define STACKSIZE 100
#define NORMALSTACKARRAY 0
#define CHECKIFTHESTACKARRAYISFULL  1
#define CHECKIFTHESTACKARRAYISEMPTY  2
#define TRUEE 1
#define FALSEE 0
extern int ErrorStackArray;
typedef int BaseTypeofStackArray; //change it if it won't be int
typedef struct
{
    BaseTypeofStackArray buf[STACKSIZE];
    unsigned arrow;
} StackArray;
void InitializeStackArray(StackArray *Stack);
void PutIntoStackArray(StackArray *Stack,BaseTypeofStackArray Input);
void TakeOutOfStackArray(StackArray *Stack,BaseTypeofStackArray *Output);
int IsStackArrayFull(StackArray *Stack);
int IsStackArrayEmpty(StackArray *Stack);
#define SAMPLEINPUT1 100
#define SAMPLEINPUT2 55
#define SAMPLEINPUT3 5
#define SAMPLEINPUT4 0
#endif
