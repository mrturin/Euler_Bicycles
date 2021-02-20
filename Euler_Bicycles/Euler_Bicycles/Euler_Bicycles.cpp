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

int n, // порядок матрицы Эйлера
	k1, // равное (ν–1)/2, где v=n/2 
	k2, // равное (ν–1)/2, где v=n/2 
	m, //длинна адреса ветви 
	M, //число ветвей
	mlenA, // число листьев на дереве А
	mlenB; // число листьев на дереве В

int v, v1, v2, vO, xO, z, z1;

bool open, modified, FO;
char name[256],
	aseq[256], //последовательность a
	bseq[256], //последовательность b
	gseq[256], //последовательность адресов
	O[256], //орбиты
	A[256], //дерево А
	B[256]; //дерево В
int pw2[256];//массив степеней 2



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
	xO=get_xO(n); //находим первое приближение
	vO = orbit(O, xO, v); putss("O", O, vO); puts1("vO", vO); puts1("k1=k2", k1); //находим орбиту 

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
