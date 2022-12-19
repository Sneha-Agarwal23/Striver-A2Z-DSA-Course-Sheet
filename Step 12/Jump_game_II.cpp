class Solution {
public:
    int jump(vector<int>& nums)
    {
        if(nums.size() < 2)
            return 0;
        int count = 1;
        int n = nums.size();
        int curr = nums[0], maxjump = nums[0];
        for(int i = 0; i < n-1; i++)
        {
            maxjump = max(maxjump, i + nums[i]);
            if(curr == i)
            {
                count++;
                curr = maxjump;
            }
        }
        return count;
        
    }
};