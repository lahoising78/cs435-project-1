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

    if(val < this->val)
    {
        if(this->left) left->deleteRec(val);
        return;
    }
    if(val > this->val)
    {
        if(this->right) right->deleteRec(val);
        return;
    }

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
    next = this->findNextRec(this->val);
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
        /* You have found the node that contains val */
        /* if you have a right node, get the min  from that side */
        if(this->right) return this->right->findMinRec();
        /* else, traverse the tree backwards */
        return this->parent;
    }

    /* you know you are not the node that contains the value at this point */
    if(val < this->val)
    {
        /* the value is less than my value but i have no left child? The value simply CANNOT be in this tree */
        if(!this->left) return nullptr;
        /* I have a child less than me, so let me ask them if they or one of their children have the successor */
        res = this->left->findNextRec(val);
    }
    else
    {
        /* the value is greater than my value but i have no right child? The value simply CANNOT be in this tree */
        if(!this->right) return nullptr;
        /* I have a child greater than me, so let me ask them if they or one of their children have the successor */
        res = this->right->findNextRec(val);
    }

    /* 
    if my children say that they have it, then great,
    but if they say they don't have it, then i suppose it should be me or one of my parents.
    if my value is greater than the value, then i guess I the successor,
    because at this point if im greater than the value, then my parent asked me because the value was less than them
    */
    if(res != this || res->val - val > 0) return res;

    /* if my children dont have it and I'm less than the value, then I guess my parents have it */
    /* if I have don't have one, then that value simply must be out of range */
    /* but if i have a parent, i'll just tell them to figure it out themselves */
    return this->parent;
}

BSTNode *BSTNode::findPrevRec(int val)
{
    BSTNode *res = nullptr;

    if(val == this->val)
    {
        if(left) return left->findMaxRec();
        return this->parent;
    }

    if(val < this->val)
    {
        if(!left) return nullptr;
        res = left->findPrevRec(val);
    }
    else
    {
        if(!right) return nullptr;
        res = right->findPrevRec(val);
    }

    if(res != this || val - this->val > 0) return res;

    return this->parent;
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