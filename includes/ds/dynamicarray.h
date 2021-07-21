#ifndef DYNAMIC_ARRAY_DS_H
#define DYNAMIC_ARRAY_DS_H

#include <iostream>

// The Template Dyanmic Array Class
template <typename T>
class Array
{
private:
    T *array;     // The Array List
    int len;      // Length of the Array
    int capacity; // Max Size of the Array

public:
    // Constructor to initialize the array with a Size
    Array(int size = 0)
    {
        len = 0;
        capacity = (size == 0) ? 1 : size;
        array = new T[capacity];
    }

    // Constructor to initialize the array with another array
    Array(T arr[], int n)
    {
        len = 0;
        capacity = (n == 0) ? 1 : n;
        array = new T[capacity];
        for (int i = 0; i < n; i++)
        {
            add_element(arr[i]);
        }
    }

    // Returns the Length of the Array
    int get_length()
    {
        return len;
    }

    // Checks if the Array is empty
    bool is_empty()
    {
        return (len == 0);
    }

    // Gets the Element by an index
    T get_element(int index)
    {
        if (index < len && index >= 0)
        {
            return array[index];
        }
        return NULL;
    }

    // Sets the val for a given index
    void set_element(T val, int index)
    {
        if (index < len && index >= 0)
        {
            array[index] = val;
        }
    }

    // Clears the Array
    void clear_array()
    {
        len = 0;
    }

    // Prints the Array
    void print_array()
    {
        std::cout << "(";
        for (int i = 0; i < len; i++)
        {
            std::cout << array[i];
            if (i != len - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << ")" << std::endl;
    }

    // Returns the Index of a Given value
    int get_index(T val)
    {
        for (int i = 0; i < len; i++)
        {
            if (array[i] == val)
            {
                return i;
            }
        }
        return -1;
    }

    // Checks if the value is present in the Array
    bool contains(T val)
    {
        return (get_index(val) != -1);
    }

    // Adds a Element ot the Array
    void add_element(T val)
    {
        len++;
        if (capacity == len - 1)
        {
            capacity *= 2;
            T *tempArray = new T[capacity];
            for (int i = 0; i < len - 1; i++)
            {
                tempArray[i] = array[i];
            }
            array = tempArray;
        }
        array[len - 1] = val;
    }

    // Inserts an element at the middle of the array
    void insert_at(T val, int index)
    {
        if (index <= len && index >= 0)
        {
            add_element(val);
            T temp = get_element(index);
            for (int i = index + 1; i < len; i++)
            {
                T nTemp = get_element(i);
                set_element(temp, i);
                temp = nTemp;
            }
            set_element(val, index);
        }
    }

    // Removes a value at a given index
    void remove_at_index(int index)
    {
        if (index < len && index >= 0)
        {
            if (len > 1)
            {
                for (int i = index; i < len - 1; i++)
                {
                    array[i] = array[i + 1];
                }
            }
            len--;
        }
    }

    // Remove the val from the Array
    void remove_element(T val)
    {
        if (contains(val))
        {
            remove_at_index(get_index(val));
        }
    }

    // Sets the Memory capacity to the Length
    void trim_array()
    {
        capacity = (len == 0) ? 1 : len;
        T *tempArray = new T[capacity];
        for (int i = 0; i < len; i++)
        {
            tempArray[i] = array[i];
        }
        array = tempArray;
    }
};

// Returns a sub array of Array from [start,end)
template <typename T>
Array<T> *get_subarray(Array<T> *array, int start, int end)
{
    if (start >= 0 && end <= array->get_length() && start < end)
    {
        int nLen = end - start - 1;
        Array<T> *nArray = new Array<T>(nLen);
        for (int i = start; i < end; i++)
        {
            nArray->add_element(array->get_element(i));
        }
        return nArray;
    }
    return NULL;
}

// Returns a merged array of from [array1->array2]
template <typename T>
Array<T> *merge_arrays(Array<T> *array1, Array<T> *array2)
{
    int len1 = array1->get_length();
    int len2 = array2->get_length();
    Array<T> *array = new Array<T> *(len1 + len2);
    for (int i = 0; i < len1 + len2; i++)
    {
        array->add_element(((i < len1) ? (array1->get_element(i)) : (array2->get_element(i - len1))));
    }
    return array;
}

#endif // DYANAMIC_ARRAY_DS_H
