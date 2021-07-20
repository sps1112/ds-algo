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
            for (int i = 1; i <= index && current != NULL; i++)
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
                    delete temp;
                    return;
                }
                count++;
                current = current->next;
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

    // Returns the First Element in the List
    T peek()
    {
        if (!is_empty())
        {
            return head->data;
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
        int count = 0;
        DNode<T> *current = head;
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
            for (int i = 1; i <= index && current != NULL; i++)
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
                count++;
                current = current->next;
            }
        }
    }

    // Inserts a Value at some Index
    void insert_at(T val, int index)
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
                count++;
                current = current->next;
            }
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        else if (index == 0)
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
                    DNode<T> *temp = current->next;
                    DNode<T> *parent = current->prev;
                    parent->next = temp;
                    if (current != tail)
                    {
                        temp->prev = parent;
                    }
                    else
                    {
                        tail = parent;
                    }
                    delete current;
                    return;
                }
                count++;
                current = current->next;
            }
        }
        else if (index == 0)
        {
            tail = (tail == head) ? NULL : tail;
            if (!is_empty())
            {
                DNode<T> *temp = head;
                head = head->next;
                delete temp;
            }
        }
    }

    // Removes the Element at the End of the List
    void remove_end()
    {
        if (tail != head && !is_empty())
        {
            DNode<T> *temp = tail->prev;
            temp->next = NULL;
            tail = temp;
        }
        else if (tail == head)
        {
            tail = NULL;
            head = NULL;
        }
    }

    // Removes a Given value from the List
    void remove_val(T val)
    {
        DNode<T> *current = head;
        while (current != NULL)
        {
            if (current->data == val)
            {
                DNode<T> *temp = current->next;
                DNode<T> *parent = current->prev;
                if (current != head)
                {
                    parent->next = temp;
                }
                else
                {
                    head = temp;
                }
                if (current != tail)
                {
                    temp->prev = parent;
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

    // Converts to Dynamic Array
    Array<T> *to_dynamic_array()
    {
        Array<T> *arr = new Array<T>(get_count());
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

    // Returns the First Element in the List
    T peek()
    {
        if (!is_empty())
        {
            return head->data;
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
};

// Default Float Single Node
using ListNode = Node<float>;

// Default Float Doubly Linked Node
using DListNode = DNode<float>;

// Default Float Singly Linked List Type Class
using List = LinkedList<float>;

// Default Float Double Linked List Type Class
using DList = DoubleLinkedList<float>;

#endif // LINKEDLIST_H
