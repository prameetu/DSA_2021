#include<bits/stdc++.h>

using namespace std;

void factorisation(int n)
{
    while(n!=1)
    {
        for(int i=2;i<=n;i++)
        {
            if(n%i == 0)
            {
                cout << i << " ";
                n=n/i;
                break;
            }
        }
    }
    
}


int main()
{
    int n;
    cin >> n;
    factorisation(n);
}
