//////////////////////////////////////////////////////////////////
//
// Unit tests για το Bitmap.
// Οποιαδήποτε υλοποίηση οφείλει να περνάει όλα τα tests.
//
//////////////////////////////////////////////////////////////////

#include "acutest.h"			// Απλή βιβλιοθήκη για unit testing
#include "Bitmap.h"
#include <iostream>

using namespace std;

void test_posOfFirstAce()
{
    Bitmap* b = new Bitmap(16);

    b->setBit(12);
    b->setBit(8);
    b->setBit(14);

    // the first one is in 8th position
    TEST_ASSERT(b->posOfFirstAce() == 8);

    b->setBit(6);

    // the first one is in 6th position
    TEST_ASSERT(b->posOfFirstAce() == 6);

    delete b;
}

void test_posOfFirstAce_from_Pos()
{
    Bitmap* b = new Bitmap(16);

    b->setBit(12);
    b->setBit(8);
    b->setBit(14);

    // the first one from the 9th position is the 12th one
    TEST_ASSERT(b->posOfFirstAceFromPos(9) == 12);
    // the first one from the 13th position is the 14th one
    TEST_ASSERT(b->posOfFirstAceFromPos(13) == 14);
    // the first one from the 1st position is the 8th one
    TEST_ASSERT(b->posOfFirstAceFromPos(1) == 8);

    b->setBit(6);

    // the first one from the 7th position is the 8th one
    TEST_ASSERT(b->posOfFirstAceFromPos(7) == 8);
    // the first one from the 1st position is the 6th one
    TEST_ASSERT(b->posOfFirstAceFromPos(1) == 6);

    delete b;
}

void test_reset_and_resize()
{
    Bitmap* b = new Bitmap(16);

    unsigned int i;
    // Setting all bits to 1
    for(i = 1; i <= 16; i++)
    {
        b->setBit(i);
    }

    // Resetting and Resizing to 32 
    b->resetAndChangeSize(32);

    // Reset and Change size resets all bits to zero.
    for(i = 1; i <= 32; i++)
    {
        TEST_ASSERT(b->isSet(i) == false);
    }

    delete b;
}

// Λίστα με όλα τα tests προς εκτέλεση
TEST_LIST = {
	{ "Position of first ace in Bitmap", test_posOfFirstAce},
    { "Position of first ace from given position in Bitmap", test_posOfFirstAce_from_Pos},
    { "Reset and resize Bitmap", test_reset_and_resize},
	{ NULL, NULL } // τερματίζουμε τη λίστα με NULL
};