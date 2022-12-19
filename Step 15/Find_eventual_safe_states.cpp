class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int> &vis, vector<int> &path, int i)
    {

        if(path[i] == 1)
            return true;
        if(vis[i] == 1)
            return false;
        vis[i] = 1;
        path[i] = 1;
        for(auto j : graph[i])
        {
            if(dfs(graph, vis, path, j) == true)
                return true;
        }
        path[i] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int> ans;
        vector<int> vis(n, 0);
        vector<int> path(n, 0);
        for(int i = 0; i < n; i++)
        {
            if(dfs(graph, vis, path, i) == false)
                ans.push_back(i);
            
        }
        return ans;
        
    }
};