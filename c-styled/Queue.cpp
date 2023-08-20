#include "Queue.h"

Queue::Queue()
{
    List();
}

Queue::~Queue()
{
    //this->clear_list();
}

void Queue::Enqueue(void* value)
{
    this->ListInsertLast(value);
}

void Queue::Dequeue()
{
    this->RemoveFirst();
}