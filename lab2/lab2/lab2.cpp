// lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <malloc.h>
#include <stddef.h>

int a[4000][4000], b[4000][4000], c[4000][4000];

int main()
{
  setvbuf(stdin, NULL, _IONBF, 0);
  setvbuf(stdin, NULL, _IONBF, 0);


  int i=0;
  int j=0;
  int r=0;

  int elem_c;

  int arr;

  clock_t begin2, finish2;

  printf("Введите размер массива:");
  scanf("%d",&arr );

  srand(time(NULL));


  while(i<arr){
    while(j<arr){
      a[i][j] = rand()%100+1;
      j++;
    }
    i++;
  }


  srand(time(NULL));


  i=0; j=0;
  while(i<arr){
    while(j<arr){
      b[i][j] = rand()%100+1;
      j++;
    }
    i++;

  }

  srand(time(NULL));

  begin2 = clock();

  for(int i=0;i<arr;i++){
    for(int j=0;j<arr;j++){
      elem_c = 0;
      for( r = 0;r<arr;r++){
        elem_c = elem_c + a[i][r] * b[j][r];
        c[i][j] = elem_c;
      }
    }
  }
  finish2 = clock();
  printf("Выведем время выполнения программы %ld\n", (finish2 - begin2)/CLOCKS_PER_SEC);

  getchar();
  return 0;

}
