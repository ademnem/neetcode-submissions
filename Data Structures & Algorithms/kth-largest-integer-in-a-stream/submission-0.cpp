class KthLargest {
    priority_queue<int> max_heap;
    int k;
public:
    KthLargest(int k, vector<int>& nums) : k{k} { 
        for (int n : nums)
            max_heap.push(n);
    }
    
    int add(int val) {
        max_heap.push(val);
        vector<int> nums;
        for (int i = 0; i < k - 1; ++i) {
            nums.push_back(max_heap.top());
            max_heap.pop();
        }

        int kth = max_heap.top();
        for (int n : nums) 
            max_heap.push(n);    

        return kth;
    }
};
