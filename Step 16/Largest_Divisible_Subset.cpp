class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> ans;
        if(n == 0)
            return ans;
        vector<int> dp(n, 1);
        sort(nums.begin(), nums.end());
        int size = 1, lei = 0; // lei = largest element index
        for(int i = 1; i < n; i++)
        {
            for(int j = i-1; j >= 0; j--)
            {
                if(nums[i] % nums[j] == 0)
                {
                    dp[i] = max(dp[i], dp[j]+1);
                    if(dp[i] > size)
                    {
                        size = dp[i];
                        lei = i;
                    }
                }
            }
        }
        ans.push_back(nums[lei]);
        int prev = lei;
        for(int i = lei-1; i >= 0; i--)
        {
            if(ans.back() % nums[i] == 0 && dp[i] == dp[prev]-1)
            {
                ans.push_back(nums[i]);
                prev = i;
            }
        }
        return ans;
    }
};