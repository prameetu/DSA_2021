//find the only non repeating number in array whwere every number repeats twice
#include<bits/stdc++.h>
using namespace std;

int func(vector <int> v)
{
    int ans(0);
    for(auto x:v)
    {
       ans ^=x; 
    }

    return ans;

}

int main()
{
    vector <int> v(7);
    for(int i=0;i<7;i++)
    {
        cin >> v[i];
    }

    cout << "The non rep element is: " << func(v);
}