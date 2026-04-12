class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> subsets(vector<int>& nums) {
        buildSubsets(nums, 0, vector<int>{});
        return res;
    }

    void buildSubsets(vector<int>& nums, int index, vector<int> vals) {
        if (index >= nums.size()) {
            res.push_back(vals);
        } else { 
            buildSubsets(nums, index + 1, vals);
            vals.push_back(nums[index]);
            buildSubsets(nums, index + 1, vals);
        }
    }
};
