class Solution {
public:
    //Undirected graph using dfs
    /*bool iscycle(vector<int> adj[], vector<int>& vis, int node)
    {
        if(vis[node] == 1)
            return true;
        if(vis[node] == 0)
        {
            vis[node] = 1;
            for(auto e : adj[node])
            {
                if(iscycle(adj, vis, e))
                {
                    return true;
                }
            }
        }
        vis[node] = 2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<int> adj[numCourses];
        for(auto e : prerequisites)
        {
            adj[e[1]].push_back(e[0]);  
        }
        vector<int> vis(numCourses, 0);
        for(int i = 0; i < numCourses; i++)
        {
            if(iscycle(adj, vis, i) == true)
                return false;
        }
        return true;
        
    }*/
    
    //undirected graph using bfs
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> adj(numCourses);
        vector<int> vis(numCourses, 0);
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
                numCourses--;
            }
        }
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            for(int i = 0; i < adj[node].size(); i++)
            {
                vis[adj[node][i]]--;
                if(vis[adj[node][i]] == 0)
                {
                    q.push(adj[node][i]);
                    numCourses--;
                }
            }
        }
        if(numCourses == 0)
            return true;
        else
            return false;
    }
    
};