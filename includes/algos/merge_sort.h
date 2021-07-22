#ifndef MERGE_SORT_H
#define MERGE_SORT_H

// Custom Headers
#include <ds/arraylist.h>

// Sorts and Merges to sub arrays of the ArrayList i.e. [start1,end1)+[start2,end2)
template <typename T>
void sort_and_merge_arrays(ArrayList<T> *array, int start1, int end1, int start2, int end2, bool minSort = true)
{
    int index1 = start1;
    int index2 = start2;
    ArrayList<T> *nArray = new ArrayList<T>(end2 - start1);
    for (int i = start1; i < end2; i++)
    {
        T val1 = array->get_element(index1);
        T val2 = array->get_element(index2);
        int index = i;
        if (val1 != NULL && val2 != NULL)
        {
            if ((val1 < val2) == minSort)
            {
                index = index1;
                index1 = (index1 + 1 >= end1) ? -1 : (index1 + 1);
            }
            else
            {
                index = index2;
                index2 = (index2 + 1 >= end2) ? -1 : (index2 + 1);
            }
        }
        else
        {
            if (val1 == NULL)
            {
                index = index2;
                index2 = (index2 + 1 >= end2) ? -1 : (index2 + 1);
            }
            else
            {
                index = index1;
                index1 = (index1 + 1 >= end1) ? -1 : (index1 + 1);
            }
        }
        nArray->add_element(array->get_element(index));
    }
    for (int i = start1; i < end2; i++)
    {
        array->set_element(nArray->get_element(i - start1), i);
    }
    delete nArray;
}

// Sorts an ArrayList by using Merge Sort
template <typename T>
void merge_sort(ArrayList<T> *array, int start, int end, bool minSort = true)
{
    if (end - 1 <= start)
    {
        return;
    }
    int m = end - ((end - start) / 2);
    merge_sort(array, start, m, minSort);
    merge_sort(array, m, end, minSort);
    sort_and_merge_arrays(array, start, m, m, end, minSort);
}

#endif // MERGE_SORT_H
