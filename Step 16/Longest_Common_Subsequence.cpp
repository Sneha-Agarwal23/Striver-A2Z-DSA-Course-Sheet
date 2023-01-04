#include<bits/stdc++.h>
int solve(string s, int m, string t, int n, vector<vector<int>>& dp)
{
    if(m == 0)
        return 0;
    if(n == 0)
        return 0;
    if(dp[m-1][n-1] != -1)
        return dp[m-1][n-1];
    if(s[m-1] != t[n-1])
    {
        dp[m-1][n-1] = max(solve(s, m-1, t, n, dp) , solve(s, m, t, n-1, dp));
    }
    else
    {
        dp[m-1][n-1] = 1 + solve(s, m-1, t, n-1, dp);
    }
    return dp[m-1][n-1];
}
int lcs(string s, string t)
{
	int m = s.length();
    int n = t.length();
    vector<vector<int>> dp(m, vector<int> (n, -1));
    int ans = solve(s, m, t, n, dp);
    return ans;
}