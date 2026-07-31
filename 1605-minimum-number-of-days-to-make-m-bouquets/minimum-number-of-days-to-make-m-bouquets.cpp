class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        if ((long long)m * k > n)
            return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int bouquets = 0;
            int flowers = 0;

            // Check if we can make m bouquets by day = mid
            for (int i = 0; i < n; i++) {
                if (bloomDay[i] <= mid) {
                    flowers++;
                } else {
                    flowers = 0;
                }

                if (flowers == k) {
                    bouquets++;
                    flowers = 0; // Use these flowers
                }
            }

            if (bouquets >= m) {
                high = mid - 1;   // Try a smaller day
            } else {
                low = mid + 1;    // Need more days
            }
        }

        return low;
    }
};