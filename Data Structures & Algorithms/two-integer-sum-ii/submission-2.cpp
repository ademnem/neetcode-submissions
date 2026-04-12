class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        int one = 0, two = len - 1;

        while (one < two) {
            int diff = target - numbers[one];
            while (diff < numbers[two])
                --two;
            if (numbers[one] + numbers[two] == target)
                return vector<int>{one + 1, two + 1};
            ++one;
        }
        return vector<int>{0, 0};
    }
};
