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
void Deletelist(list **New) //удаляем список
{
    knot *help2=NULL;
    knot *help1=(*New)->begin; //запоминаем начало списка
    while(help1)  //пока указатель не станет нуль
    {
        help2=help1->next; //берем следующий узел списка
        free(help1); //освобождаем память
        help1=help2;
    }
    free(*New);
    *New=NULL;
}
void AddtoBegin(list *Changing,void *Value)
{
    knot *New=(knot*)malloc(sizeof(knot));//создаем вспомогательный узел
    if (New==NULL)//проверяем что он создался
    {
        exit(0);
    }
    New->value=Value;//задаем ему переданное значение
    New->next=Changing->begin;//задаем ему указатель на начало нашего списка
    New->previous=NULL;//устанавливаем его указатьль на предудщий элемент в NULL
    if (Changing->end==NULL) Changing->end=New;//если список был пуст то конец списка и начало указывают на 1 элемент
    if(Changing->begin) Changing->begin->previous=New;//если список был не пуст устанавливаем указатель на наш элемент
    Changing->begin=New;//говорим списку что наш первый элемент теперь New
    Changing->sizeknot++;//увеличиваем количество узлов
    
}
void *DeletefromBegin(list *List)
{
    knot *Begin;
    void *Value;
    if(List->begin==NULL) exit(0); //если список пуст-ничего не удаляем
    Begin=List->begin;
    List->begin=List->begin->next;
    if(List->begin) List->begin->previous=NULL;//установили предыдущее значение на ноль
    if(List->end==Begin) List->end=NULL;//если элемент был последним
    Value=Begin->value;
    free(Begin);
    List->sizeknot--;
    return Value;
}
void AddtoEnd(list *Changing,void *Value) //аналогично
{
    knot *New=(knot*)malloc(sizeof(knot));
    if (New==NULL)
    {
        exit(0);
    }
    New->value=Value;
    New->next=Changing->end;
    New->next=NULL;
    if(Changing->begin==NULL) Changing->begin=New;
    if(Changing->end) Changing->end->next=New;
    Changing->end=New;
    Changing->sizeknot++;
}
void *DeletefromEnd(list *List)
{
    knot *End;
    void *Value;
    if(List->end==NULL) exit(0);
    End=List->end;
    
    List->end=List->end->previous;
    if(List->end) List->end->next=NULL;
    if(List->begin==End) List->end=NULL;
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
        k = (List->sizeknot)--;
        help = List->end;
        while (help && k > indexofelement)
        {
            help = help->previous;
            k--;
        }
    }
    return help;
}
size_t SerchString(list *List,void *Value)
{
    knot *help=NULL;
    size_t k;
    help=List->begin;
    while(help)
    {
        if(help->value==Value) return k;
        k++;
        help=help->next;
    }
    return -1;
}
void AddtoKnot(list *List,size_t indexofinsertelement,void *Value)
{
    knot *help=NULL;
    knot *Adding=NULL;
    help=GetNumberKnot(List,indexofinsertelement);
    if (help==NULL) exit(0);
    Adding=(knot*)malloc(sizeof(knot));
    Adding->value=Value;
    Adding->next=help;
    Adding->previous=help->previous;
    if(help->previous) help->previous->next=Adding;
    help->previous=Adding;
    if (help->next==NULL) List->end=help;
    if(help->previous==NULL) List->begin=help;
    List->sizeknot++;
}
void* DeletefromKnot(list *List,size_t indexofinsertelement)
{
    knot *help=NULL;
    void *Value;
    help=GetNumberKnot(List,indexofinsertelement);
    if (help==NULL) exit(0);
    if(help->next) help->next->previous=help->previous;
    if(help->previous) help->previous->next=help->next;
    Value=help->value;
    if(help->next==NULL) List->end=help->previous;
    if (help->previous==NULL) List->begin=help->next;
    free (help);
    List->sizeknot--;
    return Value;
}
void printtValue(void *Value)
{
    printf("%d",*((int*)Value));
}
void PrintList(list *List)
{
    knot *help;
    help=List->begin;
    while(help)
    {
        printtValue(help->value);
        help=help->next;
    }
    printf("\n");
}
list ** SplitLists(list *List,int *Counts)
{
    list **NewList;
    knot *help;
    help=(knot*)malloc(sizeof(knot));
    NewList=(list**)malloc(sizeof(list**));
    help=(List->begin);
    for (int i=0;i<(sizeof(Counts)/sizeof(int));i++)
    {
        if (help==NULL)
        {
            exit(0);
        }
        NewList[i]=CreatList();
        for (int j=0;j<Counts[i];j++)
        {
            if (j==0)
            {
                AddtoBegin(NewList[i],help->value);
                help=help->next;
            }
            else if(j==(Counts[i]-1))
            {
                AddtoEnd(NewList[i],help->value);
                help=help->next;
            }
            else
            {
                AddtoKnot(NewList[i],j,help->value);
                help=help->next;
            }
        }
    }
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
    if ((help1==NULL)&&(help2==NULL)) exit(0);
    int i=0;
    for(i=0;i<(((List1->sizeknot)+(List2->sizeknot))-1);i++)
    {
        if (help1==NULL)
        {
            AddtoKnot(List,i,help2->value);
            help2=help2->next;
        }
        else if (help2==NULL)
        {
            AddtoKnot(List,i,help1->value);
            help1=help1->next;
        }
        else
        {
            if (i%2==0){
                AddtoKnot(List,i,help1->value);
                help1=help1->next;
            }
            else
            {
                AddtoKnot(List,i,help2->value);
                help2=help2->next;
            }
        }
    }
    if (i%2==0) List->end=help1;
    else List->end=help2;
    return List;
}
/*int main()
{
    list *TestList;
    TestList=CreatList();
    int *value=5;
    AddtoBegin(TestList,value);

}*/


