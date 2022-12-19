class Solution {
public:
    int swimInWater(vector<vector<int>>& grid)
    {
        int n = grid.size();
        if(grid[0][0] == 0 && n == 1)
            return 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int ans = max(grid[0][0], grid[n-1][n-1]);
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vis[0][0] = 1;
        vector<int> dirx = {1, -1, 0, 0};
        vector<int> diry = {0, 0, -1, 1}; 
        pq.push({ans, 0, 0});
        while(!pq.empty())
        {
            auto x = pq.top();
            pq.pop();
            ans = max(ans, x[0]);
            for(int i = 0; i < 4; i++)
            {
                int r = x[1] + dirx[i];
                int c = x[2] + diry[i];
                if(r >= 0 && r < n && c >= 0 && c < n && vis[r][c] == 0)
                {
                    if(r == n-1 && c == n-1)
                        return ans;
                    pq.push({grid[r][c], r, c});
                    vis[r][c] = 1;
                }
            }
        }
        return -1;
        
    }
};