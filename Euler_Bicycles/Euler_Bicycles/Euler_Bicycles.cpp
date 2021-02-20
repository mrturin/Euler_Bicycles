// Euler_Bicycles.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "Formatter.h" // описывает модуль вывода текста в консоль
#include "Orbit.h" // описывает модуль работы с орбитами
#include "Sequence_Generator.h" // описывает модуль работы с генерацией последовательностей
#include "Tree.h"//описывает модуль работы с деревьями

int n, // порядок матрицы Эйлера
	k1, // равное (ν–1)/2, где v=n/2 
	k2, // равное (ν–1)/2, где v=n/2 
	m, //длинна адреса ветви 
	M, //число ветвей
	mlenA=200, // число листьев на дереве А
	mlenB=20, // число листьев на дереве В
	Len,Len1,
	N0,N1,N2,N3,
	N0L, N1L, N2L, N3L,//- аналог v1 для куска кода
	L1, L2, L3,
	v,//размер последовательностей a,b
	v1,v2,
	vO,//размер массива орбит 
	xO,//первый X для поиска орбит
	z, z1;

bool open, modified, FO;
char aseq[256], //последовательность a
	 bseq[256], //последовательность b
	 gseq[256], //последовательность адресов
	 O[256]; //орбиты
	
int pw2[256];//массив степеней 2

char*** A;//дерево А
char*** B;//дерево В

void init(int n) {
	v = n / 2; 
	v1 = v - 1;  
	k1 = k2 = v1 / 2;
	z = (v + 1) / 2;
	z1 = z - 1;

	m = 8;
	if (m > z1) m = z1;
	M = pow(2, m);
	pw2[0] = 1;
	for (int i = 0; i < m; i++) pw2[i + 1] = pow(2, i);
}

void program_1()
{
	printf("Order (n):\r\n");
	scanf("%i", &n);
	init(n);
	xO=get_xO(n);
	vO = orbit(O, xO, v); putss("O", O, vO); puts1("vO", vO); puts1("k1=k2", k1); //находим орбиту 
	
	//ГЕНЕРАЦИЯ ДЕРЕВЬЕВ А,В
	A = init_tree(mlenA, M);
	B = init_tree(mlenB, M);
	char* lenA = new char[M];
	char* lenB = new char[M];

	// ДЛИНА КУСКА КОДА В БИТАХ
	Len = 32;
	Len1 = Len - 1;
	N0 = N1 = N2 = N3 = 0;
	// Длины в битах N0L,N1L,N2L,N3L - аналог v1 для куска кода
	L1 = Len1;
	if (v1 < L1) L1 = v1;
	N0L = L1;
	L2 = L3 = 0;
	N1L = N2L = N3L = 0;
	







	//putss("pw2", pw2, m+1);

	
	/*getseq(aseq, gseq, O, vO, v, k1); 
				
				FO = k == k1; 
				puts2("a", aseq, v); puts1("k1'", k);

				getseq(bseq, gseq, O, vO, v, k2);  FO = k == k2; 
				puts2("b", bseq, v); puts1("k2'", k);*/
				
			
		
}


int main() {
	srand(time(NULL));
	program_1();
}
