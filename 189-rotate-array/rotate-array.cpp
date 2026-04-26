class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> demo(n);
        
        for(int i = 0;i<n;i++){
            int index = (i+k)%n;
            demo[index] = nums[i];
        }

        nums = demo;
        
    }
};