class Solution {
public:
    /*bool isPalindrome(string t)
    {
        int i = 0, j = t.length()-1;
        while(i < j)
        {
            if(t[i] != t[j])
                return false;
            i++;
            j--;
        }
        return true;
    }*/
    void ispalindrome(string &s,int n,int left,int right,int &start,int &maxlength)
    {
        while(left >= 0 && right < n && s[left] == s[right])
        {
            left--;
            right++;
        }
        if(maxlength < right -left -1)
        {
            maxlength = right -left -1;
            start = left +1;
        }
    }
    string longestPalindrome(string s) 
    {
        /*int n = s.length();
        unordered_map<string, int> m;
        int maxlength = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                string temp = s.substr(0, j-i);
                if(isPalindrome(temp))
                {
                    m[temp] = j-i+1;
                    maxlength = max(maxlength, j-i+1);
                }
            }
        }
        for(auto i : m)
        {
            if(i.second == maxlength)
                return i.first;
        }
        return "";*/
        
        int n = s.length(),start = 0,maxlength = 0;
        if( n < 2)
        {
            return s;
        }
        for(int i = 0; i < n-1; i++)
        {
            ispalindrome(s,n,i,i,start,maxlength);
            ispalindrome(s,n,i,i+1,start,maxlength);
        }
        return s.substr(start,maxlength);
        
        
    }
};