class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // k = bananas / hour
        // h = total hours
        // k <= max(piles)
        // h / k >= # of piles
        int r = 0;
        for (int pile : piles)
            r = max(r, pile);

        int l = 1; 
        int k = r;
        while (l <= r) {
            double mid = (r + l) / 2;
            int hours = 0;
            for (int pile : piles)
                hours += ceil(pile / mid); 
            
            if (hours <= h) {
                k = k < mid ? k : mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return k;
    }
};
