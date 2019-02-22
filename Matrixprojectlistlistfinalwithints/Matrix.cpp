#include "Matrix.hpp"
#include "stdio.h"
#include "math.h"
#include "stdlib.h"
int errorinfo;
//добавление в начало  списка
void AddToBegin(knot **head,void *value)
{
    knot *help=(knot*)malloc(sizeof(knot));
    help->value=value;
    help->next=(*head);
   (*head)=help;
}
//добавление списка в список списков
void AddToBeginList(knot *head,knotknot **list)
{
    knotknot *help=(knotknot*)malloc(sizeof(knotknot));
    help->rootknot=head;
    help->next=(*list);
    (*list)=help;
}
//воврат элемента списка по номеру
knot* GetNumber(knot *head,int number)
{
    int k = 0;
    while (head && (k < number))
    {
        head = head->next;
        k++;
    }
    return head;
}
//возвращает список из списка списков по номеру
knotknot* GetNumberList(knotknot *head, int number)
{
    int k = 0;
    while (head && (k < number))
    {
        head = head->next;
        k++;
    }
    return head;
}
//удаление  списка
void DeleteHead(knot **head)
{
    knot *help1=NULL;
    while((*head)->next)
    {
        help1=(*head);
        (*head)=(*head)->next;
        //free(help1->value);
        free(help1);
    }
    free(*head);
}
//удаляет список списков
void DeleteHeadList(knotknot **head)
{
    knot *help1=NULL;
    knotknot *help2=NULL;
    while((*head)->next)
    {
        help2=*head;
        help1=(*head)->rootknot;
        (*head)=(*head)->next;
        DeleteHead(&help1);
        free(help2);
    }
    DeleteHead(&((*head)->rootknot));
    free(*head);
}
//печать списка
void PrintList(knot *head)
{
    while(head)
    {
        printf("%d",*(int*)(head->value));
        head=head->next;
    }
    printf("\n");
}
void PrintListList(knotknot *head)
{
    while(head)
    {
        PrintList(head->rootknot);
        printf("\n");
        head=head->next;
    }
}
//вовзращает размер списка
int GetSize(knot *head)
{
    int count=1;
    if (head==NULL)
    {
        printf("Error:1");
        errorinfo=NULLERROR;
        exit(1);
    }
    while (head->next)
    {
        head=head->next;
        count++;
    }
    return count;
}
//возвращает размер списка списков
int GetSizeList(knotknot *head)
{
    int count=1;
    if (head==NULL)
    {
        printf("Error:1");
        errorinfo=NULLERROR;
        exit(1);
    }
    while (head->next)
    {
        head=head->next;
        count++;
    }
    return count;
}
//преобразует массив в целочисленный список
void MakeListFromArray(knot **head,int **array,int size)
{
    int i=size -1;
    if ((*array==NULL)||(size==0)) return;
    while (i!=-1)
    {
        AddToBegin(head,array[i]);
        i--;
    }
}
void MakeListFromArrayD(knot **head,double **array,int size)
{
    int i=size -1;
    if ((*array==NULL)||(size==0)) return;
    while (i!=-1)
    {
        AddToBegin(head,array[i]);
        i--;
    }
}
//Matrix A:m строк (берем)n столбцов Matrix B:n строк q столбцов(берем)  so Matrix C:m строк q столбцов
void MatrixMultiplication(knotknot *head1,knotknot *head2,knotknot **head3)
{
    int numberofstringsmatrix1=GetSizeList(head1);
    int numberofstringsmatrix2=GetSizeList(head2);
    int numberofcolumnsmatrix1=GetSize((GetNumberList(head1,1))->rootknot);
    int numberofcolumnsmatrix2=GetSize((GetNumberList(head2,1))->rootknot);
    //printf("colimn1 %d string2 %d ",numberofstringsmatrix1,numberofstringsmatrix2);
    //printf("%d",size1);
    //printf("%d",size2);
    //проверяем что списки и переданные размеры совпадают
    if (numberofcolumnsmatrix1!=numberofstringsmatrix2)
    {
        printf("Wrong Matrix\n");
        errorinfo=WRONGERROR;
        exit(0);
    }
    else
    {
        knot *help1=NULL;
        knotknot *helphelp1=NULL;
        knot *help2=NULL;
        knotknot *helphelp2=NULL;
        knot *help3=NULL;
        knotknot *helphelp3=NULL;
        //заполним новую матрицу нулями
        for (int i=0;i<numberofstringsmatrix1;i++)
        {
            knot *help=NULL ;
            for (int j=0;j<numberofcolumnsmatrix2;j++)
            {
                int *zero;
                zero=(int*)malloc(sizeof(int));
                *zero=0;
                AddToBegin(&help,zero);
            }
            AddToBeginList(help,head3);
        }
        for (int i=0;i<numberofstringsmatrix1;i++)
            for(int j=0;j<numberofcolumnsmatrix2;j++)
            {
                helphelp3=GetNumberList(*head3,i);
                help3=GetNumber(helphelp3->rootknot,j);
                for(int k=0;k<numberofcolumnsmatrix1;k++)
                {
                    helphelp1=GetNumberList(head1,i);
                    help1=GetNumber(helphelp1->rootknot,k);
                    helphelp2=GetNumberList(head2,k);
                    help2=GetNumber(helphelp2->rootknot,j);
                    *(int*)(help3->value)=(*(int*)(help3->value))+(*(int*)(help1->value)) * (*(int*)(help2->value));
                }
            }
    }
}
//Транспонирование квадратных матриц
void TransposeSquareMatrix(knotknot **head1)
{
    knot *help1=NULL;
    knot *help2=NULL;
    int size=GetSizeList(*head1);
    for(int i=0;i<size;i++)
        for(int j=i;j<size;j++)
        {
            knotknot *helphelp1=GetNumberList(*head1,i);
            knotknot *helphelp2=GetNumberList(*head1,j);
            help1=GetNumber(helphelp1->rootknot,j);
            help2=GetNumber(helphelp2->rootknot,i);
            int *temp=(int*)help1->value;
            help1->value=(help2->value);
            help2->value=temp;
        }
}
//просто транспонирование матриц
void TransposeMatrix(knotknot *head1,knotknot **head2)
{
    knot *help1=NULL;
    knot *help2=NULL;
    int size1=GetSizeList(head1);
    int size2=GetSize((GetNumberList(head1,0))->rootknot);
    //printf("%d",size1);
    //printf("%d",size2);
    for (int i=0;i<size2;i++)
    {
        knot *help=NULL ;
        for (int j=0;j<size1;j++)
        {
            int *zero;
            zero=(int*)malloc(sizeof(int));
            *zero=0;
            AddToBegin(&help,zero);
            free(zero);
        }
        AddToBeginList(help,head2);
    }
    for(int i=0;i<size1;i++)
        for(int j=0;j<size2;j++)
        {
            knotknot *helphelp1=GetNumberList(head1,i);
            knotknot *helphelp2=GetNumberList(*head2,j);
            help1=GetNumber(helphelp1->rootknot,j);
            help2=GetNumber(helphelp2->rootknot,i);
            help2->value=help1->value;
        }
}
//печать матрицы
void PrintfMatrix(knotknot *head)
{
    int numberofstringsmatrix=GetSizeList(head);
    int numberofcolumnsmatrix;
    knotknot *helphelp=NULL;
    knot *help=NULL;
    for (int i=0;i<numberofstringsmatrix;i++)
    {
        helphelp=GetNumberList(head,i);
        numberofcolumnsmatrix=GetSize(helphelp->rootknot);
        for (int j=0;j<numberofcolumnsmatrix;j++)
        {
            help=GetNumber(helphelp->rootknot,j);
            printf("%d ",*(int*)(help->value));
        }
        printf("\n ");
    }
}
//печать вещественной матрицы
void PrintfMatrixD(knotknot *head)
{
    int numberofstringsmatrix=GetSizeList(head);
    int numberofcolumnsmatrix;
    knotknot *helphelp=NULL;
    knot *help=NULL;
    for (int i=0;i<numberofstringsmatrix;i++)
    {
        helphelp=GetNumberList(head,i);
        numberofcolumnsmatrix=GetSize(helphelp->rootknot);
        for (int j=0;j<numberofcolumnsmatrix;j++)
        {
            help=GetNumber(helphelp->rootknot,j);
            printf("%f ",*(double*)help->value);
        }
        printf("\n ");
    }
}
//создание списка заданного размера
void CreatNewList(knot **head1,int size)
{
    for(int i=0;i<size;i++)
    {
        AddToBegin(head1,0);
    }
}
//Метод Гауса-приведение матрицы к треугольной форме
int GaussMethod(knotknot **head,double eps)
{
    int i,j,k,l;
    double r;
    knotknot *helphelp;
    knotknot *helphelp1;
    knot *help;
    knot *help1;
    i=0;j=0;
    int z=0;
    int m=GetSizeList(*head);
    int n=GetSize((GetNumberList(*head,0))->rootknot);
    while (i<m && j<n)
    {
        r=0.0;/*
        printf("\n");
        printf("Итерация%d:",z);
        printf("\n");*/
        //макс элемент в  j столбце(начало с i строки)
        for (k=i;k<m;++k)
        {
            helphelp=GetNumberList(*head,k);
            help=GetNumber(helphelp->rootknot,j);
            if (fabs(*(double*)(help->value)) > r)
            {
                l=k;                     //номер строки
                r=fabs(*(double*)(help->value));     //макс элемент
            }
        }/*
        printf("номер строки,максимальный элемент%d%10.3lf:",l,r);
        printf("\n");*/
        //обнулим столбец с i строки
        if (r <= eps)
        {
            for (k = i; k < m; ++k)
            {
                helphelp=GetNumberList(*head,k);
                help=GetNumber(helphelp->rootknot,j);
                *(double*)(help->value) = 0.0;
            }
            ++j;
            continue;
        }/*
        printf("после обнуления:");
        printf("\n");
        PrintfMatrixD(*head);
        printf("\n");*/
        //обмен местами строк
        if (l != i)
        {
            for (k = j; k < n; ++k)
            {
                helphelp=GetNumberList(*head,i);
                help=GetNumber(helphelp->rootknot,k);
                r =*(double*)(help->value);
                helphelp1=GetNumberList(*head,l);
                help1=GetNumber(helphelp1->rootknot,k);
                *(double*)(help->value) = *(double*)(help1->value);
                *(double*)(help1->value)=-r;
            }
        }/*
        printf("после обмена строк:");
        printf("\n");
        PrintfMatrixD(*head);
        printf("\n");*/
        //обнуление столбца с i+1 строки и прибавляем потом к k строке i умноженную на r
        for (k = i+1; k < m; ++k)
        {
            helphelp=GetNumberList(*head,k);
            help=GetNumber(helphelp->rootknot,j);
            helphelp1=GetNumberList(*head,i);
            help1=GetNumber(helphelp1->rootknot,j);
            r = (-(*(double*)(help->value)) / (*(double*)(help1->value)));
            *(double*)(help->value) = 0.0;
            for (l = j+1; l < n; ++l)
            {
                helphelp=GetNumberList(*head,k);
                help=GetNumber(helphelp->rootknot,l);
                helphelp1=GetNumberList(*head,i);
                help1=GetNumber(helphelp1->rootknot,l);
                *(double*)(help->value) += r *(*(double*)(help1->value));
            }
        }/*
        printf("после обнуления:");
        printf("\n");
        PrintfMatrixD(*head);
        printf("\n");*/
        ++i; ++j;
        z++;
    }
    return i;
}
//собственно функция считающая детерминант по приведенной матрице
double Determinant(knotknot *head,double eps)
{
    double det=-1;
    knotknot *helphelp;
    knot *help;
    int m=GetSizeList(head);
    int n=GetSize((GetNumberList(head,0))->rootknot);
    if (m == n)
    {
        GaussMethod(&head,eps);
        det = 1;
        for (int i = 0; i < m; ++i)
        {
            helphelp=GetNumberList(head,i);
            help=GetNumber(helphelp->rootknot,i);
            det *= *(double*)(help->value);
        }
    }
        return det;
}
//вычисление следа матрицы
int* TraceOfMatrix(knotknot *head)
{
    int *track;
    track=(int*)malloc(sizeof(int));
    *track=-1;
    int size1=GetSizeList(head);
    int size2=GetSize((GetNumberList(head,0))->rootknot);
    knot *help=NULL;
    knotknot *helphelp=NULL;
    if(size1==size2)
    {
        *track=0;
        for (int i=0;i<size1;i++)
            for(int j=0;j<size1;j++)
            {
                helphelp=GetNumberList(head,i);
                help=GetNumber(helphelp->rootknot,j);
                if (i==j) (*track)+=*(int*)(help->value);
            }
    }
    return track;
}
