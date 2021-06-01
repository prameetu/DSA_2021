//find ith bit
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n(333);
    int i;
    cout << "Enter i: ";
    cin >> i ; 
    int mask  = 1 << i;
    if(n & mask)
        cout << "The " << i << "th bit is 1";
    else
        cout << "The " << i << "th bit is 0";
}