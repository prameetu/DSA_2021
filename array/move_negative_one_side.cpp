//Move all negative numbers 
//to beginning and positive to end with constant extra space
#include<bits/stdc++.h>

using namespace std;

void ans(vector <int> &v)
{
    int i(0),j(v.size() - 1);
    while(i<j)
    {
        if(v[i] > 0 && v[j] < 0)
        {
            swap(v[i],v[j]);
            i++;
            j--;
        }
        else if(v[i] > 0 && v[j] > 0)
            j--;
        else if(v[i] < 0 && v[j] < 0)
            i++;
        else
        {
            i++;j--;
        }

    }

    for(auto x:v)
        cout << x << " ";
}

int main()
{
    vector <int> v;
    int n,x;
    cin >> n;
    while(n--)
    {
        cin >> x;
        v.push_back(x);
    }
    ans(v);
}