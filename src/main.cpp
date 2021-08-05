#include <iostream>
#include <string>
#include <ds/binarytree.h>

BNodeF root(0);

void Log(std::string message)
{
    std::cout << message.c_str() << std::endl;
}

void print_status(BNodeF *node)
{
    std::cout << "Printing Status..." << std::endl;
    node->print_tree();
    std::cout << "Height of Tree is: " << node->get_height() << std::endl;
    std::cout << "MinHeight of Tree is: " << node->get_min_height() << std::endl;
    std::cout << "Depth from Root is: " << node->get_depth(&root) << std::endl;
    std::cout << "Number of Nodes: " << node->get_count() << std::endl;
    std::cout << "Strict Binary Tree: " << node->is_strict_binarytree() << std::endl;
    std::cout << "Complete Binary Tree: " << node->is_complete_binary_tree() << std::endl;
    std::cout << "Perfect Binary Tree: " << node->is_perfect_binary_tree() << std::endl;
    std::cout << "Balanced Binary Tree: " << node->is_balanced_binary_tree() << std::endl;
    std::cout << std::endl;
}

int main()
{
    print_status(&root);
    BNodeF nodes[22];
    for (int i = 0; i < 22; i++)
    {
        nodes[i].data = i + 1;
    }
    /*root.add_child(&nodes[0]);
    root.add_child(&nodes[1]);
    nodes[0].add_child(&nodes[2]);
    nodes[0].add_child(&nodes[3]);
    nodes[1].add_child(&nodes[4]);
    nodes[1].add_child(&nodes[5]);
    nodes[2].add_child(&nodes[6]);
    nodes[2].add_child(&nodes[7]);
    nodes[3].add_child(&nodes[8]);
    nodes[3].add_child(&nodes[9]);
    nodes[4].add_child(&nodes[10]);
    nodes[4].add_child(&nodes[11]);
    nodes[6].add_child(&nodes[12]);
    nodes[6].add_child(&nodes[13]);
    nodes[8].add_child(&nodes[14]);
    print_status(&root);
    print_status(&nodes[0]);
    print_status(&nodes[2]);
    print_status(&nodes[3]);
    print_status(&nodes[1]);
    print_status(&nodes[4]);
    print_status(&nodes[5]);*/
    root.add_child(&nodes[0]);
    root.add_child(&nodes[1]);
    nodes[0].add_child(&nodes[2]);
    nodes[0].add_child(&nodes[3]);
    nodes[1].add_child(&nodes[4]);
    nodes[1].add_child(&nodes[5]);
    nodes[3].add_child(&nodes[6], false);
    nodes[4].add_child(&nodes[7], false);
    nodes[5].add_child(&nodes[8], false);
    nodes[6].add_child(&nodes[9]);
    nodes[7].add_child(&nodes[10], false);
    nodes[8].add_child(&nodes[11]);
    nodes[8].add_child(&nodes[12]);
    nodes[9].add_child(&nodes[13], false);
    nodes[10].add_child(&nodes[14]);
    nodes[10].add_child(&nodes[15]);
    nodes[12].add_child(&nodes[16]);
    nodes[12].add_child(&nodes[17]);
    nodes[15].add_child(&nodes[18]);
    nodes[18].add_child(&nodes[19]);
    nodes[18].add_child(&nodes[20]);
    nodes[19].add_child(&nodes[21], false);
    print_status(&root);
    for (int i = 0; i < 22; i++)
    {
        print_status(&nodes[i]);
    }
    Log("Finish");
}
