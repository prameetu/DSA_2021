// Minimum number of steps(insertion or deletion) to convert string a to string b

//Leetcode - 583

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();

        int dp[n + 1][m + 1];

        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < m + 1; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        // string res = "";
        // int i(n),j(m);
        // while(i > 0 && j > 0)
        // {
        //     if(word1[i-1] == word2[j-1])
        //     {
        //         res.push_back(word1[i-1]);
        //         i--;
        //         j--;
        //     }
        //     else
        //     {
        //         if(dp[i-1][j] > dp[i][j-1])
        //             i--;
        //         else
        //             j--;
        //     }
        // }

        // reverse(res.begin(),res.end());

        int ans(0);

        int res_size(dp[n][m]);

        ans = (n-res_size) + (m-res_size);

        return ans;


        // int p(0),q(0);

        // while(p<word1.size() && q < res.size())
        // {
        //     if(word1[p] == word2[q])
        //     {
        //         p++;q++;
        //     }
        //     else
        //     {
        //         ans++;
        //         p++;
        //     }
        // }

        // if(p < word1.size())
        // {
        //     ans = ans + (word1.size()-p);
        // }

        // p = 0;
        // q = 0;



    }
};