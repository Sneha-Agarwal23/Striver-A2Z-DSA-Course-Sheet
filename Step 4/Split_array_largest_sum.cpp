class Solution {
public:
    int splitArray(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int low = 0, sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            low = max(low, nums[i]);
        }
        int high = sum;
        int ans = 0;
        while(low <= high)
        {
            int mid = (low + high)/2;
            int count = 0, temp = 0;
            for(int i = 0; i < n; i++)
            {
                if(temp + nums[i] <= mid)
                {
                    temp += nums[i];
                }
                else
                {
                    count++;
                    temp = nums[i];
                }
            }
            if(count < k)
            {
                ans = mid;
                high = mid -1;
            }   
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};