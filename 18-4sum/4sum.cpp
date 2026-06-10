//ABSOLUTE OPTIMAL CODE..

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        
        // Edge Case: If there are fewer than 4 numbers, a quadruplet is impossible.
        if (n < 4) return ans; 

        // 1. Sort the array so we can use Two-Pointers and easily skip duplicates
        sort(nums.begin(), nums.end());

        // Loop 1: Fixes the 1st number
        for (int i = 0; i < n; i++) {
            // Skip duplicates for the 1st number to avoid duplicate answers
            if (i > 0 && nums[i] == nums[i-1]) continue;

            // Loop 2: Fixes the 2nd number
            for (int j = i + 1; j < n; j++) {
                // Skip duplicates for the 2nd number.
                // 'j > i + 1' ensures we don't accidentally skip the first choice for 'j'
                if (j > i + 1 && nums[j] == nums[j-1]) continue;

                // 2. Set up Two-Pointers for the remaining sorted window
                int k = j + 1; // 3rd pointer (moves right)
                int l = n - 1; // 4th pointer (moves left)

                while (k < l) {
                    // Use 'long long' cast on the first element to force C++ 
                    // to calculate the entire sum without 32-bit integer overflow
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                    // Case 1: Sum matches target
                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});

                        // Skip identical adjacent numbers to avoid duplicate answers
                        while (k < l && nums[k] == nums[k + 1]) k++;
                        while (k < l && nums[l] == nums[l - 1]) l--;

                        // Move both pointers inward to look for the next combination
                        k++;
                        l--;
                    } 
                    // Case 2: Sum is too big, move the right pointer leftward
                    else if (sum > target) {
                        l--;
                    } 
                    // Case 3: Sum is too small, move the left pointer rightward
                    else {
                        k++;
                    }
                }
            }
        }
        return ans;
    }
};