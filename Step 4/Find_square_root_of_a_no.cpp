//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        /*long long int ans = floor(sqrt(x));
        return ans;*/
        long long int low = 1, high = x;
        long long int mid = (low+high)/2;
        while(low <= high)
        {
            
            if(mid * mid == x)
                return mid;
            else if(mid * mid < x)
                low = mid + 1;
            else
                high = mid - 1;
            mid = (low+high)/2;
        }
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
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends