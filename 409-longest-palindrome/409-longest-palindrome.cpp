class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        for(auto &i: s)
        {
            m[i]++;
        }
        vector<int> even, odd;
        for(auto &i : m)
        {
            if(i.second % 2 == 0)
            {
                even.push_back(i.second);
            }
            else
            {
                odd.push_back(i.second - i.second % 2);
            }
        }
        int ans = accumulate(even.begin(), even.end(), 0);
        if(!odd.empty())
        {
            ans += accumulate(odd.begin(), odd.end(), 0);
            ans++;
        }
        
        return ans;
    }
};