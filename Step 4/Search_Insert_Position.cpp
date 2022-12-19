//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int searchInsertK(vector<int>arr, int N, int k)
    {
        int low = 0, high = N-1;
        int mid = -1;
        while(low <= high)
        {
            mid = (low + high)/2;
            if(arr[mid] == k)
                return mid;
            else if(arr[mid] < k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        if(arr[mid] < k)
            return mid +1;
        return mid;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<int>Arr(N);
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.searchInsertK(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends