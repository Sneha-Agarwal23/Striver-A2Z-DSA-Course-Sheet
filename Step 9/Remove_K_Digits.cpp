class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        string ans = "";
        if(num.length() == k)
            return "0";
        for(int i = 0;i < num.length(); i++)
        {
            while(ans.size() > 0 && ans.back() > num[i] && k != 0)
            {
                ans.pop_back();
                k--;
            }
            if(ans.size() > 0 || num[i] != '0')
                ans.push_back(num[i]);
        }
        while(ans.size() > 0 && k != 0)
        {
            ans.pop_back();
            k--;
        }
        if(ans.empty())
            return "0";
        return ans;
        
    }
};