#ifndef NODE_DS_H
#define NODE_DS_H

// Template Node Element Struct for Linked List, Stacks and Queues
template <typename T>
struct Node
{
    T data;        // Data of the Node
    Node<T> *next; // Pointer to the Next Node

    // Default Node Constructor
    Node() : next(NULL) {}

    // Node Data Constructor
    Node(T data_) : data(data_), next(NULL) {}
};
// Default Float Node
using NodeF = Node<float>;

// Template Node Element Struct for Doubly Linked List
template <typename T>
struct DNode
{
    T data;         // Data of the Node
    DNode<T> *next; // Pointer to the Next Node
    DNode<T> *prev; // Pointer to the Previous Node

    // Default DNode Constructor
    DNode() : next(NULL), prev(NULL) {}

    // DNode Data Constructor
    DNode(T data_) : data(data_), next(NULL), prev(NULL) {}
};
// Default Float Doubly Linked Node
using DNodeF = DNode<float>;

#endif // NODE_DS_H
