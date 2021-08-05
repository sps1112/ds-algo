#ifndef BINARY_TREE_DS_H
#define BINARY_TREE_DS_H

// Custom Headers
#include <ds/treenode.h>

// Standard Headers
#include <iostream>
#include <cmath>

// Gets the Max Number of Nodes in a Level of a BinaryTree
int get_max_nodes_in_level(int level)
{
    if (level >= 0)
    {
        return (int)(pow(2, level));
    }
    return -1;
}

// Gets the Max Number of Nodes in a BinaryTree of given Height
int get_total_nodes_in_tree(int height)
{
    if (height >= 0)
    {
        return (int)((pow(2, height + 1)) - 1);
    }
    return -1;
}

// Gets the min height of a complete BinaryTree with the given number of nodes
int get_tree_height(int number)
{
    if (number > 0)
    {
        return (int)(log2(number));
    }
    return -1;
}

// Template Binary Tree Class
template <typename T>
class BinaryTree
{
private:
    BinaryNode<T> *root; // Root Node of the Binary Tree

public:
    // Default Binary Tree Constructor
    BinaryTree()
    {
        root = NULL;
    }

    // Binary Tree Value Constructor
    BinaryTree(T val)
    {
        root = new BinaryNode<T>(val);
    }

    // Checks if the Tree is Empty
    bool is_empty()
    {
        return (root == NULL);
    }

    // Prints the Complete Binary Tree
    void print_tree()
    {
        if (!is_empty())
        {
            root->print_tree();
        }
    }

    // Sets the Root Node of the Binary Tree
    void set_root(BinaryNode<T> *node)
    {
        root = node;
    }

    // Gets the Height of the Root of Binary Tree
    int get_height_tree()
    {
        if (!is_empty())
        {
            return root->get_height();
        }
    }

    // Checks if the complete has 0 or 2 childs for each node
    bool is_strict_bt()
    {
        return root->is_strict_binarytree();
    }

    // Checks if all the depth levels except the bottom is filled with left-most orientation
    bool is_complete_bt()
    {
        return root->is_complete_binary_tree();
    }

    // Checks if all the depth levels are filled
    bool is_perfect_bt()
    {
        return root->is_perfect_binary_tree();
    }

    // Checks if the Subtrees are balanced for each node
    bool is_balanced_bt()
    {
        return root->is_balanced_binary_tree();
    }
};

#endif // BINARY_TREE_DS_H
