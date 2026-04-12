class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len);
        vector<int> prefix(len);
        vector<int> suffix(len);

        prefix[0] = 1;
        for (int i = 1; i < len; ++i)
            prefix[i] = nums[i - 1] * prefix[i - 1];

        suffix[len - 1] = 1;
        for (int i = len - 2; i >= 0; --i)
            suffix[i] = nums[i + 1] * suffix[i + 1];

        for (int i = 0; i < len; ++i)
            res[i] = prefix[i] * suffix[i];

        return res;
    }
};
