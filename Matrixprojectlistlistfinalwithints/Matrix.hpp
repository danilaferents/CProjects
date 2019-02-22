#ifndef Matrix_hpp
#define Matrix_hpp

#include <stdio.h>
#define NULLERROR 1
#define WRONGERROR 2
extern int errorinfo;

typedef struct KKnot {
    void *value;
    struct KKnot *next;
} knot;

typedef struct KKnot2 {
    knot  *rootknot;
    struct KKnot2 *next;
} knotknot;

void AddToBegin(knot **,void*);
void AddToBeginList(knot *,knotknot **);

int DeleteFromBegin(knot **);

knot* GetNumber(knot*, int);
knotknot* GetNumberList(knotknot *, int);

void DeleteHead(knot **);
void DeleteHeadList(knotknot **);

int GetSize(knot *);
int GetSizeList(knotknot *);

void MakeListFromArray(knot **,int **,int);
void MakeListFromArrayD(knot **head,double **array,int size);

void MatrixMultiplication(knotknot *,knotknot *,knotknot **);

void TransposeMatrix(knotknot *,knotknot **);
void TransposeSquareMatrix(knotknot **);

void PrintfMatrix(knot *);

void CreatNewList(knot **,int);

int GaussMethod(knotknot **,double);

double Determinant(knotknot *,double);

int* TraceOfMatrix(knotknot *);
#endif
