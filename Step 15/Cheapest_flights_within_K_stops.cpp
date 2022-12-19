class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        vector<pair<int, int>> adj[n];
        vector<int> dist(n, INT_MAX);
        for(auto i : flights)
        {
            adj[i[0]].push_back({i[1], i[2]});
        }
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        dist[src] = 0;
        while(!q.empty())
        {
            auto x = q.front();
            q.pop();
            int stop = x.first;
            int node = x.second.first;
            int cost = x.second.second;
            if(stop > k)
                continue;
            for(auto i : adj[node])
            {
                int a = i.first;
                int b = i.second;
                if(dist[a] > cost + b && stop <= k)
                {
                    dist[a] = cost + b;
                    q.push({stop+1, {a, cost+b}});
                }
            }
        }
        if(dist[dst] == INT_MAX)
            return -1;
        return dist[dst];
        
    }
};