class Solution {
public:
    bool isAnagram(string s, string t) {
        int len = s.length();
        if (len != t.length())
            return false;

        std::unordered_map<char, int> freq;
        for (int i = 0; i < len; ++i) {
            ++freq[s[i]];
            --freq[t[i]];
        }
        for (pair<char, int> pair : freq)
            if (pair.second)
                return false;
        return true;
    }
};
