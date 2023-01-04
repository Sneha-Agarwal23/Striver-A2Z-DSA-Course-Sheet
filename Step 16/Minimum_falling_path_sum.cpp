class Solution {
public:
    /*int solve(vector<vector<int>>& matrix, int r, int c)      //Brute Force
    {
        if(r == 0 && c < matrix.size() && c >= 0)
            return matrix[r][c];
        
        if(c >= matrix.size() || c < 0)
            return INT_MAX;
        
        
        return matrix[r][c] + min(min(solve(matrix, r-1, c+1), solve(matrix, r-1, c)), solve(matrix, r-1, c-1));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int ans = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            ans = min(ans, solve(matrix, n-1, i));
        }
        return ans;
        
    }*/
    
    int solve(vector<vector<int>> &dp, vector<vector<int>>& matrix, int r, int c)      
    {
        if(r == 0 && c < matrix.size() && c >= 0)
            return matrix[r][c];
        
        if(c >= matrix.size() || c < 0)
            return INT_MAX;
        
        if(dp[r][c] != INT_MAX)
            return dp[r][c];
        
        
        return dp[r][c] = matrix[r][c] + min(min(solve(dp,matrix, r-1, c+1), solve(dp,matrix, r-1, c)), solve(dp,matrix, r-1, c-1));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MAX));
        int ans = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            ans = min(ans, solve(dp, matrix, n-1, i));
        }
        return ans;
        
    }
};