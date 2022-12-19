//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beautySum(string s) {
        // Your code goes here
        int ans = 0;
        for(int i = 0; i <s.length(); i++)
        {
            vector<int> v(26,0);
            for(int j = i;j <s.length();j++)
            {
                v[s[j] - 'a']++;
                int maxf = 0,minf = INT_MAX;
                for(auto x : v)
                {
                    maxf = max(maxf,x);
                    if(x >= 1)
                        minf = min(minf,x);
                }
                ans += (maxf-minf);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends