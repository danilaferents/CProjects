#include "String.hpp"
#include "stdio.h"
#include "stdlib.h"
  /*
int main()
{
 //main
  */
   /*
    string NewString1;
    AddString(&NewString1);
    string NewString2;
    AddString(&NewString2);
    PrinString(NewString1);
    PrinString(NewString2);
    */
    //testing Split
     /*
    string *sstring;
    char a;
    int count;
    scanf("%c",&a);
    sstring=Split(NewString1,a,&count);
    for (int i=0;i<count;i++)
    {
        PrinString(sstring[i]);
    }
    for (int i=0;i<count;i++)
    {
        RemovestringforTests(&sstring[i]);
    }
    free(sstring);
    
    
     */
    //testing Strcmp
    /*
    string NewStr;
    NewStr=Strcmp(NewString1,NewString2);
    PrinString(NewStr);
    RemovestringforTests(&NewStr);
     */
    //testing constructor
    /*
     int begin,end;
     scanf("%d%d",&begin,&end);
     string substring;
     substring=substr(NewString1,begin,end);
     RemovestringforTests(&substring);
     PrinString(substring);
     */
    // testing Deletesubstring
    /*
     Delete(&NewString1,NewString2);
     PrinString(NewString1);
     */
    //testing Split
     /*
     char a='l';
     string *help;
     help=(string*)malloc((100)*(sizeof(string*)));
     help=Split(NewString1,a);
 //    */
    // testing SearchString
    
    //testing Strcpy
    /*
     Strcpy(NewString1,&NewString2);
     printf("after copy\n");
     PrinString(NewString2);
    
     */
    //testing StringLength
    /*
    int length=LengthString(NewString1);
    printf("%d",length);
     */
    //testing Searchstring
     /*
     int index;
     string Searchingstring;
     AddString(&Searchingstring);
     if ((index=SearchString(NewString1,Searchingstring))>=0)
     printf("Index of comparing:\n%i\n",index);
     else
     printf("no such string\n");
     RemovestringforTests(&Searchingstring);
    */
    
    //testing AppendingString and Prepending String
    
    /*
     string AppendingString;
     AppendingString.len=0;
     AppendingString=StringAppend(NewString1,NewString2);
     PrinString(AppendingString);
     RemovestringforTests(&AppendingString);
     */
     /*
     string PreppendString;
     int changing=0;
     PreppendString.len=0;
     StringPreppend(&PreppendString,NewString1,&changing);
     printf("first Preppend\n");
     PrinString(PreppendString);
     printf("Second Preppend\n");
     StringPreppend(&PreppendString,NewString2,&changing);
     RemovestringforTests(&PreppendString);
     PrinString(PreppendString);
     */
    
    //testing string Removing
    
    //RemoveString(&NewString1);
    /*
     for(int i=0;i<NewString1.len;i++)
     {
     printf("%c",(char)NewString1.str[i]);
     }
     printf("\n");
     */
  //  RemovestringforTests(&NewString1);
   // RemovestringforTests(&NewString2);
//}
void AddString(string *NewString)
{
    printf("Input string\n");
    char a;
    scanf("%c",&a);
    NewString->str=(int*)malloc(1000 * sizeof(int));
    int i=0;
    int *str1;
    str1=(int*)malloc(1000 * sizeof(int));
    while(a!='\n')
    {
        NewString->str[i]=a;
        scanf("%c",&a);
        i++;
        if(i>1000)
        {
         
           
            for (int j=0;j<=i;j++)
            {
                str1[j]=NewString->str[i];
            }
            NewString->str=(int*)realloc(NewString->str,i*sizeof(int));
            for (int j=0;j<=i;j++)
            {
                NewString->str[i]=str1[i];
            }
        }
    }
    free(str1);
    NewString->str[i]='\0';
    NewString->len=(i+1);
}
void AddstringforTests(string *NewString)
{
    NewString->str=(int*)malloc(NewString->len * sizeof(int));
}
void RemovestringforTests(string *NewString)
{
    free(NewString->str);
}
void RemoveString(string *NewString)
{
    free(NewString->str);
    NewString->len=0;
    printf("Successful cleaning up made!!!");
    printf("\n");
}
void PrinString(string _String)
{
    //for(int i=0;i<_String.len;i++)
    int i=0;
    int a=_String.str[i];
    i++;
    while(a!='\0')
    {
        printf("%c",(char)a);
        a=_String.str[i];
        i++;
    }
    printf("\n");
    printf("---------------");
    printf("string length%i",_String.len);
    printf("\n");
}
//StringPreppend
void StringPreppend(string *_String,string PreppendingString)
{
    int *help;
    int size_help;
    help=(int*)malloc(_String->len * sizeof(int));
    size_help=_String->len;
    for(int i=0;i<(_String->len)-1;i++)
    {
        help[i]=_String->str[i];
    }
    _String->str=(int*)realloc(_String->str,(_String->len+PreppendingString.len-1)*sizeof(int));
    int k=0;
    for(int i=0;i<(_String->len)-1;i++)
    {
        _String->str[i]=help[i];
    }
    for(int i=(_String->len)-1;i<(_String->len+PreppendingString.len-1);i++)
    {
        _String->str[i]=PreppendingString.str[k];
        k++;
    }
    _String->len=(_String->len+PreppendingString.len)-1;
    free(help);
}
//stringAppend
string StringAppend(string _String,string AppendingString)
{
    string CreatString;
    CreatString.str=(int*)malloc((_String.len+AppendingString.len-1) * sizeof(int));
    for(int i=0;i<(_String.len)-1;i++)
    {
        CreatString.str[i]=_String.str[i];
    }
    int k=0;
    for(int i=(_String.len)-1;i<(_String.len+AppendingString.len-1);i++)
    {
        CreatString.str[i]=AppendingString.str[k];
        k++;
    }
    CreatString.len=(_String.len+AppendingString.len)-1;
    return CreatString;
}
//поиск в строке
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
//длина строки
int LengthString(string String1)
{
    int i;
    for (i=0;String1.str[i]!='\0';i++);
    i++;
    return i;
}
/*
string* Split(string Splitingstring, char a,int *Count)
{
  //  int *help;
    string *sstrings;
 //   help=(int*)malloc(Splitingstring.len*(sizeof(int)));
    int i=0;
    int k=0;
    // printf("length%d\n",Splitingstring.len);
    int count=0,j=0;
    while(Splitingstring.str[j]!='\0')
    {
        if (Splitingstring.str[j]==a) count++;
    }
    count++;
    int l=0;
    sstrings=(string*)malloc((count+1)*(sizeof(string*)));
    if (count!=1)
    while(Splitingstring.str[i]!='\0')
    {
        //  printf("step:%d\n",i);
   //     help[k]=Splitingstring.str[i];
        k++;
        if (Splitingstring.str[i]==a)
        {
            int help1=sstrings[l-1].len;
            for (int j=0;j<i;j++)
            {
                sstrings[l].str=(int*)malloc(sizeof(int)*i);
                if (l==0)
                {
                    sstrings[l].str[j]=Splitingstring.str[j];
                }
                else
                {
                    sstrings[l].str[j]=Splitingstring.str[sstrings[l-1].len];
                    help1++;
                }
            }
            if (l!=0) sstrings[l].len=help1;
                else sstrings[l].len=i-1;
            l++;
            k=0;
            help1=0;
        }
        i++;
    }
    *Count=count;
    return sstrings;
}*/
string* Split(string Splitingstring, char a,int *Count)
{
    string *sstrings;
    int i=0;
    int k=0;
    // printf("length%d\n",Splitingstring.len);
    int count=0,j=0;
    while(Splitingstring.str[j]!='\0')
    {
        if (Splitingstring.str[j]==a)
        {
            Splitingstring.str[j]='\0';
            count++;
        }
        j++;
    }
    count++;
    sstrings=(string*)malloc((count)*(sizeof(string)));
    for(int i=0;i<count;i++)
    {
        sstrings[i].str=(int*)malloc(sizeof(int)*Splitingstring.len);
    }
    j=0;
    for(int i=0;i<count;i++)
    {
        while(Splitingstring.str[j]!='\0')
        {
            sstrings[i].str[k]=Splitingstring.str[j];
         //   printf("%c",(char)sstrings[i].str[k]);
            j++;
            k++;
        }
      //  printf("\n");
        j++;
        sstrings[i].str[k]='\0';
        sstrings[i].len=k;
        k=0;
        }
    *Count=count;
   // printf("%d",count);
   // for(int p=0;p<count;p++) PrinString(sstrings[p]);
    return sstrings;
}
//копирование строк
void Strcpy(string Str1,string *Str2)
{
    Str2->str=(int*)realloc(Str2->str,(Str1.len)*sizeof(int));
    int i=0;
    do
    {
        Str2->str[i]=Str1.str[i];
    }
    while (Str1.str[i++]!='\0');
    Str2->len=Str1.len;
}
//удаление строки в строке
void Delete(string *deletingstring,string deletingsubstring)
{
    int number;
    int *help;
    number=SearchString(*deletingstring,deletingsubstring);
    help=(int*)malloc(sizeof(int)*(deletingstring->len - deletingsubstring.len));
    if (number==-1) exit(0);
    int k=0;
    for (int i=0;i<number;i++)
    {
        help[k]=deletingstring->str[i];
        k++;
    }
    for (int i=number+deletingsubstring.len-1;i<deletingsubstring.len;i++)
    {
        help[k]=deletingstring->str[i];
        k++;
    }
    deletingstring->str=(int*)realloc(deletingstring->str,(deletingstring->len-deletingsubstring.len)*sizeof(int));
    for (int i=0;i<(deletingstring->len-deletingsubstring.len);i++)
    {
        deletingstring->str[i]=help[i];
    }
    free(help);
}
//создание строки из подстроки
string substr(string Operatingstring,int begin, int end)
{
    int length=end-begin+1;
    string help;
    help.str=(int*)malloc(length*(sizeof(int)));
    int i;
    for (i=0;i<(length);i++)
    {
        help.str[i]=Operatingstring.str[i+begin];
    }
    //help.str[++i]='\0';
    help.len=length;
    return help;
}
//объединение
string Strconc(string Str1,string Str2)
{
    int length=(Str1.len+Str2.len)-1;
    string Comparingstring;
    Comparingstring.str=(int*)malloc(length*sizeof(int));
    int i;
    for( i=0;i<(Str1.len)-1;i++)
    {
        Comparingstring.str[i]=Str1.str[i];
    }
    int k=0;
    for ( i=(Str1.len)-1;i<length;i++)
    {
        Comparingstring.str[i]=Str2.str[k];
        k++;
    }
    
    Comparingstring.len=length;
    return Comparingstring;
}
//сравнение строк
int StrCmp(string Str1,string Str2)
{
    int result=0;
    int size1,size2;
    size1=Str1.len;
    size2=Str2.len;
    if (size1==size2)
    {
        for (int i=0;i<size1;i++)
        {
            if (Str1.str[i]>Str2.str[i])
            {
                result=50;
                return result;
            }
            else if(Str1.str[i]<Str2.str[i])
            {
                result=-50;
                return result;
            }
            else
            {
                result=1;
            }
        }
    }
    else
    {
        result=-1;
    }
    return result;
}
//g++ String.cpp -o String
//g++ -g -Og String.cpp -o String

