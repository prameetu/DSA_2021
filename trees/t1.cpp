//Creating a binary tree
//inserting it into the first vacant space
//delete a node from it by making sure that tree shrinks from the bottom 
//(i.e. the deleted node is replaced by bottom most and rightmost node)
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

Node * insert_Node(Node *root,int data)
{
    if(!root)
    {
        root = create_node(data);
        return root;
    }

    queue <Node*> q;
    q.push(root);
    while(!q.empty()){
        Node * temp  = q.front();
        q.pop();

        if(temp->left != NULL){
            q.push(temp->left);
        }
        else{
            temp->left = create_node(data);
            return root;
        }

        if(temp->right != NULL){
            q.push(temp->right);
        }
        else{
            temp->right = create_node(data);
            return root;
        }
    }
}

void delete_deepest(Node *root,Node * key)
{
    queue <Node *> q;
    q.push(root);

    Node * temp;
    while(!q.empty())
    {
        temp = q.front();
        q.pop();

        if(temp == key)
        {
            temp = NULL;
            delete(key);
            return;
        }

        if(temp->left)
        {
            if(temp->left == key){
                temp->left = NULL;
                delete key;
                return;
            }
            else
                q.push(temp->left);
        }

        if(temp->right)
        {
            if(temp->right == key){
                temp->right = NULL;
                delete key;
                return;
            }
            else
                q.push(temp->right);
        }

        
    }
}

Node *delete_node(Node *root,int key)
{
    if(root == NULL)
        return NULL;
    
    if(root->left == NULL && root->right == NULL)
    {
        if(root->data == key)
            return NULL;
        else    
            return root;
    }

    Node *deepest_node;
    Node *key_node(NULL);

    queue <Node *> q;
    q.push(root);

    while(!q.empty())
    {
        deepest_node = q.front();
        q.pop();

        if(deepest_node->data == key)
            key_node = deepest_node;
        
        if(deepest_node->left)
            q.push(deepest_node->left);
        
        if(deepest_node->right)
            q.push(deepest_node->right);

    }
    if(key_node != NULL)
    {
        key_node->data = deepest_node->data;
        delete_deepest(root,deepest_node);
    }
    

    return root;

    
}

void inorder(Node * temp){
    if(!temp)
        return;
    inorder(temp->left);
    cout << temp->data << " ";
    inorder(temp->right);
}

void preorder(Node * temp){
    if(!temp)
        return;
        
    cout << temp->data << " ";
    preorder(temp->left);
    preorder(temp->right);
}

void postorder(Node * temp){
    if(!temp)
        return;
    postorder(temp->left);
    postorder(temp->right);
    cout << temp->data << " ";
}

void level_order(Node * temp)
{
    if(!temp)
        return;
    
    queue <Node *>q;
    q.push(temp);

    cout <<temp->data << " ";

    Node *r;

    while(!q.empty())
    {
        r = q.front();
        q.pop();

        if(temp->left)
        {
            cout << temp->left->data << " ";
            q.push(temp->left);
        }
        if(temp->right)
        {
            cout << temp->right->data << " ";
            q.push(temp->right);   
        }
    }
}

int main()
{
    Node * root = create_node(1);
    insert_Node(root,2);
    insert_Node(root,3);
    insert_Node(root,4);
    insert_Node(root,5);
    insert_Node(root,6);
    insert_Node(root,7);
    insert_Node(root,8);

    delete_node(root,3);

    inorder(root);
}