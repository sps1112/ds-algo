#ifndef TREE_DS_H
#define TREE_DS_H

// Custom Headers
#include <ds/treenode.h>

// Template Tree Class
template <typename T>
class Tree
{
private:
    TNode<T> *root; // The Root Node of the Tree

public:
    // Default Tree Constructor
    Tree()
    {
        root = NULL;
    }

    // Tree value constructor
    Tree(T val)
    {
        root = new TNode<T>(val);
    }

    // Checks if the Tree is Empty
    bool is_empty()
    {
        return (root == NULL);
    }

    // Prints the Complete Tree
    void print_tree()
    {
        if (!is_empty())
        {
            root->print_tree();
        }
    }

    // Sets the Root Value
    void set_root(TNode<T> *node)
    {
        root = node;
    }

    // Gets the Height of the Root Node of the Tree
    int get_height_tree()
    {
        if (!is_empty())
        {
            return root->get_height();
        }
    }

    // Checks if the Tree is a Binary Tree
    bool is_binary_tree()
    {
        return root->is_binary_tree();
    }
};
// Default Float Tree Class
using TreeF = Tree<float>;

#endif // TREE_DS_H
