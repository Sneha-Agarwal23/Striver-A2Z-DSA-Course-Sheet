class Solution {
public:
    int getsum(vector<int>& nums, int mid)
    {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            ans += ceil(float(nums[i])/mid);
        }
        return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold)
    {
        int h = INT_MIN;
        for(int i = 0; i < nums.size(); i++)
        {
            h = max(h, nums[i]);
        }
        int l = 1;
        h++;
        while(l < h)
        {
            int mid = (l + h)/2;
            if(getsum(nums, mid) > threshold)
                l = mid +1;
            else
                h = mid;
        }
        return l;
    }
};