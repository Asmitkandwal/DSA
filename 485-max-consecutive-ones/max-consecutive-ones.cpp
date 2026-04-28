class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_value = 0;
        int c = 0;
        for(int i = 0;i<nums.size();i++){
            if (nums[i] == 1){
                c++;
            }
            if (nums[i] == 0){
                c = 0;
            }

            max_value = max(max_value,c);

        }

        return max_value;
    }
};