#ifndef TREE_TRAVERSAL_H
#define TREE_TRAVERSAL_H

// Custom Headers
#include <ds/treenode.h>
#include <ds/queue.h>

// Standard Headers
#include <iostream>

// Prints a Tree using BFS
template <typename T>
void print_tree_bfs(TNode<T> *root)
{
    Queue<TNode<T> *> nextNodes;
    nextNodes.enqueue(root);
    int level = 0;
    while (nextNodes.get_size() > 0)
    {
        int s = nextNodes.get_size();
        std::cout << "Level- " << level << "  |--> ";
        for (int i = 0; i < s; i++)
        {
            TNode<T> *node = nextNodes.dequeue();
            std::cout << node->data;
            int l = node->childrenList->get_length();
            for (int j = 0; j < l; j++)
            {
                nextNodes.enqueue(node->childrenList->get_element(j));
            }
            if (i != s - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
        level++;
    }
    std::cout << "------------" << std::endl;
    nextNodes.free_queue();
}

// Prints a Binary Tree using BFS
template <typename T>
void print_binarytree_bfs(BinaryNode<T> *root)
{
    Queue<BinaryNode<T> *> nextNodes;
    nextNodes.enqueue(root);
    int level = 0;
    while (nextNodes.get_size() > 0)
    {
        int s = nextNodes.get_size();
        std::cout << "Level- " << level << "  |--> ";
        for (int i = 0; i < s; i++)
        {
            BinaryNode<T> *node = nextNodes.dequeue();
            std::cout << node->data;
            if (node->left != NULL)
            {
                nextNodes.enqueue(node->left);
            }
            if (node->right != NULL)
            {
                nextNodes.enqueue(node->right);
            }
            if (i != s - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
        level++;
    }
    std::cout << "------------" << std::endl;
    nextNodes.free_queue();
}

// DFS TRAVERSAL MODES
enum DFS_MODE
{
    PRE_ORDER_DFS,
    IN_ORDER_DFS,
    POST_ORDER_DFS,
};

// Prints a Binary Tree using DFS
template <typename T>
void print_binarytree_dfs(BinaryNode<T> *root, DFS_MODE mode = PRE_ORDER_DFS, bool isFirst = true)
{
    switch (mode)
    {
    case PRE_ORDER_DFS:
        if (isFirst)
        {
            std::cout << "PreOrder: ";
        }
        std::cout << root->data;
        if (!root->is_leaf_node())
        {
            std::cout << " -> [";
            if (root->left != NULL)
            {
                print_binarytree_dfs(root->left, mode, false);
            }
            if (root->right != NULL)
            {
                std::cout << ", ";
                print_binarytree_dfs(root->right, mode, false);
            }
            std::cout << "]";
        }
        break;
    case IN_ORDER_DFS:
        if (isFirst)
        {
            std::cout << "InOrder: ";
        }
        if (!root->is_leaf_node())
        {
            std::cout << "[";
            if (root->left != NULL)
            {
                print_binarytree_dfs(root->left, mode, false);
                std::cout << " -> ";
            }
            std::cout << root->data;
            if (root->right != NULL)
            {
                std::cout << " <- ";
                print_binarytree_dfs(root->right, mode, false);
            }
            std::cout << "]";
        }
        else
        {
            std::cout << root->data;
        }
        break;
    case POST_ORDER_DFS:
        if (isFirst)
        {
            std::cout << "PostOrder: ";
        }
        if (!root->is_leaf_node())
        {
            std::cout << "[";
            if (root->left != NULL)
            {
                print_binarytree_dfs(root->left, mode, false);
            }
            if (root->right != NULL)
            {
                std::cout << ", ";
                print_binarytree_dfs(root->right, mode, false);
            }
            std::cout << "] -> ";
        }
        std::cout << root->data;
        break;
    }
    if (isFirst)
    {
        std::cout << std::endl;
        std::cout << "------------" << std::endl;
    }
}

#endif // TREE_TRAVERSAL_H
