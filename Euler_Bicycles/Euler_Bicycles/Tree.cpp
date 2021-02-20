/******************************************************************************
     * File: Tree.cpp
     * Description: Определяет методы связанные с выделением дерева, заполнением дерева
******************************************************************************/

char*** init_tree(int mlet, int M) {
    char*** tree = new char** [M];
    char* zero = new char[4]{ 0,0,0,0 };
    for (int i = 0; i < M; i++)
    {
        tree[i] = new char* [mlet]; // столбцы
        for (int j = 0; j < mlet; i++)
        {
            tree[i][j] = new char[4]; //строки
            tree[i][j] = zero;
        }
    }
    return tree;
}