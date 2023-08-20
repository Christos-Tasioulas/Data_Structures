#ifndef QUEUE
#define QUEUE
#include "List.h"

class Queue : public List 
{
public:
    Queue();
    ~Queue();
    void Enqueue(void* value);
    void Dequeue();
};

#endif