class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        std::unordered_map<char, int> sfreq;
        std::unordered_map<char, int> tfreq;
        for (char c : s)
            ++sfreq[c];
        for (char c : t)
            ++tfreq[c];
        for (auto& pair : sfreq)
            if (pair.second != tfreq[pair.first])
                return false;
        return true;
    }
};
