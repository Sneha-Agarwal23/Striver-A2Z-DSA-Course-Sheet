#include<bits/stdc++.h>
bool ispalindrome(string& s, int i, int j)
{
    while(i < j)
    {
        if(s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int palindromePartitioning(string str)
{
    int n = str.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for(int i = n-1; i >= 0; i--)
    {
        for(int j = i; j < n; j++)
        {
            if(ispalindrome(str, i, j) == true)
                dp[i][j] = 0;
            else
            {
                int ans = 1e9;
                for(int k = i; k < j; k++)
                {
                    ans = min(ans, dp[i][k] + dp[k+1][j] + 1);
                }
                dp[i][j] = ans;
            }
        }
    }
    return dp[0][n-1];
}
