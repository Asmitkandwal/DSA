class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;

        // Phase 1: Find the majority candidate
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            
            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }

        // Note: The problem description typically guarantees that a majority 
        // element always exists. If it doesn't, a second pass would be 
        // required to verify that the candidate appears > n/2 times.
        return candidate;
    }
};