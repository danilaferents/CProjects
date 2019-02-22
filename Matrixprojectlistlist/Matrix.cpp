#include "Matrix.hpp"
#include "stdio.h"
#include "math.h"
#include "stdlib.h"
//добавление в начало целочисленного списка
void AddToBegin(knot **head,int value)
{
    knot *help=(knot*)malloc(sizeof(knot));
    help->value=value;
    help->next=(*head);
   (*head)=help;
}
//добавление в начало вещественного списка
void AddToBeginD(knotd **head,double value)
{
    knotd *help=(knotd*)malloc(sizeof(knotd));
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
void AddToBeginListD(knotd *head,knotknotd **list)
{
    knotknotd *help=(knotknotd*)malloc(sizeof(knotknotd));
    help->rootknot=head;
    help->next=(*list);
    (*list)=help;
}
//удаление с начала списка
int DeleteFromBegin(knot **head)
{
    knot *help;
    int value;
    if(head==NULL)
    {
        printf("Error 0");
        exit(0);
    }
    help=(*head);
    value=help->value;
    (*head)=(*head)->next;
    free(help);
    return value;
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
knotknotd* GetNumberListD(knotknotd *head, int number)
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
void DeleteHead(knot **head)
{
    knot *help1=NULL;
    while((*head)->next)
    {
        help1=(*head);
        (*head)=(*head)->next;
        free(help1);
    }
    free(*head);
}
//удаление вещественного списка
void DeleteHeadD(knotd **head)
{
    knotd *help1=NULL;
    while((*head)->next)
    {
        help1=(*head);
        (*head)=(*head)->next;
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
void DeleteHeadListD(knotknotd **head)
{
    knotd *help1=NULL;
    knotknotd *help2=NULL;
    while((*head)->next)
    {
        help2=*head;
        help1=(*head)->rootknot;
        (*head)=(*head)->next;
        DeleteHeadD(&help1);
        free(help2);
    }
    DeleteHeadD(&((*head)->rootknot));
    free(*head);
}
//печать списка
void PrintList(knot *head)
{
    while(head)
    {
        printf("%d",head->value);
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
        exit(1);
    }
    while (head->next)
    {
        head=head->next;
        count++;
    }
    return count;
}
int GetSizeD(knotd *head)
{
    int count=1;
    if (head==NULL)
    {
        printf("Error:1");
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
        exit(1);
    }
    while (head->next)
    {
        head=head->next;
        count++;
    }
    return count;
}
int GetSizeListD(knotknotd *head)
{
    int count=1;
    if (head==NULL)
    {
        printf("Error:1");
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
void MakeListFromArray(knot **head,int *array,int size)
{
    int i=size -1;
    if ((array==NULL)||(size==0)) return;
    while (i!=-1)
    {
        AddToBegin(head,array[i]);
        i--;
    }
}
//преобразует массив в вещественный список
void MakeListFromArrayD(knotd **head,double *array,int size)
{
    int i=size -1;
    if ((array==NULL)||(size==0)) return;
    while (i!=-1)
    {
        AddToBeginD(head,array[i]);
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
                AddToBegin(&help,0);
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
                    (help3->value)=(help3->value)+(help1->value)*(help2->value);
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
void TransposeMatrix(knotknot *head1,knotknot **head2)
{
    knot *help1=NULL;
    knot *help2=NULL;
    int size1=GetSizeList(head1);
    int size2=GetSize((GetNumberList(head1,0))->rootknot);
    for (int i=0;i<size2;i++)
    {
        knot *help=NULL ;
        for (int j=0;j<size1;j++)
            AddToBegin(&help,0);
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
            printf("%d ",help->value);
        }
        printf("\n ");
    }
}
//печать вещественной матрицы
void PrintfMatrixD(knotknotd *head)
{
    int numberofstringsmatrix=GetSizeListD(head);
    int numberofcolumnsmatrix;
    knotknotd *helphelp=NULL;
    knotd *help=NULL;
    for (int i=0;i<numberofstringsmatrix;i++)
    {
        helphelp=GetNumberListD(head,i);
        numberofcolumnsmatrix=GetSizeD(helphelp->rootknot);
        for (int j=0;j<numberofcolumnsmatrix;j++)
        {
            help=GetNumberD(helphelp->rootknot,j);
            printf("%f ",help->value);
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
int GaussMethod(knotknotd **head,double eps)
{
    int i,j,k,l;
    double r;
    knotknotd *helphelp;
    knotknotd *helphelp1;
    knotd *help;
    knotd *help1;
    i=0;j=0;
    int z=0;
    int m=GetSizeListD(*head);
    int n=GetSizeD((GetNumberListD(*head,0))->rootknot);
    while (i<m && j<n)
    {
        r=0.0;
        printf("\n");
        printf("Итерация%d:",z);
        printf("\n");
        //макс элемент в  j столбце(начало с i строки)
        for (k=i;k<m;++k)
        {
            helphelp=GetNumberListD(*head,k);
            help=GetNumberD(helphelp->rootknot,j);
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
                helphelp=GetNumberListD(*head,k);
                help=GetNumberD(helphelp->rootknot,j);
                help->value = 0.0;
            }
            ++j;
            continue;
        }
        printf("после обнуления:");
        printf("\n");
        PrintfMatrixD(*head);
        printf("\n");
        //обмен местами строк
        if (l != i)
        {
            for (k = j; k < n; ++k)
            {
                helphelp=GetNumberListD(*head,i);
                help=GetNumberD(helphelp->rootknot,k);
                r =help->value;
                helphelp1=GetNumberListD(*head,l);
                help1=GetNumberD(helphelp1->rootknot,k);
                help->value = help1->value;
                help1->value=-r;
            }
        }
        printf("после обмена строк:");
        printf("\n");
        PrintfMatrixD(*head);
        printf("\n");
        //обнуление столбца с i+1 строки и прибавляем потом к k строке i умноженную на r
        for (k = i+1; k < m; ++k)
        {
            helphelp=GetNumberListD(*head,k);
            help=GetNumberD(helphelp->rootknot,j);
            helphelp1=GetNumberListD(*head,i);
            help1=GetNumberD(helphelp1->rootknot,j);
            r = (-(help->value) / (help1->value));
            help->value = 0.0;
            for (l = j+1; l < n; ++l)
            {
                helphelp=GetNumberListD(*head,k);
                help=GetNumberD(helphelp->rootknot,l);
                helphelp1=GetNumberListD(*head,i);
                help1=GetNumberD(helphelp1->rootknot,l);
                (help->value) += r * (help1->value);
            }
        }
        printf("после обнуления:");
        printf("\n");
        PrintfMatrixD(*head);
        printf("\n");
        ++i; ++j;
        z++;
    }
    return i;
}
//собственно функция считающая детерминант по приведенной матрице
double Determinant(knotknotd *head,double eps)
{
    double det=-1;
    knotknotd *helphelp;
    knotd *help;
    int m=GetSizeListD(head);
    int n=GetSizeD((GetNumberListD(head,0))->rootknot);
    if (m == n)
    {
        GaussMethod(&head,eps);
        det = 1;
        for (int i = 0; i < m; ++i)
        {
            helphelp=GetNumberListD(head,i);
            help=GetNumberD(helphelp->rootknot,i);
            det *= help->value;
        }
    }
        return det;
}
//вычисление следа матрицы
int TraceOfMatrix(knotknot *head)
{
    int track=-1;
    int size1=GetSizeList(head);
    int size2=GetSize((GetNumberList(head,0))->rootknot);
    knot *help=NULL;
    knotknot *helphelp=NULL;
    if(size1==size2)
    {
        track=0;
        for (int i=0;i<size1;i++)
            for(int j=0;j<size1;j++)
            {
                helphelp=GetNumberList(head,i);
                help=GetNumber(helphelp->rootknot,j);
                if (i==j) track+=help->value;
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
/*
int main()
{
    int array1[3]={1,2,3};
    int array2[3]={4,5,6};
    int array3[3]={7,8,9};
    knot *head1=NULL;
    knot *head2=NULL;
    knot *head3=NULL;
    knotknot *list1=NULL;
    MakeListFromArray(&head1,array1,3);
    MakeListFromArray(&head2,array2,3);
    MakeListFromArray(&head3,array3,3);
    AddToBeginList(head3,&list1);
    AddToBeginList(head2,&list1);
    AddToBeginList(head1,&list1);
    PrintfMatrix(list1);
    printf("\n");
    TransposeSquareMatrix(&list1);
    PrintfMatrix(list1);
    printf("\n");
    DeleteHeadList(&list1);
}*/
