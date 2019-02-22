#include "Matrix.hpp"
#include "stdio.h"
#include "math.h"
#include "stdlib.h"
//knot *head=NULL;
/*void Creat(knot **Head)
{
    *Head=NULL;
}*/
//добавление в начало целочисленного списка
void AddtoBegin(knot **head,int Value)
{
    knot *help=(knot*)malloc(sizeof(knot));
    help->value=Value;
    help->next=(*head);
   (*head)=help;
}
//добавление в начало вещественного списка
void AddtoBeginD(knotd **head,double Value)
{
    knotd *help=(knotd*)malloc(sizeof(knotd));
    help->value=Value;
    help->next=(*head);
    (*head)=help;
}
//удаление с начала списка
int DeletefromBegin(knot **head)
{
    knot *help;
    int Value;
    if(head==NULL)
    {
        printf("Error 0");
        exit(0);
    }
    help=(*head);
    Value=help->value;
    (*head)=(*head)->next;
    free(help);
    return Value;
}
//воврат элемента целочисленного списка по номеру
knot* GetNumber(knot* head, int number)
{
    int k = 0;
    while (head && (k < number))
    {
        head = head->next;
        k++;
    }
    return head;
}
//воврат элемента вещественного списка по номеру
knotd* GetNumberD(knotd* head, int number)
{
    int k = 0;
    while (head && (k < number))
    {
        head = head->next;
        k++;
    }
    return head;
}
//удаление целочисленного списка
void DeleteHead(knot **Head)
{
    knot *help1=NULL;
    while((*Head)->next)
    {
        help1=(*Head);
        (*Head)=(*Head)->next;
        free(help1);
    }
    free(*Head);
}
//удаление вещественного списка
void DeleteHeadD(knotd **Head)
{
    knotd *help1=NULL;
    while((*Head)->next)
    {
        help1=(*Head);
        (*Head)=(*Head)->next;
        free(help1);
    }
    free(*Head);
}
//печать списка
void PrintList(knot *Head)
{
    while(Head)
    {
        printf("%d",Head->value);
        Head=Head->next;
    }
}
//вовращает последний элемент
knot *GetLast(knot *Head)
{
    if (Head==NULL)
    {
        printf("Error:1");
        exit(1);
    }
    while (Head->next)
    {
        Head=Head->next;
    }
    return Head;
}
//добавляет элемент в конец списка
void AddtoEnd(knot *Head,int Value)
{
    knot *last=GetLast(Head);
    knot *New=(knot*)malloc(sizeof(knot));
    New->value=Value;
    New->next=NULL;
    last->next=New;
}
//вовзращает размер списка
int GetSize(knot *Head)
{
    int Count=1;
    if (Head==NULL)
    {
        printf("Error:1");
        exit(1);
    }
    while (Head->next)
    {
        Head=Head->next;
        Count++;
    }
    return Count;
}
//преобразует массив в целочисленный список
void MakeListfromArray(knot **Head,int *Massife,int size)
{
    int i=size -1;
    if ((Massife==NULL)||(size==0)) return;
    while (i!=-1)
    {
        AddtoBegin(Head,Massife[i]);
        i--;
    }
}
//преобразует массив в вещественный список
void MakeListfromArrayD(knotd **Head,double *Massife,int size)
{
    int i=size -1;
    if ((Massife==NULL)||(size==0)) return;
    while (i!=-1)
    {
        AddtoBeginD(Head,Massife[i]);
        i--;
    }
}
//Matrix A:m строк (берем)n столбцов Matrix B:n строк q столбцов(берем)  so Matrix C:m строк q столбцов
void Matrixmultiplication(knot *head1,knot *head2,int m,int q,int n,knot **head3)
{
    int size1,size2;
    size1=GetSize(head1);
    size2=GetSize(head2);
    //printf("%d",size1);
    //printf("%d",size2);
    //проверяем что списки и переданные размеры совпадают
    if (((size1%m)!=0)||((size2%q)!=0))
    {
        printf("Wrong Matrix\n");
        exit(0);
    }
    else
    {
        knot *help1=NULL;
        knot *help2=NULL;
        knot *help3=NULL;//(m*q)
        //заполним новую матрицу нулями
        for (int p=0;p<(m*q);p++)
        {
            AddtoBegin(head3,0);
        }
        for (int i=0;i<m;i++)
            for(int j=0;j<q;j++)
            {
                help3=GetNumber(*head3,i*q+j);
                for(int k=0;k<n;k++)
                {
                    help1=GetNumber(head1,i*n+k);
                    help2=GetNumber(head2,k*q+j);
                    (help3->value)=(help3->value)+(help1->value)*(help2->value);
                }
            }
    }
}
//Транспонирование квадратных матриц
void TransporateSquareMatrix(knot **head1,int n,int m)
{
    knot *help1=NULL;
    knot *help2=NULL;
    for(int i=0;i<n;i++)
        for(int j=i;j<m;j++)
        {
            help1=GetNumber(*head1,i*m+j);
            help2=GetNumber(*head1,j*n+i);
            //printf("coordinates:%d,%d.",i,j);
            //printf("\n");
            //printf("help1 value:%d",help1->value);
            //printf("\n");
            //printf("help2 value:%d",help2->value);
            //printf("\n");
            int temp=help1->value;
            help1->value=help2->value;
            help2->value=temp;
            //printf("help1 value:%d",help1->value);
            //printf("\n");
            //printf("help2 value:%d",help2->value);
            //printf("\n");
        }
}
//просто транспонирование матриц
void TransporateMatrix(knot *head1,knot **head2,int n,int m)
{
    knot *help1=NULL;
    knot *help2=NULL;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                help1=GetNumber(head1,j*m+i);
                help2=GetNumber(*head2,i*n+j);
                help2->value=help1->value;
            }
}
//печать матрицы
void printfMatrix(knot *Head,int n,int m)
{
    knot *help=NULL;
    for (int i=0;i<(n*m);i++)
    {
        if (((i%m)==0)&&(i!=0)) printf("\n");
        help=GetNumber(Head,i);
        printf("%d ",help->value);
    }
}
//печать вещественной матрицы
void printfMatrixD(knotd *Head,int n,int m)
{
    knotd *help=NULL;
    for (int i=0;i<(n*m);i++)
    {
        if (((i%m)==0)&&(i!=0)) printf("\n");
        help=GetNumberD(Head,i);
        printf("%10.3lf ",help->value);
    }
}
//создание списка заданного размера
void CreatNewList(knot **head1,int size)
{
    for(int i=0;i<size;i++)
    {
        AddtoBegin(head1,0);
    }
}
//Метод Гауса-приведение матрицы к треугольной форме
int gaussMethod(int m,int n,knotd **head,double eps)
{
    int i,j,k,l;
    double r;
    knotd *help;
    knotd *help1;
    i=0;j=0;
    int z=0;
    while (i<m && j<n)
    {
        r=0.0;
        printf("\n");
        printf("Итерация%d:",z);
        printf("\n");
        //макс элемент в  j столбце(начало с i строки)
        for (k=i;k<m;++k)
        {
            help=GetNumberD(*head,k*n+j);
            if (fabs(help->value) > r)
            {
                l=k;                     //номер строки
                r=fabs(help->value);     //макс элемент
            }
        }
        printf("номер строки,максимальный элемент%d%10.3lf:",l,r);
        printf("\n");
        //обнулим столбец с i строки
        if (r <= eps)
        {
            for (k = i; k < m; ++k)
            {
                help=GetNumberD(*head,k*n+j);
                help->value = 0.0;
            }
            ++j;
            continue;
        }
        printf("после обнуления:");
        printf("\n");
        printfMatrixD(*head,n,m);
        printf("\n");
        //обмен местами строк
        if (l != i)
        {
            for (k = j; k < n; ++k)
            {
                help=GetNumberD(*head,i*n+k);
                r =help->value;
                help1=GetNumberD(*head,l*n + k);
                help->value = help1->value;;
                help1->value=r;
            }
        }
        printf("после обмена строк:");
        printf("\n");
        printfMatrixD(*head,n,m);
        printf("\n");
        //обнуление столбца с i+1 строки и прибавляем потом к k строке i умноженную на r
        for (k = i+1; k < m; ++k)
        {
            help=GetNumberD(*head,k*n + j);
            help1=GetNumberD(*head,i*n + j);
            r = (-(help->value) / (help1->value));
            help->value = 0.0;
            for (l = j+1; l < n; ++l)
            {
                help=GetNumberD(*head,k*n + l);
                help1=GetNumberD(*head,i*n + l);
                (help->value) += r * (help1->value);
            }
        }
        printf("после обнуления:");
        printf("\n");
        printfMatrixD(*head,n,m);
        printf("\n");
        ++i; ++j;
        z++;
    }
    return i;
}
//собственно функция считающая детерминант по приведенной матрице
double Determinant(int m,int n,knotd *head,double eps)
{
    double det=-1;
    knotd *help;
    if (m == n)
    {
        gaussMethod(m,n,&head,eps);
        det = 1;
        for (int i = 0; i < m; ++i)
        {
            help=GetNumberD(head,i*n + i);
            det *= help->value;
        }
    }
        return det;
}
//вычисление следа матрицы
int TrackOfMatrix(knot *head,int n,int m)
{
    int track=-1;
    knot *help;
    if(n==m)
    {
        track=0;
        for (int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                help=GetNumber(head,i*n+j);
                if ((i*n+j)==(j*n+i)) track+=help->value;
            }
    }
    return track;
}
/*
int main()
{
    int m=3, n=3,rank;
    knotd *head=NULL;
    knotd *help;
    double eps=0.00001, det;
    double Massife[9]={1,2,3,4,5,6,7,8,9};
    MakeListfromArrayD(&head,Massife,9);
    rank = gaussMethod(m, n, &head, eps);
    //det=Determinant(m,n,head,eps);
    //double detexp=-1;
    //det=ceil(det);
    //ASSERT_EQ(detexp,det);
    DeleteHeadD(&head);
}*/
