class Solution {
public:
    int longestOnes(vector<int>& nums, int k)
    {
        int ans = 0, zeros = 0, start = 0,end = 0;
        for(end = 0; end < nums.size(); end++)
        {
            if(nums[end] == 0)
                zeros++;
            while(zeros > k)
            {
                if(nums[start] == 0) zeros--;
                start++;
            }
            ans = max(ans, end - start +1);
        }
        return ans;
        
    }
};