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
    std::cout << "Is List Empty: " << list.is_empty() << std::endl;
    list.insert_at(9, 0);
    list.add_val(5);
    list.add_val(-3);
    list.add_val(8);
    list.print_list();
    std::cout << "Number of Elements: " << list.get_count() << std::endl;
    list.clear_list();
    list.print_list();
    list.add_val(11);
    list.add_val(-8);
    list.add_val(5);
    list.add_val(-2);
    list.add_val(10.3);
    list.print_list();
    std::cout << "Is -8 Present: " << list.contains_val(-8) << std::endl;
    list.set_val_at_index(8, 1);
    list.print_list();
    std::cout << "Is -8 Present: " << list.contains_val(-8) << std::endl;
    std::cout << "Index of 5 is: " << list.get_index_of(5) << std::endl;
    std::cout << "Element at index 3 is: " << list.get_at_index(3)->data << std::endl;
    list.insert_at(3, 4);
    list.insert_at(-6, 0);
    list.insert_at(-4.2, 0);
    list.insert_at(15, 50);
    list.insert_at(9.2, 9);
    list.print_list();
    list.remove_at(4);
    list.remove_end();
    list.remove_end();
    list.remove_val(-6);
    list.remove_val(1);
    list.print_list();
    list.to_dynamic_array()->print_array();
}
