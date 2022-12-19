class Solution {
public:
    int sum;
    void solve(vector<int>& candidates, int target, int n, vector<int>& v, vector<vector<int>> &ans, int index)
    {
        if(sum > target)
            return;
        if(sum == target)
            ans.push_back(v);
        
        for(int i = index; i < n; i++)
        {
            sum += candidates[i];
            v.push_back(candidates[i]);
            solve(candidates, target, n, v, ans, i);
            sum -= candidates[i];
            v.pop_back();
        }
        
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        sum = 0;
        vector<vector<int>> ans;
        vector<int> v;
        int n = candidates.size();
        solve(candidates, target, n, v, ans, 0);
        return ans;
        
    }
};