class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind = -1; // Correctly initialize to -1
        int n = nums.size();
        
        // Step 1: Find the breakpoint (first dip from the right)
        for(int i = n - 2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                ind = i;
                break;
            }
        }

        // Step 2: If no breakpoint, it's the last permutation. Reverse all.
        if(ind == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find the next largest element to the right of the breakpoint and swap
        for(int i = n - 1; i > ind; i--){
            if(nums[i] > nums[ind]){
                swap(nums[i], nums[ind]);
                break;
            }
        }

        // Step 4: Reverse the suffix to get the smallest lexicographical order
        reverse(nums.begin() + ind + 1, nums.end()); 
    }
};