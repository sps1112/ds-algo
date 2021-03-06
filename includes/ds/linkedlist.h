#ifndef LINKEDLIST_DS_H
#define LINKEDLIST_DS_H

// Custom Headers
#include <ds/node.h>
#include <ds/arraylist.h>

// Standard Headers
#include <iostream>

// A Template Singly Linked List
template <typename T>
class LinkedList
{
private:
    Node<T> *head; // First Node of the List
    Node<T> *tail; // Last Node of the List

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

    // Adds a Val to the End of the List
    void add_val(T val)
    {
        Node<T> *node = new Node<T>(val);
        add_node(node);
    }

    // Returns the number of Nodes in the List
    int get_count()
    {
        Node<T> *current = head;
        int count = 0;
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
        Node<T> *current = head;
        while (current != NULL)
        {
            Node<T> *temp = current;
            current = current->next;
            delete temp;
        }
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
            int count = 0;
            while (current != NULL)
            {
                if (index == count)
                {
                    return current;
                }
                current = current->next;
                count++;
            }
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
                current = current->next;
                count++;
            }
        }
    }

    // Inserts a Value at some Index
    void insert_at(T val, int index)
    {
        if (index >= 0)
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
                    current = current->next;
                    count++;
                }
                tail->next = node;
                tail = node;
            }
            else
            {
                node->next = head;
                tail = (is_empty()) ? node : tail;
                head = node;
            }
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
                    if (temp == tail)
                    {
                        tail = current;
                    }
                    delete temp;
                    return;
                }
                current = current->next;
                count++;
            }
        }
        else if (index == 0)
        {
            tail = (tail == head) ? NULL : tail;
            if (!is_empty())
            {
                Node<T> *temp = head;
                head = head->next;
                delete temp;
            }
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
                Node<T> *temp = tail;
                current->next = NULL;
                tail = current;
                delete temp;
                return;
            }
            current = current->next;
        }
    }

    // Removes a Given value from the List
    void remove_val(T val)
    {
        if (!is_empty())
        {
            Node<T> *current = head;
            if (current->data == val)
            {
                tail = (tail == head) ? NULL : tail;
                if (!is_empty())
                {
                    Node<T> *temp = head;
                    head = head->next;
                    delete temp;
                    return;
                }
            }
            while (current != NULL)
            {
                if (current->next != NULL && current->next->data == val)
                {
                    Node<T> *temp = current->next;
                    current->next = temp->next;
                    if (temp == tail)
                    {
                        tail = current;
                    }
                    delete temp;
                    return;
                }
                current = current->next;
            }
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

    // Converts to an ArrayList
    ArrayList<T> *to_array_list()
    {
        ArrayList<T> *arr = new ArrayList<T>(get_count());
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

    // Returns the First or Last Element in the List
    T peek(bool start = true)
    {
        if (!is_empty())
        {
            return (start) ? head->data : tail->data;
        }
        return NULL;
    }

    // Reverses the linked list
    void reverse_list()
    {
        if (!is_empty())
        {
            Node<T> *node1 = head;
            Node<T> *node2 = head->next;
            head->next = NULL;
            while (node1 != NULL && node2 != NULL)
            {
                Node<T> *temp = node2->next;
                node2->next = node1;
                node1 = node2;
                node2 = temp;
                if (node2 == NULL)
                {
                    tail = head;
                    head = node1;
                }
            }
        }
    }

    // Reverses a Linked List Recursively from a Start Node
    void reverse_list_recursive(Node<T> *current, Node<T> *parent = NULL)
    {
        if (current == NULL)
        {
            head = parent;
            return;
        }
        reverse_list_recursive(current->next, current);
        current->next = parent;
        if (parent == NULL)
        {
            tail = current;
        }
    }
};

// A Template Doubly Linked List
template <typename T>
class DoubleLinkedList
{
private:
    DNode<T> *head; // First Node of the List
    DNode<T> *tail; // Last Node of the List

    // Adds a Node at the End of the List
    void add_node(DNode<T> *node)
    {
        if (is_empty())
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

public:
    // Default Linked List Constructor
    DoubleLinkedList(DNode<T> *head_ = NULL, DNode<T> *tail_ = NULL)
    {
        head = head_;
        tail = tail_;
    }

    // Checks if the List is empty
    bool is_empty()
    {
        return (head == NULL);
    }

    // Prints the Complete List
    void print_list()
    {
        DNode<T> *current = head;
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

    // Adds a Val to the End of the List
    void add_val(T val)
    {
        DNode<T> *node = new DNode<T>(val);
        add_node(node);
    }

    // Returns the number of Nodes in the List
    int get_count()
    {
        DNode<T> *current = head;
        int count = 0;
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
        DNode<T> *current = head;
        while (current != NULL)
        {
            DNode<T> *temp = current;
            current = current->next;
            delete temp;
        }
        tail = NULL;
        head->next = tail;
        head = NULL;
    }

    // Gets the Node at a Position in the List. Starts at 0
    DNode<T> *get_at_index(int index)
    {
        if (index >= 0)
        {
            DNode<T> *current = head;
            int count = 0;
            while (current != NULL)
            {
                if (index == count)
                {
                    return current;
                }
                current = current->next;
                count++;
            }
        }
        return NULL;
    }

    // Returns the Index of given Value. Starts at 0
    int get_index_of(T val)
    {
        DNode<T> *current = head;
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
            DNode<T> *current = head;
            int count = 0;
            while (current != NULL)
            {
                if (count == index)
                {
                    current->data = val;
                    break;
                }
                current = current->next;
                count++;
            }
        }
    }

    // Inserts a Value at some Index
    void insert_at(T val, int index)
    {
        if (index >= 0)
        {
            DNode<T> *node = new DNode<T>(val);
            if (index > 0)
            {
                DNode<T> *current = head;
                int count = 0;
                while (current != NULL)
                {
                    if (count == index)
                    {
                        DNode<T> *parent = current->prev;
                        parent->next = node;
                        node->prev = parent;
                        node->next = current;
                        current->prev = node;
                        return;
                    }
                    current = current->next;
                    count++;
                }
                tail->next = node;
                node->prev = tail;
                tail = node;
            }
            else
            {
                node->next = head;
                if (!is_empty())
                {
                    head->prev = node;
                }
                else
                {
                    tail = node;
                }
                head = node;
            }
        }
    }

    // Removes an Element at a Given Index
    void remove_at(int index)
    {
        if (index > 0)
        {
            DNode<T> *current = head;
            int count = 0;
            while (current != NULL)
            {
                if (count == index)
                {
                    DNode<T> *child = current->next;
                    DNode<T> *parent = current->prev;
                    parent->next = child;
                    if (current != tail)
                    {
                        child->prev = parent;
                    }
                    else
                    {
                        tail = parent;
                    }
                    delete current;
                    return;
                }
                current = current->next;
                count++;
            }
        }
        else if (index == 0)
        {
            tail = (tail == head) ? NULL : tail;
            if (!is_empty())
            {
                DNode<T> *temp = head;
                head = head->next;
                head->prev = NULL;
                delete temp;
            }
        }
    }

    // Removes the Element at the End of the List
    void remove_end()
    {
        if (!is_empty())
        {
            DNode<T> *temp = tail;
            if (tail != head)
            {
                tail = tail->prev;
                tail->next = NULL;
            }
            else
            {
                tail = NULL;
                head = NULL;
            }
            delete temp;
        }
    }

    // Removes a Given value from the List
    void remove_val(T val)
    {
        if (!is_empty())
        {
            DNode<T> *current = head;
            while (current != NULL)
            {
                if (current->data == val)
                {
                    DNode<T> *child = current->next;
                    DNode<T> *parent = current->prev;
                    if (current != head)
                    {
                        parent->next = child;
                    }
                    else
                    {
                        head = child;
                    }
                    if (current != tail)
                    {
                        child->prev = parent;
                    }
                    else
                    {
                        tail = parent;
                    }
                    delete current;
                    return;
                }
                current = current->next;
            }
        }
    }

    // Converts the List into an Array
    T *to_static_array()
    {
        T *arr = new T[get_count()];
        DNode<T> *current = head;
        int index = 0;
        while (current != NULL)
        {
            arr[index] = current->data;
            current = current->next;
            index++;
        }
        return arr;
    }

    // Converts to an ArrayList
    ArrayList<T> *to_array_list()
    {
        ArrayList<T> *arr = new ArrayList<T>(get_count());
        DNode<T> *current = head;
        int index = 0;
        while (current != NULL)
        {
            arr->add_element(current->data);
            current = current->next;
            index++;
        }
        return arr;
    }

    // Returns the First or Last Element in the List
    T peek(bool start = true)
    {
        if (!is_empty())
        {
            return (start) ? head->data : tail->data;
        }
        return NULL;
    }

    // Reverses the linked list
    void reverse_list()
    {
        if (!is_empty())
        {
            DNode<T> *node1 = head;
            DNode<T> *node2 = head->next;
            head->next = NULL;
            head->prev = node2;
            while (node1 != NULL && node2 != NULL)
            {
                DNode<T> *temp = node2->next;
                node2->next = node1;
                node2->prev = temp;
                node1 = node2;
                node2 = temp;
                if (node2 == NULL)
                {
                    tail = head;
                    head = node1;
                }
            }
        }
    }

    // Reverses a Doubly Linked List Recursively from a Start Node
    void reverse_list_recursive(DNode<T> *current, DNode<T> *parent = NULL)
    {
        if (current == NULL)
        {
            parent->prev = current;
            head = parent;
            return;
        }
        reverse_list_recursive(current->next, current);
        current->next = parent;
        if (parent == NULL)
        {
            tail = current;
            return;
        }
        parent->prev = current;
    }
};

// Default Float Singly Linked List Type Class
using List = LinkedList<float>;

// Default Float Double Linked List Type Class
using DList = DoubleLinkedList<float>;

#endif // LINKEDLIST_DS_H
