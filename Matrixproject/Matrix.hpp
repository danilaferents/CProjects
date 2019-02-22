#ifndef Matrix_hpp
#define Matrix_hpp

#include <stdio.h>
typedef struct KKnot {
    int value;
    struct KKnot *next;
} knot;
//for gausse
typedef struct KKnot1 {
    double value;
    struct KKnot1 *next;
} knotd;
void AddToBegin(knot **head,int Value);
void AddToBeginD(knotd **head,double Value);
knotd* GetNumberD(knotd* head, int number);
int GaussMethod(int m,int n,knotd **head,double eps);
void DeleteHeadD(knotd **Head);
void MakeListFromArrayD(knotd **Head,double *Massife,int size);
//another
int DeleteFromBegin(knot **head);
knot* GetNumber(knot* head, int number);
void DeleteHead(knot **Head);
void PrintList(knot *Head);
knot *GetLast(knot *Head);
int GetSize(knot *Head);
void MakeListFromArray(knot **Head,int *Massife,int size);
void TransposeMatrix(knot *head1,knot **head2,int n,int m);//Transpose
void PrintfMatrix(knot *Head,int n,int m);
void CreatNewList(knot **head1,int size);
void MatrixMultiplication(knot *head1,knot *head2,int m,int q,int n,knot **head3);
double Determinant(int m,int n,knotd *head,double eps);
void TransporateSquareMatrix(knot **head1,int n,int m);
int TraceOfMatrix(knot *head,int n,int m);//Trace
#endif
