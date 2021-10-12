#ifndef HEAP_SORT_H
#define HEAP_SORT_H

// Custom Headers
#include <ds/heap.h>
#include <ds/arraylist.h>

// Sorts an Array using Heap Sort
template <typename T>
void heap_sort(T array[], int n, bool minSort = true)
{
    Heap<T> heap;
    for (int i = 0; i < n; i++)
    {
        heap.insert((minSort) ? array[i] : -array[i]);
    }
    for (int i = 0; i < n; i++)
    {
        array[i] = heap.poll() * ((minSort) ? 1 : -1);
    }
}

// Sorts an ArrayList using Heap Sort
template <typename T>
void heap_sort(ArrayList<T> *array, bool minSort = true)
{
    Heap<T> heap;
    int n = array->get_length();
    for (int i = 0; i < n; i++)
    {
        heap.insert((minSort) ? array->get_element(i) : -array->get_element(i));
    }
    for (int i = 0; i < n; i++)
    {
        array->set_element(heap.poll() * ((minSort) ? 1 : -1), i);
    }
}

#endif // HEAP_SORT_H
