//////////////////////////////////////////////////////////////////
//
// Unit tests για το Complete Binary Tree.
// Οποιαδήποτε υλοποίηση οφείλει να περνάει όλα τα tests.
//
//////////////////////////////////////////////////////////////////

#include "acutest.h"			// Απλή βιβλιοθήκη για unit testing
#include "CompleteBinaryTree.h"
#include <iostream>

using namespace std;


//////////////////////////////////////////////////////////////////
//
//  Tests
//////////////////////////////////////////////////////////////////

void completeBinaryTreeInsertTest()
{
    CompleteBinaryTree *tree = new CompleteBinaryTree();

    int key1 = 0;
    int key2 = 1;
    int key3 = 2;

    tree->insert(&key1);
    tree->insert(&key2);
    tree->insert(&key3);

    Treenode* node = tree->getRoot();
    // The first key that was inserted is the final root of the tree
    TEST_ASSERT(*((int *)node->getItem()) == key1);
    /* The first key that was inserted is the root of the tree
     * The other keys that were inserted will automatically be 
     * the left and right children of the root respectively
     * So the final height of the tree will be equal to 2.
     */
    TEST_ASSERT(tree->height() == 2);

    delete tree;
}

void completeBinaryTreeRemoveTest()
{
    CompleteBinaryTree *tree = new CompleteBinaryTree();

    int key1 = 0;
    int key2 = 1;
    int key3 = 2;
    int key4 = 3;
    int key5 = 4;
    int key6 = 5;
    int key7 = 6;
    int key8 = 7;
    int key9 = 8;

    tree->insert(&key1);
    tree->insert(&key2);
    tree->insert(&key3);
    tree->insert(&key4);
    tree->insert(&key5);
    tree->insert(&key6);
    tree->insert(&key7);
    tree->insert(&key8);
    tree->insert(&key9);

    // The tree has 9 keys so its height should be equal 
    // to the integer part of log9 plus 1 which equals to 4  
    TEST_ASSERT(tree->height() == 4);

    // In a Complete Binary Tree we can only remove the last node traversing in level order
    tree->removeLast();
    tree->removeLast();
    
    // We have removed all the keys from the last level of the tree
    // so the height will be lowered to 3
    TEST_ASSERT(tree->height() == 3);

    delete tree;
}

// Λίστα με όλα τα tests προς εκτέλεση
TEST_LIST = {
	{ "Complete Binary Tree Insert Test", completeBinaryTreeInsertTest},
    { "Complete Binary Tree Remove Test", completeBinaryTreeRemoveTest},
	{ NULL, NULL } // τερματίζουμε τη λίστα με NULL
};