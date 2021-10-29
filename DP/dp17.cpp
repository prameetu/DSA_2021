//Longest Palindromic Substring
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string rev(s);
        
        reverse(s.begin(),s.end());
        int n = s.size();

        int m = rev.size();

        int dp[n + 1][m + 1];

        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < m + 1; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (s[i - 1] == rev[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = 0;
            }
        }

        string res = "";
        int i(n),j(m);
        while(i > 0 && j > 0)
        {
            if(s[i-1] == rev[j-1])
            {
                res.push_back(s[i-1]);
                i--;
                j--;
            }
            else
            {
                if(dp[i-1][j] > dp[i][j-1])
                    i--;
                else
                    j--;
            }
        }

        return res;
    }
};