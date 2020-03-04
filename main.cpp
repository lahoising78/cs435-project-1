#include "AVL.h"
#include <iostream>
#include <random>
#include <time.h>
#include <string.h>
#include <chrono>

#define AVL_MAIN
// #define ITER_MAIN
// #define REC_MAIN

void printArray(std::vector<int> &arr);
std::vector<int> sort(std::vector<int> &arr);
std::vector<int> getRandomArray(int n);
std::vector<int> getSortedArray(int n);

int bst_iter(int argc, char *argv[])
{
    BST bst = BST();
    std::vector<int> inOrderArr;
    std::vector<int> unsorted{5, 235, 16, 7304, 74, 54};
    std::vector<int> r;
    std::vector<int> sorted;

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

    bst.inOrder(inOrderArr);
    printArray(inOrderArr);

    unsorted = sort(unsorted);
    printArray(unsorted);

    r = getRandomArray(10);
    printArray( r );

    sorted = getSortedArray(12);
    printArray(sorted);
}

int bst_rec(int argc, char *argv[])
{
    BST bst = BST();
    std::vector<int> inOrderArr;
    std::vector<int> unsorted{5, 235, 16, 7304, 74, 54};
    std::vector<int> r;
    std::vector<int> sorted;

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

    bst.inOrder(inOrderArr);
    printArray(inOrderArr);

    unsorted = sort(unsorted);
    printArray(unsorted);

    r = getRandomArray(10);
    printArray( r );

    sorted = getSortedArray(12);
    printArray(sorted);
}

int avl_main(int argc, char *argv[])
{
    AVL avl = AVL();
    BST iter = BST();
    AVL avlSorted = AVL();
    BST iterSorted = BST();
    BST bst = BST();
    std::vector<int> toarr;
    std::vector<int> randomArr;
    std::vector<int> sorted;
    int a;
    std::chrono::duration<double, std::micro> avlTime;
    auto avlStart = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> iterTime;
    auto iterStart = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> recTime;
    auto recStart = std::chrono::high_resolution_clock::now();
    randomArr = getRandomArray( 10000 );

    avlStart = std::chrono::high_resolution_clock::now();
    for(int i : randomArr)
    {
        avl.insertIter(i);
    }
    avlTime = std::chrono::high_resolution_clock::now() - avlStart;
    
    iterStart = std::chrono::high_resolution_clock::now();
    for(int i : randomArr)
    {
        iter.insertIter(i);
    }
    iterTime = std::chrono::high_resolution_clock::now() - iterStart;
    
    recStart = std::chrono::high_resolution_clock::now();
    for(int i : randomArr)
        bst.insertRec(i);
    recTime = std::chrono::high_resolution_clock::now() - recStart;

    avl.inOrder(toarr);
    printArray(toarr);
    toarr.clear();

    sorted = getSortedArray( 10000 );
    for(int i : sorted)
    {
        avlSorted.insertIter(i);
        iterSorted.insertIter(i);
    }

    avl.inOrder(toarr);
    printArray(toarr);

    std::cout << std::endl;
    std::cout << "AVL Rand traversed nodes " << avl.getTraversed() << std::endl;
    std::cout << "BST Rand traversed nodes " << iter.getTraversed() << std::endl;
    std::cout << "AVL Sort traversed nodes " << avlSorted.getTraversed() << std::endl;
    std::cout << "BST Sort traversed nodes " << iterSorted.getTraversed() << std::endl;

    std::cout << "BST REC TREE took " << recTime.count() << " microseconds to insert" << std::endl;
    std::cout << "BST ITER TREE took " << iterTime.count() << " microseconds to insert" << std::endl;
    std::cout << "AVL TREE took " << avlTime.count() << " microseconds to insert" << std::endl;

    recStart = std::chrono::high_resolution_clock::now();
    for(int i : randomArr)
    {
        bst.deleteRec(i);
    }
    recTime = std::chrono::high_resolution_clock::now() - recStart;

    iterStart = std::chrono::high_resolution_clock::now();
    for(int i : randomArr)
    {
        iter.deleteIter(i);
    }
    iterTime = std::chrono::high_resolution_clock::now() - iterStart;

    avlStart = std::chrono::high_resolution_clock::now();
    for(int i : randomArr)
    {
        avl.deleteIter(i);
    }
    avlTime = std::chrono::high_resolution_clock::now() - avlStart;

    std::cout << "BST REC TREE took " << recTime.count() << " microseconds to delete" << std::endl;
    std::cout << "BST ITER TREE took " << iterTime.count() << " microseconds to delete" << std::endl;
    std::cout << "AVL TREE took " << avlTime.count() << " microseconds to delete" << std::endl;
}

int main(int argc, char *argv[])
{
    int i;

#ifdef ITER_MAIN
    bst_iter(argc, argv);
#endif

#ifdef REC_MAIN
    bst_rec(argc, argv);
#endif

#ifdef AVL_MAIN
    avl_main(argc, argv);
#endif

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
    // const int max = 64;
    BST bst = BST();
    std::vector<int> arr;
    std::srand(time(0));
    int cur = 0;
    int num = 0;

    while(cur < n)
    {
        // num = std::rand() % max;
        num = std::rand();
        if( bst.insertIter(num) )
        {
            arr.push_back(num);
            cur++;
        }
    }

    return arr;
}

std::vector<int> getSortedArray(int n)
{
    std::vector<int> arr;

    for(; n > 0 ; n--)
    {
        arr.push_back(n);
    }

    return arr;
}