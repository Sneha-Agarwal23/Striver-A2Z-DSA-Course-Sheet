//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i, int N, int arr[], int sum, vector<vector<int>> &dp)
    {
        if(sum == 0)
            return 1;
        if(i == N || sum < 0)
            return 0;
        if(dp[i][sum] != -1)
            return dp[i][sum];
            
        int x = solve(i+1, N, arr, sum, dp);
        int y = 0;
        if(arr[i] <= sum)
            y = solve(i+1, N, arr, sum-arr[i], dp);
            
        if(x == 1)
            return dp[i][sum] = 1;
        if(y == 1)
            return dp[i][sum] = 1;
        
        return dp[i][sum] = 0;
        
        
    }
    int equalPartition(int N, int arr[])
    {
        int count;
        int sum = 0;
        for(int i = 0; i < N; i++)
        {
            sum = sum + arr[i];
        }
        if(sum %2 != 0)
            return 0;
        count = sum/2;
        vector<vector<int>> dp(N+1, vector<int>(count+1, -1));
        return solve(0, N, arr, count, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends