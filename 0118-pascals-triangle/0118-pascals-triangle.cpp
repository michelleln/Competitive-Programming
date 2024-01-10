class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) return {};
        if (numRows == 1) return {{1}};
        vector<vector<int>> prevRows = generate(numRows - 1);

        vector<int> currentRow(numRows, 1);
        for (int i = 0; i < numRows - 2; i++) {
            currentRow[i + 1] = prevRows.back()[i] + prevRows.back()[i + 1];
        }
        prevRows.push_back(currentRow);
        return prevRows;
    }
};