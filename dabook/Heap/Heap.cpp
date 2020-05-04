#include "Heap.h"

template<typename T>
void Heap<T>::Insert_minheap(T dat, HeapData<T>* heap)
{
    int i = 0;

    if(heap->size == 0)
    {
        heap->data.push_back(dat);
        heap->size++;
    }
    else
    {
        for(i = heap->size++;heap->data[i / 2] > dat; i /= 2)
            heap->data[i] = heap->data[i / 2];
        heap->data[i] = dat; 
    }
    
}
 
int main()
{
    HeapData<int> *heap_data = new HeapData<int>;
    Heap<int> heap;
    int A[10] = {1,5,0,3,456,13,56,70,34,546};
    for(int i = 0;i < 10; ++i)
    {
        heap.Insert_minheap(A[i],heap_data);
    }

    for(int i = 0;i < heap_data->size ;++i)
    {
        std::cout << "min heap:" << heap_data->data[i] << std::endl; 
    }
}