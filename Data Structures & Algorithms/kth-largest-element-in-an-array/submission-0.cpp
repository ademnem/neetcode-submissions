class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> min;
        for (int n : nums) {
            min.push(n);
            if (min.size() > k)
                min.pop();
        }
        return min.top();
    }
};
