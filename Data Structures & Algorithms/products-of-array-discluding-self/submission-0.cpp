class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len, 1);

        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < len; ++j) {
                if (i != j)
                    res[i] *= nums[j];
            }     
        }

        return res;
    }
};
