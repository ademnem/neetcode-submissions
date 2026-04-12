class Solution {
public:
    bool isAnagram(string s, string t) {
        int slen = s.length();
        int tlen = t.length();
        if (slen != tlen)
            return false;
        for (int i = 0; i < slen; ++i) {
            size_t found = t.find(s[i]);
            if (found == -1)
                return false;
            t[found] = 0;
        }
        return true;
    }
};
