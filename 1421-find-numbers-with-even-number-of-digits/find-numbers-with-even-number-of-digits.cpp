class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int val = 0; 
        for(int i = 0;i<nums.size();i++){
            long long k = 0;
            while(nums[i] != 0){
                nums[i] = nums[i]/10;
                k++;
            }
            if(k%2 == 0) {
                val++;
            }
        }

        return val;
    }
};