//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        string ans = arr[0];
        for(int i = 0; i < N; i++)
        {
            int k = 0;
            while(k < arr[i].size() && k < ans.size())
            {
                if(arr[i][k] != ans[k])
                    break;
                k++;
            }
            ans = ans.substr(0,k);
            if(ans.size() == 0)
                return "-1";
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends