class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        // A set to automatically store unique quadruplets and remove duplicates
        set<vector<int>> st;

        // Loop 1: Fixes the first number
        for(int i = 0; i < n; i++){
            // Loop 2: Fixes the second number
            for(int j = i + 1; j < n; j++){
                
                // This hashset tracks numbers that sit between index 'j' and index 'k'
                // Using 'long long' prevents any integer overflow bugs
                unordered_set<long long> hashset;
                
                // Loop 3: Fixes the third number
                for(int k = j + 1; k < n; k++){
                    // Calculate the sum of the first three picked numbers
                    long long sum = (long long)nums[i] + nums[j] + nums[k];
                    
                    // Find what value the 4th number needs to be to hit the target
                    long long fourth = (long long)target - sum;
                    
                    // Convert it back to a normal integer for our final answer container
                    int new_fourth = (int)fourth;
                    
                    // If that 4th required number is found inside our lookup hashset, we have a match!
                    if(hashset.find(fourth) != hashset.end()){
                        vector<int> temp = {nums[i], nums[j], nums[k], new_fourth};
                        sort(temp.begin(), temp.end()); // Sort so the outer 'set' can identify duplicates
                        st.insert(temp);
                    }
                    
                    // Put the current number into the hashset for subsequent loop iterations
                    hashset.insert(nums[k]);
                }
            }
        }

        // Convert our unique set of answers back into a standard 2D vector to return it
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};