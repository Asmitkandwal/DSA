// OPTIMAL APPROACH USING XOR

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int xor_val = 0;

        for (int i = 0; i < nums.size(); i++) {

            // Same numbers cancel each other in XOR
            // a ^ a = 0
            // 0 ^ x = x
            xor_val = xor_val ^ nums[i];
        }

        // Only unique element remains after all cancellations
        return xor_val;
    }
};