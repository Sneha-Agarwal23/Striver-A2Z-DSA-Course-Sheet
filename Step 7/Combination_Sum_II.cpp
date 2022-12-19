class Solution {
public:
    void solve(vector<int>& candidates, int target, int n, vector<int> &v, vector<vector<int>> &ans, int index)
    {
        if(target == 0)
        {
            ans.push_back(v);
            return;
        }
        
        for(int i = index; i < n; i++)
        {
            if(candidates[i] > target)
                break;
            if(i > index && candidates[i] == candidates[i-1])
                continue;
            v.push_back(candidates[i]);
            solve(candidates, target - candidates[i], n, v, ans, i+1);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        int n = candidates.size();
        solve(candidates, target, n, v, ans, 0);
        return ans;
        
    }
};