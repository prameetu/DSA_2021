// Count number of subsets with given sum
#include<bits/stdc++.h>
using namespace std;

// Perfect Sum Problem 
//https://www.geeksforgeeks.org/count-of-subsets-with-sum-equal-to-x/

class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
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
                else if(arr[i-1] <= j)
                    dp[i][j] = dp[i-1][j]%1000000007 + dp[i-1][j-arr[i-1]]%1000000007;
                else if(arr[i-1] > j)
                    dp[i][j] = dp[i-1][j]%1000000007;
            }
        }
        return dp[n][sum]%1000000007;
	}
	  
};