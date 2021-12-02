//Palindrome Partitioning
#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
//---------------RECURSIVE APPROACH--------------    
    // int helper(string s,int i,int j)
    // {
    //     if(i<=j)
    //         return 0;
    //     if(isPalindrome(s,i,j))
    //         return 0;
    //     int ans(INT_MAX);
    //     for(int k=i;k<j;k++)
    //     {
    //         int temp = helper(s,i,k) + helper(s,k+1,j) + 1;
    //         ans = min(ans,temp);
    //     }
    //     return ans;
    // }
    int dp[501][501];

    bool isPalindrome(string s,int i,int j)
    {
        while (i<=j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    


    int helper(string s,int i,int j)
    {
        if(dp[i][j] != -1)
            return dp[i][j];

        if(i>=j || isPalindrome(s,i,j))
            return 0;
        int ans(INT_MAX);
        for(int k=i;k<j;k++)
        {
            int ct = helper(s,i,k) + helper(s,k+1,j) + 1;
            ans = min(ct,ans);
        }
        dp[i][j] = ans;
        return ans;

    }


    int palindromicPartition(string str)
    {
        memset(dp,-1,sizeof(dp));
        return helper(str,0,str.size()-1);
    }

    int palindromicPartition(string str)
    {
        int n = str.size();

        int dp[n][n];

        for(int i=0;i<n;i++)
            dp[i][i] = 0;

        for(int l=2;l<=n;l++)
        {
            for(int i=0;i<=n-l;i++)
            {
                int  j = i + l - 1;

                if (isPalindrome(str,i,j))
                    dp[i][j] = 0;

                else
                {
                    dp[i][j] = INT_MAX;
                    for(int k = i;k<j;k++)
                    {
                        dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+1);
                    }
                }    
                
            }

        }

        return dp[0][n-1];
    }
};