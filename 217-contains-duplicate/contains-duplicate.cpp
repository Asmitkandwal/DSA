class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>my_set(nums.begin(),nums.end());
        if(my_set.size() == nums.size()){
            return false;
        }
        else
        return true;
    }
};