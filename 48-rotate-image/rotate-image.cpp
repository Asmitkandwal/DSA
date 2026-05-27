class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();

        // Temporary matrix is used because directly modifying
        // original matrix would overwrite values still needed later
        vector<vector<int>> arr(n, vector<int>(n, 0));

        // Place every element into its 90° rotated position
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                // Mapping:
                // matrix[i][j] -> arr[j][n-i-1]
                arr[j][n - i - 1] = matrix[i][j];
            }
        }

        // Copy rotated matrix back into original matrix
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                matrix[i][j] = arr[i][j];
            }
        }
    }
};