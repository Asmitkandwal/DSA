//OPTIMAL SOLUTION(ONLY WORKING)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        
        // 1. Sort the numbers from smallest to largest.
        // This lets us use two pointers and easily skip duplicate answers.
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++){
            // If this number is the same as the last one we processed, skip it.
            // This prevents us from creating the exact same triplet again.
            if(i > 0 && nums[i] == nums[i-1]) continue;

            // 2. Set up two pointers for the rest of the array.
            int j = i + 1; // Starts right after the fixed number
            int k = n - 1; // Starts at the very end of the array
            
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                
                // Case 1: The sum is exactly 0. We found a valid triplet!
                if(sum == 0){
                    ans.push_back({nums[i], nums[j], nums[k]});

                    // Skip identical numbers on the left and right 
                    // so we don't pick up duplicate combinations.
                    while(j < k && nums[j] == nums[j+1]) j++;
                    while(j < k && nums[k] == nums[k-1]) k--; 

                    // Move both pointers inward to keep looking for other pairs
                    j++;
                    k--;
                }
                // Case 2: The sum is too big. 
                // Since the array is sorted, move the right pointer leftward to get a smaller number.
                else if(sum > 0){
                    k--;
                }
                // Case 3: The sum is too small.
                // Move the left pointer rightward to get a bigger number.
                else {
                    j++;
                }
            }
        }
        return ans;
    }
};