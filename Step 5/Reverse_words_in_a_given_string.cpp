//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        vector<string> st;
        int start = 0;
        int length = 0;
        S = S+'.';
        for(int i = 0; i < S.size();i++)
        {
            if(S[i] == '.')
            {
                string temp = S.substr(start,length);
                st.push_back(temp);
                start = i+1;
                length = 0;
            }
            else
                length++;
        }
        reverse(st.begin(),st.end());
        string ans;
        for(auto i : st)
        {
            ans = ans + i +'.'; 
        }
        ans[ans.size()-1] = '\0';
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends