class Solution {
public:
    int numDistinct(string s, string t) 
    {
        int n = s.length();
        int m = t.length();
        vector<long long int> dp(m+1);
        dp[0] = 1;
        for(int i = 0; i < n; i++)
        {
            for(int j = m;j > 0;j--)
            {
                long long int x;
                if(t[j-1] == s[i])
                    x = dp[j-1];
                else
                    x = 0;
                dp[j] += x; 
            }
        }
        return dp[m];
        
    }
};