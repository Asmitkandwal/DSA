class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int>even;
        vector<int> odd;

        for(int i = 0;i<nums.size();i++){
            if(i%2 == 0){
                even.push_back(nums[i]);
            }else{
                odd.push_back(nums[i]);
            }
        }

        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end(),greater<int>());

        int e_index = 0,o_index = 0;
        for(int i = 0;i<nums.size();i++){
            if(i%2 == 0){
                nums[i] = even[e_index];
                e_index++;
            }else{
                nums[i] = odd[o_index];
                o_index++;
            }
        }

        return nums;
    }
};