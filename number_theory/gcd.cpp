#include<bits/stdc++.h>

using namespace std;

int gcd(int a,int b)
{
    int n = min(a,b);
    int gcd = 1;
    for(int i=1;i<=n;i++)
    { 
        if(a%i==0 && b%i==0)
        {
            gcd =  i;
        }
    }

    return gcd;
}

int euclid_gcd(int a,int b)
{
    if(b==0)
        return a;
    else
    {
        euclid_gcd(b,a%b);
    }
}

int lcm(int a,int b)
{
    return (a*b)/euclid_gcd(a,b);
}



int main()
{
    int a,b;
    cin >> a >> b;
    cout << "GCD OF " << a << " and "<< b << ": " << euclid_gcd(a,b) <<endl;; 
    cout << "LCM OF " << a << " and "<< b << ": " << lcm(a,b); 

}