//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n)
    {
        if(n == 1)
            return 0;
        if(arr[0] == 0)
            return -1;
        int ans = 1;
        int cp = arr[0];
        int step = arr[0];
        for(int i = 1; i < n; i++)
        {
            if(i == n-1)
                return ans;
            cp = max(cp, i+arr[i]);
            step--;
            if(step == 0)
            {
                ans++;
                if(i >= cp)
                    return -1;
                step = cp-i;
            }
        }
        return ans;
        
        
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends