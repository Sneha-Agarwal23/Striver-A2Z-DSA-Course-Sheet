//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        vector<double> temp;
        for(int i = 0; i < array1.size(); i++)
        {
            temp.push_back(array1[i]);
        }
        for(int i = 0; i < array2.size(); i++)
        {
            temp.push_back(array2[i]);
        }
        sort(temp.begin(), temp.end());
        if(temp.size() % 2 == 0)
        {
            double x = temp[temp.size()/2] + temp[temp.size()/2 -1];
            return x/2;
        }
        return temp[temp.size()/2];
        
    
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends