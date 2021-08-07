#include <iostream>
#include <string>
#include <ds/binarytree.h>

void Log(std::string message)
{
    std::cout << message.c_str() << std::endl;
}

int main()
{
    BST tree;
    tree.print_tree();
    std::cout << "Min is: " << tree.get_min_val() << " and Max is: " << tree.get_max_val() << std::endl;
    float arr[] = {3, -5, 8, -7, 2, 6, 10, 2.5f, 5, 7, 9, 11};
    for (int i = 0; i < 12; i++)
    {
        tree.add_node(arr[i]);
    }
    tree.print_tree();
    std::cout << "Min is: " << tree.get_min_val() << " and Max is: " << tree.get_max_val() << std::endl;
    tree.remove_node(6);
    tree.print_tree();
    tree.add_node(4);
    tree.add_node(-8);
    tree.add_node(13);
    tree.print_tree();
    std::cout << "Contains 7: " << tree.contains_node(7) << std::endl;
    std::cout << "Min is: " << tree.get_min_val() << " and Max is: " << tree.get_max_val() << std::endl;
    Log("Finish");
}
