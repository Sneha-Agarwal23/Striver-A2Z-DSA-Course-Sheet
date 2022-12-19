#define ll long long
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads)
    {
        vector<pair<ll, ll>> adj[n];
        for(auto it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        vector<ll> dist(n, LONG_MAX);
        vector<ll> path(n, 0);
        pq.push({0, 0});
        dist[0] = 0;
        path[0] = 1;
        int mod = 1e9+7;
        
        while(!pq.empty())
        {
            auto t = pq.top();
            pq.pop();
            ll time = t.first;
            ll node = t.second;
            for(auto i : adj[node])
            {
                ll p = i.first;
                ll q = i.second;
                if(time + q < dist[p])
                {
                    dist[p] = time+q;
                    pq.push({time+q, p});
                    path[p] = path[node];
                }
                else if(time+q == dist[p])
                {
                    path[p] = (path[p] + path[node]) % mod;
                }
            }
        }
        return path[n-1]%mod;
        
        
    }
};