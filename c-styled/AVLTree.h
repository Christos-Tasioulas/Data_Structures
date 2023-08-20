#ifndef AVLTREE
#define AVLTREE
#include "BinarySearchTree.h"

class AVLTree : public BinarySearchTree
{
private:
    // checks if the node given is balanced or not (is balanced if the function returns an integer between -1 and 1)
    int balance_factor(BinaryTreeNode* node);
    // rotates the node given leftside
    void Left_Rotation(BinaryTreeNode* node);
    // rotates the node given rightside
    void Right_Rotation(BinaryTreeNode* node);
public:
    // Constructor
    AVLTree();
    // Destructor
    ~AVLTree();
    // Inserts at the tree and rotates bottom up afterwards
    void AVL_Insert(void* value, int(*compare)(void*, void*));
    // Removes from the tree and rotates bottom up afterwards
    void AVL_Remove(void* value, int(*compare)(void*, void*));
};

#endif