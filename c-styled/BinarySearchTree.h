#ifndef BINARYSEARCHTREE
#define BINARYSEARCHTREE
#include "BinaryTree.h"


class BinarySearchTree : public BinaryTree
{
private:
    // recursive assistant function for the insert function that sorts values accordingly
    void rec_insert(BinaryTreeNode* node, void* value, int (*compare)(void *, void *));
    // recursive assistant function for the search function to traverse the tree downwards
    BinaryTreeNode* rec_search(BinaryTreeNode* node, void* value, int (*compare)(void *, void *));
    // assisstant function that finds the inorder predecessor node for a non leaf node given to be removed
    BinaryTreeNode* find_predecessor(BinaryTreeNode* node);
    // assisstant function that finds the inorder successor node for a non leaf node given to be removed
    BinaryTreeNode* find_successor(BinaryTreeNode* node);
    // assistant function that finds the leftmost descendant of a node given
    BinaryTreeNode* find_leftmost(BinaryTreeNode* node);
    // assistant function taht finds the rightmost descendant of a node given
    BinaryTreeNode* find_rightmost(BinaryTreeNode* node);
public:
    // Constructor
    BinarySearchTree();
    // Destructor
    ~BinarySearchTree();
    // Inserts a value at the tree sorted
    void Insert(void* value, int (*compare)(void *, void *));
    // Searches an element of the tree
    BinaryTreeNode* Search(void* value, int (*compare)(void *, void *));
    // Removes an element from the tree
    void Remove(void* value, int (*compare)(void *, void *));
};


#endif