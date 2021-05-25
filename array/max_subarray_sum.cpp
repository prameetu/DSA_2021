//kadanes algo
//leetcode-53
//Given an integer array nums, find the contiguous subarray 
//(containing at least one number)
// which has the largest sum and return its sum.

#include<bits/stdc++.h>

using namespace std;

int max_subarray_naive(vector <int> &v)
{
    int max_sum = INT32_MIN;

    for(int i=0;i<v.size();i++)
    {
        int sum(0);
        for(int j=i;j<v.size();j++)
        {
            sum += v[j];

            max_sum = max(max_sum,sum);

        }
    }
    return max_sum;
}

int maxSubArray(vector<int> &nums) 
{        
    int max_sum = INT32_MIN;
    int curr_sum(0);

    for(int i=0;i<nums.size();i++)
    {
        curr_sum += nums[i];

        if(curr_sum > max_sum)
            max_sum = curr_sum;
        
        if(curr_sum < 0)
            curr_sum = 0;
    }    

    return max_sum;
}

int main()
{
    vector <int> v;
    int n,x;
    cin >> n;
    while(n--)
    {
        cin >> x;
        v.push_back(x);
    }

    cout << max_subarray_naive(v);
}