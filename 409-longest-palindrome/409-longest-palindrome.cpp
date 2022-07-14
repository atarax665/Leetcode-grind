class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        for(auto &i: s)
        {
            m[i]++;
        }
        int ans = 0;
        int flag = 0;
        for(auto &i : m)
        {
            if(i.second % 2 == 0)
            {
                ans += i.second;
            }
            else
            {
                ans += i.second - i.second % 2;
                flag = 1;
            }
        }
        if(flag == 1)
        {
            ans++;
        }
        return ans;
    }
};