class Solution {
public:
    int trap(vector<int>& height)
    {
        int n = height.size();
        int i = 0;
        int j = n-1;
        int result = 0;
        int maxleft = 0, maxright = 0;
        while(i <= j)
        {
            if(height[i] <= height[j])
            {
                if(height[i] >= maxleft)
                {
                    maxleft = height[i];
                }
                else
                {
                    result = result + maxleft - height[i];
                }
                i++;
            }
            else
            {
                if(height[j] >= maxright)
                {
                    maxright = height[j];
                }
                else
                {
                    result = result + maxright - height[j];
                }
                j--;
            }
        }
        return result;
        
    }
};