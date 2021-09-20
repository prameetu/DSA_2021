// 0 1 Knapsack Problem
#include <bits/stdc++.h>

using namespace std;
//recursive code
int knapSack(int W, int wt[], int val[], int n)
{
    if (n == 0 || W == 0)
        return 0;

    if (wt[n - 1] <= W)
    {
        return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1));
    }
    else
    {
        return knapSack(W, wt, val, n - 1);
    }
}
int knapSack(int W, int wt[], int val[], int n)
{
    int dp[n + 1][W + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if(wt[i-1] <= j)
                dp[i][j] = max(val[i-1] + dp[i-1][j - wt[i-1]],dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][W];
}

int main()
{
}