class Solution {
public:
    int best = 1;
    int pos = 0;
     void palindrome_size(string &s, int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        
        int newLen =  r - l -1;
         if(best < newLen)
         {
             best = newLen;
             pos = l + 1;
         }
    }
    
    string longestPalindrome(string s) {   
        
        for (int i = 0; i < s.size(); i++) {
            palindrome_size(s, i, i);
            palindrome_size(s, i, i + 1);
        }
        return s.substr(pos, best);
    }
};