//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int maxDepth(string s)
    {
        // code here
        int depth = 0, maxd = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
                depth++;
            else if(s[i] == ')')
                depth--;
            maxd = max(maxd,depth);
        }
        return maxd;
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
        int ans = obj.maxDepth(s);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends