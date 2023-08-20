//////////////////////////////////////////////////////////////////
//
// Unit tests για το BinaryTree.
// Οποιαδήποτε υλοποίηση οφείλει να περνάει όλα τα tests.
//
//////////////////////////////////////////////////////////////////

#include "acutest.h"			// Απλή βιβλιοθήκη για unit testing
#include "BinaryTree.h"
#include <iostream>

using namespace std;

void binaryTreeInsertTest()
{
    BinaryTree *tree = new BinaryTree();
    int key1 = 0;
    int key2 = 1;
    int key3 = 2;

    tree->insertRoot(&key1);
    tree->insertRoot(&key2);
    tree->insertRoot(&key3);
    Treenode* node = tree->getRoot();
    TEST_ASSERT(node != NULL);
    // The first key that was inserted is the final root of the tree
    // The final two keys were not inserted in the tree
    TEST_ASSERT(*((int *)node->getItem()) == key1);

    tree->insertLeft(node, &key2);
    Treenode* leftNode = node->getLeft();
    TEST_ASSERT(leftNode!= NULL);
    TEST_ASSERT(*((int *)leftNode->getItem()) == key2);

    tree->insertRight(node, &key3);
    Treenode* rightNode = node->getRight();
    TEST_ASSERT(rightNode!= NULL);
    TEST_ASSERT(*((int *)rightNode->getItem()) == key3);

    delete tree;
}

void binaryTreeRemoveTest()
{
    BinaryTree *tree = new BinaryTree();
    int key1 = 0;
    int key2 = 1;
    int key3 = 2;

    tree->insertRoot(&key1);
    Treenode* node = tree->getRoot();
    tree->insertLeft(node, &key2);
    tree->insertRight(node, &key3);

    // We can't remove the root node from the tree because it is not a leaf node
    tree->remove(node);
    TEST_ASSERT(tree->size() == 3);

    // This node is a leaf node
    Treenode* leftNode = node->getLeft();
    tree->remove(leftNode);
    TEST_ASSERT(tree->size() == 2);

    delete tree;
}

// Λίστα με όλα τα tests προς εκτέλεση
TEST_LIST = {
	{ "Binary Tree Insert Test", binaryTreeInsertTest},
    { "Binary Tree Remove Test", binaryTreeRemoveTest},
	{ NULL, NULL } // τερματίζουμε τη λίστα με NULL
};