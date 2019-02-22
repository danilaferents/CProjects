#ifndef graph_hpp
#define graph_hpp
#include <stdio.h>
typedef struct KKnot {
    int value;
    struct KKnot *next;
} knot;
typedef struct KKnot1 {
    knot *rootknot;
    struct KKnot1 *next;
} knotknot;
//void Creat(knot **Head);
void AddToBeginList(knot *head,knotknot **list);
void AddtoBegin(knot **head,int Value);
int DeletefromBegin(knot **head);
knot* GetNumber(knot* head, int number);
knotknot* GetNumberList(knotknot *head, int number);
void DeleteHead(knot **Head);
void DeleteHeadList(knotknot **Head);
void PrintList(knot *Head);
knot *GetLast(knot *Head);
knot *GetPrevLast(knot *Head);
knotknot *GetPrevLastList(knotknot *Head);
void AddtoEnd(knot *Head,int Value);
knotknot *GetLastList(knotknot *Head);
int GetSize(knot *Head);
int GetSizeList(knotknot *Head);
void MakeListfromArray(knot **Head,int *Massife,int size);
void printfMatrix(knot *Head,int n,int m);
void Swapknots(knot **head);
void SwapList(knotknot **head);
//void MakeListfromArrayList(knotknot **Head,int **Massife,int size);
#endif 
