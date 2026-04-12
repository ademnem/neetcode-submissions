class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        priority_queue<int, vector<int>, greater<int>> min;
        for (int n : nums) 
            min.push(n);
        
        int longest = 0;
        int curr_len = 1;
        int prev = min.top();
        min.pop();
        while (!min.empty()) {
            if (min.top() == prev) {
                min.pop();
            } else if (min.top() - prev == 1) {
                ++curr_len;
                prev = min.top();
                min.pop();
            } else {
                longest = max(longest, curr_len);
                prev = min.top();
                curr_len = 1;
                min.pop();
            }
        }
        longest = max(curr_len, longest);
        return longest;
    }
};
