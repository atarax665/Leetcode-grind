class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int res=0;
        for(int i=0;i<s.size();i++)
        {
            if(!st.empty() && s[i]=='a')
            {
                st.pop();
                res++;
            }
            if(s[i]=='b')
                st.push(s[i]);
        }
        return res;
    }
};