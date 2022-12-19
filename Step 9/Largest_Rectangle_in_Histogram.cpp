class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        /*int n = heights.size();
        int area = 0, h, l;
        stack<int> indexes;
        for(int i = 0; i <= n; i++)
        {
            while(i == n || !indexes.empty() && heights[indexes.top()] > heights[i])
            {
                if(i == n && indexes.empty())
                {
                    h = 0;
                    i++;
                }
                else
                {
                    h = heights[indexes.top()];
                    indexes.pop();
                }
                if(indexes.empty())
                    l = -1;
                else
                    l = indexes.top();
                
                int a = h * (i-l-1);
                area = max(area, a);
            }
            indexes.push(i);
        }
        return area;*/
        
        int n = heights.size();
        int area = 0;
        vector<int> left(n);
        vector<int> right(n);
        left[0] = -1;
        right[n-1] = n;
        for(int i = 1; i < n; i++)
        {
            int prev = i-1;
            while(prev >= 0 && heights[prev] >= heights[i])
            {
                prev = left[prev];
            }
            left[i] = prev;
        }
        for(int i = n-2; i >= 0; i--)
        {
            int next = i+1;
            while(next < n && heights[next] >= heights[i])
            {
                next = right[next];
            }
            right[i] = next;
        }
        for(int i = 0; i < n; i++)
        {
            int l = right[i] - left[i] - 1;
            int a = heights[i] * l;
            area = max(area, a);
        }
        return area;
    }
};