class Solution {
public:
    bool canMake(vector<int>& bloomDay, int day, int m, int k) {
        int bouquets = 0;
        int flowers = 0;

        for (int i = 0; i < bloomDay.size(); i++) {

            if (bloomDay[i] <= day) {
                flowers++;
            } else {
                flowers = 0;
            }

            if (flowers == k) {
                bouquets++;
                flowers = 0;      // Flowers are used in one bouquet
            }
        }

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        // Impossible to make enough bouquets
        if ((long long)m * k > bloomDay.size())
            return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canMake(bloomDay, mid, m, k)) {
                ans = mid;
                high = mid - 1;      // Try to find an even smaller day
            } else {
                low = mid + 1;       // Need to wait longer
            }
        }

        return ans;
    }
};