
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
    void u_inorder(BinarytreeNode<Data>* Node)
    {
        if(Node != NULL)
        {
            u_inorder(Node->left);
            std::cout << Node->data << " ";
            u_inorder(Node->right);
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
    void InOrder()
    {
        u_inorder(root);
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
   
    ~BinaryTree()
    {
        delete root;
    }


};