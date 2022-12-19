class Solution {
public:
    string minWindow(string s, string t)
    {
        string ans = "";
        unordered_map<char, int> m;
        unordered_map<char, int> window;
        for(int i = 0; i < t.length(); i++)
        {
            m[t[i]]++;
        }
        int minlength = INT_MAX;
        int count = 0;
        for(int slow = 0, fast = 0; fast < s.length(); fast++)
        {
            char c = s[fast];
            if(m.find(c) != m.end())
            {
                window[c]++;
                if(window[c] <= m[c])
                    count++;
            }
            if(count == t.length())
            {
                while(m.find(s[slow]) == m.end() || window[s[slow]] > m[s[slow]])
                {
                    window[s[slow]]--;
                    slow++;
                }
                if(fast - slow + 1 < minlength)
                {
                    minlength = fast-slow+1;
                    ans = s.substr(slow, minlength);
                }
                    
            }
        }
        return ans;
        
    }
};