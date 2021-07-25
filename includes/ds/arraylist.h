#ifndef ARRAY_LIST_DS_H
#define ARRAY_LIST_DS_H

// Standard Headers
#include <iostream>

// The Template ArrayList Class
template <typename T>
class ArrayList
{
private:
    T *array;     // The Array List
    int len;      // Length of the ArrayList
    int capacity; // Max Size of the ArrayList

public:
    // Constructor to initialize the ArrayList with a Size
    ArrayList(int size = 0)
    {
        len = 0;
        capacity = (size == 0) ? 1 : size;
        array = new T[capacity];
    }

    // Constructor to initialize the ArrayList with an array
    ArrayList(T arr[], int n)
    {
        len = 0;
        capacity = (n == 0) ? 1 : n;
        array = new T[capacity];
        for (int i = 0; i < n; i++)
        {
            add_element(arr[i]);
        }
    }

    // Returns the Length of the ArrayList
    int get_length()
    {
        return len;
    }

    // Checks if the ArrayList is empty
    bool is_empty()
    {
        return (len == 0);
    }

    // Checks if the given index is valid
    bool is_index_valid(int index)
    {
        return (index >= 0 && index < len);
    }

    // Gets the Element by an index
    T get_element(int index)
    {
        return ((is_index_valid(index)) ? array[index] : NULL);
    }

    // Sets the val for a given index
    void set_element(T val, int index)
    {
        array[index] = ((is_index_valid(index)) ? val : array[index]);
    }

    // Clears the ArrayList also freeing memory
    void clear_array()
    {
        len = 0;
        trim_array();
    }

    // Prints the ArrayList
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

    // Checks if the value is present in the ArrayList
    bool contains(T val)
    {
        return (get_index(val) != -1);
    }

    // Adds a Element ot the ArrayList
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
            delete array;
            array = tempArray;
        }
        array[len - 1] = val;
    }

    // Inserts an element at the middle of the ArrayList
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

    // Remove the val from the ArrayList
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
        delete array;
        array = tempArray;
    }
};

// Returns a sub array list of ArrayList from [start,end)
template <typename T>
ArrayList<T> *get_subarraylist(ArrayList<T> *array, int start, int end)
{
    if (start >= 0 && end <= array->get_length() && start < end)
    {
        int nLen = end - start - 1;
        ArrayList<T> *nArray = new ArrayList<T>(nLen);
        for (int i = start; i < end; i++)
        {
            nArray->add_element(array->get_element(i));
        }
        return nArray;
    }
    return NULL;
}

// Returns a merged ArrayList of from [array1->array2]
template <typename T>
ArrayList<T> *merge_arraylists(ArrayList<T> *array1, ArrayList<T> *array2)
{
    int len1 = array1->get_length();
    int len2 = array2->get_length();
    ArrayList<T> *array = new ArrayList<T> *(len1 + len2);
    for (int i = 0; i < len1 + len2; i++)
    {
        array->add_element(((i < len1) ? (array1->get_element(i)) : (array2->get_element(i - len1))));
    }
    return array;
}

// Default FLoat Array List Class
using Array = ArrayList<float>;

#endif // ARRAY_LIST_DS_H
