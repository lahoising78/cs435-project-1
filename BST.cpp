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
                node->left->parent = node;
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
                node->right->parent = node;
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

void BST::deleteIter(int val)
{
    BSTNode *node = find(val);
    BSTNode *next = nullptr;

    while(node)
    {
        if(!node->right && !node->left)
        {
            node->setParentNode(nullptr);
            delete node;
            return;
        }

        if(!node->right && node->left)
        {
            node->setParentNode(node->left);
            node->left = nullptr;
            delete node;
            return;
        }

        if(node->right && !node->left)
        {
            node->setParentNode(node->right);
            node->right = nullptr;
            delete node;
            return;
        }

        next = node->right;
        while(next->left)
        {
            next = next->left;
        }

        node->val = next->val;
        node = next;
    }
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
    BSTNode *node = find(val);
    
    if(!node) return -1;
    
    if(node->right)
    {
        node = node->right;
        while(node->left)
        {
            node = node->left;
        }
        return node->val;
    }

    while(node->parent && node != node->parent->left)
    {
        node = node->parent;
    }

    return node->parent? node->parent->val : -1;
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

int BST::findPrevIter(int val)
{
    BSTNode *node = find(val);

    if(!node) return -1;

    if(node->left)
    {
        node = node->left;
        while(node->right)
        {
            node = node->right;
        }
        return node->val;
    }

    while(node->parent && node->parent->right != node)
    {
        node = node->parent;
    }

    return node->parent? node->parent->val : -1;
}

/* ======================FIND MIN======================= */

int BST::findMinRec()
{
    if(!root)
        return -10;
    return root->findMinRec()->val;
}

int BST::findMinIter()
{
    BSTNode *node = root;
    
    while(node->left)
    {
        node = node->left;
    }

    return node->val;
}

/* ======================FIND MAX====================== */

int BST::findMaxRec()
{
    if(!root)
        return -10;
    return root->findMaxRec()->val;
}

int BST::findMaxIter()
{
    BSTNode *node = root;
    
    while(node->right)
    {
        node = node->right;
    }

    return node->val;
}

/* ===============PRIVATE=============== */

BSTNode *BST::find(int val)
{
    BSTNode *node = root;

    while( val != node->val ) 
    {
        if(val < node->val)
        {
            node = node->left;
        }
        else if (val > node->val)
        {
            node = node->right;
        }
        else
        {
            return nullptr;
        }
    }

    return node;
}