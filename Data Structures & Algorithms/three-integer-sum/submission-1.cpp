class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len; ++i) {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1;    
            int k = len - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum > 0)
                    --k;
                else if (sum < 0)
                    ++j;
                else {
                    res.push_back(vector<int>{nums[i], nums[j++], nums[k--]});
                    while (j < k && nums[j] == nums[j - 1])
                        ++j;
                }
            }
        }   
        return res;
    }
};
