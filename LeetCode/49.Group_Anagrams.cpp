class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> m;
        for (auto x : strs)
        {
            string a = x;
            sort(a.begin(), a.end());
            m[a].push_back(x);
        }
        vector<vector<string>> ans;

        for (auto it = m.begin(); it != m.end(); it++)
        {
            ans.push_back(it->second);
        }
        return ans;
    }
};