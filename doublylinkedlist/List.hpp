#ifndef List_hpp
#define List_hpp

#include <stdio.h>
typedef struct KKnot{
    int value;           
    struct KKnot *next;
    struct KKnot *previous;
}knot;
typedef struct List{
    size_t sizeknot;
    knot *begin;
    knot *end;
}list;
list *CreatList();
void Deletelist(list**);
void AddtoBegin(list*,int);
int DeletefromBegin(list*);
void AddtoEnd(list *,int);
void insert(list *List, size_t index, int value);
int DeletefromEnd(list *);
knot *GetNumberKnot(list *,size_t);
int SerchString(list *,int);
void AddtoKnot(list *,size_t,int);
int  DeletefromKnot(list *,size_t );
void PrintList(list *);
list ** SplitLists(list *,int *);
list* Stick(list *,list *);
#endif
