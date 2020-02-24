#include "BST.h"
#include <iostream>

int main(int argc, char *argv[])
{
    BST bst = BST();
    std::vector<int> inOrderArr;

    bst.insertRec(50);
    bst.insertRec(30);
    bst.insertRec(70);
    bst.insertRec(20);
    bst.insertRec(40);
    bst.insertRec(70);
    bst.insertRec(60);
    bst.insertRec(80);

    // bst.deleteRec(5);
    bst.deleteRec(20);
    bst.deleteRec(30);
    bst.deleteRec(50);

    bst.inOrder(inOrderArr);

    for( int i : inOrderArr )
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}