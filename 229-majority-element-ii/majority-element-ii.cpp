// OPTIMAL APPROACH (MOORE'S VOTING ALGORITHM)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int count1 = 0;
        int count2 = 0;

        int el1 = INT_MIN;
        int el2 = INT_MIN;

        int n = nums.size();

        // Phase 1: Find potential majority candidates
        for (int i = 0; i < n; i++) {

            // Assign first candidate if its count becomes zero
            if (count1 == 0 && nums[i] != el2) {

                count1++;
                el1 = nums[i];
            }

            // Assign second candidate if its count becomes zero
            else if (count2 == 0 && nums[i] != el1) {

                count2++;
                el2 = nums[i];
            }

            // Vote for first candidate
            else if (nums[i] == el1) {

                count1++;
            }

            // Vote for second candidate
            else if (nums[i] == el2) {

                count2++;
            }

            // Current element cancels one vote from both candidates
            else {

                count1--;
                count2--;
            }
        }

        vector<int> ans;

        // Phase 2: Verify actual frequencies of candidates
        count1 = 0;
        count2 = 0;

        for (int i = 0; i < n; i++) {

            if (nums[i] == el1) count1++;

            if (nums[i] == el2) count2++;
        }

        int min = n / 3;

        // Only include candidates appearing more than n/3 times
        if (count1 > min) ans.push_back(el1);

        if (count2 > min) ans.push_back(el2);

        return ans;
    }
};