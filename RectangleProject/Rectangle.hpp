#ifndef Rectangle_hpp
#define Rectangle_hpp

#include <stdio.h>
int giveAbs(int,int**);
#define COUNTOFCOORDINATES 4
void Putincoordinates(int **,int );
void Printcoordinates(int **,int);
void giveAmount(int ,long int *,int **);
int **Creat(int);
void Erase(int **,int);
#endif /* Rectangle_hpp */
// g++ Rectangle.cpp -o Rectangle
