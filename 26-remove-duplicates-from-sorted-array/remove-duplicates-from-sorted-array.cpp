class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        // First element is already unique,
        // next unique element will be placed from index 1
        int index = 1;

        for (int i = 1; i < nums.size(); i++) {

            // If current element differs from previous,
            // it means a new unique number is found
            if (nums[i] != nums[i - 1]) {

                // Place unique element in compact front portion
                nums[index] = nums[i];
                index++;
            }
        }

        // Number of unique elements stored in front
        return index;
    }
};