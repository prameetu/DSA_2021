//count number of subsets with guven difference 
#include<bits/stdc++.h>
using namespace std;

class Solution{

  public:
	int minDifference(int arr[], int n,int diff)  { 
	    int range(0);
        for(int i=0;i<n;i++)
        {
            range += arr[i];
        }
        int dp[n+1][range+1];
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<range+1;j++)
            {
                if(j==0)
                    dp[i][j] = 1;
                else if(i==0)
                    dp[i][j] = 0;
                else if(arr[i-1] <= j)
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
                else if(arr[i-1] > j)
                    dp[i][j] = dp[i-1][j];
            }
        }

        int s1 = (range+diff)/2;
        return dp[n][s1];

	} 
};