/////////////////////////////////////////////////////////////////
//
// Unit tests για το Red Black Tree.
// Οποιαδήποτε υλοποίηση οφείλει να περνάει όλα τα tests.
//
//////////////////////////////////////////////////////////////////

#include "acutest.h"			// Απλή βιβλιοθήκη για unit testing
#include "RedBlackTree.h"
#include <iostream>

using namespace std;

// Global variables

// Used for traversal testings of insert functions
int* int_data;
int counter;
// Used to determine how much the counter should be incremented in the test_compare function
// Also used to determine the number of index keys in the inverted index
int modifier;

static int compare_ints(void *i1, void* i2)
{
    int myInt1, myInt2;
    if(i1 != NULL) myInt1 = *((int *) i1);
    else return -1;
    if(i2 != NULL) myInt2 = *((int *) i2);
    else return 1;
    return myInt1 - myInt2;
}

static void test_compare(void *value, void *key)
{
    int myValue = *((int *) value);
    TEST_ASSERT(myValue == int_data[counter]);
    counter+=modifier;
}

void redBlackTreeInsertTest()
{
    RedBlackTree *tree = new RedBlackTree();
    int* test_data = new int[20];
    int_data = new int[20];

    for(int i=0; i<20; i++)
    {
        test_data[i] = i;
        int_data[i] = i;
    }

    for(int i=0; i<20; i++)
    {
        tree->insert(&test_data[i], &test_data[i], compare_ints);
    }

    // traversing the nodes in order so that we find out that the keys were sorted correctly during insertion
    counter = 0;
    modifier = 1;
    tree->traverse(Inorder, test_compare);

    // height is bounded on the lower side by log(2)(n+1) and on the upper side by 2*log(2)(n+1)
    // so, when n=20 the height is between about 4 and 8
    int height = tree->height();
    TEST_ASSERT((height >= 4) && (height <= 8));

    delete[] test_data;
    delete[] int_data;
    delete tree;
}

void redBlackTreeSearchTest()
{
    RedBlackTree *tree = new RedBlackTree();
    int* test_data = new int[20];

    for(int i=0; i<20; i++)
    {
        test_data[i] = i;
    }

    for(int i=0; i<20; i++)
    {
        tree->insert(&test_data[i], &test_data[i], compare_ints);
    }

    int key1 = 5;
    int key2 = 21;
    // Trying to search an element from the tree, same as BST
    TEST_ASSERT(tree->search(&key1, compare_ints) == true);
    // Trying to search an element that is not in the tree, same as BST
    TEST_ASSERT(tree->search(&key2, compare_ints) == false);

    delete[] test_data;
    delete tree;
}

void redBlackTreeSearchItemTest()
{
    RedBlackTree *tree = new RedBlackTree();
    int* test_data = new int[20];

    for(int i=0; i<20; i++)
    {
        test_data[i] = i;
    }

    for(int i=0; i<20; i++)
    {
        tree->insert(&test_data[i], &test_data[i], compare_ints);
    }

    int key1 = 5;
    int key2 = 21;
    // Trying to search an element from the tree, same as BST
    TEST_ASSERT(*((int *)tree->searchItem(&key1, compare_ints)) == key1);
    // Trying to search an element that is not in the tree, same as BST
    TEST_ASSERT(tree->searchItem(&key2, compare_ints) == NULL);

    delete[] test_data;
    delete tree;
}

void redBlackTreeSearchKeyTest()
{
    RedBlackTree *tree = new RedBlackTree();
    int* test_data = new int[20];

    for(int i=0; i<20; i++)
    {
        test_data[i] = i;
    }

    for(int i=0; i<20; i++)
    {
        tree->insert(&test_data[i], &test_data[i], compare_ints);
    }

    int key1 = 5;
    int key2 = 21;
    // Trying to search an element from the tree, same as BST
    TEST_ASSERT(*((int *)tree->searchKey(&key1, compare_ints)) == key1);
    // Trying to search an element that is not in the tree, same as BST
    TEST_ASSERT(tree->searchKey(&key2, compare_ints) == NULL);

    delete[] test_data;
    delete tree;
}

void redBlackTreeRemoveTest()
{
    RedBlackTree *tree = new RedBlackTree();
    int* test_data = new int[20];

    for(int i=0; i<20; i++)
    {
        test_data[i] = i;
    }

    for(int i=0; i<20; i++)
    {
        tree->insert(&test_data[i], &test_data[i], compare_ints);
    }

    // Trying to remove an element from the tree
    int key1 = 5;
    bool *removal_true = new bool;
    tree->remove(&key1, compare_ints, removal_true);
    TEST_ASSERT(*removal_true == true);
    TEST_ASSERT(tree->search(&key1, compare_ints) == false);

    // Trying to remove an element that doesn't exist
    int key2 = 21;
    tree->remove(&key2, compare_ints, removal_true);
    TEST_ASSERT(*removal_true == false);

    // Removing enough keys to potentially drop the tree's height down 
    int key3 = 15;
    tree->remove(&key3, compare_ints, NULL);
    int key4 = 6;
    tree->remove(&key4, compare_ints, NULL);
    int key5 = 16;
    tree->remove(&key5, compare_ints, NULL);
    int key6 = 7;
    tree->remove(&key6, compare_ints, NULL);
    int key7 = 17;
    tree->remove(&key7, compare_ints, NULL);

    // height is bounded on the lower side by log(2)(n+1) and on the upper side by 2*log(2)(n+1)
    // so, when n=14 the height is between about 3 and 7
    int height = tree->height();
    TEST_ASSERT((height >= 3) && (height <= 7));

    delete removal_true;
    delete tree;
}

// Λίστα με όλα τα tests προς εκτέλεση
TEST_LIST = {
	{ "Red Black Tree Insert Test", redBlackTreeInsertTest},
    { "Red Black Tree Search Test", redBlackTreeSearchTest},
    { "Red Black Tree Search Item Test", redBlackTreeSearchItemTest},
    { "Red Black Tree Search Key Test", redBlackTreeSearchKeyTest},
    { "Red Black Tree Remove Test", redBlackTreeRemoveTest},
	{ NULL, NULL } // τερματίζουμε τη λίστα με NULL
};