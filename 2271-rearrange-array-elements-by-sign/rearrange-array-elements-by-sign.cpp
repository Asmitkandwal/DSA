class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive;
        vector<int> negative;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] > 0){
            positive.push_back(nums[i]);
            }

            else{
            negative.push_back(nums[i]);
            }
            
        }

        int n = nums.size();
        for(int i = 0;i<n/2;i++){
            nums[i*2] = positive[i];
            nums[(i*2)+1] = negative[i];
        }

        return nums;
    }
};