/******************************************************************************
     * File: Orbit.cpp
     * Description: Определяет методы связанные с орбитами
******************************************************************************/

/**
	* Генератор орбиты O=[1,x,x*x,x*x*x,...] mod v длины vO
	* @param O[] - массив орбиты;
	* @param x - элемент x орбиты в программе задается на старте как xO;
	* @param v - размер последовательности равный n/2;
	* @return Возвращает размер массива орбит.
	*/
int orbit(char O[], int x, int v) {
	int i, p, p2, vO;
	O[0] = 1; p = x; p2 = p;
	for (i = 1; i < v; i++) {
		vO = i; O[vO] = p; p = (p * x) % v; //  puts1("p", p);
		if ((p == 0) || (p == 1) || (p == p2) || (p == x)) break;
		p2 = p;
	}
	vO++;
	// puts1("x", x); puts1("vO", vO); putss("O",O,vO);
	return vO;
}

/**
	* Поиск начального хО
	* @param n - порядок матрицы Эйлера;
	* @return Возвращает хО.
	*/
int get_xO(int n) {
	int xO = 0;
	if (n == 42) return xO = 7;
	if (n == 62) return xO = 2;
	if (n == 82) return xO = 2;
	if (n == 86) return xO = 11;
	if (n == 98) return xO = 18;
	if (n == 102) return xO = 35;
	if (n == 114) return xO = 7;
	if (n == 122) return xO = 14;
	if (n == 126) return xO = 25;
	if (n == 182) return xO = 9;
}
	