//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int KthMissingElement(int a[], int n, int k);


int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << KthMissingElement(a, n, k) << endl;
    
    }
    return 0;
}

// } Driver Code Ends


int KthMissingElement(int a[], int n, int k)
{
    for(int i = 0; i < n-1; i++)
    {
        int x = a[i];
        while(x + 1 != a[i+1])
        {
            x++;
            k--;
            if(k == 0)
                return x;
        }
        if(k == 0)
        {
            return a[i]+ 1;
        }
    }
    return -1;
}