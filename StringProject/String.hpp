#ifndef String_hpp
#define String_hpp
#include <stdio.h>
typedef struct
{
    int len;
    int *str;
} string;
void AddString(string*);
void AddstringforTests(string*);
void RemovestringforTests(string*);
void RemoveString(string*);
void StringPreppend(string*,string);
string StringAppend(string,string);
void Strcpy(string,string*);
int StrCmp(string,string);
void Delete(string*,string);
string Strconc(string,string);
string substr(string,int,int);
string * Split(string, char,int*);
int SearchString(string,string);
int LengthString(string);
void PrinString(string);
#endif
