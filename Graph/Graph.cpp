#include "Graph.hpp"
#include "stdio.h"
#include "stdlib.h"
knot *path;
knot **Graph;
knot **Ribs;
void AddtoBegin(knot **head,int Value)
{
    knot *help=(knot*)malloc(sizeof(knot));
    help->value=Value;
    help->next=(*head);
    (*head)=help;
}
AddtoGraph(knot ***Graph,knot *graph)
{
    *Graph[]
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
void PrintList(knot *Head)
{
    while(Head)
    {
        printf("%d",Head->value);
        Head=Head->next;
    }
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
void DFS(int nodeCur,int nodeLast)
{
    AddtoEnd(path,nodeCur);
    if(nodeCur==nodeLast)
    {
        for (int i=0;i<GetSize(path);i++)
        {
            int Val=GetNumber(path,i)->value;
            printf("%d ",Val);
        }
        printf("\n");
        
        
    }
}
int main()
{
    
}
