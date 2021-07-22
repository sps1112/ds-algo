#ifndef QUICK_SORT_H
#define QUICK_SORT_H

// Custom Headers
#include <ds/arraylist.h>

// Partitions the ArrayList around a pivotand gives the pivot index
template <typename T>
int partition(ArrayList<T> *array, int start, int end, bool minSort = true)
{
    T pivot = array->get_element(end - 1);
    int i = start - 1;
    for (int j = start; j < end; j++)
    {
        if (((array->get_element(j) < pivot) == minSort) && (array->get_element(j) != pivot))
        {
            i++;
            T temp = array->get_element(i);
            array->set_element(array->get_element(j), i);
            array->set_element(temp, j);
        }
    }
    T temp = array->get_element(i + 1);
    array->set_element(pivot, i + 1);
    array->set_element(temp, end - 1);
    return i + 1;
}

// Sorts an ArrayList by using Quick Sort
template <typename T>
void quick_sort(ArrayList<T> *array, int start, int end, bool minSort = true)
{
    if (start < end - 1)
    {
        int p = partition(array, start, end, minSort);
        quick_sort(array, start, p, minSort);
        quick_sort(array, p, end, minSort);
    }
}

#endif // QUICK_SORT_H