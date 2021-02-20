/******************************************************************************
     * File: Tree.cpp
     * Description: Определяет методы связанные с выделением дерева, заполнением дерева
******************************************************************************/

char*** init_tree(int mlet, int M) {
    char*** tree = new char** [M];
    for (int i = 0; i < M; i++)
    {
        tree[i] = new char* [mlet]; // столбцы
        for (int j = 0; j < mlet; j++)
        {
            tree[i][j] = new char[4]; //строки
            for (int z = 0; z < 4; z++)
                tree[i][j][z] = 0 ;
        }
    }
    return tree;
}