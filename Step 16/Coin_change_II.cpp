class Solution {
public:
    int change(int amount, vector<int>& coins) 
    {
        int n = coins.size();
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        if(amount == 0)
            return 1;
        if(n == 0)
            return 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = coins[i]; j <= amount; j++)
            {
                dp[j] += dp[j - coins[i]];  
            }
        }
        return dp[amount];
        
    }
};