class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        int ans = 1;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        while(!q.empty())
        {
            int n = q.size();
            for(int i = 0; i < n; i++)
            {
                string s = q.front();
                q.pop();
                if(s == endWord)
                    return ans;
                dict.erase(s);
                for(int j = 0; j < s.size(); j++)
                {
                    char c = s[j];
                    for(int k = 0; k < 26; k++)
                    {
                        s[j] = 'a' + k;
                        if(dict.find(s) != dict.end())
                            q.push(s);
                    }
                    s[j] = c;
                }
            }
            ans++;
        }
        return 0;
        
        
        
    }
};