class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> res;
        vector<int> prefix(len);
        vector<int> suffix(len);

        int product = 1;
        for (int i = 0; i < len; ++i) {
            product *= nums[i];
            prefix[i] = product;
        }

        product = 1;
        for (int i = len - 1; i > 0; --i) {
            product *= nums[i];
            suffix[i] = product;
        }

        for (int i = 0; i < len; ++i) {
            if (i == 0)
                res.push_back(suffix[i + 1]);
            else if (i == len - 1)
                res.push_back(prefix[i - 1]);
            else    
                res.push_back(prefix[i - 1] * suffix[i + 1]);
        }

        return res;
    }
};
