class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);

        stack<pair<int, int>> temps;
        for (int i = temperatures.size() - 1; i >= 0; --i) {
            int day = i;
            while (!temps.empty()) {
                if (temps.top().first > temperatures[i]) {
                    day = temps.top().second;  
                    break;
                }
                temps.pop();
            }   
            temps.push({temperatures[i], i});
            res[i] = day - i; 
        }
        return res;
    }
};
