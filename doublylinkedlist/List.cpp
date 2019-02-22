#include "List.hpp"
#include "stdio.h"
#include "stdlib.h"
list* CreatList()
{
    list *New;
    New=(list*)malloc(sizeof(list));
    New->sizeknot=0;
    New->begin=NULL;
    New->end=NULL;
    return New;
}
void Deletelist(list **New)
{
    knot *help2=NULL;
    knot *help1=(*New)->begin;
    while(help1)
    {
        help2=help1->next;
        free(help1);
        help1=help2;
    }
    free(*New);
    *New=NULL;
}
void AddtoBegin(list *Changing,int Value)
{
    knot *New=(knot*)malloc(sizeof(knot));
    if (New==NULL)
    {
        printf("Mistake0");
        exit(0);
    }
    New->value=Value;
    New->next=Changing->begin;
    New->previous=NULL;
    if(Changing->begin)
    {
        Changing->begin->previous=New;
    }
    Changing->begin=New;
    if (Changing->end==NULL) Changing->end=New;
    Changing->sizeknot++;
}
int DeletefromBegin(list *List)
{
    knot *Begin;
    int Value;
    if(List->begin==NULL)
    {
        printf("Mistake1");
        exit(1);
        
    }
    Begin=List->begin;
    List->begin=List->begin->next;
    if(List->begin) List->begin->previous=NULL;
    if(List->end==Begin) List->end=NULL;
    Value=Begin->value;
    free(Begin);
    List->sizeknot--;
    return Value;
}
void AddtoEnd(list *Changing,int Value) 
{
    knot *New=(knot*)malloc(sizeof(knot));
    if (New==NULL)
    {
        printf("Mistake2");
        exit(2);
    }
    New->value=Value;
    New->previous=Changing->end;
    New->next=NULL;
    if(Changing->begin==NULL) Changing->begin=New;
    if(Changing->end) Changing->end->next=New;
    Changing->end=New;
    Changing->sizeknot++;
}
int DeletefromEnd(list *List)
{
    knot *End;
    int Value;
    if(List->end==NULL)
    {
         printf("Mistake3");
        exit(3);
    }
    End=List->end;
    List->end=List->end->previous;
    if(List->end) List->end->next=NULL;
    if(List->begin==End) List->begin=NULL;
    Value=End->value;
    free(End);
    List->sizeknot--;
    return Value;
}
knot *GetNumberKnot(list *List,size_t indexofelement)
{
    knot *help=NULL;
    size_t k;
    if (indexofelement<(List->sizeknot)/2)
    {
        k = 0;
        help = List->begin;
        while (help && k < indexofelement)
        {
            help = help->next;
            k++;
        }
    }
        else
    {
        k = (List->sizeknot)-1;
        help = List->end;
        while (help && k > indexofelement)
        {
            help = help->previous;
            k--;
        }
    }
    return help;
}
int SerchString(list *List,int Value)
{
    knot *help=NULL;
    int k=1;
    help=List->begin;
    while(help)
    {
        if(help->value==Value) return k;
        k++;
        help=help->next;
    }
    return -1;
}

void AddtoKnot(list *List,size_t indexofinsertelement,int Value)
{
    knot *Help=NULL;
    knot *Adding=NULL;
    Help=GetNumberKnot(List,indexofinsertelement-1);
    if (Help==NULL)
    {
        printf("index:%lu",indexofinsertelement);
        printf("\n");
        printf("Mistake4");
        exit(4);
    }
    Adding=(knot*)malloc(sizeof(knot));
    Adding->value=Value;
    Adding->next=Help;
    Adding->previous=Help->previous;
    if(Help->previous!=NULL)
    {
        Help->previous->next=Adding;
    }
    Help->previous=Adding;
    if (!Help->next) List->end=Help;
    if(!Help->previous) List->begin=Help;
    List->sizeknot++;
}
/*
void AddtoKnot(list *List,size_t indexofinsertelement,int Value)
{
    if((indexofinsertelement>1)&&((List->sizeknot)>indexofinsertelement))
    {
        knot *Help=NULL;
        knot *Adding=NULL;
        Adding=(knot*)malloc(sizeof(knot));
        Help=List->begin;
        int i=0;
        while (Help&&(i<(indexofinsertelement-1)))
        {
            Help=Help->next;
            i++;
        }
        knot *Help2=Help->previous;
        Adding->value=Value;
        Adding->next=Help;
        Adding->previous=Help2;
        Help->previous=Adding;
        if(Help2!=NULL)
        {
            if (Help2->next!=NULL)
            {
             //   Help2->next=Help->previous;
            }
        }
        List->sizeknot++;
    }

}*/
int DeletefromKnot(list *List,size_t indexofinsertelement)
{
    knot *help=NULL;
    int Value;
    help=GetNumberKnot(List,indexofinsertelement);
    if (help==NULL)
    {
        printf("Mistake5");
        exit(5);
    }
    if(help->next) help->next->previous=help->previous;
    if(help->previous) help->previous->next=help->next;
    Value=help->value;
    if(help->next==NULL) List->end=help->previous;
    if (help->previous==NULL) List->begin=help->next;
    free (help);
    List->sizeknot--;
    return Value;
}

void PrintList(list *List)
{
    knot *help;
    help=List->begin;
    while(help)
    {
        printf("%d",help->value);
        help=help->next;
    }
    printf("\n");
}
list ** SplitLists(list *List,int *Counts)
{
    list **NewList;
    knot *help;
    NewList=(list**)malloc(sizeof(list*)*(sizeof(Counts)/sizeof(int)));
    help=(List->begin);
    //printf("%lu",sizeof(Counts)/sizeof(int));
    for (int i=0;i<(sizeof(Counts)/sizeof(int));i++)
    {
        if (help==NULL)
        {
            printf("Mistake6");
            exit(6);
        }
        NewList[i]=CreatList();
        for (int j=1;j<=Counts[i];j++)
        {
            if (j==1)
            {
                AddtoBegin(NewList[i],help->value);
                help=help->next;
            }
            else
            {
                AddtoEnd(NewList[i],help->value);
                help=help->next;
            }
        }
    }
    //free(help);
    return NewList;
}
list* Stick(list *List1,list *List2)
{
    list *List;
    List=CreatList();
    knot *help1=NULL;
    knot *help2=NULL;
    help1=List1->begin;
    help2=List2->begin;
    if ((help1==NULL)&&(help2==NULL))
    {
        printf("Mistake7");
        exit(7);
    }
    int i;
    AddtoBegin(List,help1->value);
    help1=help1->next;
    AddtoEnd(List,help2->value);
    help2=help2->next;
    for(i=3;i<=(((List1->sizeknot)+(List2->sizeknot)));i++)
    {
        if (help1==NULL)
        {
            AddtoEnd(List,help2->value);
            help2=help2->next;
        }
        else if (help2==NULL)
        {
            AddtoEnd(List,help1->value);
            help1=help1->next;
        }
        else
        {
            if (i%2==1)
            {
                AddtoEnd(List,help1->value);
                help1=help1->next;
            }
            else
            {
                AddtoEnd(List,help2->value);
                help2=help2->next;
            }
        }
    }
    return List;
}
/*
int main()
{
    list *NewList;
    list *List1;
    list *List2;
    NewList=CreatList();
    List1=CreatList();
    List2=CreatList();
    int Value1=5;
    int Value2=6;
    AddtoEnd(List1,Value1);
    AddtoEnd(List2,Value2);
    Value1=7;
    Value2=8;
    AddtoEnd(List1,Value1);
    AddtoEnd(List2,Value2);
    Value1=9;
    Value2=10;
    AddtoEnd(List1,Value1);
    AddtoEnd(List2,Value2);
    PrintList(List1);
    PrintList(List2);
    NewList=Stick(List1,List2);
    PrintList(NewList);
    int Massife[2]={1,2};
    list **NewList1;
    NewList1=SplitLists(NewList,Massife);
    for (int i=0;i<2;i++)
    {
        PrintList(NewList1[i]);
    }
}
 */

  



