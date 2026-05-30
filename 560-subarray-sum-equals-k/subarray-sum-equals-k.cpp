// BRUTE FORCE APPROACH

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int n = nums.size();
        int count = 0;

        // Consider every index as starting point of a subarray
        for (int i = 0; i < n; i++) {

            int sum = 0;

            // Extend subarray one element at a time
            for (int j = i; j < n; j++) {

                sum += nums[j];

                // If current subarray sum equals k,
                // we found one valid subarray
                if (sum == k) {
                    count++;
                }
            }
        }

        return count;
    }
};