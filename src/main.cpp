#include <iostream>
#include <string>

void Log(std::string message)
{
    std::cout << message.c_str() << std::endl;
}

int main()
{
    Log("Hello World!");
}
