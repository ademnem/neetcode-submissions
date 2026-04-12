class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        unordered_map<int, int> lens;
        for (int n : nums) {
            if (!lens[n]) {
                lens[n] = lens[n - 1] + lens[n + 1] + 1;
                lens[n - lens[n - 1]] = lens[n];
                lens[n + lens[n + 1]] = lens[n];
                longest = max(longest, lens[n]);
            }
        }
        return longest;
    }
};
