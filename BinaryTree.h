#pragma once

#include <initializer_list>
#include <assert.h>


template<typename Data>
struct BinarytreeNode
{
    Data data;
    BinarytreeNode* right = nullptr;
    BinarytreeNode* left = nullptr;
};

template<typename Data , typename Compare = std::greater<Data>>
class BinaryTree
{
private:
    BinarytreeNode<Data>* root;
    void u_inorder(BinarytreeNode<Data>* Node) const
    {
        if(Node != NULL)
        {
            u_inorder(Node->left);
            std::cout << Node->data << " ";
            u_inorder(Node->right);
        }
    }

    void u_postorder(BinarytreeNode<Data>* Node) const
    {
        if(Node != NULL)
        {
            u_postorder(Node->left);
            u_postorder(Node->right);
            std::cout << Node->data << " ";
        }
    }

    void u_preorder(BinarytreeNode<Data>* Node) const
    {
        if(Node != NULL)
        {
            std::cout << Node->data << std::endl;
            u_preorder(Node->left);
            u_preorder(Node->right);
        }
    }
    int u_height(BinarytreeNode<Data>* Node) const
    {
        if(Node == NULL)
        {
            return 0;
        }
        else
        {
            return  1 + std::max(u_height(Node->left),u_height(Node->right));
        }
    }

    BinarytreeNode<Data>* u_search(const Data& Key)
    {
        BinarytreeNode<Data>* Temp = root;
        while(Temp != nullptr)
        {
            if(Key > Temp->data)
                Temp = Temp->right;
            else if(Key < Temp->data)
                Temp = Temp->left;
            else
                return Temp; 
        }
        return nullptr;

    }

    void u_insert(const Data& UserData , Compare comparator = Compare())
    {
        BinarytreeNode<Data>* NewNode;
        BinarytreeNode<Data>* Current;
        BinarytreeNode<Data>* PreviousCurrent;

        NewNode = new BinarytreeNode<Data>;
        NewNode->data = UserData;
        NewNode->right = NULL;
        NewNode->left = NULL;

        if(root == NULL)
        {
            root = NewNode;
        }
        else
        {
            Current = root;
            while (Current != NULL)
            {
                PreviousCurrent = Current;
                if (!comparator(Current->data, UserData) && !comparator(UserData, Current->data)) 
                {
                    std::cout << "There is Data Which is going To match this one " << std::endl;
                    return;
                }
                else if (comparator(Current->data, UserData)) 
                {
                    Current = Current->left;
                } 
                else 
                {
                    Current = Current->right;
                }
            }

            if (comparator(PreviousCurrent->data, UserData)) 
            {
                PreviousCurrent->left = NewNode;
            } 
            else 
            {
                PreviousCurrent->right = NewNode;
            }
        }
    }

    void delete_tree(const BinarytreeNode<Data>* Tree)
    {
        if(Tree == nullptr)
        {
            return;
        }
        delete_tree(Tree->left);
        delete_tree(Tree->right);
        delete Tree;
    }

public:
    BinaryTree():root(nullptr){}

    BinaryTree(const BinaryTree<Data>& OtherTree)
    {
        if(OtherTree.root != nullptr)
        {
            CopyTree(root , OtherTree.root);
        }
    }

    void InOrder() const
    {
        u_inorder(root);
        std::cout << std::endl;
    }

    void PostOrder() const
    {
        u_postorder(root);
        std::cout << std::endl;
    }

    void PreOrder() const
    {
        u_preorder(root);
        std::cout << std::endl;
    }

    void Insert(Data UserData)
    {
        u_insert(UserData);
    }
    
    void Insert(Data* arr, size_t size)
    {
        for(size_t i = 0; i < size; i++)
        {
            u_insert(*(arr+i));
        }
    }

    void Insert(std::initializer_list<Data> DataList)
    {
        for(auto i = DataList.begin(); i != DataList.end(); i++)
        {
            u_insert(*i);
        }
    }

    BinarytreeNode<Data>* Search(const Data& Key)
    {
        return u_search(Key);     
    }

    int Height() const
    {
        return u_height(root);
    }

    bool isEmpty() const
    {
        return (root == NULL);
    }

    void CopyTree(BinarytreeNode<Data>* CopiedTree , BinarytreeNode<Data>* Tree)
    {
        if(Tree == NULL)
        {
            CopiedTree = NULL;
        }
        else
        {
            CopiedTree = new BinarytreeNode<Data>;
            CopiedTree->data = Tree->data;
            CopyTree(CopiedTree->left , Tree->left);
            CopyTree(CopiedTree->right , Tree->right);
        }
    }
   
    ~BinaryTree()
    {
        delete_tree(root);
    }


};