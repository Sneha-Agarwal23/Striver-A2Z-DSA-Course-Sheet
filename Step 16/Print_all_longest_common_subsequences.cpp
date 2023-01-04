//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
		vector<string> all_longest_common_subsequences(string s, string t)
		{
		    int m = s.length();
		    int n = t.length();
		    vector<string> ans;
		    vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
		    vector<vector<unordered_set<string>>> x(m+1, vector<unordered_set<string>> (n+1));
		    for(int i = 1; i < m+1; i++)
		    {
		        for(int j = 1; j < n+1; j++)
		        {
		            if(s[i-1] != t[j-1])
		                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		            else
		                dp[i][j] = 1 + dp[i-1][j-1];
		        }
		    }
		    for(int i = 0; i < m+1; i++)
		    {
		        for(int j = 0; j < n+1; j++)
		        {
		            if(i == 0 || j == 0)
		            {
		                x[i][j].insert("");
		            }
		        }
		    }
		    for(int i = 1; i < m+1; i++)
		    {
		        for(int j = 1; j < n+1; j++)
		        {
		            if(s[i-1] == t[j-1])
		            {
		                for(auto it: x[i-1][j-1])
		                {
		                    x[i][j].insert(it+s[i-1]);
		                }
		            }
		            if(dp[i][j] == dp[i-1][j])
		            {
		                for(auto it: x[i-1][j])
		                {
		                    x[i][j].insert(it);
		                }
		            }
		            if(dp[i][j] == dp[i][j-1])
		            {
		                for(auto it: x[i][j-1])
		                {
		                    x[i][j].insert(it);
		                }
		            }
		        }
		    }
		    for(auto i : x[m][n])
		    {
		        if(i != "")
		            ans.push_back(i);
		    }
		    sort(ans.begin(),ans.end());
		    return ans;
		    
		        
		}
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	vector<string> ans = ob.all_longest_common_subsequences(s, t);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}


// } Driver Code Ends