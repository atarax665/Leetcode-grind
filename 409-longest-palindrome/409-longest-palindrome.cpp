class Solution {
public:
    int longestPalindrome(string s) {
        if(s.length() == 1) return 1;
        unordered_map<char,int> m;
        for(int i = 0; i < s.length(); i++)
        {
            m[s[i]]++;
        }
        int ans = 0;
        bool odd = false;
        for(auto i : m)
        {
            if(i.second%2 == 0)
            {
              ans += i.second;
             }
            
            else
            {
                odd = true;          
                ans += i.second-1;
                
            }
                
        }
        if(odd) return ans+1;
        else return ans;
        
    }
};