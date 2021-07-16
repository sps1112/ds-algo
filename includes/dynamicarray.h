#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <iostream>

// The Template Dyanmic Array Class
template <typename T>
class Array
{
public:
    // Constructor to initialize the array with a Size
    Array(int size = 0)
    {
        len = 0;
        capacity = (size == 0) ? 1 : size;
        array = new T[capacity];
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

private:
    T *array;     // The Array List
    int len;      // Length of the Array
    int capacity; // Max Size of the Array
};

#endif // DYANAMIC_ARRAY_H
