class Solution {
public:
    void solve(vector<int>& nums, int n, vector<vector<int>>& ans, vector<int> &v, int index)
    {
        ans.push_back(v);
        
        for(int i = index; i < n; i++)
        {
            if(i > index && nums[i] == nums[i-1])
                continue;
            
            v.push_back(nums[i]);
            solve(nums, n, ans, v, i+1);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> v;
        int n = nums.size();
        solve(nums, n, ans, v, 0);
        return ans;
    }
};