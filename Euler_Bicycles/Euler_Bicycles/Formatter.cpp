/******************************************************************************
     * File: Formatter.cpp
     * Description: Определяет методы связанные с выводом текстовой информации в консоль
******************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

int menu(const char* items, int count) {
	int i;
	printf(items);
	do scanf("%i", &i);	
	while (i > count || i <= 0);
	return i;
}

void puts(const char name[], char a[], int v) {
	int i;
	printf(name); printf("=[ ");
	for (i = 0; i < v; i++) {
		printf("%i ", a[i]);
	}
	printf("];\r\n");
}

void puts1(const char name[], int a) {
	printf(name); printf("="); printf("%i", a); printf(";\r\n");
}

void puts2(const char name[], char a[], int v) {
	int i;
	printf(name); printf("=[");
	for (i = 0; i < v; i++) {
		if (i > 0) printf(",");
		printf("%c1", a[i] ? '-' : '+');
	}
	printf("];\r\n");
}


void putss(const char name[], std::vector<char> a, int v) {
	int i;
	printf(name); printf("=[");
	for (i = 0; i < v; i++) {
		if (i > 0) printf(",");
		printf("%i", a[i]);
	}
	printf("];\r\n");
}
