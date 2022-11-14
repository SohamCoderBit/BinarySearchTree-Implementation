#include <initializer_list>


template<typename Data>
class BinarytreeNode
{
public:
    Data data;
    BinarytreeNode* right;
    BinarytreeNode* left;
};

template<typename Data>
class BinaryTree
{
protected:
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

    void u_insert(const Data& UserData)
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
                if(Current->data == UserData)
                {
                    std::cout << "There is Data Which is going To match this one " << std::endl;
                    return;
                }
                else if(Current->data > UserData)
                {
                    Current=Current->left;
                }
                else 
                {
                    Current=Current->right;
                }
            }

            if(PreviousCurrent->data > UserData)
            {
                PreviousCurrent->left = NewNode;
            }
            else
            {
                PreviousCurrent->right = NewNode;
            }
            
        }
    }

public:
    BinaryTree()
    {
        root = NULL;
    }
    BinaryTree(const BinaryTree<Data>& OtherTree)
    {
        if(OtherTree.root == NULL)
        {
            root = NULL;
        }
        else
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
    int Height() const
    {
        return u_height(root);
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
        delete root;
    }


};