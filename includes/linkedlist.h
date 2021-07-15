#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

// Template Node Element Struct for Linked List
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

// A Template Singly Linked List
template <typename T>
class LinkedList
{
public:
    // Default Linked List Constructor
    LinkedList(Node<T> *head_ = NULL, Node<T> *tail_ = NULL)
    {
        head = head_;
        tail = tail_;
    }

    // Prinits the Complete List
    void print_list()
    {
        Node<T> *current = head;
        std::cout << "[";
        while (current != NULL)
        {
            std::cout << current->data;
            if (current->next != NULL)
            {
                std::cout << " => ";
            }
            current = current->next;
        }
        std::cout << "]" << std::endl;
    }

    // Adds a Node at the End of the List
    void add_node(Node<T> *node)
    {
        if (head == NULL)
        {
            head = node;
            tail = node;
            head->next = NULL;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
    }

    // Adds a Val to the End of the List
    void add_val(T val)
    {
        Node<T> *node = new Node<T>(val);
        add_node(node);
    }

    // Returns the number of Nodes in the List
    int get_count()
    {
        int count = 0;
        Node<T> *current = head;
        while (current != NULL)
        {
            count++;
            current = current->next;
        }
        return count;
    }

    // Checks if the List is empty
    bool is_empty()
    {
        return (head == NULL);
    }

    // Clears the List
    void clear_list()
    {
        tail = NULL;
        head->next = tail;
        head = NULL;
    }

private:
    Node<T> *head; // First Node of the List
    Node<T> *tail; // Last Node of the List
};

// Default Float Single Node
using ListNode = Node<float>;

// Default Float Singly Linked List Type Class
using List = LinkedList<float>;

#endif // LINKEDLIST_H
