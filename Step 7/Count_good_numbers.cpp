//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  bool check(int n,int D, int &s)
  {
      if(n <= 0)
        return true;
    if(n % 10 <= s || n % 10 == D)
        return false;
    
    s += n % 10;
    if(check(n/10,D,s) == false)
        return false;
    return true;
  }
    vector<int> goodNumbers(int L, int R, int D)
    {
        vector<int> ans;
        for(int i = L;i <= R;i++)
        {
            int s = i % 10;
            if(s == D)
                continue;
            if(check(i/10,D,s) == true)
            {
                ans.push_back(i);
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
        int L, R, D;
        cin >> L >> R >> D;
        Solution ob;
        vector<int> ans = ob.goodNumbers(L, R, D);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}
// } Driver Code Ends