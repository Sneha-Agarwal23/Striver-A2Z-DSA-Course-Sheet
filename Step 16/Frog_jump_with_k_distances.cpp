class Solution {
public:
    double dfs(int src, vector<vector<int>>& adj, vector<int>& vis, int t, int target)
    {
        vis[src] = 1;
        if(t == 0)
        {
            if(src == target)
                return 1.0;
            else
                return 0.0;
        }
        int count = 0;
        double ans, temp = 0.0;
        for(auto i : adj[src])
        {
            int node = i;
            if(vis[node] == 0)
            {
                count++;
                temp += dfs(node, adj, vis, t-1, target);
            }
        }
        if(count > 0)
        {
            ans = 1.0 / count;
            ans = ans * temp;
        }
        else
        {
            if(src == target)
                ans = 1.0;
            else
                ans = 0.0;
        }
        return ans;
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target)
    {
        vector<vector<int>> adj(n+1);
        vector<int> vis(n+1, 0);
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return dfs(1, adj, vis, t, target);
    }
};