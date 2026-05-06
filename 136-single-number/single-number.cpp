class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for(int i =0;i<nums.size();i++){
            int val = nums[i];
            int count = 0;
            for(int j = 0;j<nums.size();j++){
                if(nums[j] == val)
                count++;
            }

            if(count == 1) return val;
        }
        return -1;
    }
};