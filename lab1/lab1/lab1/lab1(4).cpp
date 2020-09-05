#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <locale>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

int main() {


	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int *b;
	int min = 0;
	int max = 0;
	int sum = 0;

	int arr1;
	int arr2;
	int arr3;



	printf_s("Введем количество чисел в матрице\n:  ");
	scanf_s("%d\n", &arr1);
	printf_s("Введем количество строк в матрице\n:  ");
	scanf_s("%d\n", &arr2);
	printf_s("Введем количество столбцов в матрице\n:  ");
	scanf_s("%d\n", &arr3);

	b = (int *)malloc(arr1 * sizeof(int));

	for (int i = 0; i < arr1; i++) {
		b[i] = rand() % 100;
	}

	for (int i = 0; i < arr2; i++) {
		for (int j = 0; j < arr3; j++) {
			printf_s("%d", b);
		}
		printf_s("\n");
	}
	getchar();
	return 0;
}