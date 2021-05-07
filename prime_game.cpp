
#include<bits/stdc++.h>

using namespace std;

void solve()
{
    int l,r;
    cin >> l >> r;

    vector <int> prime(r+1,0);
    vector <int> s;

    for(int i=l;i<=r;i++)
    {
        prime[i] = 1;
    }

    for(int i=l;i<=r;i++)
    {
        if(prime[i] == 1)
        {
            for(int j=i*i;j<=r;j+=i)
            {
                prime[j] = 0;
            }
        }
    }

    prime[2] = 1;
    for(int i=0;i<prime.size();i++)
    {
        if(prime[i] == 1)
        {
            s.push_back(i);
        }
    }

    for(auto x:s)
        cout << x << " ";
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        void solave();
    }
}