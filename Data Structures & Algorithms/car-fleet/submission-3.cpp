class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars; 
        for (int i = 0; i < position.size(); ++i)
            cars.push_back({position[i], speed[i]});

        sort(cars.begin(), cars.end(), std::greater<pair<int, int>>()); // descending for position

        int fleets = 1;  

        double time = (target - cars[0].first) * 1.0 / cars[0].second; // time target is reached 
        for (int i = 1; i < cars.size(); ++i) { 
            double curr_time = (target - cars[i].first) * 1.0 / cars[i].second;
            if (curr_time > time) {
                ++fleets; 
                time = curr_time;
            }
        } 

        return fleets; 
    }
};
