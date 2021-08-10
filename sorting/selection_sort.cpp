#include<bits/stdc++.h>

using namespace std;

void selection_sort(vector <int> &v)
{
    int n(v.size());
    int k,j;
    for(int i=0;i<n-1;i++)
    {
        k=i;
        for(int j=i;j<n;j++)
        {
            if(v[j] < v[k])
                k = j;
        }
        swap(v[i],v[k]);
    }
}

int main()
{
    int n;
    cin >> n;
    vector <int> v(n);
    for(int i=0;i<n;i++)
    {
        cin  >> v[i];
    }

    selection_sort(v);

    for(auto x:v)
        cout << x << " ";
}