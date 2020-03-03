#include "AVL.h"
#include <iostream>
#include <queue>

/* Constructor - Desctructor */
AVL::AVL() : BST()
{
}

AVL::~AVL()
{
    delete root;
}

bool AVL::insertIter(int val)
{
    BSTNode *node = NULL;
    if( !BST::insertIter(val) ) return false;
    
    node = find(val);
    balanceNode(node);

    // this->printTree();
    // std::cout << val << " set root height to " << root->getHeight() << std::endl;
}

int AVL::deleteIter(int val)
{
    BSTNode *node = nullptr;
    int n = BST::deleteIter(val);

    balanceNode( find(n) );

    // if(root)
    //     std::cout << "removing " << val << " set root height to " << root->getHeight() << std::endl;
    // else
    //     std::cout << "no root" << std::endl;

    // this->printTree();
    return n;
}

int AVL::findNextIter(int val)
{
    return BST::findNextIter(val);
}

int AVL::findPrevIter(int val)
{
    return BST::findPrevIter(val);
}

int AVL::findMinIter()
{
    return BST::findMinIter();
}

int AVL::findMaxIter()
{
    return BST::findMaxIter();
}

void AVL::balanceNode(BSTNode *node)
{
    if(!node) return;
    while(node->parent)
    {
        balanceNodeHelper(node);
        node = node->parent;
    }
    balanceNodeHelper(node);
}

void AVL::balanceNodeHelper(BSTNode *node)
{
    int left = 0;
    int leftleft = 0;
    int leftright = 0;
    int right = 0;
    int rightleft = 0;
    int rightright = 0;
    if(!node) return;

    if(node->right)
    {
        right = node->right->height;
        if(node->right->right)
            rightright = node->right->right->height;
        if(node->right->left)
            rightleft = node->right->left->height;
    }

    if(node->left)
    {
        left = node->left->height;
        if(node->left->right)
            leftright = node->left->right->height;
        if(node->left->left)
            leftleft = node->left->left->height;
    }

    if( left - right > 1 )
    {
        if( leftleft - leftright > 0 )
        {
            rightRotation(node);
        }
        else if ( leftleft - leftright < 0 )
        {
            leftRotation(node->left);
            rightRotation(node);
        }
    }
    else if ( left - right < -1 )
    {
        if( rightleft - rightright < 0 )
        {
            leftRotation(node);
        }
        else if ( rightleft - rightright > 0 )
        {
            rightRotation(node->right);
            leftRotation(node);
        }
    }
}

void AVL::rightRotation(BSTNode *node)
{
    BSTNode *left = nullptr;
    BSTNode *leftleft = nullptr;
    BSTNode *leftright = nullptr;
    if(!node) return;

    left = node->left;
    leftleft = left->left;
    leftright = left->right;
    
    left->parent = node->parent;
    if(node->parent) node->setParentNode(left);

    node->left = leftright;
    if(leftright) leftright->parent = node;

    left->right = node;
    node->parent = left;

    if(node == root) root = left;

    alterParentHeight(leftleft);
    alterParentHeight(node);
}

void AVL::leftRotation(BSTNode *node)
{
    BSTNode *right = nullptr;
    BSTNode *rightright = nullptr;
    BSTNode *rightleft = nullptr;
    if(!node) return;

    right = node->right;
    rightright = right->right;
    rightleft = right->left;

    right->parent = node->parent;
    if(node->parent) node->setParentNode(right);

    node->right = right->left;
    if(rightleft) rightleft->parent = node;
    
    right->left = node;
    node->parent = right;

    if(node == root) root = right;

    alterParentHeight(node);
    alterParentHeight(rightright);
}
