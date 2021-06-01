//setting the ith bit to 1 or 0

#include<bits/stdc++.h>

using namespace std;

void set_bit_1(int n)
{
    int i;
    cout << "Enter i: ";
    cin >> i ;
    int mask = 1 << i;
    int ans  = n | mask;
    cout << ans;
}

void set_bit_0(int n)
{
    int i;
    cout << "Enter i: ";
    cin >> i ;
    int mask = ~(1 << i);
    int ans = n & mask;
    cout << ans;
}

int main()
{
    int n(333);
    int x;
    cout << "Press 0 if you want to set bit to 0 else 1 if you want to set 1";
    cin >> x;
    if(x)
        set_bit_1(n);
    else
        set_bit_0(n);
}
