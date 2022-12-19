class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        int count = 0;
        int n = s.size();
        unordered_map<char, int> m;
        int i = 0, j = 0;
        while(j < n)
        {
            m[s[j]]++;
            while(m['a'] != 0 && m['b'] != 0 && m['c'] != 0)
            {
                count += n - j;
                m[s[i]]--;
                i++;
            }
            j++;
        }
        return count;
        
    }
};