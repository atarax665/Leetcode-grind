class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int, int> m;
        vector<int> ans;
        int n = changed.size();
        sort(changed.begin(), changed.end());
        if(n % 2 == 1)
        {
            return {};
        }
        for(auto i : changed)
        {
            m[i]++;
        }
        for(int i = 0; i < n; i++) {
          if (m[changed[i]] == 0) continue;
          if (m[changed[i] * 2] == 0) return {};
          ans.push_back(changed[i]);
          m[changed[i]]--;
          m[changed[i] * 2]--;
        }
        return ans;
    }
};