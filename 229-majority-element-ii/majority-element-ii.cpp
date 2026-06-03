class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mpp;
        vector<int> ans;
        int n = nums.size();
        int req_size = n/3;
        for(int i = 0;i<n;i++){
            mpp[nums[i]]++;
        }

        for(auto it : mpp){
            if(it.second > req_size){
                ans.push_back(it.first);
            }
        }

        return ans;

    }
};