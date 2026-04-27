class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> temp;
        int c = 0;
        int n = nums.size();
        for(int i  = 0;i<n;i++){
            if(nums[i] != 0) temp.push_back(nums[i]);
            else
            c++;
        }

        for (int i = 0;i<c;i++){
            temp.push_back(0);
        }
        
        nums = temp;

    }
};