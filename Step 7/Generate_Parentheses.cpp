//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void generate(int open, int close, string s, vector<string> &ans)
    {
        if(open == 0 && close == 0)
        {
            ans.push_back(s);
            return;
        }
        
        if(open > 0)
        {
            generate(open - 1,close, s + '(', ans);
        }
        if(close > 0)
        {
            if(open < close)
            {
                generate(open, close - 1, s + ')', ans);
            }
        }
    }
    vector<string> AllParenthesis(int n) 
    {
         vector<string> ans;
         string s;
         generate(n, n, s, ans);
         return ans;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends