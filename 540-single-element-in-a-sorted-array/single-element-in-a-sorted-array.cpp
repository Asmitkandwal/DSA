class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        // Loop until 'low' and 'high' converge on a single element
        while (low < high) {
            // 1. Calculate midpoint safely
            int mid = low + (high - low) / 2;

            // 2. EVEN INDEX NORMALIZATION:
            // Force 'mid' to always point to the start of an EVEN index.
            // If mid is odd (e.g., index 3), decrement to make it even (index 2).
            if (mid % 2 == 1) {
                mid--;
            }

            // 3. CHECK THE (EVEN, ODD) PAIR PATTERN:
            // 'mid' is guaranteed even, so 'mid + 1' is odd.
            if (nums[mid] == nums[mid + 1]) {
                // Matching pair! We are on the valid left side of the single element.
                // Skip past this full pair by moving 'low' two steps to the right.
                low = mid + 2;
            } else {
                // Mismatch! The pattern broke on or before 'mid'.
                // The single element lies in the left half (inclusive of 'mid').
                high = mid;
            }
        }

        // When low == high, both pointers land directly on the single element
        return nums[low];
    }
};