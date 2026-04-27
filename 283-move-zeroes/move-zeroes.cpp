class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        vector<int> temp;
        int c = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            // Keep non-zero elements in same relative order
            if (nums[i] != 0)
                temp.push_back(nums[i]);

            // Count zeros to place later at end
            else
                c++;
        }

        // Append all counted zeros at the end
        for (int i = 0; i < c; i++) {
            temp.push_back(0);
        }

        // Replace original array with required arrangement
        nums = temp;
    }
};