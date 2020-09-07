// lab1(5).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <locale>
#include <malloc.h>
#include <stdlib.h>


int main()
{

	struct student{
		char family[20];
		char name[20];
		char facult[20];
		int Nomzach;
	} stud[3];

printf("Введем фамилию студента:\n");
	for (int i = 0; i < 3; i++) {
		scanf("%s", stud[i].family);
	}





	getchar();
	getchar();
	return 0;
}
