/*
 int main()
 {
 int size1=3,size2=4,size3=5;
 int Massife1[12]={1,2,3,4,5,6,7,8,9,5,4,3};
 int Massife2[15]={9,8,7,6,5,4,3,2,1,1,2,3,4,5,6};
 knot *list1=NULL;
 knot *list2=NULL;
 knot *list3=NULL;
 MakeListfromArray(&list1,Massife1,size1*size2);
 MakeListfromArray(&list2,Massife2,size1*size3);
 //PrintList(list1);
 //printfMatrix(list1,size2,size1);
 // printfMatrix(list2,size1,size3);
 Matrixmultiplication(list1,list2,size2,size3,size1,&list3);
 //PrintList(list3);
 printfMatrix(list3,size2,size3);
 }
 */
/*
 int main()
 {
 int size1=3,size2=3,size3=0;
 int Massife1[9]={1,2,3,4,5,6,7,8,9};
 knot *list1=NULL;
 MakeListfromArray(&list1,Massife1,size1*size2);
 printfMatrix(list1,size2,size1);
 int track=TrackOfMatrix(list1,size1,size2);
 printf("%d",track);
 }*/
/*
 int main()
 {
 int size1=3,size2=5;
 int Massife1[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
 knot *list1=NULL;
 knot *list2=NULL;
 CreatNewList(&list2,size1*size2);
 MakeListfromArray(&list1,Massife1,size1*size2);
 printfMatrix(list1,size2,size1);
 printf("\n");
 TransporateMatrix(list1,&list2,size2,size1);
 printfMatrix(list2,size1,size2);
 }*/
/*
 int main()
 {
 int size1=3,size2=7;
 int Massife1[21]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21};
 // int Massife2[21]={1,8,15,2,9,16,3,10,17,4,11,18,5,12,19,6,13,20,7,14,21};
 knot *list1=NULL;
 knot *list2=NULL;
 CreatNewList(&list2,size1*size2);
 MakeListfromArray(&list1,Massife1,size1*size2);
 printfMatrix(list1,size1,size2);
 printf("\n");
 TransporateMatrix(list1,&list2,size1,size2);
 printfMatrix(list2,size2,size1);
 }*/
/*
 int main()
 {
 int m=4, n=4, i, j, rank;
 knotd *head;
 knotd *help;
 double eps=0.00001, det;
 double Massife[16]={1,2,3,4,4,3,2,1,5,6,7,8,8,7,6,5};
 MakeListfromArrayD(&head,Massife,16);
 printfMatrixD(head,4,4);
 rank = gaussMethod(m, n, &head, eps);
 printf("Ступенчатый вид матрицы:\n");
 for (i = 0; i < m; ++i)
 {
 for (j = 0; j < n; ++j)
 {
 help=GetNumberD(head,i*n + j);
 printf( "%10.3lf ",help->value);
 }
 printf("\n");
 }
 printf("Ранг матрицы = %d\n", rank);
 if (m == n)
 {
 det = 1.0;
 for (i = 0; i < m; ++i)
 {
 help=GetNumberD(head,i*n + i);
 det *= help->value;
 }
 printf("Определитель матрицы = %.3lf\n", det);
 }
 return 0;
 }*/
/*
 int main()
 {
 int m=3, n=3, i, j, rank;
 knotd *head;
 knotd *help;
 double eps=0.00001, det;
 double Massife[9]={1,2,4,4,5,6,7,8,9};
 MakeListfromArrayD(&head,Massife,9);
 printfMatrixD(head,3,3);
 rank = gaussMethod(m, n, &head, eps);
 printf("Ступенчатый вид матрицы:\n");
 for (i = 0; i < m; ++i)
 {
 for (j = 0; j < n; ++j)
 {
 help=GetNumberD(head,i*n + j);
 printf( "%10.3lf ",help->value);
 }
 printf("\n");
 }
 printf("Ранг матрицы = %d\n", rank);
 det=Determinant(m,n,head,eps);
 printf("Определитель матрицы = %.3lf\n", det);
 return 0;
 }
 */
