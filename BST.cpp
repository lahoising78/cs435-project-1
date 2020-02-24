#include "BST.h"

BST::BST()
{
    root = nullptr;
}

void BST::insertRec(int val)
{
    if(root == nullptr)
    {
        root = new BSTNode(val);
        return;
    }

    root->insertRec(val);
}

void BST::inOrder( std::vector<int> &vec )
{
    root->inOrder(vec);
}