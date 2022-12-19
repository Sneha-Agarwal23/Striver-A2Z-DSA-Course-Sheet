class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) 
    {
        vector<vector<int>> ans;
        sort(a.begin(), a.end());
        int n = a.size();
        ans.push_back(a[0]);
        for(int i = 1; i < n; i++)
        {
            auto &prev = ans[ans.size()-1];
            auto next = a[i];
            if(prev[1] >= next[0])
            {
                prev[1] = max(prev[1], next[1]);
            }
            else
            {
                ans.push_back(next);
            }
        }
        return ans;
        
    }
};