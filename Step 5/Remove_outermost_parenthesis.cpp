class Solution {
public:
    string removeOuterParentheses(string s) 
    {
        string ans;
        stack<char> st;
        for(auto i: s)
        {
            if(i == '(')
            {
                if(st.size() > 0)
                    ans += '(';
                
                st.push('(');
            }
            else
            {
                if(st.size() > 1)
                    ans += ')';
                st.pop();
            }
        }
        return ans;
    }
};