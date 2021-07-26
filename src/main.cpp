#include <iostream>
#include <string>
#include <ds/stack.h>
#include <ds/queue.h>

void Log(std::string message)
{
    std::cout << message.c_str() << std::endl;
}

int main()
{
    int array[] = {1, 3, 5, 7, 9,
                   0, 2, 4, 6, 8,
                   -1, -3, -5, -7, -9,
                   -2, -4, -6, -8, -10};
    std::string brackets = "[A+B*{C+D}]";
    std::cout << is_parenthesis_balanced(brackets) << std::endl;

    std::string st = "Hello";
    std::cout << st << std::endl;
    st = reverse_string_via_stack(st);
    std::cout << st << std::endl;
    Log("Finish");
}
