#include<iostream>
#include<initializer_list>
#include<chrono>
#include<ctime>
#include "BinaryTree.h"

int main()
{
    
    auto start = std::chrono::system_clock::now(); 
    int Arr[] = {1,2,12,3,5,23,32,45,22,21};
    size_t size = sizeof(Arr)/sizeof(Arr[0]);
    BinaryTree<int> BinaryTree_v;
    BinaryTree_v.Insert(27);
    BinaryTree_v.Insert(Arr,size);
    BinaryTree_v.InOrder();
    auto end = std::chrono::system_clock::now();

    std::cout << std::endl;
    std::chrono::duration<double , std::milli> time = end - start;
    std::cout << time.count() << " ms" << std::endl;


}