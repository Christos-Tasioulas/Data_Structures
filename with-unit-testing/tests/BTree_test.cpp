//////////////////////////////////////////////////////////////////
//
// Unit tests για το B Tree.
// Οποιαδήποτε υλοποίηση οφείλει να περνάει όλα τα tests.
//
//////////////////////////////////////////////////////////////////

#include "acutest.h"			// Απλή βιβλιοθήκη για unit testing
#include "B_Tree.h"
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

void bTreeInsertTest()
{
    B_Tree *testTree = new B_Tree(5);
    int_data = new int[20]; 
    int* testArray = new int[20];

    for (int i = 0; i < 20; i++)
    {
        testArray[i] = i;
    }

    for (int i = 0; i < 20; i++)
    {
        bool *insertionWasSuccessful = new bool();
        testTree->insert(&testArray[i], &testArray[i], compare_ints, insertionWasSuccessful);
        TEST_ASSERT(*insertionWasSuccessful == true);
        int_data[i] = i;
        delete insertionWasSuccessful;
    }

    counter = 0;
    modifier = 1;
    testTree->traverse(Inorder, test_compare);

    delete testTree;
    delete[] int_data;
    delete[] testArray;
}

void bTreeSearchTest()
{
    B_Tree * testTree = new B_Tree(5);
    int* testArray = new int[20];

    for (int i = 0; i < 20; i++)
    {
        testArray[i] = i;
    }

    for (int i = 0; i < 20; i++)
    {
        testTree->insert(&testArray[i], &testArray[i], compare_ints, NULL);
    }

    for(int i = 0; i < 20; i++)
    {
        TEST_ASSERT(testTree->search(&testArray[i], compare_ints) == true);
    }

    delete testTree;
    delete[] testArray;
}

void bTreeSearchandReturnTest()
{
    B_Tree * testTree = new B_Tree(5);
    int* testArray = new int[20];

    for (int i = 0; i < 20; i++)
    {
        testArray[i] = i;
    }

    for (int i = 0; i < 20; i++)
    {
        testTree->insert(&testArray[i], &testArray[i], compare_ints, NULL);
    }

    for(int i = 0; i < 20; i++)
    {
        void *retrievedItem, *retrievedKey;
        TEST_ASSERT(testTree->searchAndRetrieve(&testArray[i], compare_ints, &retrievedItem, &retrievedKey) == true);
        int key = *(int*)retrievedKey;
        int value = *(int*)retrievedItem;
        TEST_ASSERT(key == testArray[i]);
        TEST_ASSERT(value == testArray[i]);
    }

    delete testTree;
    delete[] testArray;
}

void bTreeRemoveTest()
{
    B_Tree * testTree = new B_Tree(5);
    int* testArray = new int[20];

    for (int i = 0; i < 20; i++)
    {
        testArray[i] = i;
    }

    for (int i = 0; i < 20; i++)
    {
        testTree->insert(&testArray[i], &testArray[i], compare_ints, NULL);
    }

    bool *removalWasSuccessful = new bool;
    int removed = 13;
    testTree->remove(&removed, compare_ints, removalWasSuccessful);
    TEST_ASSERT(*removalWasSuccessful == true);
    TEST_ASSERT(testTree->search(&testArray[13], compare_ints) == false);
    TEST_ASSERT(testTree->getCounter() == 19);

    delete removalWasSuccessful;
    delete testTree;
    delete[] testArray;
}


// Λίστα με όλα τα tests προς εκτέλεση
TEST_LIST = {
	{ "B_Tree Insert Test", bTreeInsertTest},
    { "B_Tree Search Test", bTreeSearchTest},
    { "B_Tree Search And Return Test", bTreeSearchandReturnTest},
    { "B_Tree Remove Test", bTreeRemoveTest},
	{ NULL, NULL } // τερματίζουμε τη λίστα με NULL
};