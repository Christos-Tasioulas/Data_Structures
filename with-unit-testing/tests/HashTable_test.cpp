/////////////////////////////////////////////////////////////////
//
// Unit tests για το HashTable.
// Οποιαδήποτε υλοποίηση οφείλει να περνάει όλα τα tests.
//
//////////////////////////////////////////////////////////////////

#include "acutest.h"			// Απλή βιβλιοθήκη για unit testing
#include "HashTable.h"
#include <iostream>

using namespace std;

static unsigned int hash_int(void *i)
{
    int myInt = *((int *) i);
    return (unsigned int) myInt;
}

static int compare_ints(void *i1, void* i2)
{
    int myInt1, myInt2;
    if(i1 != NULL) myInt1 = *((int *) i1);
    else return -1;
    if(i2 != NULL) myInt2 = *((int *) i2);
    else return 1;
    return myInt1 - myInt2;
}

//////////////////////////////////////////////////////////////////
//
//  Tests
//
//////////////////////////////////////////////////////////////////

void insertWithoutRehashTest()
{
    HashTable *ht = new HashTable(16, false, 1.0, 4);

    int myKey = 5;
    ht->insert(&myKey, &myKey, hash_int, compare_ints);

    List* items1 = ht->getTable()[5].getItems();
    HashEntryItem *entryItem1 = (HashEntryItem *) items1->getItemInPos(1);
    int item1 = *((int *)entryItem1->getItem());
    TEST_ASSERT(item1 == 5);
    
    // Case: Duplicate
    int myDuplicateKey = 5;
    ht->insert(&myDuplicateKey, &myDuplicateKey, hash_int, compare_ints);
    items1 = ht->getTable()[5].getItems();
    entryItem1 = (HashEntryItem *) items1->getItemInPos(2);
    item1 = *((int *)entryItem1->getItem());
    TEST_ASSERT(item1 == 5);
    TEST_ASSERT(items1->getCounter() == 2);

    int newKey = 21;
    ht->insert(&newKey, &newKey, hash_int, compare_ints);

    // This test indicates that a key that has been entered before moves to the next index
    List* items2 = ht->getTable()[6].getItems();
    HashEntryItem *entryItem2 = (HashEntryItem *) items2->getItemInPos(1);
    int item2 = *((int *)entryItem2->getItem());
    TEST_ASSERT(item2 == 21);

    int newnewKey = 6;
    ht->insert(&newnewKey, &newnewKey, hash_int, compare_ints);

    // This test indicates that a key that its original index is occupied moves to the next index
    List* items3 = ht->getTable()[7].getItems();
    HashEntryItem *entryItem3 = (HashEntryItem *) items3->getItemInPos(1);
    int item3 = *((int *)entryItem3->getItem());
    TEST_ASSERT(item3 == 6);

    int key_4 = 37;
    ht->insert(&key_4, &key_4, hash_int, compare_ints);

    List* items4 = ht->getTable()[8].getItems();
    HashEntryItem *entryItem4 = (HashEntryItem *) items4->getItemInPos(1);
    int item4 = *((int *)entryItem4->getItem());
    TEST_ASSERT(item4 == 37);

    int key_5 = 22;
    ht->insert(&key_5, &key_5, hash_int, compare_ints);

    List* items5 = ht->getTable()[9].getItems();
    HashEntryItem *entryItem5 = (HashEntryItem *) items5->getItemInPos(1);
    int item5 = *((int *)entryItem5->getItem());
    TEST_ASSERT(item5 == 22);

    int key_6 = 15;
    ht->insert(&key_6, &key_6, hash_int, compare_ints);

    int key_7 = 31;
    ht->insert(&key_7, &key_7, hash_int, compare_ints);

    // Testing the case the hash table comes full circle
    List* items6 = ht->getTable()[15].getItems();
    HashEntryItem *entryItem6 = (HashEntryItem *) items6->getItemInPos(1);
    int item6 = *((int *)entryItem6->getItem());
    TEST_ASSERT(item6 == 15);

    List* items7 = ht->getTable()[0].getItems();
    HashEntryItem *entryItem7 = (HashEntryItem *) items7->getItemInPos(1);
    int item7 = *((int *)entryItem7->getItem());
    TEST_ASSERT(item7 == 31);

    delete ht;
}

void rehashTest()
{
    HashTable *ht = new HashTable(16, true, 0.7, 4);

    TEST_ASSERT(ht->getBucketsNum() == 16);
    TEST_ASSERT(ht->getHopInfoCapacity() == 4);

    int key_0 = 5;
    ht->insert(&key_0, &key_0, hash_int, compare_ints);

    int key_1 = 21;
    ht->insert(&key_1, &key_1, hash_int, compare_ints);

    int key_2 = 37;
    ht->insert(&key_2, &key_2, hash_int, compare_ints);

    int key_3 = 53;
    ht->insert(&key_3, &key_3, hash_int, compare_ints);

    // A rehash will happen
    int key_4 = 69;
    ht->insert(&key_4, &key_4, hash_int, compare_ints);

    // Testing the effects of the rehash
    TEST_ASSERT(ht->getBucketsNum() == 32);
    TEST_ASSERT(ht->getHopInfoCapacity() == 6);

    int key_5 = 6;
    ht->insert(&key_5, &key_5, hash_int, compare_ints);

    int key_6 = 38;
    ht->insert(&key_6, &key_6, hash_int, compare_ints);

    int key_7 = 70;
    ht->insert(&key_7, &key_7, hash_int, compare_ints);

    int key_8 = 102;
    ht->insert(&key_8, &key_8, hash_int, compare_ints);

    int key_9 = 134;
    ht->insert(&key_9, &key_9, hash_int, compare_ints);

    int key_10 = 146;
    ht->insert(&key_10, &key_10, hash_int, compare_ints);

    int key_11 = 178;
    ht->insert(&key_11, &key_11, hash_int, compare_ints);

    // Testing the effects of the rehash
    TEST_ASSERT(ht->getBucketsNum() == 64);
    TEST_ASSERT(ht->getHopInfoCapacity() == 9);

    // filling the hash table till the rehash is triggered 64*0.7 = 44.8 which is about 45
    // 8 + 37 = 45
    int key[37];
    for(unsigned int i = 0; i < 37; i++)
    {
        key[i] = i;
        ht->insert(&key[i], &key[i], hash_int, compare_ints);
    }
    
    // Testing the effects of the rehash
    TEST_ASSERT(ht->getBucketsNum() == 128);
    TEST_ASSERT(ht->getHopInfoCapacity() == 12);

    delete ht;
}

void bulkSearchTest()
{
    HashTable *ht = new HashTable(16, true, 0.7, 3);

    int key_1 = 5;
    ht->insert(&key_1, &key_1, hash_int, compare_ints);

    int key_2 = 5;
    ht->insert(&key_2, &key_2, hash_int, compare_ints);

    // Testing how many times the item has been found
    List* fives = ht->bulkSearchKeys(&key_1, hash_int, compare_ints);
    TEST_ASSERT(fives->getCounter() == 2);

    // Testing if the correct item has been found at all times
    void* first_item = fives->getItemInPos(0);
    TEST_ASSERT((*(int *) first_item) == 5);

    void* second_item = fives->getItemInPos(1);
    TEST_ASSERT((*(int *) second_item) == 5);

    ht->terminateBulkSearchList(fives);

    delete ht;
}

// Λίστα με όλα τα tests προς εκτέλεση
TEST_LIST = {
	{ "Hash Insert",  insertWithoutRehashTest},
    { "Hash Rehash",  rehashTest},
    { "Hash Bulk Search",  bulkSearchTest},
	{ NULL, NULL } // τερματίζουμε τη λίστα με NULL
};