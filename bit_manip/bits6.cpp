//Number of bits required to change the number from a to b

#include<bits/stdc++.h>

using namespace std;

int no_set_bits(int n)
{
    int ans(0);
    while(n)
    {
        n = n & n-1;
        ans++;
    }

    return ans;
}

int func(int a,int b)
{
    int res = a^b;
    return (no_set_bits(res));
}


int main()
{
    int a(21),b(26);
    cout << "No of bits required to change " << a << " to " << b << " is " << func(a,b); 
}