//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool check(vector<int>& piles,int mid,int h,int n)
    {
        long long int hours = 0;
        for(int i = 0;i <n;i++)
        {
            hours += piles[i]/mid;
            if(piles[i]%mid)
                hours++;
        }
        if(hours <=h)
            return true;
        return false;
    }
    int Solve(int N, vector<int>& piles, int H)
    {
        int low = 1,high = INT_MIN,mid;
        for(int i = 0;i < N;i++)
        {
            high = max(high,piles[i]);
        }
        if(N==H)
            return high;
        while(low <= high)
        {
            mid = (low + high) /2;
            if(check(piles,mid,H,N))
                high = mid -1;
            else
                low = mid +1;
        }
        return low;
        
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
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends