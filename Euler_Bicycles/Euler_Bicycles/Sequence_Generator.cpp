﻿/******************************************************************************
	 * File: Sequence_Generator.cpp
	 * Description: Определяет методы связанные с генерацией последовательностей a,b
******************************************************************************/

#include <stdlib.h>
#include <vector>
/**
	* Формирует k1 адресов g=[случ. число*O, случ. число*O,...] элементов 1 в последовательности a (где коды 1 и 0 отвечают элементам -1 и 1), опираясь на орбиту O.
	* @param a[] - будущий массив с 1 и -1. На данном этапе заполнен 0, размер равен v = n/2;
	* @param g[] - будущий массив адресов. На данном этапе заполнен 0, размер равен v = n/2;
	* @param O[] - массив орбит;
	* @param vO - размер массива орбит;
	* @param v - размер последовательности = n/2;
	* @param k1 - равное (?–1)/2;
	*/
void getseq(std::vector<char> a, std::vector<char> g, std::vector<char> O, int vO, int v, int k1) {
    int j, m, s, s1, s2, rs, F;
    m = 0;
    s = 0;
    F = s < k1;
    s1 = s;
    while (F) {
        m++;
        if (m > 400) break;
        // if (FlgSym1) { rs=rand()%v2; rs++; }else{ rs=rand()%v; }
        rs = rand() % v;
        for (j = 0; j < vO; j++) {
            s2 = (rs * O[j]) % v;
            g[s + j] = s2;
        }
        // if FlgSym1 then { rs=s; s=s+vO1; for (j=0;j<vO;j++) g[s+j]=v-g[rs+j]; }
        s = s + vO;
        if (s >= k1) {
            for (j = 0; j < v; j++) a[j] = 0;
            for (j = 0; j < s; j++) a[g[j]] = -1;
            s = 0;
            for (j = 0; j < v; j++)
                if (a[j] < 0) {
                    g[s] = j;
                    s++;
                }
        }
        if (s > k1) s = s1;
        F = s != k1;
    }
    for (j = 0; j < v; j++) a[j] = 0;
    for (j = 0; j < s; j++) a[g[j]] = 1;
}