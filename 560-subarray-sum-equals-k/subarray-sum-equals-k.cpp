class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0 , count = 0;
        int n = nums.size();

        unordered_map<int,int> PrefixSum;
        PrefixSum[0] =1;

        for(int i = 0;i<n;i++){
            sum += nums[i];

            int val = sum-k;
            if(PrefixSum.find(val) != PrefixSum.end()){
                count = count + PrefixSum[val];
            }
            
            PrefixSum[sum]++;
        }

        return count;
    }
};