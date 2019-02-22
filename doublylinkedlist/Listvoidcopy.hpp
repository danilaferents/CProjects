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
void AddtoBegin(list*,void*);
void *DeletefromBegin(list*);
void AddtoEnd(list *,void *);
void *DeletefromEnd(list *);
knot *GetNumberKnot(list *,size_t);
size_t SerchString(list *,void *);
void AddtoKnot(list *,size_t,void *);
void* DeletefromKnot(list *,size_t );
void printtValue(void *);
void PrintList(list *);
list ** SplitLists(list ,int *);
list* Stick(list *,list *);
#endif
