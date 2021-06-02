//number of set bits

#include<bits/stdc++.h>

using namespace std;

int no_set_bits(int n)
{
    int ans(0);
    while(n)
    {
        if(n & 1 )
            ans++;
        n = n>>1;
    }

    return ans;
}

int no_of_set_bits_optimized(int n)
{
    int ans(0);
    while(n)
    {
        n = n & n-1;
        ans++;
    }

    return ans;
}


int main()
{
    int a(22),b(27);
    cout << no_of_set_bits_optimized(a) << endl;
    cout << no_of_set_bits_optimized(b) ;

}