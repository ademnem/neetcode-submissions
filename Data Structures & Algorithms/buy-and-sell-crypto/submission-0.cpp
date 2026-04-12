class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int prof = 0;
        for (int sell : prices) {
            prof = max(sell - buy, prof);
            buy = min(buy, sell);
        }
        return prof;
    }
};
