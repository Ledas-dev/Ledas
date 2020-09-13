// lab1(4).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <locale>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>


// Задание 4
// Считаем сумму строк
int main() {


	srand(time(NULL));
	int **b;
	int *sum;
	int arr2;
	int arr3;



	// Устанавливаем размер матрицы
	printf("Введем количество строк в матрице\n:  ");
	scanf("%d", &arr2);
	printf("Введем количество столбцов в матрице\n:  ");
	scanf("%d", &arr3);

	// выделяем память под массив и матрицу
	sum = (int *)malloc(arr2 * sizeof(int));

	b = (int **)malloc(arr2 * sizeof(int));
	for (int i = 0; i < arr2; i++) {
		b[i] = (int*)malloc(arr3 * sizeof(int));
	}

	// Интелезируем матрицу и вычисляем сумму строк
	for (int i = 0; i < arr2; i++) {
		sum[i] = 0;
		for (int j = 0; j < arr3; j++) {
			printf("%4d", b[i][j] = rand() % 201 - 100);
			if(b[i][j]>=0){
						sum[i] += b[i][j];
			}
		}
		printf("\n\n");
	}
// Выводим ответ
	for (int i = 0; i < arr2; i++) {
		printf("\n%d", sum[i]);
	}

	for (int i = 0; i < arr2; i++) {
		free(b[i]);
	}
	free(b);
	free(sum);
	getchar();
	return 0;
}
