// BETTER APPROACH

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // Sorting helps bring consecutive numbers together
        sort(nums.begin(), nums.end());

        int longest = 0;

        int lastsmall = INT_MIN; // stores previous element in sequence

        int count = 0;

        int n = nums.size();

        for (int i = 0; i < n; i++) {

            // Current number continues consecutive sequence
            if (nums[i] - 1 == lastsmall) {

                count++;

                lastsmall = nums[i];
            }

            // Skip duplicates so sequence count is not affected
            else if (nums[i] == lastsmall) {
                continue;
            }

            // Sequence breaks, start new sequence
            else {

                count = 1;

                lastsmall = nums[i];
            }

            // Store maximum sequence length found so far
            longest = max(longest, count);
        }

        return longest;
    }
};