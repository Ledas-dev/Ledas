﻿// lab3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
void qs(int b[], int left, int right);
void easy(int c[], int arr);

int main()
{

  setlocale(LC_ALL, "Rus");
  setvbuf(stdin, NULL, _IONBF, 0);
  setvbuf(stdin, NULL, _IONBF, 0);

  srand(time(NULL));

  system("chcp 1251");
  system("cls");

  int *randomNumber;
  int *ac;
  int *b;
  int *c;
  int arr;
  int n;
  clock_t start, end;
  clock_t start1, end1;
  clock_t start2, end2;

  printf("Размер массива:");
  scanf("%d", &arr);

  //Выделяем память
  randomNumber = (int*)malloc(arr * sizeof(int));
  ac = (int*)malloc(arr * sizeof(int));
  b = (int*)malloc(arr * sizeof(int));
  c = (int*)malloc(arr * sizeof(int));


  FILE *file = fopen("text.txt", "a");

  fprintf(file, "\nВыведем время выполнения программы массив с рандомными числами\n\n");
  //Массив с рандомными числами
  printf("\nВводим массив с рандомными числами\n");
      for(int i=0; i<arr; i++){

        n = rand() %100;
        randomNumber[i] = n;
        b[i] = n;
        c[i] = n;
        printf("%d\n", randomNumber[i]);
      }
  start = clock();

  ShellNumber(arr, randomNumber);

  printf("Сортировка массива :\n\n");
  printf("Метод Шерли:\n ");
    for (int i = 0; i < arr; i++){
        printf("%d ", randomNumber[i]);
        fprintf(file, "%d ", randomNumber[i]);
    }

  end = clock();

  printf("\n\nВыведем время выполнения программы %lf\n\n", (double)(end - start)/CLOCKS_PER_SEC);
  fprintf(file, "\n\nВыведем время выполнения программы %lf\n\n", (double)(end - start)/CLOCKS_PER_SEC);

  start1 = clock();

  qs(b,  0,  arr-1);
  printf("Метод qs: \n ");
  for (int i = 0; i < arr; i++){
      printf("%d ", b[i]);
    fprintf(file, "%d ", b[i]);
  }

  end1 = clock();
  printf("\n\nВыведем время выполнения программы %lf\n\n", (double)(end1 - start1)/CLOCKS_PER_SEC);
    fprintf(file, "\n\nВыведем время выполнения программы %lf\n\n", (double)(end1 - start1)/CLOCKS_PER_SEC);
  start2 = clock();

  easy(c, arr);
  printf("Быстрая сортировка:\n");
  for(int i =0; i<arr;i++){
    printf("%d ", c[i]);
      fprintf(file,"%d ",c[i]);
  }

  end2 = clock();
  printf("\n\nВыведем время выполнения программы %lf\n\n", (double)(end2 - start2)/CLOCKS_PER_SEC);
  fprintf(file, "\n\nВыведем время выполнения программы %lf\n\n", (double)(end2 - start2)/CLOCKS_PER_SEC);

  fprintf(file, "------------------------------------------------------------------------------------------------------------------------------------------------\n");



/*
printf("\n\nВводим возрастающую последовательнусть \n");
  for(int i=1; i<=arr; i++){
    randomNumber[i]=i;
    printf("%d\n",  randomNumber[i]);
  }

printf("\nВводим массив с рандомными числами\n");
    for(int i=0; i<arr; i++){
      printf("%d\n", randomNumber[i] = rand() %100);
    }

    printf("\n\n Вводим убывающую последовательность\n");

    for(int i=arr;i>0;i--){
        randomNumber[i]=i;
      printf("%d\n",  randomNumber[i] );
    }
    printf("\n\n Вводим возростающий за тем убывающий массив\n");
    for(int i = 1; i<arr/2; i++){
        randomNumber[i]=i;
        printf("%d\n",  randomNumber[i]);
        ac[i] = randomNumber[i];
          b[i] = randomNumber[i];
            c[i] = randomNumber[i];

    }
    for(int i = arr/2; i>0; i--){
          randomNumber[i]=i;
        printf("%d\n",  randomNumber[i]);
        ac[i]=randomNumber[i];
          b[i] = randomNumber[i];
            c[i] = randomNumber[i];
    }
\

  }*/


fclose(file);
  _getch();
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
void qs(int b[], int left, int right) //вызов функции: qs(items, 0, count-1);
{
  int i, j;
  int x, y;



  i = left; j = right;

  /* выбор компаранда */
  x = b[(left+right)/2];

  do {
    while((b[i] < x) && (i < right)) i++;
    while((x < b[j]) && (j > left)) j--;

    if(i <= j) {
      y = b[i];
      b[i] = b[j];
      b[j] = y;
      i++; j--;
    }
  } while(i <= j);

  if(left < j) qs(b, left, j);
  if(i < right) qs(b, i, right);
}

void easy(int c[], int arr){
  for(int i = 0 ; i < arr - 1; i++) {
       // сравниваем два соседних элемента.
       for(int j = 0 ; j < arr - i - 1 ; j++) {
           if(c[j] > c[j+1]) {
              // если они идут в неправильном порядке, то
              //  меняем их местами.
              int tmp = c[j];
            c[j] = c[j+1] ;
              c[j+1] = tmp;
           }
        }
    }
}
