#include <bits/stdc++.h> 
int solve(string &str,int n, string &ptr, int m, vector<vector<int>>& dp, int i, int j)
{
    if(i == n || j == m)
        return 0;
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int a = 0;
    if(str[i] == ptr[j])
        a = 1 + solve(str, n, ptr, m, dp, i+1, j+1);
    else
    {
        int x = solve(str, n, ptr, m, dp, i+1, j);
        int y = solve(str, n, ptr, m, dp, i, j+1);
        a = max(x, y);
    }
    dp[i][j] = a;
    return a;
}
int canYouMake(string &str, string &ptr)
{
    int n = str.length();
    int m = ptr.length();
    vector<vector<int>> dp(n, vector<int> (m, -1));
    int l = solve(str, n, ptr, m, dp, 0, 0);
    int ans = n + m - (2*l);
    return ans;
}