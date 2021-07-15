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
        len = (size < 0) ? 0 : size;
        capacity = (len == 0) ? 1 : len;
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
        if (len > 0)
        {
            std::cout << "(" << array[0];
            for (int i = 1; i < len; i++)
            {
                std::cout << ", " << array[i];
            }
            std::cout << ")" << std::endl;
        }
        else
        {
            std::cout << "Array is Empty!" << std::endl;
        }
    }

    // Checks if the value is present in the Array
    bool contains(T val)
    {
        for (int i = 0; i < len; i++)
        {
            if (array[i] == val)
            {
                return true;
            }
        }
        return false;
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
    T *array;
    int len;
    int capacity;
};

#endif // DYANAMIC_ARRAY_H
