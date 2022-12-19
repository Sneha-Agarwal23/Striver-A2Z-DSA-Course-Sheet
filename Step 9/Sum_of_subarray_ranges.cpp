class Solution {
public:
    long long subArrayRanges(vector<int>& nums) 
    {
        long long ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            int maxx = nums[i], minn = nums[i];
            for(int j = i; j < n; j++)
            {
                maxx = max(maxx, nums[j]);
                minn = min(minn, nums[j]);
                ans += maxx - minn;
            }
        }
        return ans;
        
    }
};