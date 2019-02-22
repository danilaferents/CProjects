#include "Turn.hpp"
#include "stdio.h"
#include "stdlib.h"
void AddToBeginList(knot *head,knotknot **list)
{
    knotknot *help=(knotknot*)malloc(sizeof(knotknot));
    help->rootknot=head;
    help->next=(*list);
    (*list)=help;
}
void AddtoBegin(knot **head,int Value)
{
    knot *help=(knot*)malloc(sizeof(knot));
    help->value=Value;
    help->next=(*head);
    (*head)=help;
}
int DeletefromBegin(knot **head)
{
    knot *help;
    int Value;
    if(head==NULL)
    {
        printf("Error 0");
        exit(0);
    }
    help=(*head);
    Value=help->value;
    (*head)=(*head)->next;
    free(help);
    return Value;
}
knot* GetNumber(knot* head, int number)
{
    int k = 0;
    while (head && (k < number))
    {
        head = head->next;
        k++;
    }
    return head;
}
knotknot* GetNumberList(knotknot *head, int number)
{
    int k = 0;
    while (head && (k < number))
    {
        head = head->next;
        k++;
    }
    return head;
}
void DeleteHead(knot **Head)
{
    knot *help1=NULL;
    while((*Head)->next)
    {
        help1=(*Head);
        (*Head)=(*Head)->next;
        free(help1);
    }
    free(*Head);
}
void DeleteHeadList(knotknot **Head)
{
    knot *help1=NULL;
    knotknot *help2=NULL;
    while((*Head)->next)
    {
        help2=*Head;
        help1=(*Head)->rootknot;
        (*Head)=(*Head)->next;
        DeleteHead(&help1);
        free(help2);
    }
    DeleteHead(&((*Head)->rootknot));
    free(*Head);
}
void PrintList(knot *Head)
{
    while(Head)
    {
        printf("%d ",Head->value);
        Head=Head->next;
    }
}
void PrintListList(knotknot *Head)
{
    while(Head)
    {
        PrintList(Head->rootknot);
        printf("\n");
        Head=Head->next;
    }
}
knot *GetPrevLast(knot *Head)
{
    if (Head==NULL)
    {
        printf("Error:1");
        exit(1);
    }
    while (Head->next->next)
    {
        Head=Head->next;
    }
    return Head;
}
knot *GetLast(knot *Head)
{
    if (Head==NULL)
    {
        printf("Error:1");
        exit(1);
    }
    while (Head->next)
    {
        Head=Head->next;
    }
    return Head;
}
knotknot *GetLastList(knotknot *Head)
{
    if (Head==NULL)
    {
        printf("Error:1");
        exit(1);
    }
    while (Head->next)
    {
        Head=Head->next;
    }
    return Head;
}
knotknot *GetPrevLastList(knotknot *Head)
{
    if (Head==NULL)
    {
        printf("Error:1");
        exit(1);
    }
    while (Head->next->next)
    {
        Head=Head->next;
    }
    return Head;
}
void AddtoEnd(knot *Head,int Value)
{
    knot *last=GetLast(Head);
    knot *New=(knot*)malloc(sizeof(knot));
    New->value=Value;
    New->next=NULL;
    last->next=New;
}
int GetSize(knot *Head)
{
    int Count=1;
    if (Head==NULL)
    {
        //printf("%d",Head->value);
        printf("--Error:1");
        exit(1);
    }
    while (Head->next)
    {
        Head=Head->next;
        Count++;
    }
    return Count;
}
int GetSizeList(knotknot *Head)
{
    int Count=1;
    if (Head==NULL)
    {
        printf("Error:1");
        exit(1);
    }
    while (Head->next)
    {
        Head=Head->next;
        Count++;
    }
    return Count;
}
void MakeListfromArray(knot **Head,int *Massife,int size)
{
    int i=size -1;
    if ((Massife==NULL)||(size==0)) return;
    while (i!=-1)
    {
        AddtoBegin(Head,Massife[i]);
        i--;
    }
}
void Swapknots(knot **head)
{
    
    int size=GetSize(*head);
    if(size==1){return void();}
    if(size==2)
    {
        knot *help=GetLast(*head);
        knot *help1=(*head);
        *head=help;
        help->next=help1;
        help->next->next=NULL;
        return void();
    }
    //поменяем местами первый и последний элементы
    knot *help=GetLast(*head);          //указываем на последний
    knot *help3=GetPrevLast(*head);     //указываем на предпоследний
    knot *help1=(*head)->next;          //указываем на второй
    help3->next=*head;                  //говорим предпоследнему что он указывает на старый первый
    help3->next->next=NULL;             //говорим новоиспеченному первому что он конец списка
    *head=help;                         //говорим указателю на начало что он теперь указывает на старый последний
    (*head)->next=help1;                //говорим новоиспеченному последнему что он должен указывать на второй
    //поменяем местами оставшиеся
    if (size!=4)
    {
        for (int i=1;i<size/2;i++)
        {
            knot *help1=GetNumber(*head,i);
            knot *help2=GetNumber(*head,size-i-1);
            knot *help3=GetNumber(*head,i-1);
            knot *help4=GetNumber(*head,size-i-2);
            knot *help=help1->next;
            help3->next=help2;
            help4->next=help1;
            help1->next=help2->next;
            help2->next=help;
        }
    }
    else
    {
        knot *help1=GetNumber(*head,1);
        knot *help2=GetNumber(*head,2);
        knot *help3=GetNumber(*head,3);
        (*head)->next=help2;
        help2->next=help1;
        help1->next=help3;
    }
}
void SwapList(knotknot **head)
{
    
    int size=GetSizeList(*head);
    if(size==1){return void();}
    if(size==2)
    {
        knotknot *help=GetLastList(*head);
        knotknot *help1=(*head);
        *head=help;
        help->next=help1;
        help->next->next=NULL;
        return void();
    }
    //поменяем местами первый и последний элементы
    knotknot *help=GetLastList(*head);          //указываем на последний
    knotknot *help3=GetPrevLastList(*head);     //указываем на предпоследний
    knotknot *help1=(*head)->next;          //указываем на второй
    help3->next=*head;                  //говорим предпоследнему что он указывает на старый первый
    help3->next->next=NULL;             //говорим новоиспеченному первому что он конец списка
    *head=help;                         //говорим указателю на начало что он теперь указывает на старый последний
    (*head)->next=help1;                //говорим новоиспеченному последнему что он должен указывать на второй
    for (int i=0;i<size;i++)
    {
        knotknot *help=NULL;
        help=GetNumberList(*head,i);
        if ((GetSize(help->rootknot)!=1)) {Swapknots(&(help->rootknot));}
    }
    //поменяем местами оставшиеся
    if (size!=4)
    {
        for (int i=1;i<size/2;i++)
        {
            knotknot *help1=GetNumberList(*head,i);
            knotknot *help2=GetNumberList(*head,size-i-1);
            knotknot *help3=GetNumberList(*head,i-1);
            knotknot *help4=GetNumberList(*head,size-i-2);
            knotknot *help=help1->next;
            help3->next=help2;
            help4->next=help1;
            help1->next=help2->next;
            help2->next=help;
        }
    }
    else
    {
        knotknot *help1=GetNumberList(*head,1);
        knotknot *help2=GetNumberList(*head,2);
        knotknot *help3=GetNumberList(*head,3);
        (*head)->next=help2;
        help2->next=help1;
        help1->next=help3;
    }
}
/*
void MakeListfromArrayList(knotknot **Head,int (*Massife)[5],int size)
{
    int i=size -1;
    knot *help=(*Head)->rootknot;
    if ((Massife==NULL)||(size==0)) return;
    while (i!=-1)
    {
        MakeListfromArray(&help,Massife[i],sizeof(Massife[i])/sizeof(int));
        AddToBeginList(help,Head);
        help=help->next;
        i--;
    }
}*/
/*
int main()
{
    knotknot *list=NULL;
    knot *head1=NULL;
    knot *head2=NULL;
    knot *head3=NULL;
    knot *head4=NULL;
    knot *head5=NULL;
    int Massife1[4]={11,22,3,4};
    int Massife2[5]={7,8,9,10,11};
    int Massife3[3]={13,14,15};
    int Massife4[2]={19,20};
    MakeListfromArray(&head1,Massife1,4);
    MakeListfromArray(&head2,Massife2,5);
    MakeListfromArray(&head3,Massife3,3);
    MakeListfromArray(&head4,Massife4,2);
    AddtoBegin(&head5,0);
    AddToBeginList(head5,&list);
    AddToBeginList(head4,&list);
    AddToBeginList(head3,&list);
    AddToBeginList(head2,&list);
    AddToBeginList(head1,&list);
    PrintListList(list);
    int number=GetSizeList(list);
    knotknot *help=GetNumberList(list,0);
    printf("\n");
    printf("%d",number);
    help=GetLastList(list);
    SwapList(&list);
    printf("\n");
    PrintListList(list);
    for(int i=0;i<GetSizeList(list);i++)
    {
        knotknot *help=GetNumberList(list,i);
        int number=GetSize(help->rootknot);
        printf("\n");
        printf("%d",number);
    }
}*/

