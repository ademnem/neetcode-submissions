class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) { 
        sum(vector<int>{}, target, nums, 0);
        return res;
    }

    void sum(vector<int> vals, int target, vector<int>& nums, int index) {
        if (index + 1 < nums.size())
            sum(vals, target, nums, index + 1);

        vals.push_back(nums[index]);
        if (accumulate(vals.begin(), vals.end(), 0) == target)
            res.push_back(vals);
        if (accumulate(vals.begin(), vals.end(), 0) > target)
            return;
        sum(vals, target, nums, index);
    }
};
