class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<vector<pair<int,int>>> adj(n+1);
        int x = times.size();
        for(int i = 0; i < x; i++)
        {
            int source = times[i][0];
            int dest = times[i][1];
            int time = times[i][2];
            adj[source].push_back({time,dest});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        while(!pq.empty())
        {
            auto a = pq.top();
            pq.pop();
            int t = a.first;
            int node = a.second;
            for(auto i : adj[node])
            {
                int p = i.first;
                int q = i.second;
                if(dist[q] > t+p)
                {
                    dist[q] = t+p;
                    pq.push({dist[q], q});
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            if(dist[i] == INT_MAX)
                return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};