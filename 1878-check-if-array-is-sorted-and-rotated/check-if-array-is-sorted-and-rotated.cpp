class Solution {
public:

    bool is_rotated(vector<int>&arr){
        for(int i = 0;i<arr.size()-1;i++){
            if(arr[i]>arr[i+1]) return false;
        }
        return true;
    }

    bool check(vector<int>& nums) {
        int n = nums.size();
        for(int shift = 0;shift<n;shift++){

            vector<int> rotated;
            
            for(int i = 0;i<n;i++){
                int idx = (i+shift)%n;
                rotated.push_back(nums[idx]);
            }

            if(is_rotated(rotated)) {
                return true;
            }    

        }

        return false;
    }
};