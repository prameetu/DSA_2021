//Longest common subsequence of string and printing the LCS of string

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int helper(string text1, int n, string text2, int m)
    {
        if (n == 0 || m == 0)
            return 0;

        if (text1[n - 1] == text2[m - 1])
            return helper(text1, n - 1, text2, m - 1) + 1;
        else
            return max(helper(text1, n - 1, text2, m), helper(text1, n, text2, m - 1));
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        return helper(text1, text1.size(), text2, text2.size());
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        int dp[n + 1][m + 1];

        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < m + 1; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }

    string printLCS(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();

        int dp[n + 1][m + 1];

        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < m + 1; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        string res = "";
        int i(n),j(m);
        while(i > 0 && j > 0)
        {
            if(text1[i-1] == text2[j-1])
            {
                res.push_back(text1[i-1]);
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

        reverse(res.begin(),res.end());
        return res;

    }
};