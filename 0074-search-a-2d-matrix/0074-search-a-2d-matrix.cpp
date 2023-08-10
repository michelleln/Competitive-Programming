class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lowerRow = 0;
        int upperRow = matrix.size() - 1;
        int mid = 0;
        int rowFound = -1;
        int n = matrix[0].size() - 1;
        while (lowerRow <= upperRow) {
            mid = floor((lowerRow + upperRow) / 2);
            if (matrix[mid][0] == target || matrix[mid][n] == target){
                return true;
            }
            else if (matrix[mid][0] < target && matrix[mid][n] > target){
                rowFound = mid;
                break;
            } else if (matrix[mid][0] < target && matrix[mid][n] < target){
                lowerRow = mid + 1;
            } else if (matrix[mid][0] > target && matrix[mid][n] > target) {
                upperRow = mid - 1;
            }
        }

        if (rowFound == -1){
            return false;
        }

        int lowerCol = 0;
        int upperCol = matrix[0].size() - 1;
        while (lowerCol <= upperCol) {
            mid = floor((lowerCol + upperCol) / 2);
            if (matrix[rowFound][mid] == target) {
                return true;
            } else if (matrix[rowFound][mid] < target){
                lowerCol = mid + 1;
            } else {
                upperCol = mid - 1;
            }
        }
        return false;
    }
};