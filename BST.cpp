#include "BST.h"
#include <iostream>
#include <bits/stdc++.h> 

BST::BST()
{
    root = nullptr;
    traversed = 0;
}

void BST::inOrder( std::vector<int> &vec )
{
    if(!root) return;
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

BSTNode *BST::insertIter(int val)
{
    BSTNode *node = root;
    // printf("\ninsert %d", val);

    if(!root)
    {
        root = new BSTNode(val);
        root->height++;
        return root;
    }

    while(node)
    {
        if (val < node->val)
        {
            if(!node->left)
            {
                node->left = new BSTNode(val);
                node->left->parent = node;
                alterParentHeight(node->left);
                return node->left;
            }
            else
            {
                traversed++;
                node = node->left;
            }
        }
        else if (val > node->val)
        {
            if(!node->right)
            {
                node->right = new BSTNode(val);
                node->right->parent = node;
                alterParentHeight(node->right);
                return node->right;
            }
            else 
            {
                traversed++;
                node = node->right;
            }
        }
        else
        {
            return nullptr;
        }
    }
}

/* ==================DELETE================== */

void BST::deleteRec(int val)
{
    root->deleteRec(val);
}

BSTNode *BST::deleteIter(int val)
{
    BSTNode *node = find(val);
    BSTNode *next = nullptr;
    BSTNode *ret = nullptr;

    // if(node == root)
    // {
    //     delete node;
    //     root = nullptr;
    //     return ret;
    // }

    while(node)
    {
        if(!node->right && !node->left)
        {
            if(node == root)
            {
                delete node;
                root = nullptr;
                return root;
            }
            node->setParentNode(nullptr);
            alterParentHeight(node->parent);
            if(node->parent) ret = node->parent;
            delete node;
            return ret;
        }

        if(!node->right && node->left)
        {
            if(node == root)
            {
                root = node->left;
                node->left->parent = nullptr;
            }
            else
            {
                node->setParentNode(node->left);
            }
            alterParentHeight(node->left);
            ret = node->left;
            node->left = nullptr;
            delete node;
            return ret;
        }

        if(node->right && !node->left)
        {
            if(node == root)
            {
                root = node->right;
                node->right->parent = nullptr;
            }
            else
            {
                node->setParentNode(node->right);
            }
            alterParentHeight(node->right);
            ret = node->right;
            node->right = nullptr;
            delete node;
            return ret;
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
    
    if(!node) return -1;
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
    
    if(!root) return -1;
    while(node->right)
    {
        node = node->right;
    }

    return node->val;
}

void BST::printTree()
{
    double n;
    double lg;
    std::queue<BSTNode*> q;
    BSTNode *node = nullptr;

    q.push(root);

    for(n = 1.0; !q.empty(); n += 1.0)
    {
        node = q.front();
        q.pop();
        if(!node) continue;

        lg = std::log2(n);
        if( lg - floor(lg) == 0.0f)
        {
            std::cout << std::endl;
        }

        std::cout << node->val << " ";

        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }

    std::cout << std::endl;
}

int BST::getTraversed()
{
    return traversed;
}

/* ===============PRIVATE=============== */

BSTNode *BST::find(int val)
{
    BSTNode *node = root;
    if(val == -1) return nullptr;

    while( node && val != node->val ) 
    {
        if(val < node->val)
        {
            traversed++;
            node = node->left;
        }
        else if (val > node->val)
        {
            traversed++;
            node = node->right;
        }
        else
        {
            return nullptr;
        }
    }

    return node;
}

void BST::alterParentHeight(BSTNode *node)
{
    if(!node) return;

    while(node->parent)
    {
        node->updateHeight();
        node = node->parent;
    }

    node->updateHeight();

}