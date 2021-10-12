#ifndef STACK_DS_H
#define STACK_DS_H

// Custom Headers
#include <ds/node.h>
#include <ds/arraylist.h>
#include <ds/linkedlist.h>

// Standard Headers
#include <iostream>
#include <string>

// Template Stack Class using Array List
template <typename T>
class StackArray
{
private:
    ArrayList<T> *list; // Array used to store values in the stack

public:
    // Default StackArray Constructor
    StackArray()
    {
        list = new ArrayList<T>();
    }

    // StackArray Value Constructor
    StackArray(T val)
    {
        list = new ArrayList<T>(1);
        list->add_element(val);
    }

    // Prints the Stack
    void print_stack()
    {
        int size = get_size();
        std::cout << "[";
        for (int i = size - 1; i >= 0; i--)
        {
            std::cout << list->get_element(i);
            if (i != 0)
            {
                std::cout << " => ";
            }
        }
        std::cout << "]" << std::endl;
    }

    // Returns the number of elements in the Stack
    int get_size()
    {
        return list->get_length();
    }

    // Checks if the Stack is empty
    bool is_empty()
    {
        return (get_size() == 0);
    }

    // Pushes a Value to the top of the stack
    void push(T val)
    {
        list->add_element(val);
    }

    // Returns the Top value by removing it
    T pop()
    {
        if (!is_empty())
        {
            T val = list->get_element(get_size() - 1);
            list->remove_at_index(get_size() - 1);
            return val;
        }
        return NULL;
    }

    // Removes the Top value without removing it
    T peek()
    {
        if (!is_empty())
        {
            return list->get_element(get_size() - 1);
        }
        return NULL;
    }

    // Converts StackArray to a Static Array
    T *to_static_array()
    {
        int size = get_size();
        T *arr = new T[size];
        for (int i = size - 1; i >= 0; i--)
        {
            arr[(size - 1) - i] = list->get_element(i);
        }
        return arr;
    }

    // Converts StackArray to an ArrayList
    ArrayList<T> *to_array_list()
    {
        int size = get_size();
        ArrayList<T> *arr = new ArrayList<T>(size);
        for (int i = size - 1; i >= 0; i--)
        {
            arr->add_element(list->get_element(i));
        }
        return arr;
    }
};

// Default Stack Class
template <typename T>
class Stack
{
private:
    Node<T> *top; // Top Node of the Stack
    int size;     // Number of Nodes in the Stack

    // Pushes a node to the Top of the Stack
    void push_node(Node<T> *node)
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
        Node<T> *node = new Node<T>(val);
        top = node;
        size = 1;
    }

    // Prints the Complete Stack
    void print_stack()
    {
        Node<T> *current = top;
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
        Node<T> *node = new Node<T>(val);
        push_node(node);
    }

    // Pops the Top Node out the Stack by removing it
    T pop()
    {
        if (!is_empty())
        {
            Node<T> *node = top;
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

    // Converts Stack to an ArrayList
    ArrayList<T> *to_array_list()
    {
        ArrayList<T> *arr = new ArrayList<T>(size);
        Node<T> *node = top;
        while (node != NULL)
        {
            arr->add_element(node->data);
            node = node->next;
        }
        return arr;
    }
};

//Default Float Stack Array
using StackA = StackArray<float>;

// Default Float Stack List
using StackL = Stack<float>;

// Checks if a String of Parenthesis is balanced
bool is_parenthesis_balanced(std::string s)
{
    Stack<char> stack;
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        switch (c)
        {
        case ')':
            if (stack.pop() != '(')
            {
                return false;
            }
            break;
        case '}':
            if (stack.pop() != '{')
            {
                return false;
            }
            break;
        case ']':
            if (stack.pop() != '[')
            {
                return false;
            }
            break;
        case '{':
        case '(':
        case '[':
            stack.push(s[i]);
        }
    }
    return stack.is_empty();
}

// Reverses a String using Stacks
std::string reverse_string_via_stack(std::string s)
{
    Stack<char> stack;
    for (int i = 0; i < s.length(); i++)
    {
        stack.push(s.at(i));
    }
    for (int i = 0; i < s.length(); i++)
    {
        s[i] = stack.pop();
    }
    return s;
}

// Reverse a Linked List using Stacks
template <typename T>
void reverse_linked_list(LinkedList<T> *list)
{
    Stack<T> stack;
    Node<T> *head = list->get_at_index(0);
    Node<T> *current = head;
    while (current != NULL)
    {
        stack.push(current->data);
        current = current->next;
    }
    current = head;
    while (current != NULL)
    {
        current->data = stack.pop();
        current = current->next;
    }
}

#endif // STACK_DS_H
