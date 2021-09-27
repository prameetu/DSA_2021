//leetcode 416
//Partition equal subset

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isSubsetSum(vector<int> &nums, int sum)
    {
        int n = nums.size();

        bool dp[n + 1][sum + 1];

        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < sum + 1; j++)
            {
                if (j == 0)
                    dp[i][j] = true;
                else if (i == 0)
                    dp[i][j] = false;
                else if (nums[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
                else if (nums[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][sum];
    }
    bool canPartition(vector<int> &nums)
    {
        int sum(0);
        for(auto x:nums)
            sum += x;

        if(sum % 2 != 0)
            return false;
        else
        {
            return isSubsetSum(nums,sum/2);
        } 
    }
};