class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>> max;
        
        for (vector<int> p : points) {
            int x = p[0];
            int y = p[1];
            double dist = sqrt(pow(x, 2) + pow(y, 2));
            max.push({dist, p});
            if (max.size() > k)
                max.pop();
        }

        vector<vector<int>> res;
        while (!max.empty()) {
            res.push_back(max.top().second);
            max.pop();
        }

        return res;
    }
};
