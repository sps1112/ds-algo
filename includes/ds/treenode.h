#ifndef TREE_NODE_DS_H
#define TREE_NODE_DS_H

// Custom Headers
#include <ds/arraylist.h>

// Template Tree Node Struct
template <typename T>
struct TNode
{
    T data;                              // Data Stored in the Node
    TNode<T> *parent;                    // Pointer to Parent Node
    ArrayList<TNode<T> *> *childrenList; // ArrayList Containing Pointers to all the Children Node

    // Default Tree Node Constructor
    TNode() : parent(NULL), childrenList(new ArrayList<TNode<T> *>()) {}

    //Tree Node Value Constructor
    TNode(T data_) : data(data_), parent(NULL), childrenList(new ArrayList<TNode<T> *>()) {}

    // Prints the Tree with this node acting as the Root Node
    void print_tree(int n = 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (i > n - 4 && i % 4 == 0)
            {
                std::cout << "|";
            }
            else
            {
                std::cout << " ";
            }
        }
        std::cout << "|---" << data << std::endl;
        n += 4;
        int size = childrenList->get_length();
        for (int i = 0; i < size; i++)
        {
            childrenList->get_element(i)->print_tree(n);
        }
        if (n == 4)
        {
            std::cout << "------------" << std::endl;
        }
    }

    // Adds a Child Node for the Tree Node
    void add_child(TNode<T> *child)
    {
        childrenList->add_element(child);
        child->parent = this;
    }

    // Checks if the Tree Node is Root Node
    bool is_root_node()
    {
        return (parent == NULL);
    }

    // Checks if the Node is a Leaf Node
    bool is_leaf_node()
    {
        return childrenList->is_empty();
    }

    // Checks if the testNode is the Child of Tree Node
    bool is_child(TNode<T> *testNode)
    {
        return childrenList->contains(*testNode);
    }

    // Checks if the testNode is the Parent of Tree Node
    bool is_parent(TNode<T> *testNode)
    {
        return (parent == testNode);
    }

    // Checks if the testNode has the same parent as Tree Node
    bool is_sibling(TNode<T> *testNode)
    {
        return (parent == testNode->parent);
    }

    // Checks if the testNode is an Ancestor of Tree Node
    bool is_ancestor(TNode<T> *testNode)
    {
        if (is_root_node())
        {
            return false;
        }
        if (is_parent(testNode))
        {
            return true;
        }
        return parent->is_ancestor(testNode);
    }

    // Checks if the testNode is a Descendant of Tree Node
    bool is_descendant(TNode<T> *testNode)
    {
        if (is_leaf_node())
        {
            return false;
        }
        if (is_child(testNode))
        {
            return true;
        }
        int size = childrenList->get_length();
        for (int i = 0; i < size; i++)
        {
            bool status = childrenList->get_element(i)->is_descendant(testNode);
            if (status)
            {
                return true;
            }
        }
        return false;
    }

    // Gets of the Depth of Tree Node from the Root Node
    int get_depth()
    {
        if (is_root_node())
        {
            return 0;
        }
        return 1 + parent->get_depth();
    }

    // Gets the Max Height of Tree Node from its descendant Leaf Nodes
    int get_height()
    {
        if (is_leaf_node())
        {
            return 0;
        }
        int size = childrenList->get_length();
        int maxHeight = 0;
        for (int i = 0; i < size; i++)
        {
            int testHeight = 1 + childrenList->get_element(i)->get_height();
            if (testHeight > maxHeight)
            {
                maxHeight = testHeight;
            }
        }
        return maxHeight;
    }

    // Checks if this node's subtree is a binary tree
    bool is_binary_tree()
    {
        if (is_leaf_node())
        {
            return true;
        }
        int size = childrenList->get_length();
        if (size <= 2)
        {
            for (int i = 0; i < size; i++)
            {
                return childrenList->get_element(i)->is_binary_tree();
            }
        }
        return false;
    }
};
// Default Float Tree Node Constructor
using TNodeF = TNode<float>;

#endif // TREE_NODE_DS_H
