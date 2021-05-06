
//Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.

#include <bits/stdc++.h>

using namespace std;

void sort012(int a[], int n)
{
    int cnt_0 = 0;
    int cnt_1 = 0;
    int cnt_2 = 0;
    
    for(int i=0;i<n;i++)
    {
        if(a[i] == 0)
            cnt_0++;
        if(a[i] == 1)
            cnt_1++;
        if(a[i] == 2)
            cnt_2++;
    }
    
    for(int i=0;i<cnt_0;i++)
    {
        a[i] = 0;
    }
    for(int i=cnt_0;i<cnt_1+cnt_0;i++)
    {
        a[i] = 1;
    }
    for(int i=cnt_1+cnt_0;i<cnt_1+cnt_0+cnt_2;i++)
    {
        a[i] = 2;
    }
    
}

int main()
{

}