class Solution {
public:
    bool alphaNum(char c) {
        return c >= 'A' && c <= 'Z' ||
            c >= 'a' && c <= 'z' ||
            c >= '0' && c <= '9';
    }


    bool isPalindrome(string s) {
        int len = s.length();
        int front = 0, back = len - 1;

        while (back > front) {  
            while (front < back && !alphaNum(s[front]))
                ++front;
            while (back > front && !alphaNum(s[back]))
                --back;

            if (tolower(s[front]) != tolower(s[back]))
                return false; 

            ++front;
            --back; 
        }
        return true;
    }
};
