//checking for odd even number
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n & 1 )
        cout << "ODD";
    else if(!(n & 1))
        cout << "EVEN";
}