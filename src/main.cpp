#include <iostream>
#include <string>
#include <ds/array2d.h>
#include <ds/dynamicarray.h>

void Log(std::string message)
{
    std::cout << message.c_str() << std::endl;
}

int main()
{
    int array[] = {1, 3, 5, 7, 9,
                   0, 2, 4, 6, 8,
                   -1, -3, -5, -7, -9,
                   -2, -4, -6, -8, -10};
    Array2D<int> arr(array, 18, 4, 5);
    arr.print_array();
    std::cout << arr.get_total_length() << " " << arr.get_length(1) << " " << arr.get_length(0) << std::endl;
    std::cout << arr.get_element(1, 3) << std::endl;
    arr.set_element(0, 2, 2);
    arr.print_array();

    Array<int> array2(arr.get_row(0), arr.get_length(0));
    array2.print_array();

    Array<int> array3(arr.get_column(0), arr.get_length(1));
    array3.print_array();

    std::cout << "Index of -3 is: " << arr.get_index(-3) << std::endl;
    std::cout << "Column of -3 is: " << arr.get_position(-3, 0) << std::endl;
    std::cout << "Row of -3 is: " << arr.get_position(-3, 1) << std::endl;
    Log("Finish");
}
