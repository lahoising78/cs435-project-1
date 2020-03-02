#ifndef _PROJECT_1_AVL_H_
#define _PROJECT_1_AVL_H_

#include "BST.h"

class AVL: public BST
{
public:
    AVL();
    ~AVL();

    bool insertIter(int val);
    void deleteIter(int val);
    int findNextIter(int val);
    int findPrevIter(int val);
    int findMinIter();
    int findMaxIter();

private:
    void balanceNode(BSTNode *node);
    void balanceNodeHelper(BSTNode *node);
    void rightRotation(BSTNode *node);
    void leftRotation(BSTNode *node);
};

#endif