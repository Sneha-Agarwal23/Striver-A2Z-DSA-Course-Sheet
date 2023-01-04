#include <bits/stdc++.h> 
int countSquares(int n, int m, vector<vector<int>> &arr)
{
    int ans = 0;
    vector<vector<int>> dp(n, vector<int> (m, 0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(i == 0 || j == 0)
            {
                if(arr[i][j] == 1)
                    dp[i][j] = 1;
            }
            else
            {
                if(arr[i][j] == 1)
                {
                    int x = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
                    dp[i][j] = x+1;
                }
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(dp[i][j] != 0)
                ans += dp[i][j];
        }
    }
    return ans;
}


