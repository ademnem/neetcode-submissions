class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;        

        for (string s : strs) {
            int group = 0; 
            for (; group < res.size(); ++group) {
                if (isAnagram(s, res[group][0]))
                    break;
            }

            if (group == res.size())
                res.push_back(vector<string>{s});
            else 
                res[group].push_back(s);
        }    
        return res;
    }

    bool isAnagram(string l, string r) {
        if (l.length() != r.length())
            return false;

        unordered_map<char, int> freq; 
        for (int i = 0; i < l.length(); ++i) {
            ++freq[l[i]];
            --freq[r[i]];
        }

        for (pair<char, int> p : freq) {
            if (p.second != 0)
                return false;
        }
        return true;
    } 
};
