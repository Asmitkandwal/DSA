class Solution {
public:
    // HELPER: Checks if we can split 'nums' into 'k' or fewer subarrays 
    // without any single subarray sum exceeding 'mid'.
    bool isPossible(vector<int>& nums, int k, int mid) {
        int split = 1; // Start with 1 subarray
        int sum = 0;   // Current subarray sum

        for (int i = 0; i < nums.size(); i++) {
            // If adding this number fits within limit 'mid', keep packing
            if (sum + nums[i] <= mid) {
                sum += nums[i];
            } 
            // Limit exceeded! Start a new subarray with the current number
            else {
                split++;
                sum = nums[i];
            }

            // EARLY EXIT: The moment splits exceed 'k', 'mid' is invalid.
            // Stop checking the rest of the array immediately!
            if (split > k) {
                return false;
            }
        }

        return true; // Successfully split into <= k subarrays
    }

    int splitArray(vector<int>& nums, int k) {
        // MINIMUM BOUND:
        // Max single element (a subarray must at least hold the largest number).
        int low = *max_element(nums.begin(), nums.end());

        // MAXIMUM BOUND:
        // Sum of all elements (worst-case scenario where k = 1).
        // Note: Using 0LL prevents 32-bit integer overflow during summation.
        long long high = accumulate(nums.begin(), nums.end(), 0);

        int ans = high;

        // Binary search on the answer range [max_element ... total_sum]
        while (low <= high) {
            int mid = low + (high - low) / 2;

            // DECISION RULE:
            if (isPossible(nums, k, mid)) {
                ans = mid;       // 'mid' works! Save it as a candidate answer.
                high = mid - 1;  // Search LEFT for an even smaller max sum.
            } else {
                low = mid + 1;   // 'mid' was too small (exceeded k splits). Search RIGHT.
            }
        }

        return ans;
    }
};