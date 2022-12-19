//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) 
    {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        if(n == 0)
            return ans;
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                int target = k - arr[i] - arr[j];
                int left = j+1;
                int right = n-1;
                while(left < right)
                {
                    int sum = arr[left] + arr[right];
                    if(sum < target)
                        left++;
                    else if(sum > target)
                        right--;
                    else
                    {
                        vector<int> temp;
                        temp.push_back(arr[i]);
                        temp.push_back(arr[j]);
                        temp.push_back(arr[left]);
                        temp.push_back(arr[right]);
                        ans.push_back(temp);
                        while(left < right && arr[left] == arr[left+1])
                            left++;
                        while(left < right && arr[right] == arr[right-1])
                            right--;
                        left++;
                        right--;
                    }
                }
                while(j+1 < n && arr[j] == arr[j+1])
                    j++;
            }
            while(i+1 < n && arr[i] == arr[i+1])
                i++;
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends