//////////////////////////////////////////////////////////////////
//
// Unit tests για το Binary Heap.
// Οποιαδήποτε υλοποίηση οφείλει να περνάει όλα τα tests.
//
//////////////////////////////////////////////////////////////////

#include "acutest.h"			// Απλή βιβλιοθήκη για unit testing
#include "BinaryHeap.h"
#include <iostream>

using namespace std;

static int compare_ints(void *i1, void* i2)
{
    int myInt1, myInt2;
    if(i1 != NULL) myInt1 = *((int *) i1);
    else return -1;
    if(i2 != NULL) myInt2 = *((int *) i2);
    else return 1;
    return myInt1 - myInt2;
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

// Preorder traversal of a MaxBinaryHeap in order to evaluate its heap status
static void preorderBMaxHeap(Treenode *node)
{
    if(node != NULL)
    {
        BHObject* bhObject = (BHObject*) node->getItem();
        int key = *((int*) bhObject->getKey());
        if(node->getLeft())
        {
            Treenode* left = node->getLeft();
            BHObject* lBhObject = (BHObject*) left->getItem();
            int l_key = *((int*) lBhObject->getKey());
            TEST_ASSERT(l_key <= key);
        }
        if(node->getRight())
        {
            Treenode* right = node->getRight();
            BHObject* rBhObject = (BHObject*) right->getItem();
            int r_key = *((int*) rBhObject->getKey());
            TEST_ASSERT(r_key <= key);
        } 
        preorderBMaxHeap(node->getLeft());
        preorderBMaxHeap(node->getRight());
    }
}

void binaryHeapInsertTest()
{
    BinaryHeap *heap = new BinaryHeap(MAXHEAP);
    int* test_data = new int[20];

    for(int i=0; i<20; i++)
    {
        test_data[i] = i;
    }

    // the shuffle exists for testing purposes
    array_random_shuffle(test_data, 20);

    for(int i=0; i<20; i++)
    {
        heap->insert(&test_data[i], &test_data[i], compare_ints);
    }

    // Preorder traversal to compare each key in the heap with its children
    // so that we ensure the heap is sorted correctly
    preorderBMaxHeap(heap->getRoot());

    delete test_data;
    delete heap;
}

void binaryHeapGetHighestPriorityItemTest()
{
    BinaryHeap *heap = new BinaryHeap(MAXHEAP);
    int* test_data = new int[20];

    for(int i=0; i<20; i++)
    {
        test_data[i] = i;
    }

    // the shuffle exists for testing purposes
    array_random_shuffle(test_data, 20);

    for(int i=0; i<20; i++)
    {
        heap->insert(&test_data[i], &test_data[i], compare_ints);
    }

    // The largest item is 19
    TEST_ASSERT(*((int*) heap->getHighestPriorityItem()) == 19);

    delete test_data;
    delete heap;
}

void binaryHeapGetHighestPriorityKeyTest()
{
    BinaryHeap *heap = new BinaryHeap(MAXHEAP);
    int* test_data = new int[20];

    for(int i=0; i<20; i++)
    {
        test_data[i] = i;
    }

    // the shuffle exists for testing purposes
    array_random_shuffle(test_data, 20);

    for(int i=0; i<20; i++)
    {
        heap->insert(&test_data[i], &test_data[i], compare_ints);
    }

    // The largest key is 19
    TEST_ASSERT(*((int*) heap->getHighestPriorityKey()) == 19);

    delete test_data;
    delete heap;
}

void binaryHeapRemoveTest()
{
    BinaryHeap *heap = new BinaryHeap(MAXHEAP);
    int* test_data = new int[20];

    for(int i=0; i<20; i++)
    {
        test_data[i] = i;
    }

    // the shuffle exists for testing purposes
    array_random_shuffle(test_data, 20);

    for(int i=0; i<20; i++)
    {
        heap->insert(&test_data[i], &test_data[i], compare_ints);
    }

    // emptying the heap for testing purposes
    for(int i=19; i>=0; --i)
    {
        // current highest priority key is i
        TEST_ASSERT(*((int*) heap->getHighestPriorityKey()) == i);
        heap->remove(compare_ints);
    }

    // the heap must be empty
    TEST_ASSERT(heap->isEmpty() == true);

    delete test_data;
    delete heap;
}

// Λίστα με όλα τα tests προς εκτέλεση
TEST_LIST = {
    { "Binary Heap Insert Test", binaryHeapInsertTest},
    { "Binary Heap Get Highest Priority Item Test", binaryHeapGetHighestPriorityItemTest},
    { "Binary Heap Get Highest Priority Key Test", binaryHeapGetHighestPriorityKeyTest},
    { "Binary Heap Remove Test", binaryHeapRemoveTest},
	{ NULL, NULL } // τερματίζουμε τη λίστα με NULL
};