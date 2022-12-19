//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool Search(int N, vector<int>& A, int key) 
    {
        /*bool flag = false;
        int low = 0, high = N-1;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(A[mid] == key)
                flag = true;
            if(A[low] <= A[mid])
            {
                if(A[low] >= key && key <= A[mid])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            else
            {
                if(A[mid] >= key && key <= A[high])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
                
        }
        return flag;*/
        
        bool flag = false;
        for(int i = 0; i < N; i++)
        {
            if(A[i] == key)
                flag = true;
        }
        return flag;
        
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
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends