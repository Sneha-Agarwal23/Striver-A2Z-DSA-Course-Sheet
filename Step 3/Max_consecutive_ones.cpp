class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int ones = 0, maxx = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 1)
            {
                ones++;
                maxx = max(maxx,ones);
            }    
            else
                ones = 0;
        }
        return maxx;
        
    }
};