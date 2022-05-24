class Solution
{
    public:
        bool wordPattern(string pattern, string s)
        {
            vector<string> vec;
            stringstream str(s);
            string tmp;
            while (getline(str, tmp, ' '))
                vec.push_back(tmp);
            
            // initial size check for s and pattern
            if (vec.size() != pattern.size())
                return false;
            
            // using two maps
            unordered_map<string, char> mp1;
            unordered_map<char, string> mp2;
            for (int i = 0; i < pattern.size(); i++)
            {
                if (mp1.find(vec[i]) == mp1.end() && mp2.find(pattern[i]) == mp2.end())
                {
                    mp1[vec[i]] = pattern[i];
                    mp2[pattern[i]] = vec[i];
                }
                else if (mp2[pattern[i]] != vec[i])
                    return false;
            }

            return true;
        }
};