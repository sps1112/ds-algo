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
    BST tree;
    tree.print_tree();
    float arr[] = {3, -5, 7, -7, 2, 5, 10, 2.5f, 4, 6, 9, 13, 11, 15};
    for (int i = 0; i < 14; i++)
    {
        tree.add_node(arr[i]);
    }
    tree.print_tree();
    std::cout << "Min is: " << tree.get_min_val() << " and Max is: " << tree.get_max_val() << std::endl;
    std::cout << "Is BST: " << tree.get_root()->is_binary_search_tree() << std::endl;
    tree.remove_node(13);
    tree.print_tree();
    std::cout << "Min is: " << tree.get_min_val() << " and Max is: " << tree.get_max_val() << std::endl;
    std::cout << "Is BST: " << tree.get_root()->is_binary_search_tree() << std::endl;
    print_binarytree_bfs(tree.get_root());
    print_binarytree_dfs(tree.get_root());
    print_binarytree_dfs(tree.get_root(), IN_ORDER_DFS);
    print_binarytree_dfs(tree.get_root(), POST_ORDER_DFS);
    Log("Finish");
}
