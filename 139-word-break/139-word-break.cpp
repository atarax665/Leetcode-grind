class Solution {
public:
    int dp[301];
    bool helper(string &s, set<string> &st, int idx)
    {
        if(idx == s.size())
            return true;
        if(dp[idx]!=-1) return dp[idx];
        // string t = "";
        for(int i = idx; i<s.size(); i++)
        {
            if(st.find(s.substr(idx, i-idx+1))!=st.end())
            {
                if(helper(s, st, i+1))
                    return dp[idx] = 1;
            }
        }
        return dp[idx] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        memset(dp, -1, sizeof(dp));
        for(auto x: wordDict) st.insert(x);
        return helper(s, st, 0);
    }
};