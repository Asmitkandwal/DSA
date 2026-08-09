class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();    // Total rows
        int m = matrix[0].size(); // Total columns

        // Start at the TOP-RIGHT corner (row 0, last column)
        int row = 0;
        int col = m - 1;

        // Stay within matrix boundaries
        while (row < n && col >= 0) {
            
            // TARGET FOUND
            if (matrix[row][col] == target) {
                return true;
            } 
            // CURRENT NUMBER TOO SMALL:
            // All numbers to the left in this row are even smaller.
            // Move DOWN to the next row to find bigger numbers.
            else if (matrix[row][col] < target) {
                row++;
            } 
            // CURRENT NUMBER TOO BIG:
            // All numbers below in this column are even bigger.
            // Move LEFT to the previous column to find smaller numbers.
            else {
                col--;
            }
        }

        return false; // Target not present in matrix
    }
};