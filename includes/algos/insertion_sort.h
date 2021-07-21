#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include <ds/dynamicarray.h>

// Sorts a Dynamic Array using Insertion Sort
template <typename T>
void insertion_sort(Array<T> *array, bool minSort = true)
{
    int size = array->get_length();
    for (int i = 0; i < size; i++)
    {
        T val = array->get_element(i);
        int index = i;
        for (int j = i - 1; j >= 0; j--)
        {
            if (array->get_element(j) > val == minSort)
            {
                index = j;
                continue;
            }
            else
            {
                break;
            }
        }
        if (i != index)
        {
            array->remove_at_index(i);
            array->insert_at(val, index);
        }
    }
}

// Searches for insertion position via binary search
template <typename T>
int binary_search_insertion_sort(Array<T> *array, int start, int end, T val, bool minSort = true)
{
    if (end <= start)
    {
        if (array->get_element(start) == val)
        {
            return start;
        }
        if (array->get_element(start) > val == minSort)
        {
            return start;
        }
        else
        {
            return start + 1;
        }
    }
    int m = (start + end) / 2;
    if (array->get_element(m) == val)
    {
        return m;
    }
    if (array->get_element(m) > val == minSort)
    {
        return binary_search_insertion_sort(array, start, m, val, minSort);
    }
    else
    {
        return binary_search_insertion_sort(array, m + 1, end, val, minSort);
    }
}

// Sorts a Dynamic Array using Binary Insertion Sort
template <typename T>
void binary_insertion_sort(Array<T> *array, bool minSort = true)
{
    int size = array->get_length();
    for (int i = 0; i < size; i++)
    {
        T val = array->get_element(i);
        int index = binary_search_insertion_sort(array, 0, i, val, minSort);
        if (i != index)
        {
            array->remove_at_index(i);
            array->insert_at(val, index);
        }
    }
}

#endif // INSERTION_SORT_H
