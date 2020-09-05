// lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <locale>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int arr;
	int max = 0;
	int min = 0;
	int sum = 0;
	int *b;
	
	printf_s("Введите размер массива ");
	scanf_s("%d", &arr);

	b = (int *)malloc(arr * sizeof(int));


	for (int i = 0; i < arr; i++) 
		printf_s("%d\n", b[i] = rand() % 100);

	for (int j = 0; j < arr; j++) {
		if (b[j] > max) {
			max = b[j];
			min = b[j] + 1;
		}
	}
	for (int j = 0; j < arr; j++) {
		if (b[j] < min) {
			min = b[j];
		}
	}
	sum = max - min;

	printf_s("Max = %d\n", max);
	printf_s("Min = %d\n", min);
	printf_s("Выведем разницу между max min: %d", sum);
	free(b);
	getchar(), getchar();
	return 0;
	




}

