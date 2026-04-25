class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> original;
        for(int i = 0;i<nums.size();i++){
            original.insert(nums[i]);
        }

        int index = 0;

        for(auto i : original){
            nums[index] = i;
            index++;
        }

        return original.size();
    }
};