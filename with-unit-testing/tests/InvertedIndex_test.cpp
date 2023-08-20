/////////////////////////////////////////////////////////////////
//
// Unit tests για το Inverted Index.
// Οποιαδήποτε υλοποίηση οφείλει να περνάει όλα τα tests.
//
//////////////////////////////////////////////////////////////////

#include "acutest.h"			// Απλή βιβλιοθήκη για unit testing
#include "InvertedIndex.h"
#include <iostream>

using namespace std;

// Global variables

// Used for traversal testings of insert functions
int* int_data;
int counter;
// Temporary variable to store the previous counter value used in the inOrderRedBlackTree function
int prev_counter;
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

// InOrder Traversal of an Inverted Index that contains RedBlackTrees
static void inOrderRedBlackTree(void* value, void* key)
{
    prev_counter = counter;
    RedBlackTree* index_tree = (RedBlackTree*) value;
    index_tree->traverse(Inorder, test_compare);
    counter = prev_counter + 1;
}

//////////////////////////////////////////////////////////////////
//
//  Tests
//
//////////////////////////////////////////////////////////////////

void invertedIndexInsertTest()
{
    InvertedIndex *ii = new InvertedIndex();
    int* test_data = new int[20];
    int_data = new int[20];

    for(int i=0; i<20; i++)
    {
        test_data[i] = i;
        int_data[i] = i;
    }

    modifier = 4; 
    int *index = new int[modifier];
    for(int i=0; i<modifier; i++)
    {
        index[i] = i;
    }

    for(int i=0; i<20; i++)
    {
        ii->insert(&test_data[i], &index[i%modifier], &test_data[i], compare_ints, compare_ints);
    }

    // traversing the nodes in order so that we find out that the keys were sorted correctly during insertion
    counter = 0;
    ii->traverse(Inorder, inOrderRedBlackTree);

    delete[] index;
    delete[] test_data;
    delete[] int_data;
    delete ii;
}

void invertedIndexSearchItemKeyTest()
{
    InvertedIndex *ii = new InvertedIndex();
    int* test_data = new int[20];

    for(int i=0; i<20; i++)
    {
        test_data[i] = i;
    }

    modifier = 4; 
    int *index = new int[modifier];
    for(int i=0; i<modifier; i++)
    {
        index[i] = i;
    }

    for(int i=0; i<20; i++)
    {
        ii->insert(&test_data[i], &index[i%modifier], &test_data[i], compare_ints, compare_ints);
    }

    int key1 = 5;
    int index1 = key1 % modifier;
    int key2 = 22;
    int index2 = key2 % modifier;
    int index3 = key2;
    // Trying to search an element from the index tree that includes it
    TEST_ASSERT(ii->searchItemKey(&index1, &key1, compare_ints, compare_ints) != NULL);
    // Trying to search an element that is not in the tree
    TEST_ASSERT(ii->searchItemKey(&index2, &key2, compare_ints, compare_ints) == NULL);
    // Trying to search an element from an index tree that does not include it
    TEST_ASSERT(ii->searchItemKey(&index2, &key1, compare_ints, compare_ints) == NULL);
    // Trying to search an element from an index tree that does not exist in the inverted index
    TEST_ASSERT(ii->searchItemKey(&index3, &key1, compare_ints, compare_ints) == NULL);


    delete[] index;
    delete[] test_data;
    delete ii;
}

void invertedIndexSearchIndexKeyTest()
{
    InvertedIndex *ii = new InvertedIndex();
    int* test_data = new int[20];

    for(int i=0; i<20; i++)
    {
        test_data[i] = i;
    }

    modifier = 4; 
    int *index = new int[modifier];
    for(int i=0; i<modifier; i++)
    {
        index[i] = i;
    }

    for(int i=0; i<20; i++)
    {
        ii->insert(&test_data[i], &test_data[i], &index[i%modifier], compare_ints, compare_ints);
    }

    // removing a node from the inverted index
    int key1 = 5;
    int index1 = key1 % modifier;
    ii->remove(&index1, &key1, compare_ints, compare_ints);
    TEST_ASSERT(ii->searchItemKey(&index1, &key1, compare_ints, compare_ints) == NULL);

    delete[] index;
    delete[] test_data;
    delete ii;
}

void invertedIndexRemoveTest()
{
    InvertedIndex *ii = new InvertedIndex();
    int* test_data = new int[20];

    for(int i=0; i<20; i++)
    {
        test_data[i] = i;
    }

    modifier = 4; 
    int *index = new int[modifier];
    for(int i=0; i<modifier; i++)
    {
        index[i] = i;
    }

    for(int i=0; i<20; i++)
    {
        ii->insert(&test_data[i], &index[i%modifier], &test_data[i], compare_ints, compare_ints);
    }

    int key1 = 5;
    int index1 = key1 % modifier;
    int key2 = 22;
    int index2 = key2 % modifier;
    int index3 = key2;
    // Trying to search an element from the index tree that includes it
    TEST_ASSERT(ii->searchItemKey(&index1, &key1, compare_ints, compare_ints) != NULL);
    // Trying to search an element that is not in the tree
    TEST_ASSERT(ii->searchItemKey(&index2, &key2, compare_ints, compare_ints) == NULL);
    // Trying to search an element from an index tree that does not include it
    TEST_ASSERT(ii->searchItemKey(&index2, &key1, compare_ints, compare_ints) == NULL);
    // Trying to search an element from an index tree that does not exist in the inverted index
    TEST_ASSERT(ii->searchItemKey(&index3, &key1, compare_ints, compare_ints) == NULL);


    delete[] index;
    delete[] test_data;
    delete ii;
}

// Λίστα με όλα τα tests προς εκτέλεση
TEST_LIST = {
	{ "Inverted Index Insert Test", invertedIndexInsertTest},
    { "Inverted Index Search Item Key Test", invertedIndexSearchItemKeyTest},
    { "Inverted Index Search Index Key Test", invertedIndexSearchIndexKeyTest},
    { "Inverted Index Remove Test", invertedIndexRemoveTest},
	{ NULL, NULL } // τερματίζουμε τη λίστα με NULL
};