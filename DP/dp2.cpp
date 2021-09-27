//subet sum problem
//Given an array of non-negative integers, and a value sum,
//determine if there is a subset of the given set with sum equal to given sum.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSubsetSum(int N, int arr[], int sum)
    {
        bool dp[N + 1][sum + 1];

        for (int i = 0; i < N + 1; i++)
        {
            for (int j = 0; j < sum + 1; j++)
            {
                if (j == 0)
                    dp[i][j] = true;

                else if (i == 0)
                    dp[i][j] = false;

                else if (arr[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                
                else if (arr[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[N][sum];
    }
};