class Solution {
public:

    string encode(vector<string>& strs) {
        string res{};
        for (string s : strs)
            res += to_string(s.length()) + "#" + s;
        return res;
    }

    vector<string> decode(string s) {  
        vector<string> res;
        int slen = s.length();
        int i = 0;
        while (i < slen) {
            string num{}; 
            while (isdigit(s[i]))
                num += s[i++];
            int len = stoi(num);
            res.push_back(s.substr(++i, len));
            i += len;
        }
        return res;
    }
};
