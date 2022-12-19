class Solution {
public:
    bool check(vector<int>& bloomDay, int m, int k, int mid)
    {
        int count = 0, size = 0;
        for(int i = 0; i < bloomDay.size(); i++)
        {
            if(bloomDay[i] <= mid)
                size++;
            else
                size = 0;
            if(size == k)
            {
                count++;
                size = 0;
            }
            if(count == m)
                return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        if(bloomDay.size() == 0 || m == 0 || k== 0)
            return 0;
        if(m * k > bloomDay.size())
            return -1;
        int l = INT_MAX,h = INT_MIN;
        for(int i = 0; i < bloomDay.size();i++)
        {
            l = min(l,bloomDay[i]);
            h = max(h,bloomDay[i]);
        }
        while(l <= h)
        {
            int mid = (l+h)/2;
            if(check(bloomDay,m,k,mid))
                h = mid-1;
            else
                l = mid + 1;
        }
        return l;
        
    }
};