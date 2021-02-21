// Euler_Bicycles.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "Formatter.h" // описывает модуль вывода текста в консоль
#include "Orbit.h" // описывает модуль работы с орбитами
#include "Sequence_Generator.h" // описывает модуль работы с генерацией последовательностей
#include "Tree.h"//описывает модуль работы с деревьями
#include "Math_Function.h"//описывает модуль работы с деревьями

int n, // порядок матрицы Эйлера
	k1, // равное (ν–1)/2, где v=n/2 
	k2, // равное (ν–1)/2, где v=n/2 
	m, //длинна адреса ветви 
	M, //число ветвей
	mlenA=200, // число листьев на дереве А
	mlenB=20, // число листьев на дереве В
	Len,Len1,
	N0,N1,N2,N3,
	N, NumAN,
	N0L, N1L, N2L, N3L,//- аналог v1 для куска кода
	L1, L2, L3,
	v,//размер последовательностей a,b
	v1,v2,
	vO,//размер массива орбит 
	xO,//первый X для поиска орбит
	z, z1;

bool open, modified, FO, F;
std::vector<char> a,//последовательность a
				  b, //последовательность b
				  g, //последовательность адресов
				  O, //орбиты
				  Aa, 
                  Bb;
	
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
	vO = orbit(O, xO, v); 
	putss("O", O, vO); puts1("vO", vO); puts1("k1=k2", k1); //находим орбиту 
	
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
	for (int i = 0; i < Len; i++)
	{
		L1++;
		if (L1 <= v1) {
			L2 = L1;
			N1L = i;
		}
	}
	L3 = L2;
	for (int i = 0; i < Len; i++)
	{
		L2++;
		if (L2 <= v1) {
			L3 = L2;
			N2L = i;
		}
	}
	for (int i = 0; i < Len; i++)
	{
		L3++;
		if (L3 <= v1) N3L = i;
	}

	a = zero(v);
	Aa = zero(z);
	b = zero(v);
	Bb = zero(z);
	g = zero(v);
	N = NumAN = 0;
	F = true;
	// F Флаг "искать" !
 // START ВНУТРЕННЕГО ЦИКЛА ПОИСКА
	for (int kit = 0; kit < 1000; kit++)
		if (F) {

			//// Генерируем ДЕРЕВО A
			//getseq(a, g, O, vO, v, k1);
			//mulcirc2(a, Aa, 2, v, 1, z);
			//N = branchA(Aa, m, M);
			////lenAN = lenA[N];
			////seq2num4(a, v1); //  puts(N+"! a="+a);
			//A[N][lenAN][0] = N0;
			//A[N][lenAN][1] = N1;
			//A[N][lenAN][2] = N2;
			//A[N][lenAN][3] = N3;
			//if (lenAN < mlenA) lenA[N] = lenAN + 1;

			//// Генерируем ДЕРЕВО B
			//getseq(b, g, O, vO, v, k2);
			//mulcirc2(b, Bb, 0, v, 1, z);
			//N = branchB(Bb, m, M);
			////lenBN = lenB[N];
			//seq2num4(b, v1); // puts(N+"! b="+b);
			//B[N][lenBN][0] = N0;
			//B[N][lenBN][1] = N1;
			//B[N][lenBN][2] = N2;
			//B[N][lenBN][3] = N3;
			//if (lenBN < mlenB) {
			//	lenB[N] = lenBN + 1;
			//}
			//else {
			//	FINDAB(N);
			//}

		} // внутренний цикл kit
				
}


int main() {
	srand(time(NULL));
	program_1();
}
