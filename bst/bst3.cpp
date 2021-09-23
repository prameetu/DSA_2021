#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int key;
	struct Node *left, *right;
};

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if(!root)
        return;
    while(root)
    {
        if(root->key == key)
        {
            if(root->left)
            {
                Node *temp = root->left;
                while(temp->right)
                {
                    temp = temp->right;
                }
                pre = temp;
            }
            if(root->right)
            {
                Node *temp = root->right;
                while(temp->left)
                {
                    temp = temp->left;
                }
                suc = temp;
            }
            return;
        }
        if(key > root->key)
        {
            pre = root;
            root = root->right;
        }
        else {
            suc = root;
            root = root->left;
        }
    }
    

}