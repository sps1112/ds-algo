#include <iostream>
#include <string>
#include <stack.h>

void Log(std::string message)
{
    std::cout << message.c_str() << std::endl;
}

int main()
{
    StackF stack;
    stack.print_stack();
    std::cout << "Is Stack Empty: " << stack.is_empty() << std::endl;
    stack.push(1);
    stack.push(3);
    stack.push(2.4);
    stack.print_stack();
    std::cout << "Number of Elements: " << stack.get_size() << std::endl;
    stack.pop();
    stack.print_stack();
    stack.pop();
    stack.print_stack();
    stack.pop();
    stack.print_stack();
    stack.pop();
    stack.print_stack();
    stack.push(2);
    stack.push(9);
    stack.push(5.6);
    stack.push(-11.23);
    stack.push(-7);
    stack.print_stack();
    std::cout << "Top Val is(Peek): " << stack.peek() << std::endl;
    stack.print_stack();
    std::cout << "Top Val is(Pop): " << stack.pop() << std::endl;
    stack.print_stack();
}
