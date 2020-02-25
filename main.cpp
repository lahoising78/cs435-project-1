#include "BST.h"
#include <iostream>
#include <random>
#include <time.h>

// #define ITER

void printArray(std::vector<int> &arr);
std::vector<int> sort(std::vector<int> &arr);
std::vector<int> getRandomArray(int n);

int main(int argc, char *argv[])
{
    BST bst = BST();
    std::vector<int> inOrderArr;
    std::vector<int> unsorted{5, 235, 16, 7304, 74, 54};
    std::vector<int> r;

#ifdef ITER

    bst.insertIter(50);
    bst.insertIter(30);
    bst.insertIter(70);
    bst.insertIter(20);
    bst.insertIter(40);
    bst.insertIter(60);
    bst.insertIter(80);

    std::cout << "next of 20 " << bst.findNextIter(20) << std::endl;
    std::cout << "next of 30 " << bst.findNextIter(30) << std::endl;
    std::cout << "next of 40 " << bst.findNextIter(40) << std::endl;
    std::cout << "next of 50 " << bst.findNextIter(50) << std::endl;
    std::cout << "next of 60 " << bst.findNextIter(60) << std::endl;
    std::cout << "next of 70 " << bst.findNextIter(70) << std::endl;
    std::cout << "next of 80 " << bst.findNextIter(80) << std::endl << std::endl;

    std::cout << "prev of 80 " << bst.findPrevIter(80) << std::endl;
    std::cout << "prev of 70 " << bst.findPrevIter(70) << std::endl;
    std::cout << "prev of 60 " << bst.findPrevIter(60) << std::endl;
    std::cout << "prev of 50 " << bst.findPrevIter(50) << std::endl;
    std::cout << "prev of 40 " << bst.findPrevIter(40) << std::endl;
    std::cout << "prev of 30 " << bst.findPrevIter(30) << std::endl;
    std::cout << "prev of 20 " << bst.findPrevIter(20) << std::endl << std::endl;

    bst.deleteIter(20);
    bst.deleteIter(30);
    bst.deleteIter(50);
    
    std::cout << "min " << bst.findMinIter() << std::endl;
    std::cout << "max " << bst.findMaxIter() << std::endl << std::endl;

#else

    bst.insertRec(50);
    bst.insertRec(30);
    bst.insertRec(70);
    bst.insertRec(20);
    bst.insertRec(40);
    bst.insertRec(60);
    bst.insertRec(80);

    bst.deleteRec(20);
    bst.deleteRec(30);
    bst.deleteRec(50);

    std::cout << "next of 20 " << bst.findNextRec(20) << std::endl;
    std::cout << "next of 30 " << bst.findNextRec(30) << std::endl;
    std::cout << "next of 40 " << bst.findNextRec(40) << std::endl;
    std::cout << "next of 50 " << bst.findNextRec(50) << std::endl;
    std::cout << "next of 60 " << bst.findNextRec(60) << std::endl;
    std::cout << "next of 70 " << bst.findNextRec(70) << std::endl;
    std::cout << "next of 80 " << bst.findNextRec(80) << std::endl << std::endl;

    std::cout << "prev of 80 " << bst.findPrevRec(80) << std::endl;
    std::cout << "prev of 70 " << bst.findPrevRec(70) << std::endl;
    std::cout << "prev of 60 " << bst.findPrevRec(60) << std::endl;
    std::cout << "prev of 50 " << bst.findPrevRec(50) << std::endl;
    std::cout << "prev of 40 " << bst.findPrevRec(40) << std::endl;
    std::cout << "prev of 30 " << bst.findPrevRec(30) << std::endl;
    std::cout << "prev of 20 " << bst.findPrevRec(20) << std::endl << std::endl;

    std::cout << "min " << bst.findMinRec() << std::endl;
    std::cout << "max " << bst.findMaxRec() << std::endl << std::endl;

#endif

    bst.inOrder(inOrderArr);
    printArray(inOrderArr);

    unsorted = sort(unsorted);
    printArray(unsorted);

    r = getRandomArray(10);
    printArray( r );

    return 0;
}

void printArray(std::vector<int> &arr)
{
    for(int i : arr)
        std::cout << i << " ";
    std::cout << std::endl;
}

std::vector<int> sort(std::vector<int> &arr)
{
    BST bst = BST();
    std::vector<int> sorted;

    for(int i : arr)
        bst.insertIter(i);

    bst.inOrder(sorted);
    return sorted;
}

std::vector<int> getRandomArray(int n)
{
    const int max = 1000;
    BST bst = BST();
    std::vector<int> arr;
    std::srand(time(0));
    int cur = 0;
    int num = 0;

    while(cur < n)
    {
        num = std::rand() % max;
        if( bst.insertIter(num) )
        {
            arr.push_back(num);
            cur++;
        }
    }

    return arr;
}