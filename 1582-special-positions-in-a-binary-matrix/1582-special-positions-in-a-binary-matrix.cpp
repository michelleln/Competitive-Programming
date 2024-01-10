class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<int> sumRows;
        vector<int> sumColumns;
        int special = 0;

        int noRows = mat.size();
        int noColumns = mat[0].size();

        for (int row = 0; row < noRows; row++){
            int rowSum = 0;
            for (int col = 0; col < noColumns; col++) rowSum += mat[row][col];
            sumRows.push_back(rowSum);
        }

        for (int col = 0; col < noColumns; col++){
            int colSum = 0;
            for (int row = 0; row < noRows; row++) colSum += mat[row][col];
            sumColumns.push_back(colSum);
        }

        for (int row = 0; row < noRows; row++){
            for (int col = 0; col < noColumns; col++) {
                if (mat[row][col] == 1 && sumRows[row] == 1 && sumColumns[col] == 1) special++;
            }
        }
        return special;
    }
};