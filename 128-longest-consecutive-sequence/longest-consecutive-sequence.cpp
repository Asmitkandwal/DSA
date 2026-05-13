// OPTIMAL APPROACH USING HASH SET

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int longest = 0;

        // Store all elements for O(1) lookup
        unordered_set<int> st(nums.begin(), nums.end());

        for (int i : st) {

            // Start counting only if current number
            // is the beginning of a sequence
            if (st.find(i - 1) == st.end()) {

                int current = i;

                int count = 1;

                // Extend sequence while next consecutive number exists
                while (st.find(current + 1) != st.end()) {

                    current += 1;

                    count += 1;
                }

                // Store longest sequence length found
                longest = max(longest, count);
            }
        }

        return longest;
    }
};