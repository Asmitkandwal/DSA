class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        // Range of possible divisors:
        // Smallest possible divisor is 1
        int low = 1;
        // Largest useful divisor is the max number in the array
        int high = *max_element(nums.begin(), nums.end());
        
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int sum = 0;

            // Divide every number by 'mid' (rounded up) and add to total sum
            for (int num : nums) {
                // INTEGER CEILING TRICK:
                // (num + mid - 1) / mid rounds UP without slow double/ceil math
                sum += (num + mid - 1) / mid;
                //can be written as sum+= ceil((double)num /(double) mid)
            }

            // DECISION RULE:
            if (sum <= threshold) {
                ans = mid;       // 'mid' worked! Save it as a valid answer.
                high = mid - 1;  // Try to find an even SMALLER divisor on the left side.
            } else {
                low = mid + 1;   // Sum was too big! We need a LARGER divisor to make the sum smaller.
            }
        }

        return ans;
    }
};