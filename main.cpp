#include<iostream>
#include<chrono>
#include<ctime>
#include<string>

#include "BinaryTree.h"

// void* operator new(size_t size)
// {
//     static int count = 0;
//     count++;
//     std::cout << count << " " << "Allocations" << std::endl;
//     void * p = malloc(size);
//     return p;
// }

class Timer
{
    public:
        Timer()
        {
            start = std::chrono::system_clock::now();
        }
        ~Timer()
        {
            end = std::chrono::system_clock::now();
            std::chrono::duration<double , std::milli> Duration = end - start;
            std::cout << Duration.count() << " ms" << std::endl;
        }
    public:
        std::chrono::time_point<std::chrono::system_clock> start , end;
};
struct Cities
{
    std::string Name;
    uint32_t population;

    bool operator>(const Cities& other)
    {
        return Name > other.Name;
    }
    bool operator==(const Cities& other)
    {
        return Name == other.Name;
    }
};
int main()
{
    Timer timer; 
    BinaryTree<int> BinaryTree_v;

    std::cout << "First Binary Search Tree" << std::endl;
    BinaryTree_v.Insert(27);
    BinaryTree_v.Insert({1,2,3,4,32});
    auto Number = BinaryTree_v.Search(32);
    std::cout << Number->data << std::endl;

 
}