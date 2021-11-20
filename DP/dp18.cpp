//Minimum number of deleteion to make string palindrome
#include<bits/stdc++.h>

using namespace std;

class Solution{
  public:
    int minimumNumberOfDeletions(string S) { 
        // code here
        string s2 = S;
        reverse(s2.begin(),s2.end());

        int n = S.size();
        int m = s2.size();

        int dp[n+1][m+1];

        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<m+1;j++)
            {
                if(i==0 || j==0)
                    dp[i][j] = 0;
                else if(S[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }

        return n-dp[n][m];
    } 
};