#include <iostream>
#include <string>
#include <linkedlist.h>

void Log(std::string message)
{
    std::cout << message.c_str() << std::endl;
}

int main()
{
    List list;
    list.print_list();
    std::cout << list.is_empty() << std::endl;
    list.add_val(5);
    list.add_val(-3);
    list.add_val(8);
    list.print_list();
    std::cout << list.get_count() << std::endl;
    list.clear_list();
    list.print_list();
    list.add_val(11);
    list.add_val(-8);
    list.add_val(5);
    list.add_val(-2);
    list.add_val(10);
    list.print_list();
}
