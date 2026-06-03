class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0;
        int count2 = 0;
        int el1 = INT_MIN;
        int el2 = INT_MIN;
        int n = nums.size();
        for(int i  = 0;i<n;i++){
            if(count1 == 0 && nums[i] != el2){
                count1++;
                el1 = nums[i];
            }
            else if(count2 == 0 && nums[i] != el1){
                count2++;
                el2 = nums[i];
            }
            else if(nums[i] == el1)  { count1++; }
            else if(nums[i] == el2)  { count2++; }
            else{
                count1--;
                count2--;
            }

        }

        vector<int> ans;
        count1 = 0;
        count2 = 0;

        for(int i = 0;i<n;i++){
            if(el1 == nums[i]) count1++;
            if(el2 == nums[i]) count2++;
        }
        int min = (n/3);
        if(count1 > min) ans.push_back(el1);
        if(count2 > min) ans.push_back(el2);

        return ans;
    }
};