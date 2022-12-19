//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) 
	{
	    /*for(int i = 0; i < n-1;i++)
	    {
	        if(arr[i] > arr[i+1])
	            return i+1;
	    }
	    return 0;*/
	    
	    int temp[n];
	    for(int i = 0; i < n; i++)
	    {
	        temp[i] = arr[i];
	    }
	    sort(temp, temp+n);
	    int pos = 0;
	    for(int i = 0; i < n; i++)
	    {
	        if(temp[0] == arr[i])
	        {
	            pos = i;
	            break;
	        }
	    }
	    return pos;
	    
	    
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends