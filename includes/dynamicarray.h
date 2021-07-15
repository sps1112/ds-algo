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
    int get_size()
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
        if (index < len)
        {
            return array[index];
        }
        return array[0];
    }

    // Sets the val for a given index
    void set_element(T val, int index)
    {
        if (index < len)
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
        if (contains(val))
        {
            for (int i = 0; i < len; i++)
            {
                if (array[i] == val)
                {
                    return i;
                }
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
            capacity = (capacity < 4) ? (capacity + 1) : (int)((float)capacity * 1.5f);
            T *tempArray;
            if ((len - 1) > 0)
            {
                tempArray = new T[len - 1];
                for (int i = 0; i < len - 1; i++)
                {
                    tempArray[i] = array[i];
                }
            }
            array = new T[capacity];
            for (int i = 0; i < len - 1; i++)
            {
                array[i] = tempArray[i];
            }
        }
        array[len - 1] = val;
    }

    // Removes a value at a given index
    void remove_at_index(int index)
    {
        if (index < len && index > 0)
        {
            if (len > 1)
            {
                T *tempArray = new T[len - 1];
                int tempIndex = 0;
                for (int i = 0; i < len; i++)
                {
                    if (i != index)
                    {
                        tempArray[tempIndex] = array[i];
                        tempIndex++;
                    }
                }
                for (int i = 0; i < len - 1; i++)
                {
                    array[i] = tempArray[i];
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
