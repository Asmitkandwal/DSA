class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, count = 0;
        unordered_map<int, int> PrefixSum;

        // A prefix sum of 0 is considered to have occurred once.
        // This helps count subarrays that start from index 0.
        PrefixSum[0] = 1;

        for (int num : nums) {
            sum += num;

            // If (sum - k) exists, it means there is a previous
            // prefix sum such that the subarray between them sums to k.
            if (PrefixSum.find(sum - k) != PrefixSum.end()) {
                // Add all occurrences because the same prefix sum
                // may have appeared multiple times.
                count += PrefixSum[sum - k];
            }

            // Store current prefix sum for future subarrays
            PrefixSum[sum]++;
        }

        return count;
    }
};