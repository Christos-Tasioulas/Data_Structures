//////////////////////////////////////////////////////////////////
//
// Unit tests για το List.
// Οποιαδήποτε υλοποίηση οφείλει να περνάει όλα τα tests.
//
//////////////////////////////////////////////////////////////////

#include "acutest.h"			// Απλή βιβλιοθήκη για unit testing
#include "List.h"
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

void testInsertFront()
{
    List* list = new List();

    int i1 = 1;
    list->insertFront(&i1);

    void* item1 = list->getHead()->getItem();
    // testing the case this is the only node
    TEST_ASSERT((*(int *) item1) == 1);

    int i2 = 2;
    list->insertFront(&i2);

    void* item2 = list->getHead()->getItem();
    // testing the case there is another node
    TEST_ASSERT((*(int *) item2) == 2);

    delete list;
}

void testInsertLast()
{
    List* list = new List();

    int i1 = 1;
    list->insertLast(&i1);

    void* item1 = list->getTail()->getItem();
    // testing the case this is the only node
    TEST_ASSERT((*(int *) item1) == 1);

    int i2 = 2;
    list->insertLast(&i2);
    
    void* item2 = list->getTail()->getItem();
    // testing the case there is another node
    TEST_ASSERT((*(int *) item2) == 2);

    delete list;
}

void testInsertAfterPos()
{
    List* list = new List();

    int i1 = 1;
    list->insertAfterPos(&i1, 0);

    void* item1 = list->getItemInPos(0);
    // testing the case this is the only node
    TEST_ASSERT((*(int *) item1) == 1);

    int i2 = 2;
    list->insertAfterPos(&i2, 1);

    void* item2 = list->getItemInPos(2);
    // testing the case the number of entries is less or equal than one
    TEST_ASSERT((*(int *) item2) == 2);

    int i3 = 3;
    list->insertAfterPos(&i3, 1);

    void* item3 = list->getItemInPos(2);
    // testing the normal case
    TEST_ASSERT((*(int *) item3) == 3);

    int i4 = 4;
    list->insertAfterPos(&i4, 3);

    void* item4 = list->getItemInPos(4);
    // testing the case the position given is greater or equal to the number of entries
    TEST_ASSERT((*(int *) item4) == 4);

    delete list;
}

void testInsertBeforePos()
{
    List* list = new List();

    int i1 = 1;
    list->insertBeforePos(&i1, 0);

    void* item1 = list->getItemInPos(0);
    // testing the case this is the only node
    TEST_ASSERT((*(int *) item1) == 1);

    int i2 = 2;
    list->insertBeforePos(&i2, 1);

    void* item2 = list->getItemInPos(1);
    // testing the case the number of entries is less or equal than one
    TEST_ASSERT((*(int *) item2) == 2);

    int i3 = 3;
    list->insertBeforePos(&i3, 1);

    void* item3 = list->getItemInPos(1);
    // testing the case the position given is less or equal than one
    TEST_ASSERT((*(int *) item3) == 3);

    int i4 = 4;
    list->insertBeforePos(&i4, 3);

    void* item4 = list->getItemInPos(3);
    // testing the case the position given is greater or equal to the number of entries
    TEST_ASSERT((*(int *) item4) == 4);

    int i5 = 5;
    list->insertBeforePos(&i5, 2);

    void* item5 = list->getItemInPos(2);
    // testing the normal case 
    TEST_ASSERT((*(int *) item5) == 5);

    delete list;
}

void testInsertAfterKeyNode()
{
    List* list = new List();

    int i1 = 1;
    list->insertAfterKeyNode(&i1, NULL, compare_ints);

    void* item1 = list->getItemInPos(1);
    // testing the case this is the only node
    TEST_ASSERT((*(int *) item1) == 1);

    int i2 = 2;
    list->insertAfterKeyNode(&i2, NULL, compare_ints);

    void* item2 = list->getItemInPos(2);
    // testing the case the key is NULL
    TEST_ASSERT((*(int *) item2) == 2);

    int i3 = 3;
    list->insertAfterKeyNode(&i3, &i1, compare_ints);

    void* item3 = list->getItemInPos(2);
    // testing the normal case
    TEST_ASSERT((*(int *) item3) == 3);

    int i4 = 4;
    list->insertAfterKeyNode(&i4, NULL, compare_ints);

    void* item4 = list->getItemInPos(4);
    // testing the case we give NULL key
    TEST_ASSERT((*(int *) item4) == 4);

    delete list;
}

void testInsertBeforeKeyNode()
{
    List* list = new List();

    int i1 = 1;
    list->insertBeforeKeyNode(&i1, NULL, compare_ints);

    void* item1 = list->getItemInPos(1);
    // testing the case this is the only node
    TEST_ASSERT((*(int *) item1) == 1);

    int i2 = 2;
    list->insertBeforeKeyNode(&i2, NULL, compare_ints);

    void* item2 = list->getItemInPos(1);
    // testing the case this the second node
    TEST_ASSERT((*(int *) item2) == 2);

    int i3 = 3;
    list->insertBeforeKeyNode(&i3, &i1, compare_ints);

    void* item3 = list->getItemInPos(2);
    // testing the normal case
    TEST_ASSERT((*(int *) item3) == 3);

    int i4 = 4;
    list->insertBeforeKeyNode(&i4, NULL, compare_ints);

    void* item4 = list->getItemInPos(1);
    // testing the case we give NULL key
    TEST_ASSERT((*(int *) item4) == 4);

    delete list;
}

void testRemoveFront()
{
    List* list = new List();

    int i1 = 1;
    list->insertFront(&i1);

    list->removeFront();
    // testing case this is the only node
    TEST_ASSERT(list->getCounter() == 0);

    int i2 = 2;
    list->insertFront(&i1);
    list->insertFront(&i2);

    list->removeFront();
    // testing normal case 
    TEST_ASSERT(list->getCounter() == 1);
    void* item = list->getHead()->getItem();
    TEST_ASSERT((*(int *) item) == 1);

    delete list;
}

void testRemoveLast()
{
    List* list = new List();

    int i1 = 1;
    list->insertLast(&i1);

    list->removeLast();
    // testing case this is the only node
    TEST_ASSERT(list->getCounter() == 0);

    int i2 = 2;
    list->insertLast(&i1);
    list->insertLast(&i2);

    list->removeLast();
    // testing normal case 
    TEST_ASSERT(list->getCounter() == 1);
    void* item = list->getTail()->getItem();
    TEST_ASSERT((*(int *) item) == 1);

    delete list;
}

void testRemovePos()
{
    List* list = new List();

    int i1 = 1;
    list->insertLast(&i1);

    list->removePos(1);
    // testing case this is the only node
    TEST_ASSERT(list->getCounter() == 0);

    int i2 = 2;
    list->insertLast(&i1);
    list->insertLast(&i2);

    list->removePos(1);
    // testing case this is the first node
    TEST_ASSERT(list->getCounter() == 1);
    void* item = list->getHead()->getItem();
    TEST_ASSERT((*(int *) item) == 2);

    // reset and refill
    list->removeLast();
    list->insertLast(&i1);
    list->insertLast(&i2);

    list->removePos(2);
    // testing case this is the last node
    TEST_ASSERT(list->getCounter() == 1);
    void* item1 = list->getTail()->getItem();
    TEST_ASSERT((*(int *) item1) == 1);

    // reset and refill
    list->removeLast();
    int i3 = 3;
    list->insertLast(&i1);
    list->insertLast(&i2);
    list->insertLast(&i3);

    list->removePos(2);
    // testing the normal case
    TEST_ASSERT(list->getCounter() == 2);
    void* item2 = list->getItemInPos(2);
    TEST_ASSERT((*(int *) item2) == 3);

    delete list;
}

void testRemoveKeyNode()
{
    List* list = new List();

    int i1 = 1;
    list->insertLast(&i1);

    list->removeKeyNode(NULL, compare_ints, NULL);
    // testing case we didn't give key
    TEST_ASSERT(list->getCounter() == 1);

    list->removeKeyNode(&i1, compare_ints, NULL);
    // testing case this is the only node
    TEST_ASSERT(list->getCounter() == 0);

    int i2 = 2;
    list->insertLast(&i1);
    list->insertLast(&i2);

    list->removeKeyNode(&i1, compare_ints, NULL);
    // testing case this is the first node
    TEST_ASSERT(list->getCounter() == 1);
    void* item = list->getHead()->getItem();
    TEST_ASSERT((*(int *) item) == 2);

    // reset and refill
    list->removeLast();
    list->insertLast(&i1);
    list->insertLast(&i2);

    list->removeKeyNode(&i2, compare_ints, NULL);
    // testing case this is the last node
    TEST_ASSERT(list->getCounter() == 1);
    void* item1 = list->getTail()->getItem();
    TEST_ASSERT((*(int *) item1) == 1);

    // reset and refill
    list->removeLast();
    int i3 = 3;
    list->insertLast(&i1);
    list->insertLast(&i2);
    list->insertLast(&i3);

    list->removeKeyNode(&i2, compare_ints, NULL);
    // testing the normal case
    TEST_ASSERT(list->getCounter() == 2);
    void* item2 = list->getItemInPos(2);
    TEST_ASSERT((*(int *) item2) == 3);

    delete list;
}

void testSplit()
{
    List* list = new List();
    List* list1;
    List* list2;
    List* list3;
    List* list4;
    List* list5;
    List* list6;

    // Testing the case the initial list is empty
    list->split(&list1, &list2);
    TEST_ASSERT(list1->getCounter() == 0);
    TEST_ASSERT(list2->getCounter() == 0);

    int i1 = 1;
    int i2 = 2;
    list->insertLast(&i1);
    list->insertLast(&i2);
    
    // Testing the case the initial list has an even amount of elements
    list->split(&list3, &list4);
    TEST_ASSERT(list3->getCounter() == list4->getCounter());

    int i3 = 3;
    list->insertLast(&i3);

    // Testing the case the initial list has an even amount of elements
    list->split(&list5, &list6);
    // The second list will have more items than the first one
    TEST_ASSERT(list5->getCounter() <= list6->getCounter());

    delete list1;
    delete list2;
    delete list3;
    delete list4;
    delete list5;
    delete list6;
    delete list;
}

void testAppend()
{
    List* list = new List();
    List* list1 = new List();
    List* list2 = new List();
    List* list3 = new List();

    int i1 = 1;
    list1->insertLast(&i1);

    // Testing the case we append a list to an empty list
    list->append(list1);
    TEST_ASSERT(list->getCounter() == list1->getCounter());

    unsigned int prev_counter = list->getCounter();

    // Testing the case we append an empty list to a list
    list->append(list2);
    TEST_ASSERT(list->getCounter() == prev_counter);

    prev_counter = list->getCounter();

    int i2 = 2;
    list3->insertLast(&i2);

    // Testing the normal case
    list->append(list3);
    TEST_ASSERT(list->getCounter() == prev_counter + list3->getCounter());
    // The given list is appended at the end of the current list
    TEST_ASSERT(list->getTail()->getItem() == list3->getTail()->getItem());

    delete list1;
    delete list2;
    delete list3;
    delete list;
}


// Λίστα με όλα τα tests προς εκτέλεση
TEST_LIST = {
	{ "List Insert Front", testInsertFront},
    { "List Insert Last", testInsertLast},
    { "List Insert After Given Position", testInsertAfterPos},
    { "List Insert Before Given Position", testInsertBeforePos},
    { "List Insert After Given Key", testInsertAfterKeyNode},
    { "List Insert Before Given Key", testInsertBeforeKeyNode},
    { "List Remove Front", testRemoveFront},
    { "List Remove Last", testRemoveLast},
    { "List Remove From Given Position", testRemovePos},
    { "List Remove Given Key", testRemoveKeyNode},
    { "List Split", testSplit},
    { "List Append", testAppend},
	{ NULL, NULL } // τερματίζουμε τη λίστα με NULL
};