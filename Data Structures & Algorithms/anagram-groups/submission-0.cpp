class Solution {
public:

    bool isAnagram(string& l, string& r) {
        unordered_map<char, int> freq{};

        int len = l.length();
        if (len != r.length())
            return false;

        for (int i = 0; i < len; ++i) {
            ++freq[l[i]];
            --freq[r[i]];
        }
        for (pair<char, int> p : freq) 
            if (p.second != 0) 
                return false; 
        
        return true; 
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groups;
        for (string s : strs) { 
            int len = groups.size();
            int group = 0;
            for ( ; group < len; ++group) {
                if (isAnagram(groups[group][0], s))
                    break; 
            }
            
            if (group == len)
                groups.push_back(vector<string>{s});
            else
                groups[group].push_back(s);
        }
        return groups;
    }
};
