#include <iostream>
#include <string>
#include <algos/heap_sort.h>
#include <ds/hashmap.h>

void Log(std::string message)
{
    std::cout << message.c_str() << std::endl;
}

int main()
{
    int array[] = {8, 2, 5, 11, -8,
                   10, -3, 4, 15, 24,
                   30, 29, 3, 6, 37,
                   38, -39, 42, -44, 45,
                   48, -50, 51, -53, -56};
    Array<int> nArray(array, 25);
    /*int array[] = {4, 3, 2, 10, 12, 1, 5, 6};
    Array<int> nArray(array, 8);*/
    nArray.print_array();
    heap_sort(&nArray);
    nArray.print_array();
    heap_sort(&nArray, false);
    nArray.print_array();
    Log("Finish");
}
