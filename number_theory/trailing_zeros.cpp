#include<iostream>
using namespace std;

int trailing_zeros(int n)
{
    int res(0);
    for(int i=5;i<=n;i*=5)
    {
        res += n/i;
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    cout << "The number of trailing zeros are : " << trailing_zeros(n) << endl;
}