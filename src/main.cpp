#include <iostream>
#include <string>
#include <queue.h>

void Log(std::string message)
{
    std::cout << message.c_str() << std::endl;
}

int main()
{
    QueueF queue;
    queue.print_queue();
    std::cout << "Is Queue Empty: " << queue.is_empty() << std::endl;
    queue.enqueue(1);
    queue.enqueue(3);
    queue.enqueue(2);
    queue.enqueue(-4);
    queue.print_queue();
    std::cout << "Number of Elements: " << queue.get_size() << std::endl;
    queue.dequeue();
    queue.dequeue();
    queue.print_queue();
    queue.enqueue(11);
    queue.enqueue(5.5);
    queue.enqueue(7);
    queue.print_queue();
    std::cout << "Top Val is(Peek): " << queue.peek() << std::endl;
    queue.print_queue();
    std::cout << "Top Val is(Dequeue): " << queue.dequeue() << std::endl;
    queue.print_queue();
    std::cout << "Is 7 Present: " << queue.contains(7) << std::endl;
    queue.enqueue(2.2);
    queue.enqueue(74);
    queue.enqueue(23);
    queue.print_queue();
    queue.remove(23);
    queue.remove(7);
    queue.dequeue();
    queue.enqueue(11);
    queue.print_queue();
    queue.bring_front(2.2);
    queue.send_back(74);
    queue.enqueue(32);
    queue.print_queue();
    queue.to_dynamic_array()->print_array();
    queue.free_queue();
    queue.print_queue();
    queue.enqueue(1);
    queue.print_queue();
    Log("Finish");
}
