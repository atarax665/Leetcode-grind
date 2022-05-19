class Solution {
public:
    bool areAnagram(string str1, string str2)
{
    int count[256] = { 0 };
    int i;
 
    for (i = 0; str1[i] && str2[i]; i++) {
        count[str1[i]]++;
        count[str2[i]]--;
    }
 
    if (str1[i] || str2[i])
        return false;
 
    for (i = 0; i < 256; i++)
        if (count[i])
            return false;
    return true;
}
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<int> idx;
        for(int i = 0; i < n - 1; i++)
        {
            if(areAnagram(words[i], words[i + 1]))
            {
                idx.push_back(i + 1);
            }
        }
        if(idx.size() == 0)
        {
            return words;
        }
        for(int i = 0; i < idx.size(); i++)
        {
            words[idx[i]] = "0";
        }
        vector<string> ans;
        for(int i = 0; i < n; i++)
        {
            if(words[i] != "0")
            {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};