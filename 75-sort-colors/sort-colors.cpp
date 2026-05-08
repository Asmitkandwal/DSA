class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> vec;
        int zeros = 0;
        int ones = 0;
        int twos = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 0) zeros++;
            else if(nums[i] == 1) ones++;
            else
            twos++;
        }


        for(int i = 0;i<zeros;i++){
            vec.push_back(0);
        }
        for(int i = 0;i<ones;i++){
            vec.push_back(1);
        }
        for(int i = 0;i<twos;i++){
            vec.push_back(2);
        }

        nums = vec;
    }
};