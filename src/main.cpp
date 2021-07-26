#include <iostream>
#include <string>
#include <ds/heap.h>

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
    HeapF heap;
    heap.print_heap();
    for (int i = 0; i < 20; i++)
    {
        int multi = (i % 2 == 0) ? 1 : -1;
        heap.insert(i * multi);
        heap.print_heap();
    }
    heap.print_heap();
    for (int i = 0; i < 20; i++)
    {
        std::cout << "Rank " << i << ": " << heap.poll() << std::endl;
    }
    Log("Finish");
}
