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

BSTNode *AVL::insertIter(int val)
{
    /* insert the node as usual */
    BSTNode *node = BST::insertIter(val);
    if( !node ) return nullptr;
    
    /* balance the tree */
    balanceNode(node);
    return node;
}

BSTNode *AVL::deleteIter(int val)
{
    /* delete the node as usual */
    BSTNode *node = BST::deleteIter(val);
    if(!node) return nullptr;

    /* balance the tree. Important to note that deleteIter will return a node at the bottom of the tree */
    balanceNode( node );
    return node;
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
    /* check imbalance for the node and all of its parents */
    while(node->parent)
    {
        balanceNodeHelper(node);
        node = node->parent;
    }
    balanceNodeHelper(node);
}

void AVL::balanceNodeHelper(BSTNode *node)
{
    int left = 0;           /* left height */
    int leftleft = 0;       /* left left height */    
    int leftright = 0;      /* left right height */    
    int right = 0;          /* right height */
    int rightleft = 0;      /* right left height */    
    int rightright = 0;     /* right right height */    
    if(!node) return;

    /* Query subtree heights */
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

    /* if BF of node is greater than one */
    if( left - right > 1 )
    {
        /* find out what causes the imbalance */
        /* left-left imbalance */
        if( leftleft - leftright > 0 )
        {
            rightRotation(node);
        }
        /* left-right imbalance */
        else if ( leftleft - leftright < 0 )
        {
            leftRotation(node->left);
            rightRotation(node);
        }
    }
    /* if BF of node is less than -1 */
    else if ( left - right < -1 )
    {
        /* find out what causes the imbalance */
        /* right-right imbalance */
        if( rightleft - rightright < 0 )
        {
            leftRotation(node);
        }
        /* right-left imbalance */
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

    /* Save necessary nodes to make it easier when we transfer nodes */
    left = node->left;
    leftleft = left->left;
    leftright = left->right;
    
    /* Set left's parent to be node's parent */
    left->parent = node->parent;
    if(node->parent) node->setParentNode(left);

    /* make left's right child be the node's left child */
    node->left = leftright;
    if(leftright) leftright->parent = node;

    /* make the node be the left's right child */
    left->right = node;
    node->parent = left;

    /* update root if that's the node we are dealing with */
    if(node == root) root = left;

    /* update height of tree */
    alterParentHeight(leftleft);
    alterParentHeight(node);
}

void AVL::leftRotation(BSTNode *node)
{
    BSTNode *right = nullptr;
    BSTNode *rightright = nullptr;
    BSTNode *rightleft = nullptr;
    if(!node) return;

    /* Save necessary nodes to make it easier when we transfer nodes */
    right = node->right;
    rightright = right->right;
    rightleft = right->left;

    /* Set right's parent to be the node's parent */
    right->parent = node->parent;
    if(node->parent) node->setParentNode(right);

    /* make right's left child be the node's right child */
    node->right = right->left;
    if(rightleft) rightleft->parent = node;
    
    /* make the node be the right's left child */
    right->left = node;
    node->parent = right;

    /* update root if that's the node we are dealing with */
    if(node == root) root = right;

    /* update height of tree */
    alterParentHeight(node);
    alterParentHeight(rightright);
}
