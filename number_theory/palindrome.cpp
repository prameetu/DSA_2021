#include<bits/stdc++.h>

using namespace std;

int reverse(int n)
{
    int rev(0);
    while(n>0)
    {
        rev = rev*10 + (n%10);
        n /= 10;
    }

    return rev;
}

bool check_palindrome(int n)
{
    int rev = reverse(n);
    if(rev == n)
        return true;
    else
        return false;
}

int main()
{
    int n;
    cin >> n;
    bool res = check_palindrome(n);
    if(res)
        cout << n << " is a paildrome number" << endl;
    else
        cout << n << " not a plaindrome number" << endl;
}