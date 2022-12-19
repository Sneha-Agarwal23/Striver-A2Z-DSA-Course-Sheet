class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
    bool isvalid(int i, int j, int row, int col)
    {
        if(i < 0 || j < 0 || i > row-1 || j > col-1)
            return false;
        return true;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> vis(row, vector<int>(col, -1));
        queue<pair<int, int>> q;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({i, j});
                    vis[i][j] = 0;
                }
            }
        }
        while(!q.empty())
        {
            auto x = q.front();
            q.pop();
            for(auto j : dir)
            {
                int a = x.first + j[0];
                int b = x.second + j[1];
                if(isvalid(a, b, row, col) && vis[a][b] == -1)
                {
                    q.push({a, b});
                    vis[a][b] = vis[x.first][x.second] + 1;
                }
                    
            }
        }
        return vis;
        
    }
};