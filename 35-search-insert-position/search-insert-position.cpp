class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size();
        for(int i = 0;i<nums.size();i++){
            int mid = (low + (high-low))/2;
            if(nums[i] == target) return i;
            if(nums[i] < target) {
                low = mid+1;
            }
            if(nums[i] > target) return i;
            
        }
        return nums.size();
    }
};