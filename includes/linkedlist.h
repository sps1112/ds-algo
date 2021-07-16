#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <dynamicarray.h>

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

    // Checks if the List is empty
    bool is_empty()
    {
        return (head == NULL);
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
                std::cout << " -> ";
            }
            current = current->next;
        }
        std::cout << "]" << std::endl;
    }

    // Adds a Node at the End of the List
    void add_node(Node<T> *node)
    {
        if (is_empty())
        {
            head = node;
            tail = node;
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
            current = current->next;
            count++;
        }
        return count;
    }

    // Clears the List
    void clear_list()
    {
        tail = NULL;
        head->next = tail;
        head = NULL;
    }

    // Gets the Node at a Position in the List. Starts at 0
    Node<T> *get_at_index(int index)
    {
        if (index >= 0)
        {
            Node<T> *current = head;
            for (int i = 1; i <= index; i++)
            {
                current = current->next;
            }
            return current;
        }
        return NULL;
    }

    // Returns the Index of given Value. Starts at 0
    int get_index_of(T val)
    {
        Node<T> *current = head;
        int index = 0;
        while (current != NULL)
        {
            if (current->data == val)
            {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1;
    }

    // Checks if the List contains given Value
    bool contains_val(T val)
    {
        return (get_index_of(val) != -1);
    }

    // Sets the Value to an element at a given index
    void set_val_at_index(T val, int index)
    {
        if (index >= 0)
        {
            Node<T> *current = head;
            int count = 0;
            while (current != NULL)
            {
                if (count == index)
                {
                    current->data = val;
                    break;
                }
                count++;
                current = current->next;
            }
        }
    }

    // Inserts a Value at some Index
    void insert_at(T val, int index)
    {
        Node<T> *node = new Node<T>(val);
        if (index > 0)
        {
            Node<T> *current = head;
            int count = 0;
            while (current != NULL)
            {
                if (count == index - 1)
                {
                    Node<T> *temp = current->next;
                    node->next = temp;
                    current->next = node;
                    if (current == tail)
                    {
                        tail = node;
                    }
                    return;
                }
                count++;
                current = current->next;
            }
            tail->next = node;
            tail = node;
        }
        else if (index == 0)
        {
            node->next = head;
            tail = (is_empty()) ? node : tail;
            head = node;
        }
    }

    // Removes an Element at a Given Index
    void remove_at(int index)
    {
        if (index > 0)
        {
            Node<T> *current = head;
            int count = 0;
            while (current != NULL)
            {
                if (count == index - 1)
                {
                    Node<T> *temp = current->next;
                    current->next = temp->next;
                    return;
                }
                count++;
                current = current->next;
            }
        }
        else if (index == 0)
        {
            tail = (tail == head) ? NULL : tail;
            head = (is_empty()) ? head : head->next;
        }
    }

    // Removes the Element at the End of the List
    void remove_end()
    {
        Node<T> *current = head;
        while (current->next != NULL)
        {
            if (current->next == tail)
            {
                current->next = NULL;
                tail = current;
                return;
            }
            current = current->next;
        }
    }

    // Removes a Given value from the List
    void remove_val(T val)
    {
        Node<T> *current = head;
        while (current != NULL)
        {
            if (current->next != NULL && current->next->data == val)
            {
                Node<T> *temp = current->next;
                current->next = temp->next;
                return;
            }
            current = current->next;
        }
    }

    // Converts the List into an Array
    T *to_static_array()
    {
        T *arr = new T[get_count()];
        Node<T> *current = head;
        int index = 0;
        while (current != NULL)
        {
            arr[index] = current->data;
            current = current->next;
            index++;
        }
        return arr;
    }

    // Converts to Dynamic Array
    Array<T> *to_dynamic_array()
    {
        Array<T> *arr = new Array<T>(get_count());
        Node<T> *current = head;
        int index = 0;
        while (current != NULL)
        {
            arr->add_element(current->data);
            current = current->next;
            index++;
        }
        return arr;
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
