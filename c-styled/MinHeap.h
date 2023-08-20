#ifndef MINHEAP
#define MINHEAP
#include "CompleteBinaryTree.h"

class MinHeap : public CompleteBinaryTree
{
//private:
public:
    // Constructor
    MinHeap();
    // Destructor
    ~MinHeap();
    // Returns the min value
    void* get_min();
    // Inserts at the end of the heap and sorts out accordingly
    void HeapInsert(void* value, int (*compare)(void *, void *));
    // Removes the minimum element of the heap and sorts out accordingly
    void RemoveMin(int (*compare)(void *, void *));
    // function that sorts the items of the tree from the leaves and up
    void heapify_up(BinaryTreeNode* node, int (*compare)(void *, void *));
    // function that sorts the items of the tree from the root and down
    void heapify_down(BinaryTreeNode* node, int (*compare)(void *, void *));
};

#endif