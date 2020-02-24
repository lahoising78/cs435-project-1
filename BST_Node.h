#ifndef _BST_NODE_H_
#define _BST_NODE_H_

#include <vector>

class BSTNode {
public:
    BSTNode(int val);
    ~BSTNode();

    int getVal();
    void inOrder( std::vector<int> &vec );

    void insertRec(int val);
    void deleteRec(int val);

private:
    int val;
    BSTNode *left;
    BSTNode *right;
    BSTNode *parent;

    void inOrderNodes( std::vector<BSTNode*> &vec );
    BSTNode *findNextNode();
    void setParentNode(BSTNode *node);
};

#endif