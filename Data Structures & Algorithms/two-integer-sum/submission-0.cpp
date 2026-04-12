class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        std::unordered_map<int, int> add;
        for (int i = 0; i < len; ++i) {
            if (add[target - nums[i]])
                return vector<int>{add[target - nums[i]] - 1, i};
            add[nums[i]] = i + 1;
        }
        return vector<int>{};
    }
};
