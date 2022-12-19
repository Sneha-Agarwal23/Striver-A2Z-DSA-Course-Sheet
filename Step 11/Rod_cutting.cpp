//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        int dp[n];
        dp[0] = price[0];
        for(int k = 1; k < n; k++)
        {
            int maxx = price[k];
            for(int i = 0,j = k-1; i <= j;i++,j--)
            {
                if(dp[i] + dp[j] > maxx)
                    maxx = dp[i] + dp[j];
            }
            dp[k] = maxx;
        }
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends