#ifndef _BST_H_
#define _BST_H_

#include "BST_Node.h"

class BST {
public:
    BST();

    void inOrder( std::vector<int> &vec );
    
    void insertRec(int val);
    void deleteRec(int val);

private:
    BSTNode *root;
};

#endif