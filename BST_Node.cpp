#include <iostream>
#include "BST_Node.h"

/* =========================PUBLIC======================== */

BSTNode::BSTNode(int val) 
{
    this->val = val;
    this->right = this->left = this->parent = nullptr;
}

BSTNode::~BSTNode()
{
    if(left) delete left;
    if(right) delete right;
}

void BSTNode::inOrder( std::vector<int> &vec )
{
    if(left) left->inOrder(vec);    
    vec.push_back(val);
    if(right) right->inOrder(vec);
}

int BSTNode::getVal()
{
    return this->val;
}

void BSTNode::insertRec(int val)
{
    if(val < this->val)
    {
        if(this->left == nullptr)
        {
            this->left = new BSTNode(val);
            this->left->parent = this;
        }
        else
        {
            this->left->insertRec(val);
        }
    }
    else if(val > this->val)
    {
        if(this->right == nullptr)
        {
            this->right = new BSTNode(val);
            this->right->parent = this;
        }
        else
        {
            this->right->insertRec(val);
        }
    }
}

void BSTNode::deleteRec(int val)
{
    BSTNode *next = this;

    if(val != this->val)
    {
        while( val != next->val )
        {
            if( val < next->val )
            {
                next = next->left;
            }
            else
            {
                next = next->right;
            }
            if(!next) return;
        }
        next->deleteRec(val);
        return;
    }

    std::cout << "delete " << this->val << std::endl;

    /* No children */
    if(!left && !right)
    {
        setParentNode(nullptr);
        delete this;
        return;
    }

    /* Only one child */
    if( !right && left )
    {
        setParentNode(left);
        this->left = nullptr;
        delete this;
        return;
    }
    
    if (right &&!left)
    {
        setParentNode(right);
        this->right = nullptr;
        delete this;
        return;
    }

    /* Two children */
    next = findNextNode();
    if(!next) return;

    this->val = next->val;
    next->deleteRec(next->val);
}

BSTNode *BSTNode::findNextRec(int val)
{
    BSTNode *res = nullptr;
    int difs, difp;

    if(this->val == val)
    {
        if(this->right) return this->right->findMinRec();
        return this->parent;
    }

    if(val < this->val)
    {
        if(!this->left) return nullptr;
        res = this->left->findNextRec(val);
    }
    else
    {
        if(!this->right) return nullptr;
        res = this->right->findNextRec(val);
    }

    if(res != this || res->val - val > 0) return res;
    if(res->parent == nullptr) return nullptr;

    /* If we have reached this point, it means that the node with val does not have children */
    if(this == this->parent->left) return this->parent;
    return this->parent;
}

BSTNode *BSTNode::findPrevRec(int val)
{

}

BSTNode *BSTNode::findMinRec()
{
    if(left) return left->findMinRec();
    return this;
}

BSTNode *BSTNode::findMaxRec()
{
    if(right) return right->findMaxRec();
    return this;
}


/* =========================PRIVATE======================== */

BSTNode *BSTNode::findNextNode()
{
    BSTNode *next = right;

    while(next && next->left)
    {
        next = next->left;
    }

    return next;
}

void BSTNode::setParentNode(BSTNode *node)
{
    if(this->parent->left == this)
    {
        this->parent->left = node;
    }
    else if(this->parent->right == this)
    {
        this->parent->right = node;
    }
    
    if(node) node->parent = this->parent;
}