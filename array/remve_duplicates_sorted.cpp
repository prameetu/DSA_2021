//leetcode - 26

#include<bits/stdc++.h>

using namespace std;

int remove_duplicate_sorteed_array(vector <int> &v)
{
    if(v.size() == 0)
        return 0;

    int i(0);
    int j(1);

    while(j<v.size())
    {
        if(v[i] == v[j])
        {
            j++;
        }
        else
        {
            i++;
            v[i] = v[j];
            j++;
        }
    }

    return i+1;

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

    for(int i=0;i<remove_duplicate_sorteed_array(v);i++)
    {
        cout << v[i] << " ";
    }
}