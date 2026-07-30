// BINARY SEARCH ON ANSWER PATTERN

class Solution {
public:

    // Helper function: Calculates total hours Koko needs if she eats 'mid' bananas per hour
    long long cal_hours(vector<int>& piles, int mid) {

        long long total_hours = 0;

        for (int bananas : piles) {
            // INTEGER CEILING DIVISION:
            // Math trick for ceil(bananas / mid) without slow float math:
            // Example: 7 bananas at speed 3 -> (7 + 3 - 1) / 3 = 9 / 3 = 3 hours.
            // '- 1LL' prevents integer overflow if (bananas + mid) is huge.
            total_hours += (bananas + mid - 1LL) / mid;
        }

        return total_hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        // Range of possible eating speeds:
        int low = 1;                                         // Slowest speed (1 banana/hr)
        int high = *max_element(piles.begin(), piles.end()); // Fastest speed needed (largest pile)

        int ans = high;

        // Binary search to find the absolute minimum working speed
        while (low <= high) {

            int mid = low + (high - low) / 2;

            // TEST SPEED 'mid':
            if (cal_hours(piles, mid) <= h) {
                ans = mid;       // Speed 'mid' works! Save it as a valid answer.
                high = mid - 1;  // Try to find an even slower speed on the left side.
            } 
            else {
                low = mid + 1;   // Speed 'mid' is too slow! Try a faster speed on the right side.
            }
        }

        return ans;
    }
};