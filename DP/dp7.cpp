//leetcode - 494
//Target sum
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int perfectSum(vector<int>& nums, int n, int sum)
	{
        int dp[n+1][sum+1];

        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(j==0)
                    dp[i][j] = 1;
                else if(i==0)
                    dp[i][j] = 0;
                else if(nums[i-1] <= j)
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                else if(nums[i-1] > j)
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum];
	}
    int findTargetSumWays(vector<int>& nums, int target) {
        int range(0);
        for(int i=0;i<nums.size();i++)
        {
            range += nums[i];
        }
        int s1 = (range+target)/2;

        if(abs(target)>range || (range+target)%2 != 0)
            return 0;
        return perfectSum(nums,nums.size(),s1);
    }
};


// class Solution {
// public:
//     int countSubsets(vector<int>& nums, int n, int M)
//     {
//         int t[n + 1][M + 1];
        
//        for(int i = 0; i <= n; i++)
//         {
//             for(int j = 0; j <= M; j++)
//             {
//                 if(i == 0)
//                     t[i][j] = 0;
//                 if(j == 0)
//                     t[i][j] = 1;
//             }
//         }
        
//         //t[0][0] = 1;
        
//         for(int i = 1; i <= n; i++)
//         {
//             for(int j = 0; j <= M; j++)
//             {
//                 if(nums[i - 1] <= j)
//                  t[i][j] = t[i - 1][j - nums[i - 1]] + t[i - 1][j];
//                 else
//                   t[i][j] = t[i - 1][j];
//             }
//         }
        
//         return t[n][M];  
//     }
    
//     int findTargetSumWays(vector<int>& nums, int target)
//      {
//          target = abs(target);
//          int n = nums.size();
//          int sum = 0;
//          for(int i = 0; i < n; i++)
//              sum += nums[i];
         
//         int M = (sum + target)/2;
//         if(sum < target || (sum + target) % 2 != 0)
//             return 0;
//          return countSubsets(nums, n, M);
//      }
// };