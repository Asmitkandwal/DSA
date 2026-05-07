class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mpp;
        for(int i = 0;i<nums.size();i++){
            int value = nums[i];
            int need_more = target - value;
            if(mpp.find(need_more) != mpp.end()){
                return{mpp[need_more],i};
            }
            mpp[value] = i;
        }
        return{-1,-1};
    }
};