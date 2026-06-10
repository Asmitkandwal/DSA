class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>>st;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                unordered_set<int> hashset;
                for(int k = j+1;k<n;k++){
                    long long sum = (long long)nums[i]+nums[j]+nums[k];
                    long long fourth = (long long)target - sum;
                    // Check if fourth can safely fit inside a standard 32-bit int
                    if (fourth >= INT_MIN && fourth <= INT_MAX) {
                        // Now it is completely safe to cast it to an int
                        int target_element = (int)fourth; 
    
                       if (hashset.find(target_element) != hashset.end()) {
                            vector<int> temp = {nums[i], nums[j], nums[k], target_element};
                           sort(temp.begin(), temp.end());
                            st.insert(temp);
                        }
                    }
                    hashset.insert(nums[k]);
                }
            }
        }

        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};