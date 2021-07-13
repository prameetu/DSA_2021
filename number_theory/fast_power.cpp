#include <bits/stdc++.h>

using namespace std;

int power(int a,int b)//Time complexity of this soution is O(n)
{
    if(b==0)
        return 1;
    else
        return a*power(a,b-1);
}

int fast_power(int a,int b)
{
    if(b==0)
        return 1; 
    if(b==1)
        return a;
    if(b%2 != 0)
    {
        return a*fast_power(a,b/2)*fast_power(a,b/2);
    }
    else
    {
        return fast_power(a,b/2)*fast_power(a,b/2);
    }
}

int main()
{
    int a,b;
    cin >> a >> b;
    cout << fast_power(a,b);    

    
}