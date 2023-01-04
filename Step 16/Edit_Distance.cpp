#include<bits/stdc++.h>
int solve(string& str1, int n, string& str2, int m, vector<vector<int>>& dp)
{
    if(n < 0)
        return m+1;
    if(m < 0)
        return n+1;
    if(dp[n][m] != -1)
        return dp[n][m];
    
    if(str1[n-1] == str2[m-1])
        return solve(str1, n-1, str2, m-1, dp);
    else
    {
        int insert = 1 + solve(str1, n-1, str2, m, dp);
        int dlt = 1 + solve(str1, n, str2, m-1, dp);
        int replace = 1 + solve(str1, n-1, str2, m-1, dp);
        dp[n][m] = min(insert, min(dlt, replace));
    }
    return dp[n][m];
}
int editDistance(string str1, string str2)
{
    int n = str1.length();
    int m = str2.length();
    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
    int ans = solve(str1, n, str2, m, dp);
    return ans;
}