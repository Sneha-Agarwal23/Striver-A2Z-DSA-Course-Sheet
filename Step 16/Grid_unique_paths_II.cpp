class Solution {
public:
    /*int solve(int i, int j, vector<vector<int>> &dp, vector<vector<int>>& obstacleGrid)
    {
        if(obstacleGrid[i][j] == 1)
            return 0;
        if(i == 0 && j == 0)
            return 1;
        
        if(i == 0)
            return dp[i][j-1];
        if(j == 0)
            return dp[i-1][j];
        return dp[i][j-1] + dp[i-1][j];
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        if(obstacleGrid[n-1][m-1] == 1)
            return 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                dp[i][j] = solve(i, j, dp, obstacleGrid);
            }
        }
        return dp[n-1][m-1];
        
    }*/
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        dp[0][1] = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(obstacleGrid[i-1][j-1] == 0)
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[n][m];
    }
};