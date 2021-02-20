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

int n,// порядок матрицы Эйлера
	k, 
	k1,// равное (ν–1)/2, где v=n/2 
	k2;// равное (ν–1)/2, где v=n/2 

int v, v1, vO, xO, i;

bool open, modified, FO;
char name[256],
	 aseq[256], //последовательность a
	 bseq[256], //последовательность b
	 gseq[256], //последовательность адресов
	 O[256]; //орбиты


void k1k2(int n) {
	v = n / 2; v1 = v - 1;  k1 = v1 / 2; k2 = v1 / 2;
}

int getk(char a[], int v) {
	int i, N;
	N = 0; for (i = 0; i < v; i++)  if (a[i] == 1) N++;
	return N;
}

int program_1()
{
	int a, 
		b, 
		c, // хранит введеное значение порядка n матрицы Эйлера 
		d;
	//char fn[256];
	open = 0; name[0] = 0; modified = 0; FO = true;
	while (1) {
		switch (menu("1. New\r\n2. Open\r\n3. Save\r\n4. Save as\r\n5. Info\r\n"\
			"6. Generate A\r\n7. Find AB\r\n8. Auto\r\n9. Exit\r\n", 10))
		{
		case 1:
			printf("Order (n):\r\n");
			scanf("%i", &c);
			n = c;
			printf("Input k1/k2? [0/1]\r\n");
			scanf("%i", &i);
			//if (i) {
			//	printf("k1:\r\n"); scanf("%i", &k1);
			//	printf("k2:\r\n"); scanf("%i", &k2);
			//}
			k1k2(c);
			//if (!k1 || n & 1) { open = 0; printf("Error\r\n"); }
			//else create(c, b, ((a - (a >> 4) - 4 * 6) / b - 4) / 12);
			if (FO) {
				xO=get_xO(c); //находим первое приближение
				vO = orbit(O, xO, v); putss("O", O, vO); puts1("vO", vO); puts1("k1=k2", k1); //находим орбиту 
				getseq(aseq, gseq, O, vO, v, k1); 
				k = getk(aseq, v); 
				FO = k == k1; 
				puts2("a", aseq, v); puts1("k1'", k);

				getseq(bseq, gseq, O, vO, v, k2); k = getk(bseq, v); FO = k == k2; 
				puts2("b", bseq, v); puts1("k2'", k);
				if (!FO) { printf("Error orbit!\r\n"); return 1; }
			}
			break;
		}
	}
}

int main() {
	srand(time(NULL));
	program_1();
}
