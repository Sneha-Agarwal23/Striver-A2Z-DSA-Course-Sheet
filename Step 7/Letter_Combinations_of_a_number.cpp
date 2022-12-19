class Solution {
public:
    void solve(string s,vector<string>& ans,string digits,vector<string>& keypad,int i)
    {
        if(i == digits.size())
        {
            ans.push_back(s);
            return;
        }
        int d = digits[i] - '0';
        for(auto x : keypad[d])
        {
            solve(s + x,ans,digits,keypad,i+1);
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if(digits.size() == 0)
        {
            return {};
        }
        vector<string> ans;
        string s;
        vector<string> keypad = {"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(s,ans,digits,keypad,0);
        return ans;
        
    }
};