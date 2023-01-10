class Solution {
public:
    struct dsu
{
    vector<int> parent;
    vector<int> size;
    int totalComponents;

    void init(int n)
    {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
        totalComponents = n;
    }

    int get(int x)
    {
        return (x == parent[x] ? x : (parent[x] = get(parent[x])));
    }

    void unite(int x, int y)
    {
        x = get(x);
        y = get(y);
        if (x != y)
        {
            if (size[x] < size[y])
                swap(x, y);
            parent[y] = x;
            size[x] += size[y];
            totalComponents--;
        }
    }
};
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        dsu d;
        d.init(n);
        unordered_map<string, int> emailToIndex;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                if (emailToIndex.count(email)) {
                    d.unite(i, emailToIndex[email]);
                } else {
                    emailToIndex[email] = i;
                }
            }
        }
        unordered_map<int, vector<string>> indexToEmails;
        for (auto& [email, index] : emailToIndex) {
            index = d.get(index);
            indexToEmails[index].push_back(email);
        }
        vector<vector<string>> merged;
        for (auto& [index, emails] : indexToEmails) {
            sort(emails.begin(), emails.end());
            vector<string> account;
            account.push_back(accounts[index][0]);
            for (string& email : emails) {
                account.push_back(email);
            }
            merged.push_back(account);
        }
        return merged;
    }
};