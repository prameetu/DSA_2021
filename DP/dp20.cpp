#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    //memoized approach
    int dpm[1001][1001];
    //memset(dp,-1,sizeof(dp));
    int matrixMultiplication(int i,int j, int arr[])
    {
        if(i<=j)
            return 0;
        
        if(dpm[i][j] != -1)
            return dpm[i][j];
        
        dpm[i][j] = INT_MAX;

        for(int k=i;k<j;k++)
        {
            dpm[i][j] = min(dpm[i][j], matrixMultiplication(i,k,arr)  + matrixMultiplication(k+1,j,arr) + (arr[i-1]*arr[k]*arr[j]));
        }

        return dpm[i][j];
    }

     int matrixMultiplication(int N, int arr[])
    {
        int dp[N][N];
        
        for(int i=1;i<N;i++)
        {
            dp[i][i] = 0;
        }

        for(int l = 2;l<N;l++)
        {
            for(int i=1;i<N-l+1;i++)
            {
                int j = i+l-1;
                dp[i][j] = INT_MAX;

                for(int k=i;k<j;k++)
                {
                    dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+(arr[i-1]*arr[j]*arr[k]));
                } 
            }
        }

        return dp[1][N-1];
        
    }
};