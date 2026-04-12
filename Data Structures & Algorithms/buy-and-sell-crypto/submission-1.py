class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        low = 101
        high = 0
        max_prof = 0
        # new lowest, reset highest
        # new highest
        # continue
        for price in prices:
            if price < low:
                low = price
                high = 0
            if price > high:
                high = price

            curr_prof = high - low
            max_prof = curr_prof if curr_prof > max_prof else max_prof

        return max_prof