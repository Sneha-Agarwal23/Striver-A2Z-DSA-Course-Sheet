class Solution {
public:
    int solve(vector<int>& nums, int k)
    {
        int n = nums.size();
        int ans = 0;
        int count = 0;
        int i = 0,j= 0;
        while(j < n)
        {
            if(nums[j] % 2 == 1)
                count++;
            if(count > k)
            {
                while(i <= j && count > k)
                {
                    if(nums[i]% 2 == 1)
                        count--;
                    i++;
                }
            }
            ans += j-i+1;
            j++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        return solve(nums, k) - solve(nums, k-1);
    }
};