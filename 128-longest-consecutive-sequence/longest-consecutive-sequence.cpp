class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int longest = 0;
        int lastsmall = INT_MIN;
        int count = 0;
        int n = nums.size();
        
        for(int i = 0;i<n;i++){
            if(nums[i]-1 == lastsmall){
                count++;
                lastsmall = nums[i];
            }
            else if(nums[i] == lastsmall){
                continue;
            }
            else if(nums[i] != lastsmall){
                count = 1;
                lastsmall = nums[i];
            }

            longest = max(longest,count);
        }

        return longest;
    }
};