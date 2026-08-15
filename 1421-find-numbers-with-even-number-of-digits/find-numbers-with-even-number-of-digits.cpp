class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int val = 0; // Counter for numbers with an even number of digits
        
        for (int i = 0; i < nums.size(); i++) {
            // Convert the integer into a string to inspect character length
            string str = to_string(nums[i]);
            
            // Check if the total digit count (string length) is even
            if (str.length() % 2 == 0) {
                val++;
            }
        }

        return val;
    }
};