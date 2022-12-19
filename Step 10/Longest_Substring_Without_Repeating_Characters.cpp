//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string s)
    {
        /*int ans = 0;
        int n = s.length();
        unordered_map<char, int> m;
        int i = 0;
        for(int j = 0; j < n; j++)
        {
            if(m.find(s[j]) != m.end())
            {
                i = max(i , m[s[j]] + 1);
            }
            ans = max(ans, j - i + 1);
            m[s[j]] = j;    
        }
        
        return ans;*/
        
        /*int ans = 0;
        int n = s.length();
        int i = 0, j = 0;
        unordered_set<char> x;
        while(i < n && j < n)
        {
            if(x.find(s[j]) == x.end())
            {
                x.insert(s[j]);
                j++;
                ans = max(ans, j-i);
            }
            else
            {
                x.erase(s[i]);
                i++;
            }
        }
        return ans;*/
        
        
        int ans = 0;
        int n = s.length();
        vector<int> v(256,-1);
        int i = -1;
        for(int j = 0; j < n; j++)
        {
            if(v[s[j]] > i)
            {
                i = v[s[j]];
            }
            v[s[j]] = j;
            ans = max(ans , j - i);
        }
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
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends