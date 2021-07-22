#ifndef HEAP_DS_H
#define HEAP_DS_H

// Custom Headers
#include <ds/arraylist.h>

// Standard Headers
#include <iostream>
#include <cmath>

// Template Heap Class
template <typename T>
class Heap
{
private:
    ArrayList<T> *arr; // ArrayList used to store the Heap values
    bool isMin;        // Whether Heap is a Min Heap or not

    // Gets the Index of the Parent Element
    int get_parent_index(int index)
    {
        return (index - 1) / 2;
    }

    // Gets the Index of the Child Element
    int get_child_index(int index, bool left)
    {
        int nIndex = (left) ? (index * 2 + 1) : (index * 2 + 2);
        return nIndex;
    }

    // Checks if the Index is Valid
    bool index_valid(int index)
    {
        return (index >= 0 && index < arr->get_length());
    }

    // For Min Heap: Smaller is True, For Max: Greater is True
    bool compare(T val1, T val2)
    {
        T diff = val1 - val2;
        return ((diff < 0) == isMin);
    }

    // Switches the Values in the 2 Indexes
    void switch_elements(int index1, int index2)
    {
        T val1 = arr->get_element(index1);
        T val2 = arr->get_element(index2);
        val1 = val1 + val2;
        val2 = val1 - val2;
        val1 = val1 - val2;
        arr->set_element(val1, index1);
        arr->set_element(val2, index2);
    }

    // Bubbles Up the Heap starting from given index
    void bubble_up(int index)
    {
        if (index_valid(index))
        {
            while (index != 0)
            {
                int pIndex = get_parent_index(index);
                if (!compare(arr->get_element(pIndex), arr->get_element(index)))
                {
                    switch_elements(pIndex, index);
                }
                else
                {
                    break;
                }
                index = pIndex;
            }
        }
    }

    // Bubbles Down the Heap starting from given index
    void bubble_down(int index)
    {
        while (index_valid(index))
        {
            int cIndex1 = get_child_index(index, true);
            int cIndex2 = get_child_index(index, false);
            if (index_valid(cIndex1))
            {
                int nIndex = cIndex1;
                if (index_valid(cIndex2))
                {
                    if (compare(arr->get_element(cIndex2), arr->get_element(cIndex1)))
                    {
                        nIndex = cIndex2;
                    }
                }
                if (compare(arr->get_element(nIndex), arr->get_element(index)))
                {
                    switch_elements(nIndex, index);
                    index = nIndex;
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }

    // Gets Number of Rows in the Heap
    int get_rows()
    {
        int rows = 0;
        int index = 0;
        int size = arr->get_length();
        while (index < size)
        {
            rows++;
            index += (int)(std::pow(2, rows - 1));
        }
        return rows;
    }

public:
    // Default Heap Constructor
    Heap()
    {
        arr = new ArrayList<T>(0);
        isMin = true;
    }

    // Array Heap Constructor
    Heap(T *array, int size)
    {
        arr = new ArrayList<T>(size);
        isMin = true;
        for (int i = 0; i < size; i++)
        {
            arr->add_element(array[i]);
            bubble_up(i);
        }
    }

    // Prints the Complete Heap
    void print_heap()
    {
        int rows = get_rows();
        int index = 0;
        int columns = 1;
        for (int i = 0; i < rows; i++)
        {
            std::cout << "[";
            for (int j = 0; j < columns; j++)
            {
                std::cout << arr->get_element(index);
                index++;
                if (index == arr->get_length())
                {
                    break;
                }
                if (j != columns - 1)
                {
                    std::cout << ", ";
                }
            }
            std::cout << "] ";
            columns *= 2;
        }
        std::cout << std::endl;
    }

    // Inserts a new value to the Heap
    void insert(T val)
    {
        arr->add_element(val);
        bubble_up(arr->get_length() - 1);
    }

    // Returns the Top element by removing it
    T poll()
    {
        T val = arr->get_element(0);
        switch_elements(0, arr->get_length() - 1);
        arr->remove_at_index(arr->get_length() - 1);
        bubble_down(0);
        return val;
    }

    // Returns the Top Element withour removing it
    T peek()
    {
        return arr->get_element(0);
    }

    // Removes the Val from the Heap
    void remove(T val)
    {
        int index = arr->get_index(val);
        if (index_valid(index))
        {
            switch_elements(index, arr->get_length() - 1);
            arr->remove_at_index(arr->get_length() - 1);
            bubble_up(index);
            bubble_down(index);
        }
    }

    // Removes the Val via a Hash Table
    void remove_hash(T val);

    // Checks if the Value is Contained in the Heap
    bool contains(T val)
    {
        return arr->contains(val);
    }

    // Checks if the Value is present via a Hash Table
    bool contains_hash(T val);

    // Converts Min Heap to Max Heap
    void to_max_heap();

    // Converts Max Heap to Min Heap
    void to_min_heap();
};

// Default Float Heap Class Type
using HeapF = Heap<float>;

#endif // HEAP_DS_H
