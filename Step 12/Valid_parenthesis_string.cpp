class Solution {
public:
    bool checkValidString(string s) 
    {
        int n = s.length();
        int open = 0, close = 0;
        for(int i = 0, j = n-1; i < n; i++, j--)
        {
            if(s[i] == '(' || s[i] == '*')
                open++;
            else 
                open--;
            
            if(s[j] == ')' || s[j] == '*')
                close++;
            else
                close--;
            
            if(open < 0 || close < 0)
                return false;
            
        }
        return true;
        
    }
};