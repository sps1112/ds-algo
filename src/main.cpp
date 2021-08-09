#include <iostream>
#include <string>
#include <ds/treenode.h>
#include <ds/binarytree.h>
#include <algos/tree_traversal.h>

void Log(std::string message)
{
    std::cout << message.c_str() << std::endl;
}

int main()
{
    /*TNodeF root(0);
    TNodeF nodes[8];
    for (int i = 0; i < 7; i++)
    {
        nodes[i].data = 2 * i + 1;
    }
    root.add_child(&nodes[0]);
    root.add_child(&nodes[1]);
    root.add_child(&nodes[2]);
    nodes[0].add_child(&nodes[3]);
    nodes[0].add_child(&nodes[4]);
    nodes[2].add_child(&nodes[5]);
    nodes[5].add_child(&nodes[6]);
    root.print_tree();
    print_tree_bfs(&root);*/
    BST tree;
    tree.print_tree();
    // std::cout << "Min is: " << tree.get_min_val() << " and Max is: " << tree.get_max_val() << std::endl;
    float arr[] = {3, -5, 8, -7, 2, 6, 10, 2.5f, 5, 7, 9, 11};
    for (int i = 0; i < 12; i++)
    {
        tree.add_node(arr[i]);
    }
    tree.print_tree();
    /*std::cout << "Min is: " << tree.get_min_val() << " and Max is: " << tree.get_max_val() << std::endl;
    tree.remove_node(6);
    tree.print_tree();
    tree.add_node(4);
    tree.add_node(-8);
    tree.add_node(13);
    tree.print_tree();
    std::cout << "Contains 7: " << tree.contains_node(7) << std::endl;
    std::cout << "Min is: " << tree.get_min_val() << " and Max is: " << tree.get_max_val() << std::endl;*/
    print_binarytree_bfs(tree.get_root());
    print_binarytree_dfs(tree.get_root());
    print_binarytree_dfs(tree.get_root(), IN_ORDER_DFS);
    print_binarytree_dfs(tree.get_root(), POST_ORDER_DFS);
    Log("Finish");
}
