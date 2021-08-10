#include<bits/stdc++.h>

using namespace std;

void bubble_sort(vector <int> &v)
{
    int flag(0);
    int n(v.size());
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(v[j] > v[j+1]){
                swap(v[j],v[j+1]);
                flag = 1;
            }
        }
        if(flag == 0)
            break;
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
    bubble_sort(v);

    for(auto x:v)
        cout << x << " ";
}