# BinarySearchTree-Implementation
# Binary Search Tree in C++

This repository contains a C++ implementation of a Binary Search Tree (BST) using templates. The BST is a data structure that allows efficient insertion, deletion, and search operations on ordered data.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)

## Overview

The Binary Search Tree is implemented using templates, allowing it to work with different data types. The `BinarytreeNode` class represents a single node in the tree, containing the data and pointers to the left and right children.

The `BinaryTree` class serves as the container for the BST. It handles the root node and provides various methods for working with the tree, such as insertion, search, and traversal.

## Usage

To use the Binary Search Tree in your C++ project, follow these steps:

1. Clone the repository or download the source code.

2. Include the `BinaryTree.h` header file in your C++ source file:

   ```cpp
   #include "BinaryTree.h"
   ```
3. Create a BinaryTree object with the desired data type:
   ```cpp
   // Example for integers
    BinaryTree<int> tree;
   ```
4. Use the provided methods to interact with the binary search tree:
   ```cpp
   // Insert elements into the tree
    tree.Insert(10);
    tree.Insert({5, 15, 3, 7});
    
    // Search for an element
    BinarytreeNode<int>* result = tree.Search(7);
    if (result) {
        std::cout << "Element found: " << result->data << std::endl;
    } else {
        std::cout << "Element not found." << std::endl;
    }
   ```




