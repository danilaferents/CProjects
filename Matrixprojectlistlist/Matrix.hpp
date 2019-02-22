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

typedef struct KKnot2 {
    knot *rootknot;
    struct KKnot2 *next;
} knotknot;

typedef struct KKnot3 {
    knotd *rootknot;
    struct KKnot3 *next;
} knotknotd;
void AddToBegin(knot **,int);
void AddToBeginD(knotd **,double);
void AddToBeginList(knot *,knotknot **);
void AddToBeginListD(knotd *,knotknotd **);

int DeleteFromBegin(knot **);

knot* GetNumber(knot*, int);
knotd* GetNumberD(knotd*, int);
knotknot* GetNumberList(knotknot *, int);
knotknotd* GetNumberListD(knotknotd *, int);

void DeleteHead(knot **);
void DeleteHeadD(knotd **);
void DeleteHeadList(knotknot **);
void DeleteHeadListD(knotknotd **);

int GetSize(knot *);
int GetSizeD(knotd *);
int GetSizeList(knotknot *);
int GetSizeListD(knotknotd *);

void MakeListFromArray(knot **,int *,int);
void MakeListFromArrayD(knotd **,double *,int);

void MatrixMultiplication(knotknot *,knotknot *,knotknot **);

void TransposeMatrix(knotknot *,knotknot **);
void TransposeSquareMatrix(knotknot **);

void PrintfMatrix(knot *);
void PrintfMatrixD(knotd *);

void CreatNewList(knot **,int);

int GaussMethod(knotknotd **,double);

double Determinant(knotknotd *,double);

int TraceOfMatrix(knotknot *);
#endif
