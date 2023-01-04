//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    /*int solve(int n, vector<int>& dp)       //Top-down - Memoization
    {
        if(n == 0)
            return 1;
        
        if(n < 0)
            return 0;
        
        if(dp[n] != -1)
            return dp[n];
            
        return dp[n] = (solve(n-1, dp) + solve(n-2, dp)) % 1000000007;
    }*/
    int countWays(int n)
    {
        /*vector<int> dp(n+1);          //Bottom-up  Tabulation
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            dp[i] = (dp[i-1] + dp[i-2]) % 1000000007;
        }
        return dp[n];*/
        //return solve(n, dp);
        
        int first = 1;              //Brute Force
        int sec = 2;
        if(n == 1)
            return 1;
        
        for(int i = 2; i < n; i++)
        {
            int third = (first + sec) % 1000000007;
            first = sec;
            sec = third;
        }
        return sec;
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends