class Solution {
public:
    void dfs(string curemail, unordered_map<string, bool>& vis, unordered_map<string, vector<string>>& adj, vector<string>& temp)
    {
        temp.push_back(curemail);
        vis[curemail] = true;
        for(int i = 0; i < adj[curemail].size(); i++)
        {
            string next = adj[curemail][i];
            if(vis[next] == false)
                dfs(next, vis, adj,temp);
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) 
    {
        vector<vector<string>> ans;
        int n = accounts.size();
        unordered_map<string, vector<string>> adj;
        unordered_map<string, bool> vis;
        unordered_map<string, string> email_name;
        for(int i = 0; i < n; i++)
        {
            string name = accounts[i][0];
            for(int j = 1; j < accounts[i].size(); j++)
            {
                string email = accounts[i][j];
                email_name[email] = name;
                vis[email] = false;
                if(j+1 < accounts[i].size())
                {
                    string nextemail = accounts[i][j+1];
                    adj[email].push_back(nextemail);
                    adj[nextemail].push_back(email);
                }
                else
                {
                    adj[email];
                }
            }
        }
        unordered_map< string, vector <string>> :: iterator i = adj.begin();
        while(i != adj.end())
        {
            string curemail = (*i).first;
            if(vis[curemail] == false)
            {
                vector<string> temp = {email_name[curemail]};
                dfs(curemail, vis, adj, temp);
                sort(temp.begin()+1,temp.end());
                ans.push_back(temp);
            }
            i++;
        }
        return ans;
        
    }
};