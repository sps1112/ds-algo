#ifndef STACK_DS_H
#define STACK_DS_H

#include <ds/dynamicarray.h>

// Template Stack Node Struct
template <typename T>
struct StackNode
{
    T data;             // Data stored in Node
    StackNode<T> *next; // Pointer to next node
    // Default Stack Node Constructor
    StackNode() : next(NULL) {}
    // Default Stack Node Data Constructor
    StackNode(T data_) : data(data_), next(NULL) {}
};

// Default Stack Class
template <typename T>
class Stack
{
private:
    StackNode<T> *top; // Top Node of the Stack
    int size;          // Number of Nodes in the Stack

    // Pushes a node to the Top of the Stack
    void push_node(StackNode<T> *node)
    {
        if (is_empty())
        {
            top = node;
        }
        else
        {
            node->next = top;
            top = node;
        }
        size++;
    }

public:
    // Default Constructor
    Stack()
    {
        top = NULL;
        size = 0;
    }

    // Stack Value Constructor
    Stack(T val)
    {
        StackNode<T> *node = new StackNode<T>(val);
        top = node;
        size = 1;
    }

    // Prints the Complete Stack
    void print_stack()
    {
        StackNode<T> *current = top;
        std::cout << "[";
        while (current != NULL)
        {
            std::cout << current->data;
            current = current->next;
            if (current != NULL)
            {
                std::cout << " => ";
            }
        }
        std::cout << "]" << std::endl;
    }

    // Returns the Size of the Stack
    int get_size()
    {
        return size;
    }

    // Checks if the Stack is Empty
    bool is_empty()
    {
        return (size == 0);
    }

    // Pushes a Value to the top of the Stack
    void push(T val)
    {
        StackNode<T> *node = new StackNode<T>(val);
        push_node(node);
    }

    // Pops the Top Node out the Stack by removing it
    T pop()
    {
        if (!is_empty())
        {
            StackNode<T> *node = top;
            T data_ = node->data;
            top = top->next;
            size--;
            delete node;
            return data_;
        }
        return NULL;
    }

    // Gives the Top value from the stack without removing
    T peek()
    {
        if (!is_empty())
        {
            return top->data;
        }
        return NULL;
    }

    // Converts Stack to a Static Array
    T *to_static_array()
    {
        T *arr = new T[size];
        StackNode<T> *node = top;
        for (int i = 0; i < size && node != NULL; i++)
        {
            arr[i] = node->data;
            node = node->next;
        }
        return arr;
    }

    // Converts Stack to a Dynamic Array
    Array<T> *to_dynamic_array()
    {
        Array<T> *arr = new Array<T>(size);
        StackNode<T> *node = top;
        while (node != NULL)
        {
            arr->add_element(node->data);
            node = node->next;
        }
        return arr;
    }
};

// Default Float Stack Node
using SNode = StackNode<float>;

// Default Float Stack
using StackF = Stack<float>;

#endif // STACK_DS_H
