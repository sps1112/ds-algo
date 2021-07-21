#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H

#include <ds/dynamicarray.h>

// Searches for Val in the Array. Time=O(n) Space=O(1)
template <typename T>
int linear_search(T array[], int length, T val)
{
    for (int i = 0; i < length; i++)
    {
        if (array[i] == val)
        {
            return i;
        }
    }
    return -1;
}

// Searches for Val in the Array. Time=O(n) Space=O(1)
template <typename T>
int linear_search(Array<T> *array, T val)
{
    int length = array->get_length();
    for (int i = 0; i < length; i++)
    {
        if (array->get_element(i) == val)
        {
            return i;
        }
    }
    return -1;
}

#endif // LINEAR_SEARCH_H
