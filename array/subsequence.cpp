#include<bits/stdc++.h>

using namespace std;

void subsequence(string v)
{
    string b;
    cin >> b;

    int i(0),j(0);
    while(i<v.size() && j<b.size())
    {
        if(v[i]==b[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }

    if(j==b.size())
        cout << "POSITIVE" << endl;
    else
        cout << "NEGATIVE" << endl;
}


int main()
{
    string v,b;
    int n;

    cin >> v;
    cin >> n;
    while(n--)
    {
        subsequence(v);
    }
}