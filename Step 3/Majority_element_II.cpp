//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Solve(int n, vector<int>& nums) 
    {
        vector<int> v;
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++)
        {
            m[nums[i]]++;
        }
        for(auto i : m)
        {
            if(i.second > n/3)
                v.push_back(i.first);
        }
        sort(v.begin(), v.end());
        if(v.size() == 0)
            return {-1};
        else
            return v;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        Solution obj;

        vector<int> res = obj.Solve(n, a);

        for (auto x : res) cout << x << " ";

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends