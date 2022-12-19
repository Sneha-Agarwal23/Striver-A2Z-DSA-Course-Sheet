class Solution {
public:
    bool isvalid(vector<int>& p1, vector<int>& p2)
    {
        if(p1[0] == p2[0]) return true;
        if(p1[1] == p2[1]) return true;
        return false;
    }

    void dfs(vector<vector<int>>& stones, vector<bool> &vis, int i)
    {
        vis[i] = true;
        for(int j = 0; j < stones.size(); j++)
        {
            if(vis[j] == true) continue;
            if(isvalid(stones[j], stones[i])) dfs(stones, vis, j);
        }
    }
    int removeStones(vector<vector<int>>& stones) 
    {
        int n = stones.size();
        vector<bool> vis(n, false);
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(vis[i] == true) continue;
            dfs(stones, vis, i);
            ans++;
        }
        return (n - ans);
    }
};