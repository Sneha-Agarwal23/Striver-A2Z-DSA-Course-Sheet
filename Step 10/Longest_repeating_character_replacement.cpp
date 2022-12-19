class Solution {
public:
    int characterReplacement(string s, int k)
    {
        int ans = 0, maxf = 0;
        unordered_map<char,int> m;
        for(int i = 0;i < s.length();i++)
        {
            m[s[i]]++;
            maxf = max(maxf,m[s[i]]);
            if(ans - maxf < k)
                ans++;
            else
                m[s[i - ans]]--;
        }
        return ans;
        
    }
};