#ifndef HEAP
#define HEAP
#include "CompleteBinaryTree.h"

class Heap : public CompleteBinaryTree
{
//private:
public:
    // Constructor
    Heap();
    // Destructor
    ~Heap();
    // Returns the max value
    void* get_max();
    // Inserts at the end of the heap and sorts out accordingly
    void HeapInsert(void* value, int (*compare)(void *, void *));
    // Removes the maximum element of the heap and sorts out accordingly
    void RemoveMax(int (*compare)(void *, void *));
    // function that sorts the items of the tree from the leaves and up
    void heapify_up(BinaryTreeNode* node, int (*compare)(void *, void *));
    // function that sorts the items of the tree from the root and down
    void heapify_down(BinaryTreeNode* node, int (*compare)(void *, void *));
};

#endif