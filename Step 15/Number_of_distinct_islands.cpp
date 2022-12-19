//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int i, int j, int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis,vector<pair<int, int>>& v, int x,int y)
    {
        if(i < 0 || j < 0 || i > row-1 || j > col-1 || grid[i][j] == 0 || vis[i][j] == 1)
            return;
        
        vis[i][j] = 1;
        v.push_back({i-x, j-y});
        dfs(i+1, j, row, col, grid, vis, v,x,y);
        dfs(i-1, j, row, col, grid, vis, v,x,y);
        dfs(i, j+1, row, col, grid, vis, v,x,y);
        dfs(i, j-1, row, col, grid, vis, v,x,y);
        
    }
    int countDistinctIslands(vector<vector<int>>& grid) 
    {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> vis(row, vector<int>(col, 0));
        set<vector<pair<int, int>>> s;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(grid[i][j] == 1 && vis[i][j] == 0)
                {
                    vector<pair<int, int>> v;
                    dfs(i, j, row, col, grid, vis, v,i,j);
                    s.insert(v);
                }
            }
        }
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends