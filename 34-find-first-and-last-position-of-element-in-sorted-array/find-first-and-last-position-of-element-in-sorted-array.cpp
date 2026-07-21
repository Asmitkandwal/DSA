//OPTIMAL APPROACH

class Solution {
public:
    // =========================================================================
    // HELPER 1: Finds the VERY FIRST index where 'target' appears.
    // =========================================================================
    int findFirstOccurrence(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int first_index = -1; // Default -1 means target hasn't been found yet

        // Standard Closed-Interval Loop [low, high]
        while (low <= high) {
            // OVERFLOW PREVENTION:
            // Never write '(low + high) / 2'. If low and high are near INT_MAX,
            // adding them causes 32-bit integer overflow (wraps into a negative number).
            // 'low + (high - low) / 2' reaches the exact same midpoint safely.
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                first_index = mid; // 1. Save 'mid' as a potential answer
                high = mid - 1;    // 2. KEEP SEARCHING LEFT: Shrink the window to [low, mid - 1]
                                   //    to check if 'target' appears even earlier.
            } 
            else if (nums[mid] < target) {
                low = mid + 1;     // 'mid' is too small -> Target is strictly in the right half
            } 
            else {
                high = mid - 1;    // 'mid' is too big   -> Target is strictly in the left half
            }
        }

        return first_index;
    }

    // =========================================================================
    // HELPER 2: Finds the VERY LAST index where 'target' appears.
    // =========================================================================
    int findLastOccurrence(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int last_index = -1; // Default -1 means target hasn't been found yet

        while (low <= high) {
            // Same overflow protection
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                last_index = mid;  // 1. Save 'mid' as a potential answer
                low = mid + 1;     // 2. KEEP SEARCHING RIGHT: Expand the window to [mid + 1, high]
                                   //    to check if 'target' appears further right.
            } 
            else if (nums[mid] < target) {
                low = mid + 1;     // 'mid' is too small -> Target is strictly in the right half
            } 
            else {
                high = mid - 1;    // 'mid' is too big   -> Target is strictly in the left half
            }
        }

        return last_index;
    }

    // =========================================================================
    // MAIN FUNCTION
    // =========================================================================
    vector<int> searchRange(vector<int>& nums, int target) {
        // Step 1: Run binary search for the first boundary
        int first = findFirstOccurrence(nums, target);

        // EARLY EXIT OPTIMIZATION:
        // If 'target' doesn't exist in the array at all, 'first' will be -1.
        // Don't waste time running the second search! Immediately return {-1, -1}.
        if (first == -1) {
            return {-1, -1};
        }

        // Step 2: Target definitely exists, so find the last boundary
        int last = findLastOccurrence(nums, target);

        return {first, last};
    }
};