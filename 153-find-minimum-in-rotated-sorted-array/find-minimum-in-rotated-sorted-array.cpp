class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = INT_MAX; // Tracks the minimum value found across search windows

        while (low <= high) {
            // OPTIMIZATION: If the current subarray is already fully sorted,
            // the minimum element MUST be at 'low'. We don't need binary search anymore!
            if (nums[low] <= nums[high]) {
                ans = min(ans, nums[low]);
                break; // Exit loop early
            }

            // SAFE MIDPOINT: Prevents 32-bit integer overflow
            int mid = low + (high - low) / 2;

            // CORE PROPERTY OF ROTATED SORTED ARRAYS:
            // One half is ALWAYS cleanly sorted, while the other half contains the pivot (drop point).

            // CASE 1: The LEFT half [low...mid] is sorted
            if (nums[low] <= nums[mid]) {
                // The smallest value in a sorted left half is always nums[low]
                ans = min(ans, nums[low]);
                
                // The global minimum could still be hiding in the unsorted right half, so move right
                low = mid + 1;
            } 
            // CASE 2: The RIGHT half [mid...high] is sorted
            else {
                // The smallest value in a sorted right half is always nums[mid]
                ans = min(ans, nums[mid]);

                // The global minimum must be in the unsorted left half, so move left
                high = mid - 1;
            }
        }

        return ans;
    }
};