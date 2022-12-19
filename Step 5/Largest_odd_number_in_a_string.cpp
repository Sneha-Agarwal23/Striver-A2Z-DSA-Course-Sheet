//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string maxOdd(string s) 
    {
        string ans = "", x = "";
        int n = 0;
        for(int i = 0; i < s.size(); i++)
        {
            ans += s[i];
            n = s[i] - '0';
            if(n % 2 != 0)
            {
                x = ans;
            }
        }
        return x;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;

        cout << ob.maxOdd(s) << endl;
    }
}

// } Driver Code Ends