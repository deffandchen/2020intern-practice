#ifndef _HEAP_H
#define _HEAP_H
#include<iostream>
#include<vector>
using namespace std;

//define data structure
template <typename T>
struct HeapData
{
    /* data */
    int size = 0;
    vector<T> data;
};

//define heap class and function
template <typename T>
class Heap
{
private:
    /* data */

public:
    void Insert_minheap(T dat, HeapData<T>* heap);
    void DeleteMin();
};

#endif