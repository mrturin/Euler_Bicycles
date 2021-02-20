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
	if (n == 6) return xO = 2;
	if (n == 10) return xO = 4;
	if (n == 14) return xO = 2;
	if (n == 18) return xO = 3;
	if (n == 22) return xO = 3;
	if (n == 26) return xO = 3;
	if (n == 30) return xO = 2;
	if (n == 34) return xO = 2;
	if (n == 38) return xO = 4;
	if (n == 42) return xO = 7;
	if (n == 46) return xO = 2;
	if (n == 50) return xO = 10;
	if (n == 54) return xO = 19;
	if (n == 58) return xO = 6;
	if (n == 62) return xO = 2;
	if (n == 82) return xO = 2;
	if (n == 86) return xO = 11;
	if (n == 98) return xO = 18;
	if (n == 102) return xO = 35;
	if (n == 114) return xO = 7;
	if (n == 118) return xO = 3;
	if (n == 122) return xO = 14;//14 или 3
	if (n == 126) return xO = 25;//25 или 2
	if (n == 130) return xO = 16;
	if (n == 134) return xO = 4;
	if (n == 146) return xO = 8;//8 или 16 hard
	if (n == 158) return xO = 2;
	if (n == 166) return xO = 3;
	if (n == 178) return xO = 2;
	if (n == 182) return xO = 16;//16 или 9 hard
	if (n == 186) return xO = 25; //hard
	if (n == 194) return xO = 2;
	if (n == 246) return xO = 10;//hard
	
}
	