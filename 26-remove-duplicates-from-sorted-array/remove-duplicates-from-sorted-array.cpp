class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        set<int> original;

        // Set stores only unique values automatically
        for (int i = 0; i < nums.size(); i++) {
            original.insert(nums[i]);
        }

        int index = 0;

        // Copy unique sorted values back into nums
        for (auto i : original) {
            nums[index] = i;
            index++;
        }

        // Number of unique elements = new valid length
        return original.size();
    }
};