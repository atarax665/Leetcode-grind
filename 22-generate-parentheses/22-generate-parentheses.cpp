class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        backtrack(n, s, 0, 0, ans);
        return ans;
    }
    
    void backtrack(int n, string s, int open, int close, vector<string> &ans)
    {
        if(open > n)
        {
            return;
        }
        if(open == n && close == n)
        {
            ans.push_back(s);
            return;
        }
        
        backtrack(n, s + '(', open + 1, close, ans);
        if(open > close)
        {
            backtrack(n, s + ')', open, close + 1, ans);
        }
    }
};