//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    void dfs(int i, vector<vector<int>>& graph, vector<int>& vis, stack<int>& st)
    {
        if(vis[i] == 1)
            return;
        
        vis[i] = 1;
        for(auto j : graph[i])
        {
            dfs(j, graph, vis, st);
        }
        st.push(i);
    }
    string findOrder(string dict[], int N, int K)
    {
        vector<vector<int>>graph(K);
        for(int i = 0;i < N-1;i++)
        {
            string a = dict[i];
            string b = dict[i+1];
            int j = 0;
            while(j < a.size() && j < b.size())
            {
                if(a[j] != b[j])
                {
                    graph[(b[j] - 'a')].push_back(a[j]- 'a');
                    break;
                }
                j++;
            }
        }
        vector<int> vis(K,0);
        stack<int> st;
        for(int i = 0;i < K;i++)
        {
            dfs(i,graph,vis,st);
        }
        string ans;
        while(!st.empty())
        {
            ans += ('a' + st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends