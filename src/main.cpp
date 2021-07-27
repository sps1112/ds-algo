#include <iostream>
#include <string>
#include <ds/tree.h>

void Log(std::string message)
{
    std::cout << message.c_str() << std::endl;
}

int main()
{
    TNodeF root(0);
    root.print_tree();
    TNodeF node1(1);
    TNodeF node2(2);
    TNodeF node3(3);
    TNodeF node4(4);
    TNodeF node5(5);
    TNodeF node6(6);
    TNodeF node7(7);
    TNodeF node8(8);
    root.add_child(&node1);
    root.add_child(&node2);
    node1.add_child(&node3);
    node1.add_child(&node4);
    node2.add_child(&node5);
    node2.add_child(&node6);
    node5.add_child(&node7);
    node6.add_child(&node8);
    root.print_tree();
    node1.print_tree();
    node2.print_tree();
    node3.print_tree();
    TreeF tree;
    tree.set_root(&root);
    tree.print_tree();
    std::cout << tree.is_binary_tree() << std::endl;
    Log("Finish");
}
