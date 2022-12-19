//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long int substring(string &s, int k)
    {
        long long int n = s.length();
        long long int start = 0, count = 0, d = 0;
        vector<long long int> v(26, 0);
        for(int i = 0; i < n; i++)
        {
            if(v[s[i] - 'a'] == 0)
                d++;
            v[s[i] - 'a']++;
            while(d > k)
            {
                v[s[start] - 'a']--;
                if(v[s[start] -'a'] == 0)
                    d--;
                start++;
            }
            if(d <= k)
            {
                count = count + i -start +1;
            }
        }
        return count;
        
    }
    long long int substrCount (string s, int k) 
    {
        return substring(s,k) - substring(s,k-1);
    	
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends