#ifndef HASHTABLE
#define HASHTABLE

#include "List.h"

class HashTable
{
private:
    // a hash table is a dynamic array of lists
    List** buckets;
    // number of total elements in the data structure
    int num_of_elements;
    // number of lists
    int capacity;
    // a float that indicates the ratio between the number of buckets and the number of elements
    // is at about 75%
    // ratio = num_of_elements / capacity 
    double load_factor;
    
    // determines if the table will be rehashed or not
    bool rehash;

    // function replaces the old one with a new one that has double the capacity of the old one
    // Inserts every element of the old hashtable accordingly 
    void Rehash(int (*hash)(void*, int));

    // changes wether the function should be rehashed or not (useful for rehashing)
    void set_rehash(bool rehash);

public:
    // Constructor
    HashTable(int capacity, double load_factor, bool rehash);
    // Destructor
    ~HashTable();
    // returns the number of elements in the hash table
    int get_num_of_elements() const;
    // changes the number of buckets in the hash table
    void set_capacity(int c);
    // returns the number of buckets in the hash table
    int get_capacity() const;
    // cahnges the load factor of the hash table
    void set_load_factor(double lf);
    // returns the load factor of the hash table
    double get_load_factor() const;
    // Inserts a value given accordingly using a given hash function 
    void Insert(void* value, int (*hash)(void*, int));
    // Searches a value given and returns it accordingly using a given hash function
    void* Search_Element(void* value, int (*hash)(void*, int), int (*compare)(void*, void*));
    // Searches a value given and returns the bucket it belongs accordingly using a given hash function
    List* Search_Bucket(void* value, int (*hash)(void*, int), int (*compare)(void*, void*));
    // Removes a value given accordingly using a given hash function
    void Remove(void* value, int (*hash)(void*, int), int (*compare)(void*, void*));
    // Prints the hash table
    void Print(void (*visit)(void*));
};


#endif