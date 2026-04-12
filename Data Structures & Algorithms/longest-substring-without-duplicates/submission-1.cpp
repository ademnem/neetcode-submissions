class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        int len = s.length();
        int l = 0, r = 0;  
        set<char> ch;
        for (; r < len; ++r) {
            if (ch.find(s[r]) == ch.end()) {
                ch.insert(s[r]);
            } else {
                longest = max(r - l, longest);
                while (s[l] != s[r])
                    ch.erase(s[l++]); 
                ++l;
            } 
        }
        longest = max(r - l, longest);
        return longest;
    }
};
