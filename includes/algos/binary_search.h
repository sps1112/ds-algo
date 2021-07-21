#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

// Searches for Val in the Array. Time=O(log n) Space=O(1)
template <typename T>
int binary_search(T *array, int length, T val, bool minSorted = true)
{
    int l = 0;
    int u = length - 1;
    int m = (l + u) / 2;
    while (array[m] != val)
    {
        if (l == u)
        {
            return -1;
        }
        if ((array[m] > val) == minSorted)
        {
            u = m - 1;
        }
        else
        {
            l = m + 1;
        }
        m = (l + u) / 2;
    }
    return m;
}

// Searches for Val in the Array. Time=O(log n) Space=O(1)
template <typename T>
int binary_search(Array<T> *array, T val, bool minSorted = true)
{
    int l = 0;
    int u = array->get_length() - 1;
    int m = (l + u) / 2;
    while (array->get_element(m) != val)
    {
        if (l == u)
        {
            return -1;
        }
        if ((array->get_element(m) > val) == minSorted)
        {
            u = m - 1;
        }
        else
        {
            l = m + 1;
        }
        m = (l + u) / 2;
    }
    return m;
}

// Searches for Val in the Array. Time=O(log n) Space=O(log n)
template <typename T>
int recursive_binary_search(T *array, int start, int end, T val, bool minSorted = true)
{
    if (end <= start)
    {
        return -1;
    }
    int m = (end + start) / 2;
    if (array[m] == val)
    {
        return m;
    }
    else if ((array[m] < val) == minSorted)
    {
        return recursive_binary_search(array, m + 1, end, val, minSorted);
    }
    else
    {
        return recursive_binary_search(array, start, m, val, minSorted);
    }
}

// Searches for Val in the Array. Time=O(log n) Space=O(log n)
template <typename T>
int recursive_binary_search(Array<T> *array, int start, int end, T val, bool minSorted = true)
{
    if (end <= start)
    {
        return -1;
    }
    int m = (end + start) / 2;
    if (array->get_element(m) == val)
    {
        return m;
    }
    else if ((array->get_element(m) < val) == minSorted)
    {
        return recursive_binary_search(array, m + 1, end, val, minSorted);
    }
    else
    {
        return recursive_binary_search(array, start, m, val, minSorted);
    }
}

#endif // BINARY_SEARCH_H
