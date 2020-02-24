#include "BST.h"
#include <iostream>

BST::BST()
{
    root = nullptr;
}

void BST::inOrder( std::vector<int> &vec )
{
    root->inOrder(vec);
}

/* ===================INSERT================= */

void BST::insertRec(int val)
{
    if(root == nullptr)
    {
        root = new BSTNode(val);
        return;
    }

    root->insertRec(val);
}

void BST::insertIter(int val)
{
    BSTNode *node = root;

    if(!root)
    {
        root = new BSTNode(val);
        return;
    }

    while(node)
    {
        if (val < node->val)
        {
            if(!node->left)
            {
                node->left = new BSTNode(val);
                return;
            }
            else
            {
                node = node->left;
            }
        }
        else if (val > node->val)
        {
            if(!node->right)
            {
                node->right = new BSTNode(val);
                return;
            }
            else 
            {
                node = node->right;
            }
        }
        else
        {
            node = nullptr;
        }
    }
}

/* ==================DELETE================== */

void BST::deleteRec(int val)
{
    root->deleteRec(val);
}

/* =================FIND NEXT================== */

int BST::findNextRec(int val)
{
    BSTNode *node = nullptr;
    
    if(root)
        node = root->findNextRec(val);

    if(node)
        return node->val;

    return -1;
}

int BST::findNextIter(int val)
{
    std::vector<int> vec;
    root->inOrder(vec);

    for(int i = 0; i < vec.size() - 1; i++)
    {
        if( vec[i] == val )
            return vec[i+1];
    }

    return -1;
}

/* ======================FIND PREV==================== */

int BST::findPrevRec(int val)
{
    BSTNode *node = nullptr;

    if(root)
        node = root->findPrevRec(val);
    
    if(node)
        return node->val;

    return -1;
}

/* ======================FIND MIN======================= */

int BST::findMinRec()
{
    if(!root)
        return -10;
    return root->findMinRec()->val;
}

/* ======================FIND MAX====================== */

int BST::findMaxRec()
{
    if(!root)
        return -10;
    return root->findMaxRec()->val;
}