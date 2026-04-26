class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();

        // Create vector with size n because we already know
        // exact positions where elements must be placed.
        // If it were empty + push_back(), elements would only
        // be added at end, not directly inserted at index.
        vector<int> demo(n);

        for (int i = 0; i < n; i++) {

            // New index after right rotation
            int index = (i + k) % n;

            // Direct assignment needs valid pre-sized indexes
            demo[index] = nums[i];
        }

        // Replace original array with rotated array
        nums = demo;
    }
};