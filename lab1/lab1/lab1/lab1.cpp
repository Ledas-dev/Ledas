// lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <locale>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>




/* Задание 1-3
	1) выводит разницу между максимальным и минимальным числом
	2) Устанавливаем размер массива в консоле
	3) В массив выводит рандомные числа
*/
int main()
{

	srand(time(NULL));
	int arr;
	int max = 0;
	int min = 0;
	int sum = 0;
	int *b;

	// Вводим размер массива
	printf("Введите размер массива ");
	scanf("%d", &arr);

	// Выделяем память под массив

	b = (int *)malloc(arr * sizeof(int));

	// Интелезируем массив
	for (int i = 0; i < arr; i++)
		printf("%d\n", b[i] = rand() % 100);
	// Вычисляем разницу
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

	// Выводим ответ
	printf("Max = %d\n", max);
	printf("Min = %d\n", min);
	printf("Выведем разницу между max min: %d", sum);
	free(b);
	getchar(), getchar();
	return 0;

}
