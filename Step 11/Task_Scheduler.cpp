class Solution {
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        unordered_map<char,int> m;
        int count = 0;
        for(auto i : tasks)
        {
            m[i]++;
            count = max(count , m[i]);
        }
        int ans = (n+1) * (count-1);
        for(auto i : m)
        {
            if(i.second == count)
                ans++;
        }
        return max((int)tasks.size(),ans);
        
        
    }
};