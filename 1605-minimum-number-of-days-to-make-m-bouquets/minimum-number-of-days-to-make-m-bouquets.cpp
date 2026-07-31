class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        // QUICK CHECK: If total flowers needed (m * k) is more than 
        // total flowers available in the garden (n), it's impossible.
        // Cast to 'long long' to stop integer overflow if m * k is huge!
        if ((long long)m * k > n)
            return -1;

        // Search range for days: 
        // Earliest possible bloom day vs Latest possible bloom day
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int bouquets = 0;
            int flowers = 0;

            // GREEDY FLOWER COUNT for day 'mid':
            for (int i = 0; i < n; i++) {
                // If flower has bloomed by day 'mid', pick it!
                if (bloomDay[i] <= mid) {
                    flowers++;
                } else {
                    // Flower hasn't bloomed! Since bouquets require ADJACENT flowers,
                    // the chain breaks. Reset flower counter back to 0.
                    flowers = 0;
                }

                // Every time we get 'k' adjacent flowers, make 1 bouquet!
                if (flowers == k) {
                    bouquets++;
                    flowers = 0; // Reset counter for the next bouquet
                }
            }

            // DECISION RULE:
            if (bouquets >= m) {
                // We made enough bouquets! 
                // Try searching for an EVEN FEWER number of days on the left.
                high = mid - 1;   
            } else {
                // Not enough bouquets! We need MORE days for more flowers to bloom.
                low = mid + 1;   
            }
        }

        // When the loop ends, 'low' automatically stops at the smallest valid day!
        return low;
    }
};