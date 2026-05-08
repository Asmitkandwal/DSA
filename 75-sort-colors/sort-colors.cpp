// BRUTE FORCE APPROACH

class Solution {
public:
    void sortColors(vector<int>& nums) {

        vector<int> vec;

        int zeros = 0;
        int ones = 0;
        int twos = 0;

        // Count frequency of 0s, 1s and 2s
        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == 0)
                zeros++;

            else if (nums[i] == 1)
                ones++;

            else
                twos++;
        }

        // Insert all 0s first
        for (int i = 0; i < zeros; i++) {
            vec.push_back(0);
        }

        // Then insert all 1s
        for (int i = 0; i < ones; i++) {
            vec.push_back(1);
        }

        // Finally insert all 2s
        for (int i = 0; i < twos; i++) {
            vec.push_back(2);
        }

        // Replace original array with sorted result
        nums = vec;
    }
};