class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        add = dict()
        for i, n in enumerate(nums):
            if target-n in add:
                return [add[target-n], i]
            add[n] = i