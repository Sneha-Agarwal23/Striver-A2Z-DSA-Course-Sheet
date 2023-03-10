#include <bits/stdc++.h> 
int solve(int i, int j, int n, vector<vector<int>> &dp, vector<vector<int>> &triangle)
{
    if(i == n-1)
        return triangle[i][j];
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int x = triangle[i][j] + solve(i+1, j, n, dp, triangle);
    int y = triangle[i][j] + solve(i+1, j+1, n, dp, triangle);
    
    return dp[i][j] = min(x, y);
}
int minimumPathSum(vector<vector<int>>& triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve(0, 0, n, dp, triangle);
}