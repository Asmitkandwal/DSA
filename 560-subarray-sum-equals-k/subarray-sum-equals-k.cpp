// OPTIMAL APPROACH (PREFIX SUM + HASH MAP)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int sum = 0, count = 0;
        int n = nums.size();

        unordered_map<int, int> PrefixSum;

        // Handles case when subarray starting from index 0 has sum k
        PrefixSum[0] = 1;

        for (int i = 0; i < n; i++) {

            // Running prefix sum till current index
            sum += nums[i];

            // If a previous prefix sum of (sum - k) exists,
            // then subarray between those positions has sum k
            int val = sum - k;

            if (PrefixSum.find(val) != PrefixSum.end()) {

                // Add all occurrences because multiple prefix sums
                // can generate valid subarrays
                count = count + PrefixSum[val];
            }

            // Store current prefix sum frequency
            PrefixSum[sum]++;
        }

        return count;
    }
};