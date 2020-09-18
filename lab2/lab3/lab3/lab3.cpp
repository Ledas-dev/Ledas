// lab3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <locale>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void ShellNumber(int arr, int randomNumber[]);
void qs(int randomNumber[], int left, int right);

int main()
{
  setvbuf(stdin, NULL, _IONBF, 0);
  setvbuf(stdin, NULL, _IONBF, 0);

  srand(time(NULL));

  int *randomNumber;
  int *higthNumber;
  int *smallNumber;
  int *HSNumber;
  int arr;

  clock_t start, end;
  clock_t start1, end1;

  printf("Размер массива:");
  scanf("%d", &arr);

  //Выделяем память
  randomNumber = (int*)malloc(arr * sizeof(int));
  higthNumber = (int*)malloc(arr * sizeof(int));
  smallNumber = (int*)malloc(arr * sizeof(int));
  HSNumber = (int*)malloc(arr * sizeof(int));

  //Массив с рандомными числами
  printf("\nВводим массив с рандомными числами\n");
  for(int i=0; i<arr; i++){
    printf("%d\n", randomNumber[i] = rand() %100);
  }
  start = clock();

  ShellNumber(arr, randomNumber);

  printf("Сортировка массива :\n\n");
    for (int i = 0; i < arr; i++)
        printf("%d ", randomNumber[i]);

  end = clock();

  printf("\n\nВыведем время выполнения программы %lf\n", (double)(end - start)/CLOCKS_PER_SEC);

  start1 = clock();
  
  qs(randomNumber,  0,  arr-1);
  for (int i = 0; i < arr; i++)
      printf("%d ", randomNumber[i]);

  end1 = clock();
  printf("\n\nВыведем время выполнения программы %lf\n", (double)(end1 - start1)/CLOCKS_PER_SEC);

  //Возростающая последовательность
/*  printf("\n\nВводим возрастающую последовательнусть \n");
  for(int i=1; i<=arr; i++){
    higthNumber[i]=i;
    printf("%d\n", higthNumber[i]);
  }
  //Вводим убывающую последоватьльность
  printf("\n\n Вводим убывающую последовательность\n");

  for(int i=arr;i>0;i--){
    smallNumber[i]=i;
    printf("%d\n", smallNumber[i] );
  }

  // Вводим сначала возростающую за тем убывающую последовательность
  printf("\n\n Вводим возростающий за тем убывающий массив\n");
  for(int i = 1; i<arr/2; i++){
      HSNumber[i]=i;
      printf("%d\n", HSNumber[i]);
  }
  for(int i = arr/2; i>0; i--){
      HSNumber[i]=i;
      printf("%d\n", HSNumber[i]);
  }*/



  _getch();
  free(HSNumber);
  free(smallNumber);
  free(higthNumber);
  free(randomNumber);
  return 0;
}

// Сортировка Шелла
void ShellNumber(int arr, int randomNumber[])
{

  int i, j, gap, k;
  int x, a[5];

  a[0]=9; a[1]=5; a[2]=3; a[3]=2; a[4]=1;

  for(k=0; k < arr; k++) {
    gap = a[k];
    for(i=gap; i < arr; ++i) {
      x = randomNumber[i];
      for(j=i-gap; (x < randomNumber[j]) && (j >= 0); j=j-gap)
        randomNumber[j+gap] = randomNumber[j];
      randomNumber[j+gap] = x;
    }
  }
}

// Сортировка qs
void qs(int randomNumber[], int left, int right) //вызов функции: qs(items, 0, count-1);
{
  int i, j;
  int x, y;



  i = left; j = right;

  /* выбор компаранда */
  x = randomNumber[(left+right)/2];

  do {
    while((randomNumber[i] < x) && (i < right)) i++;
    while((x < randomNumber[j]) && (j > left)) j--;

    if(i <= j) {
      y = randomNumber[i];
      randomNumber[i] = randomNumber[j];
      randomNumber[j] = y;
      i++; j--;
    }
  } while(i <= j);

  if(left < j) qs(randomNumber, left, j);
  if(i < right) qs(randomNumber, i, right);
}
