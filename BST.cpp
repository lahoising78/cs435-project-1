#include "BST.h"

BST::BST()
{
    root = nullptr;
}

void BST::inOrder( std::vector<int> &vec )
{
    root->inOrder(vec);
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

void BST::deleteRec(int val)
{
    root->deleteRec(val);
}