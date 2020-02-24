#ifndef _BST_H_
#define _BST_H_

#include "BST_Node.h"

class BST {
public:
    BST();
    void insertRec(int val);
    void inOrder( std::vector<int> &vec );

private:
    BSTNode *root;
};

#endif