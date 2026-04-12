class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> dups;
        for (int n : nums) {
            if (dups.count(n) > 0)
                return true;
            dups.insert(n);
        }
        return false;
    }
};
