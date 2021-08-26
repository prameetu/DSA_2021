//Building heap form heapify function
#include <bits/stdc++.h>

using namespace std;

int parent(int i)
{
    return (i - 1) / 2;
}
int left_child(int i)
{
    return 2 * i + 1;
}
int right_child(int i)
{
    return 2 * i + 2;
}

void Heapify(vector<int> &v,int n, int i)
{
    int lchild = left_child(i);
    int rchild = right_child(i);
    int largest = i;

    if (lchild < n && v[lchild] > v[largest])
        largest = lchild;

    if (rchild < n && v[rchild] > v[largest])
        largest = rchild;

    if (largest != i)
    {
        swap(v[largest], v[i]);
        Heapify(v,n, largest);
    }
}

int main()
{
    vector<int> v = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    int n(v.size());
    for(int j=(n/2)-1;j>=0;j--)
    {
        Heapify(v,n,j);
    }
    for(auto x:v)
        cout << x << " ";
}