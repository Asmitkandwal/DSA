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
        int posi = 0;
        int nega = 0;
        for(int i = 0;i<n;i++){
            if(i%2==0){
            nums[i] = positive[posi];
            posi++;
            }
            else if(i%2 != 0) {
                nums[i] = negative[nega];
                nega++;
            }
        }

        return nums;
    }
};