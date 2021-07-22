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

int count_nodes_degree_2_iter(Node * temp)
{
    if(!temp)
        return 0;

    queue <Node *> q;

    int cnt(0);
    q.push(temp);

    while(!q.empty())
    {
        Node * temp = q.front();
        q.pop();
        if(temp->left && temp->right)
            cnt++;

        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);

    }

    return cnt;

}

int count_nodes_degree_2(Node * temp)
{
    int x,y;

    if(temp)
    {
        x = count_nodes_degree_2(temp->left);
        y = count_nodes_degree_2(temp->right);

        if(temp->left && temp->right)
            return x+y+1;
        else
            return x+y;
    }
    return 0;
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


    cout << count_nodes_degree_2(root);
}