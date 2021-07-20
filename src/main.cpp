#include <iostream>
#include <string>
#include <linkedlist.h>

void Log(std::string message)
{
    std::cout << message.c_str() << std::endl;
}

int main()
{
    DList list;
    list.add_val(1);
    list.add_val(3);
    list.add_val(5);
    list.add_val(-2);
    list.add_val(7);
    list.add_val(-3);
    list.print_list();
    list.reverse_list();
    list.print_list();
    Log("Finish");
}
