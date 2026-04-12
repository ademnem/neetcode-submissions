class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min;

        for (int i = 0; i < temperatures.size(); ++i) {
            while (!min.empty() && min.top().first < temperatures[i]) { 
                res[min.top().second] = i - min.top().second; 
                min.pop();
            }
            min.push({temperatures[i], i});
        }

        return res;
    }
};
