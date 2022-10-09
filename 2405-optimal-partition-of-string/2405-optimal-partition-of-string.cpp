class Solution {
public:
    int partitionString(string s) {
        int count = 1;
        vector<int> freq(26, 0);
        for(int i = 0; i < s.size(); i++)
        {
            if(freq[s[i] - 'a'] != count)
            {
                freq[s[i] - 'a'] = count;
            }
            else if(freq[s[i] - 'a'] == count)
            {
                count++;
                freq[s[i] - 'a'] = count;
            }
        }
        return count;
    }
};