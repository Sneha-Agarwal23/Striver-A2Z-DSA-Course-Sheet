//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void merge(long long arr[], long long l, long long m, long long r, long long int &ans)
    {
        long long l1 =(m - l) + 1;
        long long l2 = (r - m);
        long long a[l1];
        long long b[l2];
        long long k = 0;
        for(long long i = l; i <= m; i++)
        {
            a[k] = arr[i];
            k++;
        }
        k = 0;
        for(long long i = m+1; i <= r; i++)
        {
            b[k] = arr[i];
            k++;
        }
        long long i = 0;
        long long j = 0;
        k = l;
        while(i < l1 && j < l2)
        {
            if(a[i] <= b[j])
            {
                arr[k] = a[i];
                i++;
                k++;
            }
            else
            {
                ans += (l1 - i);
                arr[k] = b[j];
                j++;
                k++;
            }
        }
        while(i < l1)
        {
            arr[k] = a[i];
            i++;
            k++;
        }
        while(j < l2)
        {
            arr[k] = b[j];
            j++;
            k++;
        }
        return;
    }
    void mergesort(long long arr[],long long l,long long r,long long int &ans)
    {
        if(l < r)
        {
            int m = l+(r-l)/2;
            mergesort(arr,l,m,ans);
            mergesort(arr,m+1,r,ans);
            
            merge(arr,l,m,r,ans);
        }
        return;
    }
    long long int inversionCount(long long arr[], long long N)
    {
         long long int ans = 0;
         mergesort(arr,0,N-1,ans);
         return ans;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends