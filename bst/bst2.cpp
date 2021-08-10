//Searching for particular key in bst
#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;  
};

Node *create_node(int data){
    Node *new_node = new Node();
    if(!new_node){
        cout << "Memory Error!";
        return NULL;
    }
    new_node->data = data;;
    new_node->left = new_node->right = NULL;
    return new_node;
}

Node * insert_Node(Node *root,int key)
{
    if(!root)
    {
        root = create_node(key);
        return root;
    }

    if(key < root->data){
        root->left = insert_Node(root->left,key);
    }
    else{
        root->right = insert_Node(root->right,key);
    }

    return root;
}

void inorder(Node *temp)
{
    if(temp){
        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }
}

Node *search(Node *root,int key)
{
    if(!root){
        return NULL;
    }
    if(key == root->data)
        return root;
    else if(key < root->data)
        return search(root->left,key);
    else
        return search(root->right,key);
}

int main(){
    Node * root = create_node(1);
    insert_Node(root,5);
    insert_Node(root,2);
    insert_Node(root,7);
    insert_Node(root,3);
    insert_Node(root,4);
    insert_Node(root,6);
    insert_Node(root,8);

    Node *res = search(root,8);
    if(res)
        cout << "The key is found in bst! " << "\n";
    else
        cout << "Key is not found in bst!" << "\n";
}