#include "Massife.hpp"
#include <stdbool.h>
#include "stdio.h"
int CanthisCountbe(int Count[],int n,int Summ,int K);
int K;
/*int main()
{
    int in,Need;
    printf("Please Input position,Summ,Size of Massife:");
    scanf("%d%d%d",&in,&Need,&K);
    int Input[K];
    printf("%d%d%d\nsize:%lu",in,Need,K,sizeof(Input)/sizeof(int));
    
    for (int i=0;i<K;i++)
    {
        scanf("%d",&Input[i]);
        printf("%d",Input[i]);
    }
    bool YesorNot;
    YesorNot=CanthisCountbe(Input,in,Need,K);
    printf("Result:%d\n",YesorNot);
}
 */

int CanthisCountbe(int counts[],int n,int Summ,int K)
{
   // printf("step:%d\nSumm:%d\n",n,Summ);
    if (Summ==0) return 1;
    if ((counts[n]>Summ) || (K<=n)) return 0;
    return (CanthisCountbe(counts,n+1,Summ-counts[n],K) || CanthisCountbe(counts,n+3,Summ-counts[n],K));
}
