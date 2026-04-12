class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> max;         
        for (int s : stones)
            max.push(s);

        while (max.size() > 1) {
            int x = max.top();     
            max.pop();
            int y = max.top();
            max.pop();
            if (abs(x - y) > 0)
                max.push(abs(x - y));
        }

        if (max.empty())
            return 0;
        return max.top();
    }
};
