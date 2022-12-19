//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool check(int A[], int N, int M, int mid)
    {
        int student = 1, page = 0;
        for(int i = 0; i < N; i++)
        {
            if(page + A[i] <= mid)
                page += A[i];
            else
            {
                student++;
                if(student > M || A[i] > mid)
                    return false;
                page = A[i];
            }
        }
        return true;
    }
    int findPages(int A[], int N, int M) 
    {
        int l = 0;
        int sum = 0;
        for(int i = 0; i < N;i++)
        {
            sum += A[i];
        }
        int h = sum;
        int ans = -1;
        if( M > N)
            return ans;
        while(l <= h)
        {
            int mid = (l+h)/2;
            if(check(A,N,M,mid))
            {
                ans = mid;
                h = mid-1;
            }
            else
                l = mid +1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends