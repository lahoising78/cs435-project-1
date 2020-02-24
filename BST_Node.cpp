#include "BST_Node.h"

BSTNode::BSTNode(int val) 
{
    this->val = val;
    this->right = this->left = nullptr;
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
        }
        else
        {
            this->right->insertRec(val);
        }
    }
}