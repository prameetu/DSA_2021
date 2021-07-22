//Height of Binary tree

//Counting number of nodes with degree 2

#include<bits/stdc++.h>

using namespace std;
 
struct Node{
    int data;
    Node *left;
    Node *right;
};

Node * create_node(int data)
{
    Node *new_node = new Node();
    if(!new_node){
        cout << "Memory Error!";
        return NULL;
    }
    new_node->data = data;;
    new_node->left = new_node->right = NULL;
    return new_node;
}

int height(Node *temp)
{
    int x,y;
    if(temp)
    {
        x = height(temp->left);
        y = height(temp->right);
        if(x>y)
            return x+1;
        else
            return y+1;
    }

    return 0; // thois can be return -1 also depending on the fact just root node is taken at level 0 or level 1

}

int main()
{
    Node *root = create_node(2);
    root->left     = create_node(7);
    root->right     = create_node(5);
    root->left->right = create_node(6);
    root->left->right->left = create_node(1);
    root->left->right->right = create_node(11);
    root->right->right = create_node(9);
    root->right->left = create_node(9);


    cout << height(root);
}