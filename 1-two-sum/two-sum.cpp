// BRUTE FORCE APPROACH

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // Try every possible pair
        for (int i = 0; i < nums.size(); i++) {

            // Start from i+1 to avoid using same element twice
            for (int j = i + 1; j < nums.size(); j++) {

                // Pair found whose sum equals target
                if (nums[i] + nums[j] == target)
                    return {i, j};
            }
        }

        // No valid pair found
        return {-1, -1};
    }
};