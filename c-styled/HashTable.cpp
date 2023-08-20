#include "HashTable.h"

// Constructor
HashTable::HashTable(int capacity, double load_factor, bool rehash)
{
    this->buckets = new List* [capacity];
    // constructing each list of the array
    for(int i = 0; i < capacity; i++)
    {
        this->buckets[i] = new List();
    }
    this->num_of_elements = 0;
    this->load_factor = load_factor;
    this->capacity = capacity;
    this->rehash = rehash;
}

// Destructor
HashTable::~HashTable()
{
    // destroying each list of the array
    for(int i = 0; i < this->capacity; i++)
    {
        delete this->buckets[i];
    }
    delete[] this->buckets;
}

// changes wether the function should be rehashed or not (useful for rehashing)
void HashTable::set_rehash(bool rehash)
{
    this->rehash = rehash;
}

// returns the number of elements in the hash table
int HashTable::get_num_of_elements() const
{
    return this->num_of_elements;
}

// changes the number of buckets in the hash table
void HashTable::set_capacity(int c)
{
    this->capacity = c;
}

// returns the number of buckets in the hash table
int HashTable::get_capacity() const
{
    return this->capacity;
}

// cahnges the load factor of the hash table
void HashTable::set_load_factor(double lf)
{
    this->load_factor = lf;
}

// returns the load factor of the hash table
double HashTable::get_load_factor() const
{
    return this->load_factor;
}

// Inserts a value given accordingly using a given hash function 
void HashTable::Insert(void* value, int (*hash)(void*, int))
{
    // hashes to find the corret bucket for the value
    int index = hash(value, this->capacity);

    // insert the new element at the top of the bucket
    this->buckets[index]->ListInsertFirst(value);
    this->num_of_elements++;

    // getting the ratio (number of elements / capacity)
    double ratio = ((double) this->num_of_elements) / ((double) this->capacity);

    // before we rehash, if possible, we must ensure that the previous ratio is greater than the load factor of the hash table
    if((ratio >= this->load_factor) && this->rehash) this->Rehash(hash);
}

// Searches a value given accordingly using a given hash function
void* HashTable::Search_Element(void* value, int (*hash)(void*, int), int (*compare)(void*, void*))
{
    // hashes to find the corret bucket for the value
    int index = hash(value, this->capacity);
    // searches the chosen list and if it exists it is returned
    if(this->buckets[index]->ListSearch(value, compare)) return value;
    // otherwise, NULL is returned
    else return NULL;
}

// Searches a value given and returns the bucket it belongs accordingly using a given hash function
List* HashTable::Search_Bucket(void* value, int (*hash)(void*, int), int (*compare)(void*, void*))
{
    // hashes to find the corret bucket for the value
    int index = hash(value, this->capacity);
    // searches the chosen list and if it exists the bucket it belongs is returned
    if(this->buckets[index]->ListSearch(value, compare)) return this->buckets[index];
    // otherwise, NULL is returned
    else return NULL;  
}

// Removes a value given accordingly using a given hash function
void HashTable::Remove(void* value, int (*hash)(void*, int), int (*compare)(void*, void*))
{
    // if the element exists the bucket that contains it is returned in order for the removal to happen
    List* Bucket = this->Search_Bucket(value, hash, compare); 
    if(Bucket) 
    {
        Bucket->Remove(value, compare);
        this->num_of_elements--;
    }  
}

// function replaces the old one with a new one that has double the capacity of the old one
// Inserts every element of the old hashtable accordingly 
void HashTable::Rehash(int (*hash)(void*, int))
{
    // saving the old hash array to take its values
    List** old_hash = this->buckets;

    // saving the old capacity to traverse the old hash table
    int old_capacity = this->capacity;

    // doubling the capacity of the current hash function
    this->capacity = 2*(this->capacity);

    // the new hash table starts with nothing
    this->num_of_elements = 0;

    // we do not need to check for rehashes now that we are rehashing
    bool old_rehash = this->rehash;
    this->set_rehash(false);

    // creating the new hash table
    this->buckets  = new List* [this->capacity]; 
    for(int i = 0; i < capacity; i++)
    {
        this->buckets[i] = new List();
    }

    // getting the values from the old one and inserting them to the new one serially
    for(int i=0; i<old_capacity; i++)
    {
        ListNode* node = old_hash[i]->get_first();
        while(node)
        {
            if(node->get_value()) this->Insert(node->get_value(), hash);
            node = node->get_next();
        }
    }

    // returning the rehash flag to its previous state
    this->set_rehash(old_rehash);

    // deleting the old hash table
    for(int i=0; i<old_capacity; i++)
    {
        delete old_hash[i];
    }
    delete[] old_hash;
}

// Prints the hash table
void HashTable::Print(void (*visit)(void*))
{
    // prints buckets serially
    for(int i = 0; i < this->capacity; i++)
    {
        cout << i << ": ";
        // we will print in the list only if the elements exist
        if(this->buckets[i]->get_size()) 
        this->buckets[i]->print1(visit);
        cout << endl;
    }
}
