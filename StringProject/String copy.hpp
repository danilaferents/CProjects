#ifndef String_hpp
#define String_hpp
#include <stdio.h>
typedef struct
{
    int len;
    int *str;
    int changing;
} string;
void AddString(string);
void AddstringforTests(string);
string RemoveString(string);
string StringPreppend(string,string);
string StringAppend(string,string);
string Strcpy(string,string);
string Delete(string,string);
string Strcmp(string,string);
string substr(string,int,int);
void Split(string, char);
int SearchString(string,string);
int LengthString(string);
void PrinString(string);
#endif
