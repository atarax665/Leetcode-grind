class Solution {
public:
    bool isSubsequence(string s, string t) {
        int x = 0;
        if(s == "")
            return true;
        for(int i = 0; i < t.size(); i++)
        {
            if(t[i] == s[x])
            {
                x++;
            }
        }
        if(x == s.size())
        {
            return true;
        }
        return false;
    }
};