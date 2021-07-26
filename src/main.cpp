#include <iostream>
#include <string>
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
    QueueA queue;
    queue.print_queue();
    for (int i = 0; i < 10; i++)
    {
        queue.enqueue(array[i]);
    }
    queue.print_queue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.print_queue();
    queue.enqueue(12);
    queue.enqueue(-14);
    queue.dequeue();
    queue.print_queue();
    std::cout << "Front (Peek): " << queue.peek() << std::endl;
    queue.print_queue();
    std::cout << "Front (Pop): " << queue.dequeue() << std::endl;
    queue.print_queue();
    queue.free_queue();
    queue.print_queue();
    Log("Finish");
}
