class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        int row = heights.size();
        int col = heights[0].size();
        
        vector<vector<int>> dist(row, vector<int>(col, INT_MAX));
        dist[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0,{0,0}});
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        while(!pq.empty())
        {
            auto x = pq.top();
            pq.pop();
            int i = x.second.first;
            int j = x.second.second;
            int d = x.first;
            if(i == row-1 && j == col-1)
                return d;
            for(int k = 0; k < 4; k++)
            {
                int a = i + dx[k];
                int b = j + dy[k];
                if(a >= 0 && a < row && b >= 0 && b < col)
                {
                    int newdist = abs(heights[i][j] - heights[a][b]);
                    if(dist[a][b] > max(newdist, d))
                    {
                        dist[a][b] = max(newdist, d);
                        pq.push({dist[a][b], {a, b}});
                    }
                }
            }
        }
        return dist[row-1][col-1];
    }
};