#include "Heap.h"

// Constructor
Heap::Heap()
{
    CompleteBinaryTree();
}

// Destructor
Heap::~Heap()
{
}

// Returns the max value
void* Heap::get_max()
{
    // the maximum item is at the root of the heap
    return this->get_root()->get_value();
}

// Inserts at the end of the heap and sorts out accordingly
void Heap::HeapInsert(void* value, int (*compare)(void *, void *))
{
    // inserting the element at the end of the tree
    this->Insert(value);

    // sorting the last element at the place where it should be
    this->heapify_up(this->get_last(), compare);
}

// Removes the maximum element of the heap and sorts out accordingly
void Heap::RemoveMax(int (*compare)(void *, void *))
{
    // we won't remove anything if nothing exists in the heap
    if(!this->get_size()) return;

    // swapping the max value with the last value added to the heap
    // the heap is a complete binary tree after all
    swap_values(this->get_root(), this->get_last());

    // removing the now last node
    this->RemoveLast();

    // sorting the new root at the place where it should be
    this->heapify_down(this->get_root(), compare);
}

// function that sorts the items of the tree from the leaves and up
void Heap::heapify_up(BinaryTreeNode* node, int (*compare)(void *, void *))
{
    // base case if we reached the root
    if(node == this->get_root()) return;

    BinaryTreeNode* parent = node->get_parent();

    // if the value of the current node is greater than the value of its parent we swap the values and we keep on sorting upwards
    if(compare(parent->get_value(), node->get_value()) < 0)
    {
        swap_values(parent, node);
        this->heapify_up(parent, compare);
    }
}

// function that sorts the items of the tree from the root and down
void Heap::heapify_down(BinaryTreeNode* node, int (*compare)(void *, void *))
{
    BinaryTreeNode* Left = node->get_left_child();
    BinaryTreeNode* Right = node->get_right_child();

    // base case if a left child does not exist (a right child would not exist if a left one does not exist because it is a complete binary tree)
    // the node is a leaf
    if(!Left) return;

    // the left child is by default the max because at this stage it is the only child we are 100% sure it exists
    BinaryTreeNode* Max;
    Max = Left;

    // examining if the right child exists and its value is greater than its left wing sibling
    // that's when it is the max
    if(Right && (compare(Right->get_value(), Left->get_value()) > 0)) Max = Right;

    // if the current node's value is less than its max child's value we swap the values and we keep on sorting downwards
    if(compare(node->get_value(), Max->get_value()) < 0)
    {
        swap_values(node, Max);
        this->heapify_down(Max, compare);
    }

}