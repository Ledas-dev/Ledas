// lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

int main()
{
  setvbuf(stdin, NULL, _IONBF, 0);
  setvbuf(stdin, NULL, _IONBF, 0);


  int i=0;
  int j=0;
  int a[100][100], b[100][100], c[100][100], elem_c;

  srand(time(NULL));

  clock_t start = clock();
  while(i<100){
    while(i<100){
      a[i][j] = rand()%100+1;
      j++;
    }
    i++;
  }
  clock_t end = clock();
  double elapsed = (double)(end - start)/(CLOCKS_PER_SEC);
  printf("Выведем время выполнения %.10lf программмы\n", elapsed);
  clock_t start1 = clock();
  srand(time(NULL));
  i=0; j=0;
  while(i<100){
    while(j<100){
      b[i][j] = rand()%100+1;
      j++;
    }
    i++;
  }
  clock_t endd = clock();
  double elapsed1 = (double)(endd - start1)/(CLOCKS_PER_SEC);
  printf("Выведем время выполнения %.10lf программмы\n", elapsed1);
clock_t start2 = clock();
  for(int i=0;i<100;i++){
    for(int j=0;j<100;j++){
      elem_c = 0;
      for(int r =0;r<100;r++){
        elem_c = elem_c + a[i][r] * b[r][j];
        c[i][j] = elem_c;
      }
    }
  }
  clock_t enddd = clock();
  double elapsed2 = (double)(enddd - start2)/(CLOCKS_PER_SEC);
  printf("Выведем время выполнения %.10lf программмы\n", elapsed2);

  return 0;

}
