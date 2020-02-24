#include "BST.h"
#include <iostream>

int main(int argc, char *argv[])
{
    BST bst = BST();
    std::vector<int> inOrderArr;

    bst.insertRec(5);
    bst.insertRec(10);
    bst.insertRec(25);
    bst.insertRec(3);
    bst.insertRec(1);

    bst.inOrder(inOrderArr);

    for( int i : inOrderArr )
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}