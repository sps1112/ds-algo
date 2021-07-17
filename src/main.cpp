#include <iostream>
#include <string>
#include <heap.h>

void Log(std::string message)
{
    std::cout << message.c_str() << std::endl;
}

int main()
{
    HeapF heap;
    heap.print_heap();
    heap.insert(1);
    heap.print_heap();
    heap.insert(2);
    heap.print_heap();
    heap.insert(-1);
    heap.print_heap();
    heap.poll();
    heap.print_heap();
    heap.insert(3);
    heap.print_heap();
    heap.insert(-2);
    heap.print_heap();
    heap.insert(5);
    heap.print_heap();
    heap.insert(9);
    heap.print_heap();
    heap.poll();
    heap.print_heap();
    heap.poll();
    heap.print_heap();
    heap.remove(2);
    heap.print_heap();
    Log("Finish");
}
