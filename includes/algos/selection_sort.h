#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include <ds/dynamicarray.h>

// Sorts an Array by using Selection Sort
template <typename T>
void selection_sort(T *array, int size, bool minSort = true)
{
    for (int i = 0; i < size - 1; i++)
    {
        int index = i;
        T newVal = array[i];
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < newVal == minSort)
            {
                index = j;
                newVal = array[j];
            }
        }
        array[index] = array[i];
        array[i] = newVal;
    }
}

// Sorts a Dynamic Array using Selection Sort
template <typename T>
void selection_sort(Array<T> *array, bool minSort = true)
{
    int size = array->get_length();
    for (int i = 0; i < size - 1; i++)
    {
        int index = i;
        T newVal = array->get_element(i);
        for (int j = i + 1; j < size; j++)
        {
            if (array->get_element(j) < newVal == minSort)
            {
                index = j;
                newVal = array->get_element(j);
            }
        }
        array->set_element(array->get_element(i), index);
        array->set_element(newVal, i);
    }
}

#endif // SELECTION_SORT_H
