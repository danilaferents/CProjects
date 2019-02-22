#ifndef graph_hpp
#define graph_hpp
#include <stdio.h>
typedef struct KKnot {
    int value;
    struct KKnot *next;
} knot;
//void Creat(knot **Head);
void AddtoBegin(knot **head,int Value);
int DeletefromBegin(knot **head);
knot* GetNumber(knot* head, int number);
void DeleteHead(knot **Head);
void PrintList(knot *Head);
knot *GetLast(knot *Head);
int GetSize(knot *Head);
void MakeListfromArray(knot **Head,int *Massife,int size);
void printfMatrix(knot *Head,int n,int m);
void Matrixmultiplication(knot *head1,knot *head2,int m,int q,int n,knot **head3);
#endif 
