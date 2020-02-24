#include "BST.h"
#include <iostream>

// #define ITER

int main(int argc, char *argv[])
{
    BST bst = BST();
    std::vector<int> inOrderArr;

#ifdef ITER

    bst.insertIter(50);
    bst.insertIter(30);
    bst.insertIter(70);
    bst.insertIter(20);
    bst.insertIter(40);
    bst.insertIter(60);
    bst.insertIter(80);
    


#else

    bst.insertRec(50);
    bst.insertRec(30);
    bst.insertRec(70);
    bst.insertRec(20);
    bst.insertRec(40);
    bst.insertRec(60);
    bst.insertRec(80);

    // bst.deleteRec(5);
    // bst.deleteRec(20);
    // bst.deleteRec(30);
    // bst.deleteRec(50);

    std::cout << "next of 20 " << bst.findNextRec(20) << std::endl;
    std::cout << "next of 30 " << bst.findNextRec(30) << std::endl;
    std::cout << "next of 40 " << bst.findNextRec(40) << std::endl;
    std::cout << "next of 50 " << bst.findNextRec(50) << std::endl;
    std::cout << "next of 60 " << bst.findNextRec(60) << std::endl;
    std::cout << "next of 70 " << bst.findNextRec(70) << std::endl;
    std::cout << "next of 80 " << bst.findNextRec(80) << std::endl;

    std::cout << "min " << bst.findMinRec() << std::endl;
    std::cout << "max " << bst.findMaxRec() << std::endl;

#endif

    bst.inOrder(inOrderArr);

    for( int i : inOrderArr )
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}