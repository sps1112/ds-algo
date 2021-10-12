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

    // Returns the Root Node Pointer
    BinaryNode<T> *get_root()
    {
        return root;
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

// Template Binary Search Tree Class
template <typename T>
class BinarySearchTree
{
private:
    BinaryNode<T> *root; // Root Node of BST

    // Adds a Node to the BST
    void add_to_tree(BinaryNode<T> *node)
    {
        bool nodeSet = false;
        BinaryNode<T> *current = root;
        while (!nodeSet)
        {
            if (node->data <= current->data)
            {
                if (current->left != NULL)
                {
                    current = current->left;
                }
                else
                {
                    current->left = node;
                    nodeSet = true;
                }
            }
            else
            {
                if (current->right != NULL)
                {
                    current = current->right;
                }
                else
                {
                    current->right = node;
                    nodeSet = true;
                }
            }
        }
    }

public:
    // Default BST Constructor
    BinarySearchTree()
    {
        root = NULL;
    }

    // BST Value Constructor
    BinarySearchTree(T val)
    {
        root = new BinaryNode<T>(val);
    }

    // Checks if the BST is Empty
    bool is_empty()
    {
        return (root == NULL);
    }

    // Prints the Complete BST
    void print_tree()
    {
        if (!is_empty())
        {
            root->print_tree();
        }
    }

    // Sets the Root Node of the BST
    void set_root(BinaryNode<T> *node)
    {
        root = node;
    }

    // Returns the Root Node Pointer
    BinaryNode<T> *get_root()
    {
        return root;
    }

    // Adds a Node to the BST
    void add_node(T val)
    {
        BinaryNode<T> *node = new BinaryNode<T>(val);
        if (is_empty())
        {
            set_root(node);
        }
        else
        {
            add_to_tree(node);
        }
    }

    // Checks if the Node is Present in the Tree
    bool contains_node(T val)
    {
        bool foundNode = false;
        BinaryNode<T> *current = root;
        while (!foundNode)
        {
            if (val == current->data)
            {
                foundNode = true;
            }
            else
            {
                if (val < current->data)
                {
                    if (current->left != NULL)
                    {
                        current = current->left;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    if (current->right != NULL)
                    {
                        current = current->right;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        return foundNode;
    }

    // Removes the Node if Present in the Tree
    void remove_node(T val)
    {
        if (!is_empty())
        {
            bool foundNode = false;
            BinaryNode<T> *current = root;
            BinaryNode<T> *parent = root;
            bool isLeft = false;
            while (!foundNode)
            {
                if (val == current->data)
                {
                    foundNode = true;
                }
                else
                {
                    if (val < current->data)
                    {
                        if (current->left != NULL)
                        {
                            parent = current;
                            isLeft = true;
                            current = current->left;
                        }
                        else
                        {
                            break;
                        }
                    }
                    else
                    {
                        if (current->right != NULL)
                        {
                            parent = current;
                            isLeft = false;
                            current = current->right;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
            if (foundNode)
            {
                BinaryNode<T> *leftChild = current->left;
                BinaryNode<T> *rightChild = current->right;
                if (leftChild == NULL || rightChild == NULL)
                {
                    if (isLeft)
                    {
                        parent->left = NULL;
                    }
                    else
                    {
                        parent->right = NULL;
                    }
                    if (!current->is_leaf_node())
                    {
                        if (isLeft)
                        {
                            parent->left = (leftChild == NULL) ? rightChild : leftChild;
                        }
                        else
                        {
                            parent->right = (leftChild == NULL) ? rightChild : leftChild;
                        }
                    }
                    delete current;
                }
                else
                {
                    BinarySearchTree bst1, bst2;
                    bst1.set_root(current);
                    bst2.set_root(current->right);
                    T min = bst2.get_min_val();
                    bst1.remove_node(min);
                    current->data = min;
                }
            }
        }
    }

    // Gets the Minimum Val in BST
    T get_min_val()
    {
        BinaryNode<T> *current = root;
        while (current != NULL)
        {
            if (current->left == NULL)
            {
                return current->data;
            }
            current = current->left;
        }
        return NULL;
    }

    // Gets the Maximum Val in BST
    T get_max_val()
    {
        BinaryNode<T> *current = root;
        while (current != NULL)
        {
            if (current->right == NULL)
            {
                return current->data;
            }
            current = current->right;
        }
        return NULL;
    }
};
// Default Float Binary Search Tree Class
using BST = BinarySearchTree<float>;

template <typename T>
int get_inorder_successor(BinaryNode<T> *root)
{
}

#endif // BINARY_TREE_DS_H
