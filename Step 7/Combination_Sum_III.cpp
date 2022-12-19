class Solution {
public:
    void solve(vector<int> &v, vector<vector<int>> &ans, int k, int n, int num)
    {
        if(n < 0 || v.size() > k)
            return;
        
        if(n == 0 && v.size() == k)
        {
            ans.push_back(v);
            return;
        }
        
        for(int i = num; i <= 9; i++)
        {
            v.push_back(i);
            solve(v, ans, k, n-i, i+1);
            v.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> v;
        solve(v, ans, k, n, 1);
        return ans;
        
    }
};