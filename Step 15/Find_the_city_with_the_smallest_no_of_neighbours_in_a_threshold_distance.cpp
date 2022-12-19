class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold)
    {
        vector<vector<int>> mat(n, vector<int>(n, INT_MAX));
        for(auto i : edges)
        {
            mat[i[0]][i[1]] = i[2];
            mat[i[1]][i[0]] = i[2];
        }
        for(int i = 0; i < n; i++)
        {
            mat[i][i] = 0;
        }
        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(mat[i][k] == INT_MAX || mat[k][j] == INT_MAX)
                        continue;
                    
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
        int total = n;
        int ans = -1;
        for(int city = 0; city < n; city++)
        {
            int x = 0;
            for(int adjcity = 0; adjcity < n; adjcity++)
            {
                if(mat[city][adjcity] <= distanceThreshold)
                    x++;
            }
            if(x <= total)
            {
                total = x;
                ans = city;
            }
        }
        return ans;
        
    }
};