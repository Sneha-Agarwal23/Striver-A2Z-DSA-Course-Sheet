//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{

	public:
	int mod = 1e9 +7;
	int fun(int i, int n, int target,int arr[],vector<vector<int>> &dp)
	{
	    if(target == 0)
	        return 1;
	    if(target < 0 || i >= n)
	        return 0;
	    
	    if(dp[i][target] != -1)
	    {
	        return dp[i][target];
	    }
	    
	    int nottake = fun(i+1,n,target,arr,dp) % mod;
	    int take = 0;
	    if(target >= arr[i])
	    {
	        take = fun(i+1,n,target-arr[i],arr,dp) % mod;
	    }
	    return dp[i][target] = (take + nottake) %mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
	    sort(arr,arr+n);
	    vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
	    return fun(0,n,sum,arr,dp) % mod;
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends