#ifndef QUEUE_DS_H
#define QUEUE_DS_H

// Custom Headers
#include <ds/node.h>
#include <ds/arraylist.h>

// Standard Headers
#include <iostream>

// Template QueueArray Class
template <typename T>
class QueueArray
{
private:
    ArrayList<T> *list; // ArrayList to store queue

public:
    // Default QueueArray Constructor
    QueueArray()
    {
        list = new ArrayList<T>();
    }

    // QueueArray Value Consructor
    QueueArray(T val)
    {
        list = new ArrayList<T>(1);
        list->add_element(val);
    }

    // Prints the Complete QueueArray from Head to Tail
    void print_queue()
    {
        int size = get_size();
        std::cout << "[";
        for (int i = 0; i < size; i++)
        {
            std::cout << list->get_element(i);
            if (i != size - 1)
            {
                std::cout << " <= ";
            }
        }
        std::cout << "]" << std::endl;
    }

    // Returns the Size of the QueueArray
    int get_size()
    {
        return list->get_length();
    }

    // Checks if the QueueArray is Empty
    bool is_empty()
    {
        return (get_size() == 0);
    }

    // Appends a new value to th back of the Queue
    void enqueue(T val)
    {
        list->add_element(val);
    }

    // Moves QueueArray forward by removing the front-most node
    T dequeue()
    {
        if (!is_empty())
        {
            T val = list->get_element(0);
            list->remove_at_index(0);
            return val;
        }
        return NULL;
    }

    // Returns the front-most node without removing it
    T peek()
    {
        if (!is_empty())
        {
            return list->get_element(0);
        }
        return NULL;
    }

    // Checks if Element is Present in QueueArray
    bool contains(T val)
    {
        return list->contains(val);
    }

    // Removes an Element from the middle of the QueueArray
    void remove(T val)
    {
        list->remove_element(val);
    }

    // Brings the Val to the Front if found
    void bring_front(T val)
    {
        if (contains(val))
        {
            remove(val);
            list->insert_at(val, 0);
        }
    }

    // Sends the Val to the Back if ound
    void send_back(T val)
    {
        if (contains(val))
        {
            remove(val);
            enqueue(val);
        }
    }

    // Frees the Entire QueueArray
    void free_queue()
    {
        int size = list->get_length();
        for (int i = 0; i < size; i++)
        {
            dequeue();
        }
        list->trim_array();
    }

    // Converts the QueueArray to a Static Array
    T *to_static_array()
    {
        int size = get_size();
        T *arr = new T[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = list->get_element(i);
        }
        return arr;
    }

    // Converts the QueueArray to an ArrayList
    ArrayList<T> *to_array_list()
    {
        int size = get_size();
        ArrayList<T> *arr = new ArrayList<T>(size);
        for (int i = 0; i < size; i++)
        {
            arr->add_element(list->get_element(i));
        }
        return arr;
    }
};

// Template Queue Class
template <typename T>
class Queue
{
private:
    Node<T> *head; // Head of the Queue
    Node<T> *tail; // Tail of the Queue
    int size;      // Length of the Queue

    // Appends a new Node at the end of the Queue
    void enqueue_node(Node<T> *node)
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
        size++;
    }

public:
    // Default Queue Constructor
    Queue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    // Queue Value Consructor
    Queue(T val)
    {
        Node<T> *node = new Node<T>(val);
        head = node;
        tail = node;
        size = 1;
    }

    // Prints the Complete Queue from Head to Tail
    void print_queue()
    {
        Node<T> *node = head;
        std::cout << "[";
        while (node != NULL)
        {
            std::cout << node->data;
            node = node->next;
            if (node != NULL)
            {
                std::cout << " <= ";
            }
        }
        std::cout << "]" << std::endl;
    }

    // Returns the Size of the Queue
    int get_size()
    {
        return size;
    }

    // Checks if the Queue is Empty
    bool is_empty()
    {
        return (size == 0);
    }

    // Appends a new value to th back of the Queue
    void enqueue(T val)
    {
        Node<T> *node = new Node<T>(val);
        enqueue_node(node);
    }

    // Moves queue forward by removing the front-most node
    T dequeue()
    {
        if (!is_empty())
        {
            Node<T> *node = head;
            T val = head->data;
            head = head->next;
            tail = (head == NULL) ? NULL : tail;
            size--;
            delete node;
            return val;
        }
        return NULL;
    }

    // Returns the front-most node without removing it
    T peek()
    {
        if (!is_empty())
        {
            return head->data;
        }
        return NULL;
    }

    // Checks if Element is Present in Queue
    bool contains(T val)
    {
        Node<T> *node = head;
        while (node != NULL)
        {
            if (node->data == val)
            {
                return true;
            }
            node = node->next;
        }
        return false;
    }

    // Removes an Element from the middle of the Queue
    void remove(T val)
    {
        Node<T> *node = head;
        if (node->data == val)
        {
            dequeue();
            return;
        }
        while (node != NULL)
        {
            if (node->next != NULL && node->next->data == val)
            {
                Node<T> *temp = node->next;
                node->next = temp->next;
                if (temp == tail)
                {
                    tail = node;
                }
                size--;
                delete temp;
                return;
            }
            node = node->next;
        }
    }

    // Brings the Val to the Front if found
    void bring_front(T val)
    {
        if (contains(val))
        {
            remove(val);
            Node<T> *node = new Node<T>(val);
            if (!is_empty())
            {
                node->next = head;
                head = node;
            }
            else
            {
                head = node;
                tail = node;
            }
            size++;
        }
    }

    // Sends the Val to the Back if ound
    void send_back(T val)
    {
        if (contains(val))
        {
            remove(val);
            enqueue(val);
        }
    }

    // Frees the Entire Queue
    void free_queue()
    {
        int count = size;
        for (int i = 0; i < count; i++)
        {
            dequeue();
        }
    }

    // Converts the Queue to a Static Array
    T *to_static_array()
    {
        T *arr = new T[size];
        Node<T> *node = head;
        for (int i = 0; i < size && node != NULL; i++)
        {
            arr[i] = node->data;
            node = node->next;
        }
        return arr;
    }

    // Converts the Queue to an ArrayList
    ArrayList<T> *to_array_list()
    {
        ArrayList<T> *arr = new ArrayList<T>(size);
        Node<T> *node = head;
        while (node != NULL)
        {
            arr->add_element(node->data);
            node = node->next;
        }
        return arr;
    }
};

// Default Float Queue Array Type
using QueueA = QueueArray<float>;

// Default Float Queue Type
using QueueL = Queue<float>;

#endif // QUEUE_DS_H
