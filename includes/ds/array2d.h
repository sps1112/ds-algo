#ifndef ARRAY_2D_H
#define ARRAY_2D_H

// Custom Headers
#include <ds/arraylist.h>

// Standard Headers
#include <iostream>

// A Template 2D Array Class
template <typename T>
class Array2D
{
private:
    T *array;    // Internal 1D Array
    int rows;    // Number of Horizontal Rows
    int columns; // Number of Vertical Columns

public:
    // Default Array2D Constructor
    Array2D(int rows_ = 0, int columns_ = 0)
    {
        rows = rows_;
        columns = columns_;
        array = new T[rows * columns];
        for (int i = 0; i < rows * columns; i++)
        {
            array[i] = 0;
        }
    }

    // Array Contructor for the 2D Array
    Array2D(T arr[], int n, int rows_ = 0, int columns_ = 0)
    {
        rows = rows_;
        columns = columns_;
        array = new T[rows * columns];
        for (int i = 0; i < rows * columns; i++)
        {
            array[i] = (i < n) ? arr[i] : 0;
        }
    }

    // Returns the total number of elements in the array
    int get_total_length()
    {
        return rows * columns;
    }

    // Returns the length of an Array along an axis (0 => columns | 1 => rows)
    int get_length(int axis)
    {
        return ((axis == 0) ? columns : rows);
    }

    // Checks if the Array is empty
    bool is_empty()
    {
        return (get_total_length() == 0);
    }

    // Checks if the given index is valid
    bool is_index_valid(int y, int x)
    {
        return (y < rows && y >= 0 && x < columns && x >= 0);
    }

    // Gets the element at row=y and column=x
    T get_element(int y, int x)
    {
        if (is_index_valid(y, x))
        {
            return array[(y * columns) + x];
        }
        return NULL;
    }

    // Sets the value of the element stored at row=y and column=x
    void set_element(T val, int y, int x)
    {
        if (is_index_valid(y, x))
        {
            array[(y * columns) + x] = val;
        }
    }

    // Clears the array
    void clear_array()
    {
        rows = 0;
        columns = 0;
    }

    // Prints the Complete Array
    void print_array()
    {
        std::cout << "{";
        for (int y = 0; y < rows; y++)
        {
            std::cout << "(";
            for (int x = 0; x < columns; x++)
            {
                std::cout << array[y * columns + x];
                if (x != columns - 1)
                {
                    std::cout << ", ";
                }
            }
            std::cout << ")";
            if (y != rows - 1)
            {
                std::cout << ", " << std::endl;
                std::cout << " ";
            }
        }
        std::cout << "}" << std::endl;
    }

    // Returns the index of a value in the 2D Array
    int get_index(T val)
    {
        for (int i = 0; i < rows * columns; i++)
        {
            if (array[i] == val)
            {
                return i;
            }
        }
        return -1;
    }

    // Returns the positions along a axis of the value (0 => column | 1 => row)
    int get_position(T val, int axis = 0)
    {
        for (int y = 0; y < rows; y++)
        {
            for (int x = 0; x < columns; x++)
            {
                if (val == get_element(y, x))
                {
                    return (axis == 0) ? x : y;
                }
            }
        }
        return -1;
    }

    // Checks if the value is present in the 2D Array
    bool contains(T val)
    {
        return (get_index() != -1);
    }

    // Gets the Row as an Array (Starts from 0)
    T *get_row(int row)
    {
        T *arr = new T[columns];
        int y = row;
        for (int x = 0; x < columns; x++)
        {
            arr[x] = get_element(y, x);
        }
        return arr;
    }

    // Gets the Column as an Array(Starts from 0)
    T *get_column(int column)
    {
        T *arr = new T[rows];
        int x = column;
        for (int y = 0; y < rows; y++)
        {
            arr[y] = get_element(y, x);
        }
        return arr;
    }

    // Converts the 2D Array into an Array List
    ArrayList<T> *to_array_list()
    {
        int size = get_total_length();
        ArrayList<T> *list = new ArrayList<T>(size);
        for (int i = 0; i < size; i++)
        {
            list->add_element(array[i]);
        }
        return list;
    }
};

#endif // ARRAY_2D_H
