#ifndef _BST_H_
#define _BST_H_

#include "BST_Node.h"

class BST {
public:
    BST();

    void inOrder( std::vector<int> &vec );
    
    void insertRec(int val);
    void deleteRec(int val);
    int findNextRec(int val);
    int findPrevRec(int val);
    int findMinRec();
    int findMaxRec();
    
    void insertIter(int val);
    void deleteIter(int val);
    int findNextIter(int val);
    int findPrevIter(int val);
    int findMinIter();
    int findMaxIter();

private:
    BSTNode *root;
};

#endif