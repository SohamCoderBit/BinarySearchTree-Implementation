#include<iostream>
#include<chrono>
#include<ctime>
#include "BinaryTree.h"

int main()
{
    
    auto start = std::chrono::system_clock::now(); 
    int Arr[] = {1,2,12,3,5,23,32,45,22,21};
    size_t size = sizeof(Arr)/sizeof(Arr[0]);

    BinaryTree<int> BinaryTree_v;
    BinaryTree<int> BinaryTree_u;

    std::cout << "First Binary Search Tree" << std::endl;
    BinaryTree_v.Insert(27);
    //BinaryTree_v.Insert(Arr,size);
    BinaryTree_v.Insert({1,2,3,4,32});
    BinaryTree_v.InOrder();

    std::cout << "Second Binary Search Tree" << std::endl;
    BinaryTree_u = BinaryTree_v;
    BinaryTree_u.InOrder();

    std::cout << "Tree Height = " << BinaryTree_v.Height() << std::endl;
    auto end = std::chrono::system_clock::now();

    std::cout << std::endl;
    std::chrono::duration<double , std::milli> time = end - start;
    std::cout << time.count() << " ms" << std::endl;


}