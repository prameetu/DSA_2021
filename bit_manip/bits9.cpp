//Given: An array A with all elements occuring twice except for x and y that occur once.
//To Do: Find the x and y in O(1) space and O(N) time

#include<bits/stdc++.h>

using namespace std;

int is_bit_set(int n,int k)
{
    int mask = 1 << k;
    int ans = n & mask;

    if(ans)
        return true;
    return false;
}

int main()
{
    int n;
    cin >>n;

    int res(0);
    vector <int> ans{0,0};

    vector <int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin >> nums[i];
        res ^=nums[i];
    }

    int k(0);
    while(!is_bit_set(res,k))
        k++;
    
    for(int i=0;i<n;i++)
    {
        if(is_bit_set(nums[i],k))
        {
            ans[0] ^= nums[i];
        }
        else
        {
            ans[1] ^= nums[i];
        }
    }

    cout << ans[0] << " " << ans[1] << endl;
}