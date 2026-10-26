#include <iostream>
using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;

    node(int val)
    {
        data = val;
        left= right = nullptr;
    }
};

class BST
{
    private:
    node*root;
    node*insert(node*root,int val)
    {
        if(root == nullptr)
        {
            return new node(val);

        }
        if(val<root->data)

        {
            root->left=insert(root->right,val);

        }
        return root;
    }else if(val>root->data)
        {
            root->right=insert(root->l)
        }

    }
}