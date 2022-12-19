class Solution {
public:
    void dfs(vector<vector<int>>& adj,vector<bool> &vis, int i)
    {
        vis[i] = true;
        for(auto j : adj[i])
        {
            if(vis[j] == false)
            {
                dfs(adj, vis, j);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        if(connections.size() < n-1)
            return -1;
        vector<vector<int>> adj(n);
        for(auto i : connections)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int ans = 0;
        vector<bool> vis(n, false);
        for(int i = 0; i < n; i++)
        {
            if(vis[i] == false)
            {
                dfs(adj, vis, i);
                ans++;
            }
        }
        return ans-1;
                
    }
};