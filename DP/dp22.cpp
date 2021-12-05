//Boolean Parenthesization
#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    int dp[204][204][2];
    int helper(string str,int i,int j,bool isTrue)
    {
        if(i>j)
            return 0;
        if(i==j)
        {
            if(isTrue)
                return str[i] == 'T';
            else 
                return str[i] == 'F';
        }

        if(dp[i][j][isTrue] != -1)
            return dp[i][j][isTrue];

        int ans(0);

        for(int k=i+1;k<=j-1;k=k+2)
        {
            int leftTrue,leftFalse,rightTrue,rightFalse;

            if(dp[i][k-1][true] == -1)
                leftTrue = helper(str,i,k-1,true);
            else 
                leftTrue = dp[i][k-1][true];

            if(dp[i][k-1][false] == -1)
                leftFalse = helper(str,i,k-1,false);
            else 
                leftFalse = dp[i][k-1][false];

            if(dp[k+1][j][true] == -1)
                rightTrue = helper(str,k+1,j,true);
            else 
                rightTrue = dp[k+1][j][true];
            
            if(dp[k+1][j][false] == -1)
                rightFalse = helper(str,k+1,j,false);
            else    
                rightFalse = dp[k+1][j][false];

            
            
            if(str[k] == '^')
            {
                if(isTrue)
                    ans += (leftTrue*rightFalse) + (leftFalse*rightTrue);
                else
                    ans += (leftFalse*rightFalse) + (rightTrue*leftTrue);
            }
            else if(str[k] == '&')
            {
                if(isTrue)
                    ans += (leftTrue*rightTrue);
                else
                    ans += (leftTrue*rightFalse) + (leftFalse*rightTrue) + (leftFalse*rightFalse);
            }
            else if(str[k] == '|')
            {
                if(isTrue)
                    ans += (leftTrue*rightFalse) + (leftFalse*rightTrue) + (leftTrue*rightTrue);
                else    
                    ans += leftFalse*rightFalse;

            }
            dp[i][j][isTrue] = ans%1003;

        }

        return ans%1003;
    }

    int countWays(int N, string S){
        // code here

        memset(dp,-1,sizeof(dp));
        return helper(S,0,N-1,true);

    }
};