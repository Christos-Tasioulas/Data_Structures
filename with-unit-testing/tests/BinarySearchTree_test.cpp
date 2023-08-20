//////////////////////////////////////////////////////////////////
//
// Unit tests για το Binary Search Tree.
// Οποιαδήποτε υλοποίηση οφείλει να περνάει όλα τα tests.
//
//////////////////////////////////////////////////////////////////

#include "acutest.h"			// Απλή βιβλιοθήκη για unit testing
#include "BinarySearchTree.h"
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

void swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

void array_random_shuffle(int* array, int size)
{
  for (int i=size-1; i>0; --i) {
    int j = rand() % (i+1);
    swap (&array[i], &array[j]);
  }
}

//////////////////////////////////////////////////////////////////
//
//  Tests
//
//////////////////////////////////////////////////////////////////

void binarySearchTreeInsertTest()
{
    BinarySearchTree *tree = new BinarySearchTree();
    int_data = new int[20];
    int* test_data = new int[20];

    for(int i=0; i<20; i++)
    {
        int_data[i] = i;
        test_data[i] = i;
    }

    // shuffling the input array makes sure that the search inside the tree is in logn complexity
    array_random_shuffle(test_data, 20);

    for(int i=0; i<20; i++)
    {
        Treenode** node_p = new Treenode*;
        tree->insert(&test_data[i], &test_data[i], compare_ints, node_p);
        // testing if the node has been inserted successfully
        TEST_ASSERT(*node_p != NULL);
        delete node_p;
    }

    // traversing the nodes in order so that we find out that the keys were sorted correctly during insertion
    counter = 0;
    modifier = 1;
    tree->traverse(Inorder, test_compare);

    delete[] test_data;
    delete[] int_data;
    delete tree;
}

void binarySearchTreeSearchTest()
{
    BinarySearchTree *tree = new BinarySearchTree();

    int* test_data = new int[20];

    for(int i=0; i<20; i++)
    {
        test_data[i] = i;
    }

    // shuffling the input array makes sure that the search inside the tree is in logn complexity
    array_random_shuffle(test_data, 20);

    for(int i=0; i<20; i++)
    {
        tree->insert(&test_data[i], &test_data[i], compare_ints, NULL);
    }

    int key1 = 5;
    int key2 = 21;
    // Trying to search an element from the tree
    TEST_ASSERT(tree->search(&key1, compare_ints, NULL) == true);
    // Trying to search an element that is not in the tree
    TEST_ASSERT(tree->search(&key2, compare_ints, NULL) == false);
    delete[] test_data;
    delete tree;
}

void binarySearchTreeSearchItemTest()
{
    BinarySearchTree *tree = new BinarySearchTree();

    int* test_data = new int[20];

    for(int i=0; i<20; i++)
    {
        test_data[i] = i;
    }

    // shuffling the input array makes sure that the search inside the tree is in logn complexity
    array_random_shuffle(test_data, 20);

    for(int i=0; i<20; i++)
    {
        tree->insert(&test_data[i], &test_data[i], compare_ints, NULL);
    }

    int key1 = 5;
    int key2 = 21;
    // Trying to search an element from the tree
    TEST_ASSERT(*((int *)tree->searchItem(&key1, compare_ints, NULL)) == key1);
    // Trying to search an element that is not in the tree
    TEST_ASSERT(tree->searchItem(&key2, compare_ints, NULL) == NULL);
    delete[] test_data;
    delete tree;
}

void binarySearchTreeSearchKeyTest()
{
    BinarySearchTree *tree = new BinarySearchTree();

    int* test_data = new int[20];

    for(int i=0; i<20; i++)
    {
        test_data[i] = i;
    }

    // shuffling the input array makes sure that the search inside the tree is in logn complexity
    array_random_shuffle(test_data, 20);

    for(int i=0; i<20; i++)
    {
        tree->insert(&test_data[i], &test_data[i], compare_ints, NULL);
    }

    int key1 = 5;
    int key2 = 21;
    // Trying to search an element from the tree
    TEST_ASSERT(*((int *)tree->searchKey(&key1, compare_ints, NULL)) == key1);
    // Trying to search an element that is not in the tree
    TEST_ASSERT(tree->searchKey(&key2, compare_ints, NULL) == NULL);
    delete[] test_data;
    delete tree;
}

void binarySearchTreeRemoveTest()
{
    BinarySearchTree *tree = new BinarySearchTree();
    int* test_data = new int[20];

    for(int i=0; i<20; i++)
    {
        test_data[i] = i;
    }

    // shuffling the input array makes sure that the search inside the tree is in logn
    array_random_shuffle(test_data, 20);

    for(int i=0; i<20; i++)
    {
        tree->insert(&test_data[i], &test_data[i], compare_ints, NULL);
    }

    // Trying to remove an element from the tree
    int key1 = 5;
    bool *removal_true = new bool;
    tree->remove(&key1, compare_ints, removal_true);
    TEST_ASSERT(*removal_true == true);
    TEST_ASSERT(tree->search(&key1, compare_ints, NULL) == false);

    // Trying to remove an element that doesn't exist
    int key3 = 21;
    tree->remove(&key3, compare_ints, removal_true);
    TEST_ASSERT(*removal_true == false);

    delete removal_true;
    delete tree;
}

// Λίστα με όλα τα tests προς εκτέλεση
TEST_LIST = {
	{ "Binary Search Tree Insert Test", binarySearchTreeInsertTest},
    { "Binary Search Tree Search Test", binarySearchTreeSearchTest},
    { "Binary Search Tree Search Item Test", binarySearchTreeSearchItemTest},
    { "Binary Search Tree Search Key Test", binarySearchTreeSearchKeyTest},
    { "Binary Search Tree Remove Test", binarySearchTreeRemoveTest},
	{ NULL, NULL } // τερματίζουμε τη λίστα με NULL
};