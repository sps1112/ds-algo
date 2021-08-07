#ifndef TREE_NODE_DS_H
#define TREE_NODE_DS_H

// Custom Headers
#include <ds/arraylist.h>

// Standard Headers
#include <iostream>
#include <limits>

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
        std::cout << "|-->" << data << std::endl;
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

    // Returns the number of Nodes in this SubTree
    int get_count()
    {
        if (is_leaf_node())
        {
            return 1;
        }
        int count = 1;
        int size = childrenList->get_length();
        for (int i = 0; i < size; i++)
        {
            count += childrenList->get_element(i)->get_count();
        }
        return count;
    }
};
// Default Float Tree Node
using TNodeF = TNode<float>;

// Template Binary Tree Node
template <typename T>
struct BinaryNode
{
    T data;               // Data stored in the Node
    BinaryNode<T> *left;  // Pointer to Left Child of the Node
    BinaryNode<T> *right; // Pointer to Right Child of the Node

    // Default Binary Node Constructor
    BinaryNode() : left(NULL), right(NULL) {}

    // Binary Node Value Constructor
    BinaryNode(T data_) : data(data_), left(NULL), right(NULL) {}

    // Prints the Binary Tree
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
        std::cout << "|-->" << data << std::endl;
        n += 4;
        if (!is_leaf_node())
        {
            if (left != NULL)
            {
                left->print_tree(n);
            }
            else
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
                std::cout << "|-->" << std::endl;
            }
            if (right != NULL)
            {
                right->print_tree(n);
            }
        }
        if (n == 4)
        {
            std::cout << "------------" << std::endl;
        }
    }

    // Adds a Child to the Node
    void add_child(BinaryNode<T> *child, bool onLeft = true)
    {
        if (onLeft)
        {
            if (left == NULL)
            {
                left = child;
            }
            else if (right == NULL)
            {
                right = child;
            }
            else
            {
                std::cout << "Child Already Set!" << std::endl;
            }
        }
        else
        {
            if (right == NULL)
            {
                right = child;
            }
            else if (left == NULL)
            {
                left = child;
            }
            else
            {
                std::cout << "Child Already Set!" << std::endl;
            }
        }
    }

    // Checks if the Node is a Leaf Node
    bool is_leaf_node()
    {
        return ((left == NULL) && (right == NULL));
    }

    // Checks if the test Node is child of Node
    bool is_child(BinaryNode<T> *testNode)
    {
        return ((testNode == left) || (testNode == right));
    }

    // Checks if the testNode is a Descendant of Node
    bool is_descendant(BinaryNode<T> *testNode)
    {
        if (is_leaf_node())
        {
            return false;
        }
        if (is_child(testNode))
        {
            return true;
        }
        if (left != NULL)
        {
            if (left->is_descendant(testNode))
            {
                return true;
            }
        }
        if (right != NULL)
        {
            if (right->is_descendant(testNode))
            {
                return true;
            }
        }
        return false;
    }

    // Gets the depth of the Node from a defined Root Node
    int get_depth(BinaryNode<T> *root)
    {
        if (this == root)
        {
            return 0;
        }
        if (root->is_leaf_node())
        {
            return -1;
        }
        if (root->is_child(this))
        {
            return 1;
        }
        int depth = -1;
        if (root->left != NULL)
        {
            int testDepth = get_depth(root->left);
            if (testDepth != -1)
            {
                depth = 1 + testDepth;
            }
        }
        if (depth == -1)
        {
            if (root->right != NULL)
            {
                int testDepth = get_depth(root->right);
                if (testDepth != -1)
                {
                    depth = 1 + testDepth;
                }
            }
        }
        return depth;
    }

    // Gets the Max Height of the Tree from Node to farthest LeafNode
    int get_height()
    {
        if (is_leaf_node())
        {
            return 0;
        }
        int maxHeight = 0;
        if (left != NULL)
        {
            int height = 1 + left->get_height();
            if (height > maxHeight)
            {
                maxHeight = height;
            }
        }
        if (right != NULL)
        {
            int height = 1 + right->get_height();
            if (height > maxHeight)
            {
                maxHeight = height;
            }
        }
        return maxHeight;
    }

    // Gets the Min height of the Tree from Node to closes LeafNode
    int get_min_height()
    {
        if (is_leaf_node())
        {
            return 0;
        }
        int minHeight = -1;
        if (left != NULL)
        {
            int height = 1 + left->get_min_height();
            minHeight = height;
        }
        if (right != NULL)
        {
            int height = 1 + right->get_min_height();
            if (height < minHeight || minHeight == -1)
            {
                minHeight = height;
            }
        }
        return minHeight;
    }

    // Gets the Number of Nodes in the Binary Tree
    int get_count()
    {
        if (is_leaf_node())
        {
            return 1;
        }
        int count = 1;
        if (left != NULL)
        {
            count += left->get_count();
        }
        if (right != NULL)
        {
            count += right->get_count();
        }
        return count;
    }

    // Checks if the Tree nodes have either 0 or 2 child
    bool is_strict_binarytree()
    {
        if (is_leaf_node())
        {
            return true;
        }
        if (left == NULL || right == NULL)
        {
            return false;
        }
        bool status = false;
        status = left->is_strict_binarytree();
        if (status)
        {
            status = right->is_strict_binarytree();
        }
        return status;
    }

    // Checks if the SubTree has all depth levels filled except last with left orientation
    bool is_complete_binary_tree(int index = 0, int count = 0)
    {
        if (count == 0)
        {
            count = get_count();
        }
        if (index >= count)
        {
            return false;
        }
        if (is_leaf_node())
        {
            return true;
        }
        if (left == NULL)
        {
            return false;
        }
        bool status = left->is_complete_binary_tree(index * 2 + 1, count);
        if (status)
        {
            if (right != NULL)
            {
                status = right->is_complete_binary_tree(index * 2 + 2, count);
            }
        }
        return status;
    }

    // Checks if all the depth levels are completely filled
    bool is_perfect_binary_tree()
    {
        int count = get_count();
        int h = get_tree_height(count);
        return (count == get_total_nodes_in_tree(h));
    }

    // Checks if the Binary Tree is Balanced
    bool is_balanced_binary_tree()
    {
        if (is_leaf_node())
        {
            return true;
        }
        int leftMaxH = -1;
        int rightMaxH = -1;
        int leftMinH = -1;
        int rightMinH = -1;
        if (left != NULL)
        {
            leftMaxH = left->get_height();
            leftMinH = left->get_min_height();
        }
        if (right != NULL)
        {
            rightMaxH = right->get_height();
            rightMinH = right->get_min_height();
        }
        return (abs(rightMaxH - leftMinH) <= 1 && abs(leftMaxH - rightMinH) <= 1);
    }

    // Checks if the Binary Tree is a Binary Search Tree
    bool is_binary_search_tree(T lowerBound = 0, T upperBound = 0, bool isRoot = true)
    {
        if (isRoot)
        {
            isRoot = false;
            lowerBound = std::numeric_limits<T>::min();
            upperBound = std::numeric_limits<T>::max();
            if (!is_balanced_binary_tree())
            {
                return false;
            }
        }
        // std::cout << "Lower: " << lowerBound << "  ,  Data: " << data << "  ,  Upper: " << upperBound << std::endl;
        if (data > upperBound || data < lowerBound)
        {
            return false;
        }
        bool status = true;
        if (left != NULL)
        {
            status = left->is_binary_search_tree(lowerBound, data, isRoot);
            if (!status)
            {
                return false;
            }
        }
        if (left == NULL || status)
        {
            if (right != NULL)
            {
                status = right->is_binary_search_tree(data, upperBound, isRoot);
            }
        }
        return status;
    }
};
// Default Float Binary Tree Node
using BNodeF = BinaryNode<float>;

#endif // TREE_NODE_DS_H
