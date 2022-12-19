//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    priority_queue<int> low;
    priority_queue<int, vector<int>, greater<int>> high;
    //Function to insert heap.
    void insertHeap(int &x)
    {
        low.push(x);
        high.push(low.top());
        low.pop();
        if(low.size() < high.size())
        {
            low.push(high.top());
            high.pop();
        }
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        double ans = 0;
        int n = low.size() + high.size();
        if(n % 2 == 0)
        {
            ans = low.top() + high.top();
            return ans/2.0;
        }
        else
            ans = low.top();
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends