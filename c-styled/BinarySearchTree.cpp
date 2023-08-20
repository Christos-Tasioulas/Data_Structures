#include "BinarySearchTree.h"

// Constructor
BinarySearchTree::BinarySearchTree()
{
    BinaryTree();
}

// Destructor
BinarySearchTree::~BinarySearchTree()
{
}

// Inserts a value at the tree sorted
void BinarySearchTree::Insert(void* value, int (*compare)(void *, void *))
{
    // case if there is no other node in the tree
    if(this->get_size() == 0) this->InsertRoot(value);
    // otherwise we call the recursive function to do the work
    else rec_insert(this->get_root(), value, compare);
}

// recursive assistant function for the insert function that sorts values accordingly
void BinarySearchTree::rec_insert(BinaryTreeNode* node, void* value, int (*compare)(void *, void *))
{
    // case if the given value is less than the current node's 
    if(compare(node->get_value(), value) > 0)
    {
        // if a left child already exists we will use this child as the next one in the recursion
        if(node->get_left_child()) rec_insert(node->get_left_child(), value, compare);
        // otherwise we will insert the given value at the left of the current node
        else this->InsertLeft(value, node);
    }
    else
    {
        // if a right child already exists we will use this child as the next one in the recursion
        if(node->get_right_child()) rec_insert(node->get_right_child(), value, compare);
        // otherwise we will insert the given value at the right of the current node
        else this->InsertRight(value, node);
    }
}

// Searches an element of the tree
BinaryTreeNode* BinarySearchTree::Search(void* value, int (*compare)(void *, void *))
{
    return rec_search(this->get_root(), value, compare);
}

// recursive assistant function for the search function to traverse the tree downwards
BinaryTreeNode* BinarySearchTree::rec_search(BinaryTreeNode* node, void* value, int (*compare)(void *, void *))
{
    // Base case if we reached a node that does not have a value. That means that we did not find the value inside the tree therefore
    // the value does not exist
    if(node == NULL) return NULL;
    // Base case if we find the value given in the tree
    else if(compare(node->get_value(), value) == 0) return node;
    // If the current node has a value greater than the one given we move at the left child
    else if(compare(node->get_value(), value) > 0) return rec_search(node->get_left_child(), value, compare);
    // If the current node has a value less than the one given we move at the right child
    else return rec_search(node->get_right_child(), value, compare);
}

// Removes an element from the tree
void BinarySearchTree::Remove(void* value, int (*compare)(void *, void *))
{
    // finding the node of the value we want to remove
    BinaryTreeNode* node = this->Search(value, compare);
    // we won't do anything if the value does not exist in the tree
    if(!node) return;

    // the node has at least a child
    while(node->get_left_child() || node->get_right_child())
    {
        // looking for its in order predecessor
        BinaryTreeNode* other = this->find_predecessor(node);
        // looking for its in order successor if a predecessor was not found
        if(!other) other = this->find_successor(node);
        
        // swapping the nodes' values and traversing the tree downwards by moving to the swapped node
        // this node is closer to the one we will remove than the current one
        this->swap_values(node, other);
        node = other;
        
    }

    // Eventually removing the last one
    this->RemoveLeaf(node);
    
}

// assisstant function that finds the inorder predecessor node for a non leaf node given to be removed
BinaryTreeNode* BinarySearchTree::find_predecessor(BinaryTreeNode* node)
{
    // the predecessor value is the rightmost of the left subtree if one exists
    if(node->get_left_child() == NULL) return NULL;
    return this->find_rightmost(node->get_left_child());    
}

// assisstant function that finds a successor node for a non leaf node given to be removed
BinaryTreeNode* BinarySearchTree::find_successor(BinaryTreeNode* node)
{
    // the successor value is the leftmost of the right subtree if one exists
    if(node->get_right_child() == NULL) return NULL;
    return this->find_leftmost(node->get_right_child()); 
}

// assistant function that finds the leftmost descendant of a node given
BinaryTreeNode* BinarySearchTree::find_leftmost(BinaryTreeNode* node)
{
    if(node->get_left_child()) return find_leftmost(node->get_left_child());
    else return node;
}

// assistant function taht finds the rightmost descendant of a node given
BinaryTreeNode* BinarySearchTree::find_rightmost(BinaryTreeNode* node)
{
    if(node->get_right_child()) return find_rightmost(node->get_right_child());
    else return node;
}