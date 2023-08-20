#include "AVLTree.h"

void visit(void* v)
{
    int i = *((int*) v);
    cout << i << " ";
}

// Constructor
AVLTree::AVLTree()
{
    BinarySearchTree();
}

// Destructor
AVLTree::~AVLTree()
{
}

// checks if the node given is balanced or not (is balanced if the function returns an integer between -1 and 1)
int AVLTree::balance_factor(BinaryTreeNode* node)
{
    if(!node) return 0;

    int LHeight = this->get_height_of_node(node->get_left_child());
    //cout << "LHeight: " << LHeight << endl;
    int RHeight = this->get_height_of_node(node->get_right_child());
    //cout << "RHeight: " << RHeight << endl;

    return RHeight - LHeight;
}

// rotates the node given leftside
void AVLTree::Left_Rotation(BinaryTreeNode* node)
{
    BinaryTreeNode* Right = node->get_right_child();
    BinaryTreeNode* Left_Subtree = Right->get_left_child();
    BinaryTreeNode* Parent = node->get_parent();

    // case if the node is the root of the tree
    if(node == this->get_root()) this->set_root(Right);
    else
    {
        // the node's parent's new child will be the node's current right child

        // case if the node is its parent's right child
        if(Parent->get_right_child() == node)
        {
            Parent->set_right_child(Right);
        }
        // case if the node is its parent's left child
        else Parent->set_left_child(Right);
    }


    Right->set_parent(Parent);
    // the node's right child will now be its parent
    Right->set_left_child(node);

    node->set_parent(Right);
    // the node's right child's left child will now be the node's right child
    node->set_right_child(Left_Subtree);

    if(Left_Subtree)
    {
        Left_Subtree->set_parent(node);
    }
    
}

// rotates the node given rightside
void AVLTree::Right_Rotation(BinaryTreeNode* node)
{
    BinaryTreeNode* Left = node->get_left_child();
    BinaryTreeNode* Right_Subtree = Left->get_right_child();
    BinaryTreeNode* Parent = node->get_parent();

    // case if the node is the root of the tree
    if(node == this->get_root()) this->set_root(Left);
    else
    {
        // the node's parent's new child will be the node's current left child

        // case if the node is its parent's right child
        if(Parent->get_right_child() == node)
        {
            Parent->set_right_child(Left);
        }
        // case if the node is its parent's left child
        else Parent->set_left_child(Left);
    }

    Left->set_parent(Parent);
    // the node's left child will now be its parent
    Left->set_right_child(node);

    node->set_parent(Left);
    // the node's left child's right child will now be the node's left child
    node->set_left_child(Right_Subtree);

    if(Right_Subtree)
    {
        Right_Subtree->set_parent(node);
    }
    
}


// Inserts at the tree and rotates bottom up afterwards
void AVLTree::AVL_Insert(void* value, int(*compare)(void*, void*))
{
    this->Insert(value, compare);

    BinaryTreeNode* W = this->Search(value, compare);
    BinaryTreeNode *Y, *X;
    Y = NULL;

    // traversing the tree from the recently inserted node and upwards to maintain avl balance within the tree
    while(W != NULL)
    {
        // balance factor determines if we need to rotate and in which side we need to
        int balance_factor = this->balance_factor(W);
        
        // this is a right case
        if(balance_factor > 1)
        {
            // this is a right right case    
            if(Y->get_right_child() == X)
            {
                this->Left_Rotation(W);
            }
            // this is a right left case
            else 
            {                
                this->Right_Rotation(Y);
                this->Left_Rotation(W);
            }
        }
        // this is a left case
        else if(balance_factor < -1)
        {
            // this a left left case
            if(Y->get_left_child() == X)
            {
                this->Right_Rotation(W);
            }
            // this a left right case
            else 
            {
                this->Left_Rotation(Y);
                this->Right_Rotation(W);
            }
        }

        // marking the node and its descedants because we will need them 
        if(Y) X = Y;
        Y = W;
        W = W->get_parent(); 
    }
}

// Removes from the tree and rotates bottom up afterwards
void AVLTree::AVL_Remove(void* value, int(*compare)(void*, void*))
{
    BinaryTreeNode* W = this->Search(value, compare);
    // if node is a leaf we should check the parent's balance at first
    if(!(W->get_left_child()) && !(W->get_right_child())) W = W->get_parent();

    this->Remove(value, compare);

    // traversing the tree from the recently removed node parent and upwards to maintain avl balance within the tree
    while(W != NULL) 
    {
        // balance factor determines if we need to rotate and in which side we need to
        int balance_factor = this->balance_factor(W);

        // this is a right case
        if(balance_factor > 1)
        {
            // more balance factors that determine if the right case is a right right or a right left
            int r_balance_factor = this->balance_factor(W->get_right_child());

            // this is a right right case
            if(r_balance_factor >= 0)
            {
                this->Left_Rotation(W);
            }
            // this is a right left case
            else
            {
                this->Right_Rotation(W->get_right_child());
                this->Left_Rotation(W);
            }
        }
        // this is a left case
        else if(balance_factor < -1)
        {
            // more balance factors that determine if the left case is a left right or a left left
            int l_balance_factor = this->balance_factor(W->get_left_child());

            // this a left right case
            if(l_balance_factor > 0)
            {
                this->Left_Rotation(W->get_left_child());
                this->Right_Rotation(W);
            }
            // this a left left case
            else
            {
                this->Right_Rotation(W);
            }
        }

        W = W->get_parent();
    }
}