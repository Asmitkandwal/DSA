// BINARY SEARCH ON ANSWER

class Solution {
public:

    // Returns the total hours needed if Koko
    // eats 'mid' bananas every hour.
    long long cal_hours(vector<int>& piles, int mid) {

        long long total_hours = 0;

        for (int bananas : piles) {

            // Ceiling division:
            // Even a partially finished pile takes one full hour.
            // (a + b - 1) / b computes ceil(a / b) using only integers.
            total_hours += (bananas + mid - 1LL) / mid;
            //total_hours += ceil((double)bananas / (double)mid); {works same as above}
        }

        return total_hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        // Minimum possible eating speed.
        int low = 1;

        // Maximum useful eating speed.
        // Any speed greater than the largest pile
        // behaves exactly the same.
        int high = *max_element(piles.begin(), piles.end());

        int ans = high;

        // Search for the minimum speed that
        // finishes all bananas within h hours.
        while (low <= high) {

            int mid = low + (high - low) / 2;

            // Current speed works.
            // Save it and check if an even slower
            // speed is also sufficient.
            long long total_hours = cal_hours(piles, mid);
            if ( total_hours <= h) {
                ans = mid;
                high = mid - 1;
            }

            // Current speed is too slow.
            // Increase the eating speed.
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};