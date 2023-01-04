#include <bits/stdc++.h> 
int solve(int row, int col, vector<vector<int>> &dp, vector<vector<int>> &grid)
{
    if(row == 0 && col == 0)
        return grid[0][0];
    if(row < 0 || col < 0)
        return 1e9;
   if(dp[row][col] != -1)
       return dp[row][col];
    
    int x = grid[row][col] + solve(row-1, col, dp, grid);
    int y = grid[row][col] + solve(row, col-1, dp, grid);
    
    return dp[row][col] = min(x, y);
        
}
int minSumPath(vector<vector<int>> &grid) 
{
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int>> dp(row, vector<int>(col, -1));
    return solve(row-1, col-1, dp, grid);
}