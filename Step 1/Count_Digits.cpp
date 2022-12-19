//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int evenlyDivides(int N)
    {
        int count = 0;
        int temp = N;
        string s = to_string(temp);
        for(int i = 0; i < s.size();i++)
        {
            int r = s[i] - '0';
            if(r == 0)
                continue;
            if(N % r == 0)
                count++;
        }
        return count;
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
        cin>>N;
        Solution ob;
        cout << ob.evenlyDivides(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends