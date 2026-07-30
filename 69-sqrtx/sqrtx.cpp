// BINARY SEARCH - SQUARE ROOT

class Solution {
public:
    int mySqrt(int x) {

        int low = 1;
        int high = x;
        int ans = 0;

        // Search for the largest number whose square
        // is less than or equal to x.
        while (low <= high) {

            // Prevent integer overflow while finding mid.
            long long mid = low + (high - low) / 2;

            // Mid is a valid answer.
            // Try to find a larger one.
            if ((mid * mid) <= x) {
                ans = mid;
                low = mid + 1;
            }

            // Mid is too large.
            // Search in the left half.
            else {
                high = mid - 1;
            }
        }

        // Floor value of √x.
        return ans;
    }
};