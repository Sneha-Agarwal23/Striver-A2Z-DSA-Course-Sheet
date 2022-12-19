class Solution {
public:
    //Directed graph using dfs
    /*bool iscycle(vector<vector<int>>& adj, vector<int>& vis, int node, vector<int>& ans)
    {
        vis[node] = 1;
        for(int i = 0; i < adj[node].size(); i++)
        {
            if(vis[adj[node][i]] == 1)
                return false;
            if(vis[adj[node][i]] == 0)
            {
                if(iscycle(adj, vis, adj[node][i], ans) == false)
                {
                    return false;
                }
            }
        }
        vis[node] = 2;
        ans.push_back(node);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> adj(numCourses);
        for(auto e : prerequisites)
        {
            adj[e[1]].push_back(e[0]);  
        }
        vector<int> vis(numCourses, 0);
        vector<int> ans;
        bool flag = true;
        for(int i = 0; i < numCourses; i++)
        {
            if(vis[i] == 0)
            {
                if(iscycle(adj, vis, i, ans) == false)
                {
                    flag = false;
                    break;
                }
            }
        }
        if(flag == false)
        {
            return vector<int>();
        }
        reverse(ans.begin(), ans.end());
        return ans;*/
    
    //Directed graph using bfs
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> adj(numCourses);
        vector<int> vis(numCourses, 0);
        vector<int> ans;
        queue<int> q;
        for(auto e : prerequisites)
        {
            adj[e[1]].push_back(e[0]);
            vis[e[0]]++;
        }
        for(int i = 0; i < vis.size(); i++)
        {
            if(vis[i] == 0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            auto node = q.front();
            ans.push_back(node);
            q.pop();
            for(int i = 0; i < adj[node].size(); i++)
            {
                vis[adj[node][i]]--;
                if(vis[adj[node][i]] == 0)
                {
                    q.push(adj[node][i]);
                }
            }
        }
        if(ans.size() == numCourses)
        {
            return ans;
        }
        else
            return vector<int>();
    }
};