// BETTER APPROACH USING HASH MAP

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        map<int, int> mpp;
        int n = nums.size();

        // Store frequency of each element
        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }

        // Find element appearing more than n/2 times
        for (auto i : mpp) {

            if (i.second > (n / 2)) {
                return i.first;
            }
        }

        return -1;
    }
};