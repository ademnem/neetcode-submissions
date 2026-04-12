class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int numRows = matrix.size();
        if (numRows <= 0)
            return false;
        int numCols = matrix[0].size();
        
        int left = 0, right = numRows * numCols - 1;
        while (left <= right) {            
            int mid = (left + right) / 2;
            int row = mid / numCols;
            int col = mid % numCols;
            if (target < matrix[row][col]) 
                right = mid - 1;
            else if (target > matrix[row][col])
                left = mid + 1;
            else if (target == matrix[row][col])
                return true;
        }     
        return false;
    }
};
