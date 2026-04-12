class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = *max_element(piles.begin(), piles.end());
        int l = 1; 
        int k = r;
        while (l <= r) {
            double mid = (r + l) / 2;
            int hours = 0;
            for (int pile : piles)
                hours += ceil(pile / mid); 
            
            if (hours <= h) {
                k = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return k;
    }
};
