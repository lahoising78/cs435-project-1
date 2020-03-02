#ifndef _BST_H_
#define _BST_H_

#include "BST_Node.h"
#include <queue>

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
    
    virtual bool insertIter(int val);
    virtual int deleteIter(int val);
    virtual int findNextIter(int val);
    virtual int findPrevIter(int val);
    virtual int findMinIter();
    virtual int findMaxIter();

    void printTree();

protected:
    BSTNode *root;

    BSTNode *find(int val);
    void alterParentHeight(BSTNode *node);
};

#endif