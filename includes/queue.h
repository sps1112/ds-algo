#ifndef QUEUE_DS_H
#define QUEUE_DS_H

#include <dynamicarray.h>

// Template Queue Node Struct
template <typename T>
struct QueueNode
{
    T data;             // Queue Data
    QueueNode<T> *next; // Pointer to next Node in the queue
    // Default Queue Constructor
    QueueNode() : next(NULL) {}
    // Queue Data Constructor
    QueueNode(T data_) : data(data_), next(NULL) {}
};

// Template Queue Class
template <typename T>
class Queue
{
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
        QueueNode<T> *node = new QueueNode<T>(val);
        head = node;
        tail = node;
        size = 1;
    }

    // Prints the Complete Queue from Head to Tail
    void print_queue()
    {
        QueueNode<T> *node = head;
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

    // Appends a new Node at the end of the Queue
    void enqueue_node(QueueNode<T> *node)
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

    // Appends a new value to th back of the Queue
    void enqueue(T val)
    {
        QueueNode<T> *node = new QueueNode<T>(val);
        enqueue_node(node);
    }

    // Moves queue forward by removing the front-most node
    T dequeue()
    {
        if (!is_empty())
        {
            QueueNode<T> *node = head;
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
        QueueNode<T> *node = head;
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
        QueueNode<T> *node = head;
        if (node->data == val)
        {
            dequeue();
            return;
        }
        while (node != NULL)
        {
            if (node->next != NULL && node->next->data == val)
            {
                QueueNode<T> *temp = node->next;
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
            QueueNode<T> *node = new QueueNode<T>(val);
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
        QueueNode<T> *node = head;
        for (int i = 0; i < size && node != NULL; i++)
        {
            arr[i] = node->data;
            node = node->next;
        }
        return arr;
    }

    // Converts the Queue to a Dynamic Array
    Array<T> *to_dynamic_array()
    {
        Array<T> *arr = new Array<T>(size);
        QueueNode<T> *node = head;
        while (node != NULL)
        {
            arr->add_element(node->data);
            node = node->next;
        }
        return arr;
    }

private:
    QueueNode<T> *head; // Head of the Queue
    QueueNode<T> *tail; // Tail of the Queue
    int size;           // Length of the Queue
};

// Default Float Queue Node Type
using QNode = QueueNode<float>;

// Default Float Queue Type
using QueueF = Queue<float>;

#endif // QUEUE_h
