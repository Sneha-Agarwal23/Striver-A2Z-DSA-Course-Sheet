class Solution {
public:
    bool check(vector<int>& weights, int days, int m)
    {
        int count = 1,sum =0;
        for(int i = 0; i < weights.size(); i++)
        {
            sum += weights[i];
            if(sum > m)
            {
                count++;
                sum = weights[i];
            }
        }
        if(count <= days)
            return true;
        return false;
        
    }
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int maxCapacity = 0;
        int n = weights.size();
        for(int i = 0; i < n;i++)
        {
            maxCapacity += weights[i];
        }
        int l = *max_element(weights.begin(),weights.end()),h = maxCapacity;
        int ans;
        while(l <= h)
        {
            int m = (l+h)/2;
            if(check(weights,days,m))
            {
                ans = m;
                h = m-1;
            }
            else
                l = m+1;
        }
        return ans;  
    }
};