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
    BSTNode *findNextRec(int val);
    BSTNode *findPrevRec(int val);
    BSTNode *findMinRec(); //**< this is never going to be null
    BSTNode *findMaxRec(); //**< this is never going to be null

    friend class BST;

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