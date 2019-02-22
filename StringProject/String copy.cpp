#include "String.hpp"
#include "stdio.h"
#include "stdlib.h"
int main()
{
    string NewString1;
    AddString(&NewString1);
    string NewString2;
    //NewString2=AddString(NewString2);
    PrinString(NewString1);
    PrinString(NewString2);
    //testing Strcmp
    /*
     string NewStr;
    NewStr=Strcmp(NewString1,NewString2);
    PrinString(NewStr);
     */
    
    //testing constructor
    /*
     int begin,end;
     scanf("%d%d",&begin,&end);
     string substring;
     substring=substr(NewString1,begin,end);
     PrinString(substring);
     */
    // testing Deletesubstring
    /*
     string Del;
     Del=delete(NewString1,NewString2);
     PrinString(Del);
     */
    //testing Split
    /*
     char a;
     scanf("%c",&a);
     Split(NewString1,a);
     */
    // testing SearchString
    
    //testing Strcpy
    /*
     NewString2=Strcpy(NewString1,NewString2);
     printf("after copy\n");
     PrinString(NewString2);
     */
    /*
     int index;
     string Searchingstring;
     Searchingstring=AddString(Searchingstring);
     if ((index=SearchString(NewString1,Searchingstring))>=0)
     printf("Index of comparing:\n%i\n",index);
     else
     printf("no such string\n");
     */
    
    //testing AppendingString and Prepending String
    
    /*
     string AppendingString;
     AppendingString.len=0;
     AppendingString=StringAppend(NewString1,NewString2);
     PrinString(AppendingString);
     */
    
    /*string PreppendString;
     PreppendString.changing=0;
     PreppendString.len=0;
     PreppendString=StringPreppend(PreppendString,NewString1);
     printf("first Preppend\n");
     PrinString(PreppendString);
     printf("Second Preppend\n");
     PreppendString=StringPreppend(PreppendString,NewString2);
     PrinString(PreppendString);
     */
    
    //testing string Removing
    
    //NewString1=RemoveString(NewString1);
    /*
     for(int i=0;i<NewString1.len;i++)
     {
     printf("%c",(char)NewString1.str[i]);
     }
     printf("\n");
     */
}

void AddString(string NewString)
{
    printf("Input string\n");
    char a;
    scanf("%c",&a);
    int *str;
    NewString->str=(int*)malloc(1000 * sizeof(int));
    int i=0;
    while(a!='\n')
    {
        NewString.str[i]=a;
        scanf("%c",&a);
        i++;
        if(i>1000)
        {
           NewString.str=(int*)realloc(str,i*sizeof(int));
        }
    }
    NewString-.str[i]='\0';
    NewString-.len=i;
}
void AddstringforTests(string NewString)
{
    int *str;
    NewString.str=(int*)malloc(NewString.len * sizeof(int));
}
string RemoveString(string NewString)
{
    free(NewString.str);
    NewString.str=NULL;
    NewString.len=0;
    printf("Successful cleaning up made!!!");
    printf("\n");
    return NewString;
}
void PrinString(string _String)
{
    for(int i=0;i<_String.len;i++)
    {
        printf("%c",(char)_String.str[i]);
    }
    printf("\n");
    printf("---------------");
    //printf("string length%i",_String.len);
    printf("\n");
}
string StringPreppend(string _String,string PreppendingString)
{
    int *help;
    help=(int*)malloc(_String.len * sizeof(int));
    for(int i=0;i<_String.len;i++)
    {
        help[i]=_String.str[i];
    }
    if (!_String.changing)
    {
        _String.str=(int*)malloc(1000 * sizeof(int));
    }
    else
    {
        if((_String.len+PreppendingString.len)>1000)
        {
            _String.str=(int*)realloc(_String.str,(_String.len+PreppendingString.len)*sizeof(int));
        }
        _String.changing=1;
    }
    int k=0;
    for(int i=0;i<_String.len;i++)
    {
        _String.str[i]=help[i];
    }
    for(int i=_String.len;i<_String.len+PreppendingString.len;i++)
    {
        _String.str[i]=PreppendingString.str[k];
        k++;
    }
    _String.len=_String.len+PreppendingString.len;
    return _String;
}
string StringAppend(string _String,string AppendingString)
{
    string CreatString;
    CreatString.str=(int*)malloc(1000 * sizeof(int));
    
    if((_String.len+AppendingString.len)>1000)
    {
        _String.str=(int*)realloc(_String.str,(_String.len+AppendingString.len)*sizeof(int));
    }
    for(int i=0;i<_String.len;i++)
    {
        CreatString.str[i]=_String.str[i];
    }
    int k=0;
    for(int i=_String.len;i<_String.len+AppendingString.len;i++)
    {
        CreatString.str[i]=AppendingString.str[k];
        k++;
    }
    CreatString.len=_String.len+AppendingString.len;
    return CreatString;
}
int SearchString(string String1,string String2)
{
    int i,j,k;
    for (i=0;String1.str[i]!='\0';i++)
    {
        for (j=i,k=0;String2.str[k]!='\0'&&String1.str[j]==String2.str[k];j++,k++);
        if(k>0 && String2.str[k]=='\0')
            return i;
    }
    return -1;
}
int LengthString(string String1)
{
    int i;
    for (i=0;String1.str[i]!='\0';i++);
    return i;
}
void Split(string Splitingstring, char a)
{
    int *help;
    help=(int*)malloc(Splitingstring.len*(sizeof(int)));
    int i=0;
    int k=0;
    // printf("length%d\n",Splitingstring.len);
    while(i!=Splitingstring.len+1)
    {
        //  printf("step:%d\n",i);
        help[k]=Splitingstring.str[i];
        k++;
        if (Splitingstring.str[i]==a)
        {
            for (int j=0;j<k-1;j++)
            {
                printf("%c",(char)help[j]);
                help[j]=0;
            }
            printf("\n");
            k=0;
        }
        
        i++;
    }
    for (int j=0;j<k-1;j++)
    {
        printf("%c",(char)help[j]);
    }
}
string Strcpy(string Str1,string Str2)
{
    Str2.str=(int*) malloc(Str1.len*(sizeof(int)));
    int i=0;
    do
    {
        Str2.str[i]=Str1.str[i];
    }
    while (Str1.str[i++]!='\0');
    Str2.len=Str1.len;
    return Str2;
}
string Delete(string deletingstring,string deletingsubstring)
{
    int number;
    number=SearchString(deletingstring,deletingsubstring);
    int i;
    for( i=number;i<=number+deletingsubstring.len;i++)
    {
        
        deletingstring.str[i]=deletingstring.str[i+deletingsubstring.len];
        if ((number+deletingsubstring.len)==deletingstring.len) break;
    }
    for (i=number+deletingsubstring.len+1;i<deletingstring.len;i++)
    {
        deletingstring.str[i]=0;
    }
    deletingstring.str[i]='\0';
    return deletingstring;
}
string substr(string Operatingstring,int begin, int end)
{
    int length=end-begin+1;
    string help;
    help.str=(int*)malloc(length*(sizeof(int)));
    int i;
    for (i=0;i<length;i++)
    {
        help.str[i]=Operatingstring.str[i+begin];
    }
    help.str[i]='\0';
    help.len=length;
    return help;
}
string Strcmp(string Str1,string Str2)
{
    int length=Str1.len+Str2.len;
    string Comparingstring;
    Comparingstring.str=(int*)malloc(length*sizeof(int));
    int i;
    for( i=0;i<Str1.len;i++)
    {
        Comparingstring.str[i]=Str1.str[i];
    }
    int k=0;
    for ( i=Str1.len;i<length;i++)
    {
        Comparingstring.str[i]=Str2.str[k];
        k++;
    }
    
    Comparingstring.len=length;
    Comparingstring.str[i]='\0';
    return Comparingstring;
}
//g++ String.cpp -o String

