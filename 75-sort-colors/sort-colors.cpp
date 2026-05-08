// OPTIMAL APPROACH (DUTCH NATIONAL FLAG)

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int n = nums.size();

        int low = 0;       // next position for 0
        int mid = 0;       // current element being processed
        int high = n - 1;  // next position for 2

        while (mid <= high) {

            // Place 0 in left section
            if (nums[mid] == 0) {

                swap(nums[low], nums[mid]);

                low++;
                mid++;
            }

            // 1 is already in correct middle section
            else if (nums[mid] == 1) {
                mid++;
            }

            // Place 2 in right section
            else {

                swap(nums[mid], nums[high]);

                high--;

                // mid is not increased here because
                // swapped element from high is still unchecked
            }
        }
    }
};