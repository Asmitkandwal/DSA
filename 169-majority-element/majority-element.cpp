class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mpp;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            mpp[nums[i]]++;
        }

        for(auto i : mpp){
            if(i.second > (n/2) ){
                return i.first;
            }
        }

        return -1;
    }
};