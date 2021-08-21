//print all paths from root to leaf in a binary tree !

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

void print_array(vector <int> v,int l)
{
    for(int i=0;i<l;i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

void root_to_leaf_path_impl(Node *temp,vector <int> v,int l)
{
    if(temp == nullptr)
        return;

    v[l] = temp->data;
    l++;

    if(temp->left == nullptr && temp->right == nullptr)
        print_array(v,l);
    else{
        root_to_leaf_path_impl(temp->left,v,l);
        root_to_leaf_path_impl(temp->right,v,l);
    }
}

void root_to_leaf_path(Node * temp)
{
    if(temp==nullptr)
        return;
    vector <int> v(100);
    root_to_leaf_path_impl(temp,v,0);
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

    inorder(root);
    cout << endl;

    root_to_leaf_path(root);
}