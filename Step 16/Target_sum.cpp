class Solution {
public:
    /*int count = 0;
    void solve(vector<int>& nums, int i, int sum, int target)
    {
        int n = nums.size();
        if(i == n)
        {
            if(sum == target)
                count++;
        }
        else
        {
            solve(nums, i+1, sum + nums[i], target);
            solve(nums, i+1, sum - nums[i], target);
        }
    }
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        solve(nums, 0, 0, target);
        return count;
    }*/
    int solve(vector<int>& nums, int i, int sum, int target, int total, vector<vector<int>>& dp)
    {
        if(i == nums.size())
        {
            if(sum == target)
                return 1;
            else
                return 0;
        }
        if(dp[i][sum+total] != -1)
            return dp[i][sum+total];
        
        int add = solve(nums, i+1, sum + nums[i], target, total, dp);
        int sub = solve(nums, i+1, sum - nums[i], target, total, dp);
        dp[i][sum+total] = add+sub;
        return dp[i][sum+total];
    }
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int n = nums.size();
        int total = 0;
        for(int i = 0; i < n; i++)
            total += nums[i];
        vector<vector<int>> dp(n, vector<int> (2*total+1, -1));
        return solve(nums, 0, 0, target,total, dp);

    }
};