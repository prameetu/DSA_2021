//TRADITIONAL METHOD FOR CHENCKING PRIME
#include<bits/stdc++.h>

#define rep(i,a,b) for(int i=a;i<b;i++)
#define long long ll

using namespace std;

int check_prime(int n)
{
    if(n==0 || n==1)
        return 0;
    else if(n==2)
        return 1;
    else
    {
        rep(i,2,sqrt(n)+1)
        {
            if(n%i == 0)
                return 0;
        }
    }

    return 1;
}

int main()
{
    int n;
    cin >> n;
    if(check_prime(n))
    {
        cout << "Yes " << n << " is prime no.";
    }
    else
    {
         cout << "No " << n << " is not a prime no.";
    }
}