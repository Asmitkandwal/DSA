class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1,last = -1;

        if(nums.empty()){
            return {first,last};
        }

        if(nums.size()==1 && nums[0] == target){
            first = 0, last = 0;
            return {first,last};
        }
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == target && first == -1){
                first = i;
            }else if(nums[i] == target) {
                last = i;
            }
        }
        if(first != -1 && last == -1){
            last = first;
        }

        return{first,last};
    }
};