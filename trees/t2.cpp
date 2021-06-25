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


void preorder(Node *temp)
{
    stack <Node *> st;
    while(true)
    {
        if(temp)
        {
            cout << temp->data << " ";
            st.push(temp);
            temp=temp->left;
        }
        else
        {
            if(st.empty())
                break;
            temp = st.top();
            st.pop();
            temp = temp->right;
        }
    }
}

void inorder(Node *temp)
{
    stack <Node *> st;
    while(true)
    {
        if(temp)
        {
            st.push(temp);
            temp=temp->left;
        }
        else
        {
            if(st.empty())
                break;
            temp = st.top();
            st.pop();
            cout << temp->data << " ";
            temp=temp->right;
        }
    }
}

void postorder(Node * temp)
{
    stack <Node *> st1,st2;

    if(temp)
        st1.push(temp);

    while(!st1.empty())
    {
        temp = st1.top();
        st1.pop();

        st2.push(temp);

        if(temp->left)
            st1.push(temp->left);

        if(temp->right)
            st1.push(temp->right);
    }

    while(!st2.empty())
    {
        cout << st2.top()->data << " ";
        st2.pop();
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

    postorder(root);

}