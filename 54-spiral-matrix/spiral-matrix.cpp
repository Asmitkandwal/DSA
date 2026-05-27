class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;

        // CRITICAL: These 4 pointers define the active boundaries of our spiral window
        int top = 0;
        int left = 0;
        int right = m-1;
        int bottom = n-1;

        while(right >= left && bottom >= top){
            // 1. Move Right: Traverse top row
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++; // Shrink the top boundary downward

            // 2. Move Down: Traverse rightmost column
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]); // Crucial 'i' iteration to move down rows
            }
            right--; // Shrink the right boundary inward

            // CRITICAL: This check prevents duplicating rows in non-square (e.g., 1x5) matrices
            if (top <= bottom) {
                // 3. Move Left: Traverse bottom row
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--; // Shrink the bottom boundary upward
            }

            // CRITICAL: This check prevents duplicating columns in non-square (e.g., 5x1) matrices
            if (left <= right) {
                // 4. Move Up: Traverse leftmost column
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++; // Shrink the left boundary inward
            }
        }

        return ans;
    }
};