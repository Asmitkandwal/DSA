class Solution {
public:
    // HELPER: Checks if we can split 'nums' into 'k' or fewer subarrays 
    // such that no single subarray sum exceeds 'mid'.
    bool isPossible(vector<int>& nums, int k, int mid) {
        int split = 1; // Start with 1 subarray
        int sum = 0;   // Current subarray sum

        for (int i = 0; i < nums.size(); i++) {
            // If adding this number fits within limit 'mid', pack it in
            if (sum + nums[i] <= mid) {
                sum += nums[i];
            } 
            // Limit exceeded! Start a new subarray with the current number
            else {
                split++;
                sum = nums[i];
            }

            if(split > k){
                return false;
            }
        }

        // True if we can fit everything into 'k' or fewer subarrays
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        // MINIMUM POSSIBLE ANSWER:
        // A single subarray must hold at least the largest single number.
        int low = *max_element(nums.begin(), nums.end());

        // MAXIMUM POSSIBLE ANSWER:
        // If k = 1 (no splits), the answer is the total sum of all numbers.
        int high = accumulate(nums.begin(), nums.end(), 0);

        int ans = high;

        // Binary Search on the ANSWER range [max_element ... total_sum]
        while (low <= high) {
            int mid = low + (high - low) / 2;

            // DECISION RULE:
            if (isPossible(nums, k, mid)) {
                ans = mid;       // 'mid' works! Save it as a valid answer.
                high = mid - 1;  // Try searching LEFT for an even smaller max sum.
            } else {
                low = mid + 1;   // 'mid' was too small (needed > k splits). Search RIGHT.
            }
        }

        return ans;
    }
};