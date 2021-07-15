#include <iostream>
#include <string>
#include <dynamicarray.h>

void Log(std::string message)
{
    std::cout << message.c_str() << std::endl;
}

int main()
{
    Array<float> arr;
    arr.add_element(2);
    arr.add_element(5);
    arr.add_element(6);
    arr.print_array();
    arr.remove_element(2);
    arr.add_element(-7);
    arr.add_element(11);
    arr.print_array();
    arr.remove_element(5);
    arr.remove_at_index(2);
    arr.add_element(-9);
    arr.add_element(-6);
    arr.print_array();
    std::cout << arr.get_element(-1) << std::endl;
}
