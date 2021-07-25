#include <iostream>
#include <string>
#include <ds/linkedlist.h>

void Log(std::string message)
{
    std::cout << message.c_str() << std::endl;
}

int main()
{
    /*int array[] = {1, 3, 5, 7, 9,
                   0, 2, 4, 6, 8,
                   -1, -3, -5, -7, -9,
                   -2, -4, -6, -8, -10};*/
    DList list;
    list.print_list();
    for (int i = 0; i < 20; i++)
    {
        // list.add_val(array[i]);
        list.add_val(i);
        list.reverse_list();
    }
    list.print_list();
    list.insert_at(12, 20);
    list.print_list();
    list.reverse_list();
    list.print_list();
    std::cout << "Head is: " << list.peek() << " and Tail is: " << list.peek(false) << std::endl;
    list.remove_at(20);
    list.add_val(11);
    list.print_list();
    std::cout << "Head is: " << list.peek() << " and Tail is: " << list.peek(false) << std::endl;
    list.reverse_list();
    list.print_list();
    std::cout << "Head is: " << list.peek() << " and Tail is: " << list.peek(false) << std::endl;
    Log("Finish");
}
