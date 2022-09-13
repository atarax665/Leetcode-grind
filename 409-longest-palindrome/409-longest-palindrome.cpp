class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> m;
        for(auto i : s)
        {
            m[i]++;
        }
    int sum = 0;
    int odd = 0;
    for(auto i : m)
    {
        if(i.second % 2 == 1)
        {
            odd++;
            sum += i.second - 1;
        }
        else
        {
            sum += i.second;
        }
    }
    if(odd != 0)
    {
        return sum + 1;
    }
    return sum;
    }
};