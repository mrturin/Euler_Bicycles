#include <vector>
/******************************************************************************
     * File: Math_Function.cpp
     * Description: Вспомогательные функции для вычислений
******************************************************************************/

/*
    * Возвращает вектор нулей
    * @param n - кол-во элементов вектора;
    * @return Указатель на вектор нулей (нулевой элемент).
*/
std::vector<char> zero(const int n)
{
    std::vector<char> zero;
    for (int i = 0; i < n; i++)
    {
        zero.push_back(0);
    }
    return zero;
}

/*
    * Возвращает вектор единиц
    * @param n - кол-во элементов вектора;
    * @return Указатель на вектор единиц (нулевой элементы).
*/
std::vector<char> one(const int n)
{
    std::vector<char> one;
    for (int i = 0; i < n; i++)
    {
        one.push_back(0);
    }
    return one;
}

/*void FINDAB(int N,char* lenA, char* lenB, int& N0, int& N1, int& N2, int& N3, char* Aa, char* Bb,
    char*** A , char*** B, char* a, char* b, int v, int z) {
    int lenAN, lenBN, I, H; // int неподтверждено
    char* S = new char; // пока не понимаю какая размерность у этого всего. бесконечность?
    lenAN = lenA[N];
    lenBN = lenB[N];
    // puts("FIND AB N="+N+"; length="+lenAN+" "+lenBN);
    if ((lenAN > 0) && (lenBN > 0)) {
        for (int i = 0; i < lenAN; i++)
            if (F) {
                N0 = A[N][i][0];
                N1 = A[N][i][1];
                N2 = A[N][i][2];
                N3 = A[N][i][3];
                num2seq4(a, v);
                mulcirc2(a, Aa, 2, v, 1, z);
                for (int j = 0; j < lenBN; j++)
                    if (F) {
                        N0 = B[N][j][0];
                        N1 = B[N][j][1];
                        N2 = B[N][j][2];
                        N3 = B[N][j][3];
                        num2seq4(b, v);
                        mulcirc2(b, Bb, 0, v, 1, z); {
                            {
                               *(S+i) = *Aa + *Bb; //?? попытка инкрементировать размер массива
                            }
                        }
                        for (int jj = 1; jj < z; jj++)
                            if (F) F = S[jj] == 0;
                        if (F) { // НАШЛИ
                            //заменить puts на cout ??

                            //puts("n=" + n + " tick=" + tick + " N=" + N);
                            //puts("PAFa=[" + Aa + "];");
                            //puts("PAFb=[" + Bb + "];");
                            for (int jj = 0; jj < v; jj++)
                                if (a[jj] == 1) {
                                    a[jj] = -1;
                                }
                                else {
                                    a[jj] = 1;
                                }
                            for (int jj = 0; jj < v; jj++)
                                if (b[jj] == 1) {
                                    b[jj] = -1;
                                }
                                else {
                                    b[jj] = 1;
                                }
                            //puts("a=[" + a + "];");
                            //puts("b=[" + b + "];");
                            H = twocircul(a, b);
                            {
                                {
                                    //I = H' *H; транспонировать матрицу ??? 
                                }
                            } 
                                    putm(I);
                                    mesh(H); // plots(H); 
                                    // sound("5th.wav");
                                }
                                F = !F;
                            } // j
                        } // i
                        if (F) lenB[N] = 0; // сброс ветви
                    } // lenAN>0  
                // puts("FIND AB-");
            }
    }
}
*/

void mulcirc2(char* a,char* Aa, int s0,int v, int b, int c) {
    int s{}, ss{};
    for (int i = 0; i < b; i++) Aa[i] = 0;
    ss = 0;
    for (int i = b; i < c; i++) {
        s = s0;
        for (int j = 0; j < v; j++) {
            if (a[(i + j) % v] == a[j]) {
                s++;
            }
            else {
                s--;
            }
        }
        Aa[i] = s;
        ss += s;
    }
    Aa[0] = ss; // контрольная сумма !
}


int branchA(char* Aa,int m, int M,char* pw2) {
    int N{};
    N = 0;
    for (int i = 1; i <= m; i++)
        if (Aa[i] < 0) N += pw2[i];
    N = N % M;
    return N;
}

int branchB(char* Bb, int m, int M, char* pw2) {
    int N{};
    N = 0;
    for (int i = 1; i <= m; i++)
        if (Bb[i] < 0) N += pw2[i];
    N = N % M;
    return N;
}

long long seq2num(char* a,int v1) {
    long long d{}, t{}; // long long
    t = 0;
    d = 1; // d тут можно заменить степенями двойки
    for (int j = v1; j >= 0; j--) {
        if (a[j]) t += d;
        if (j) d = d * 2;
    }
    return t;
}

void num2seq(int& anum, char* a,int v1) {
    int k = v1;
    while (anum) {
        if (anum & 1)
            a[k] = 1;
        else
            a[k] = 0;
        anum >>= 1;
        k--;
        if (k < 0) break;
    }
    for (int i = 0; i <= k; i++) a[i] = 0;
}