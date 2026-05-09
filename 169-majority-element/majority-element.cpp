//BRUTE FORCE
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        for(int i  = 0;i<n;i++){
            int count = 0;
            int element = nums[i];
            for(int j = 0;j<n;j++){
                if (element == nums[j]){
                    count++;
                }
            }

            if(count > (n/2)){
                return element;
            }
        }

        return -1;
    }
};