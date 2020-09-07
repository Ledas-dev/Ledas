// lab1(5).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <locale>
#include <malloc.h>
#include <stdlib.h>

// задание 5
// реализует поиск по фамилии, имени, факультету, номеру зачетной книжки
int main()
{

	struct student{
		char family[20];
		char name[20];
		char facult[20];
		int Nomzach;
	} stud[3], poisk;


	printf("Введем фамилию студента:\n");
	for (int i = 0; i < 3; i++) {
		scanf("%s", stud[i].family);
	}

	printf("Введем имя студента\n" );
	for (int i = 0; i < 3; i++) {
		scanf("%s", stud[i].name);
	}
	printf("Введем название факультета\n" );
	for (int i = 0; i < 3; i++) {
		scanf("%s", stud[i].facult);
	}
	printf("Введем номер зачетной книжки\n" );
	for (int i = 0; i < 3; i++) {
		scanf("%d", &stud[i].Nomzach);
	}

	for(int i = 0; i<3;i++){
		printf("Ученик %s %s обучается на факультете %s, номер зачетной книжки %d \n", stud[i].family, stud[i].name, stud[i].facult, stud[i].Nomzach  );
	}

do{
	printf("\nПоиск: " );
	scanf("%s %s %s %d", poisk.family, poisk.name,poisk.facult,&poisk.Nomzach  );

	for(int i = 0; i<3;i++){
		if(strcmp(stud[i].family, poisk.family)==0 && strcmp(stud[i].name, poisk.name)==0 && strcmp(stud[i].facult, poisk.facult)==0 && stud[i].Nomzach == poisk.Nomzach){
			printf("\nУченик %s %s обучается на факультете %s, номер зачетной книжки %d\n", poisk.family, poisk.name, poisk.facult,poisk.Nomzach );
		}
	}
}while(true);

	getchar();
	getchar();
	return 0;
}
