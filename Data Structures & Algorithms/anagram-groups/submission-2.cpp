class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (string s : strs) {
            vector<int> count(26, 0);
            for (char c : s)
                ++count[c - 'a'];

            string id{};
            for (int c : count)
                id += to_string(c) + ',';

            groups[id].push_back(s); 
        }       

        vector<vector<string>> res;
        for (pair<string, vector<string>> g : groups)
            res.push_back(g.second);

        return res;
    }
};
