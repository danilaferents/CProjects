#include "Ring.hpp"
#include "stdio.h"
#include "math.h"
#include "time.h"
#include "stdlib.h"
void quickSort(int numbers[], int left, int right)
{
    int pivot;
    int l_hold = left;
    int r_hold = right;
    pivot = numbers[left];
    while (left < right)
    {
        while ((numbers[right] >= pivot) && (left < right))
            right--;
        if (left != right)
        {
            numbers[left] = numbers[right];
            left++;
        }
        while ((numbers[left] <= pivot) && (left < right))
            left++;
        if (left != right)
        {
            numbers[right] = numbers[left];
            right--;
        }
    }
    numbers[left] = pivot;
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot)
        quickSort(numbers, left, pivot - 1);
    if (right > pivot)
        quickSort(numbers, pivot + 1, right);
}
int* Return(int Ring[],int M)
    {
        int k=0;
        int sum=0;
        int Counts[M*M];
        for(int i=1;i<=M;i++)
        {
            for (int j=0;j<M;j++)
            {
                int Translate[i];
                for (int p=0;p<i;p++) Translate[p]=Ring[(j+p)%M];
                 sum=0;
                 for (int p=i-1;p>-1;p--)
                 {
                     if (Translate[p]) sum+=pow(2,i-(p+1));
                         }
            Counts[k]=sum;
            k++;
            }
        }
        k=0;
        int *Countshelp;
        Countshelp=(int*)malloc(sizeof(int)*M*M);
        quickSort(Counts,0,M*M-1);
        for (int i=0;i<(M*M);i++)
        {
            if((Counts[i]!=Counts[i+1])&&(Counts[i]>=0))
            {
                Countshelp[k]=Counts[i];
                k++;
            }
        }
        return Countshelp;
    }
