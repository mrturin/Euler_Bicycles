/******************************************************************************
     * File: Tree.cpp
     * Description: Определяет методы связанные с выделением дерева, заполнением дерева
******************************************************************************/

char*** init_tree(int mlet, int M) {
    char*** tree = new char** [M];
    char** tree_1 = new char* [M];

    char* zero = new char[4]{0,0,0,0};
   
    for (int N = 0; N < M; N++) {
        tree_1[N] = new char[mlet];
        for (int i = 0; i <= mlet; i++) { tree[N][i] = zero; }
    }
    return tree;
}