class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int i = 0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int ans = -1;
        int maxval = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]%2 == 0){
                if(mpp[nums[i]] > maxval){
                    maxval = mpp[nums[i]];
                    ans = nums[i];
                }else if(mpp[nums[i]] == maxval){
                    ans = min(nums[i],ans);
            }
            }
        }
        
        return ans;
    }
};