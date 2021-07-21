#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <ds/dynamicarray.h>

// Sorts an Array by using Bubble Sort
template <typename T>
void bubble_sort(T *array, int size, bool minSort = true)
{
    for (int i = 0; i < size - 1; i++)
    {
        bool swap = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j + 1] < array[j] == minSort)
            {
                T val = array[j + 1];
                array[j + 1] = array[j];
                array[j] = val;
                swap = true;
            }
        }
        if (!swap)
        {
            return;
        }
    }
}

// Sorts a Dynamic Array by using Bubble Sort
template <typename T>
void bubble_sort(Array<T> *array, bool minSort = true)
{
    int size = array->get_length();
    for (int i = 0; i < size - 1; i++)
    {
        bool swap = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array->get_element(j + 1) < array->get_element(j) == minSort)
            {
                T val = array->get_element(j + 1);
                array->set_element(array->get_element(j), j + 1);
                array->set_element(val, j);
                swap = true;
            }
        }
        if (!swap)
        {
            return;
        }
    }
}

#endif // BUBBLE_SORT_H
