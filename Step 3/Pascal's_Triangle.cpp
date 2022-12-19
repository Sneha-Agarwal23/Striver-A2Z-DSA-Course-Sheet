//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
// #define ll long long

class Solution{
    long mod = 1e9+7;
public:
    vector<ll> nthRowOfPascalTriangle(int n) 
    {
        vector<ll> ans;
        ans.push_back(1);
        for(int i = 1; i < n; i++)
        {
            vector<ll> temp;
            temp.push_back(1);
            for(int j = 0; j < i-1; j++)
            {
                temp.push_back((ans[j] + ans[j+1])%mod);
            }
            temp.push_back(1);
            ans = temp;
        }
        return ans;
    }
};


//{ Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends