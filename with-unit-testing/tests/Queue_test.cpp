/////////////////////////////////////////////////////////////////
//
// Unit tests για το Queue.
// Οποιαδήποτε υλοποίηση οφείλει να περνάει όλα τα tests.
//
//////////////////////////////////////////////////////////////////

#include "acutest.h"			// Απλή βιβλιοθήκη για unit testing
#include "Queue.h"
#include <iostream>

using namespace std;

void queueInsertTest()
{
    Queue *testQueue = new Queue();
    
    int i1 = 1;
    int i2 = 2;

    // test case this is the first item in the queue
    testQueue->insert(&i1);
    int item1 = *((int *)testQueue->getOldestItem());
    TEST_ASSERT(item1 == 1);

    // normal test case new items are always inserted at the end of the queue
    testQueue->insert(&i2);
    int item2 = *((int *)testQueue->getOldestItem());
    TEST_ASSERT(item2 == 1);

    delete testQueue;
}

void queueRemoveTest()
{
    Queue *testQueue = new Queue();

    int i1 = 1;
    int i2 = 2;

    testQueue->insert(&i1);
    testQueue->remove();
    // test case we removed the first item in the queue
    TEST_ASSERT(testQueue->isEmpty());

    testQueue->insert(&i1);
    testQueue->insert(&i2);
    testQueue->remove();
    int item = *((int *)testQueue->getOldestItem());
    // normal test case, we always remove the first item in the queue
    TEST_ASSERT(item == 2);

    delete testQueue;
}

// Λίστα με όλα τα tests προς εκτέλεση
TEST_LIST = {
	{ "Queue Insert Test", queueInsertTest},
    { "Queue Remove Test", queueRemoveTest},
	{ NULL, NULL } // τερματίζουμε τη λίστα με NULL
};