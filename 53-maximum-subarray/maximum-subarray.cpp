class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maximum_value = INT_MIN;
        int n = nums.size();
        if (n==1){
            return nums[0];
        }
         int current_sum = 0;
        for(int i = 0;i<n;i++){
            
           
            current_sum += nums[i];
            maximum_value = max(current_sum , maximum_value);

            if(current_sum < 0){
                current_sum = 0;
            }
            
        }
        return maximum_value;

    }
};