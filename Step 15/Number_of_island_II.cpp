//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(vector<vector<char>>& grid, int i, int j, int row, int col, vector<vector<int>>& vis)
    {
        if(i < 0 || j < 0 || i > row-1 || j > col-1 ||vis[i][j] == 1 || grid[i][j] == '0')
            return;
            
        vis[i][j] = 1;
        dfs(grid, i-1, j, row, col, vis);
        dfs(grid, i+1, j, row, col, vis);
        dfs(grid, i, j-1, row, col, vis);
        dfs(grid, i, j+1, row, col, vis);
        dfs(grid, i-1, j+1, row, col, vis);
        dfs(grid, i+1, j+1, row, col, vis);
        dfs(grid, i+1, j-1, row, col, vis);
        dfs(grid, i-1, j-1, row, col, vis);
    }
    int numIslands(vector<vector<char>>& grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(row, vector<int> (col, 0));
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(vis[i][j] == 0 && grid[i][j] == '1')
                {
                    ans++;
                    dfs(grid, i, j, row, col, vis);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends