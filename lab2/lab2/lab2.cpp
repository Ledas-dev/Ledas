// lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <malloc.h>

int main()
{
  setvbuf(stdin, NULL, _IONBF, 0);
  setvbuf(stdin, NULL, _IONBF, 0);


  int i=0;
  int j=0;
  int r=0;
  int **a, **b, **c;
  int elem_c;

  int arr, arr1;


  printf("Введите размер массива:");
  scanf("%d",&arr );
  printf("Введите размер массива:");
  scanf("%d",&arr1 );

  a = (int **)malloc(arr* sizeof(int));
  for(int k=0;k<arr;k++){
    a[i] = (int *)malloc(arr1* sizeof(int));
  }
  b = (int **)malloc(arr* sizeof(int));
  for(int k=0;k<arr;k++){
    b[i] = (int *)malloc(arr1* sizeof(int));
  }
  c = (int **)malloc(arr* sizeof(int));
  for(int i=0;i<arr;i++){
    c[i] = (int *)malloc(arr1* sizeof(int));
  }
  srand(time(NULL));
  clock_t start = clock();
  while(i<arr){
    while(j<arr){
      a[i][j] = rand()%100+1;
      j++;
    }
    i++;
  }
  clock_t end = clock();
  double elapsed = (double)(end - start)/(CLOCKS_PER_SEC);
  printf("Выведем время выполнения %.10lf программмы\n", elapsed);
  printf("\n");
  printf("\n");
  printf("-----------------------------------------------------------\n");
  clock_t start1 = clock();
  srand(time(NULL));
  i=0; j=0;
  while(i<arr){
    while(j<arr){
      b[i][j] = rand()%100+1;
      j++;
    }
    i++;

  }
  clock_t endd = clock();
  double elapsed1 = (double)(endd - start1)/(CLOCKS_PER_SEC);
  printf("Выведем время выполнения %.10lf программмы\n", elapsed1);
  printf("\n");
  printf("\n");
  printf("-----------------------------------------------------------\n");
clock_t start2 = clock();
  for(int i=0;i<arr;i++){
    for(int j=0;j<arr;j++){
      elem_c = 0;
      for( r = 0;r<arr;r++){
        elem_c = elem_c + a[i][r] * b[j][r];
        c[i][j] = elem_c;

      }
    }
  }
  clock_t enddd = clock();
  double elapsed2 = (double)(enddd - start2)/(CLOCKS_PER_SEC);
  printf("Выведем время выполнения %.10lf программмы\n", elapsed2);

  return 0;

}
