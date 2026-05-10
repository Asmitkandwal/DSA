class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        vector<int> positive;
        vector<int> negative;

        // Store positive and negative numbers separately
        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] > 0) {
                positive.push_back(nums[i]);
            }

            else {
                negative.push_back(nums[i]);
            }
        }

        int n = nums.size();

        int posi = 0;   // pointer for positive array
        int nega = 0;   // pointer for negative array

        for (int i = 0; i < n; i++) {

            // Even indexes should contain positive numbers
            if (i % 2 == 0) {

                nums[i] = positive[posi];
                posi++;
            }

            // Odd indexes should contain negative numbers
            else {

                nums[i] = negative[nega];
                nega++;
            }
        }

        return nums;
    }
};