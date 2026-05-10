// BRUTEFORCE

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // Track minimum buying price seen so far
        int minimum_value = prices[0];

        int maxProfit = 0;

        for (int i = 0; i < prices.size(); i++) {

            // Profit if sold today after buying at minimum price
            if (prices[i] > minimum_value) {

                int cost = prices[i] - minimum_value;

                // Store maximum profit possible
                maxProfit = max(maxProfit, cost);
            }

            // Update minimum buying price for future days
            minimum_value = min(minimum_value, prices[i]);
        }

        return maxProfit;
    }
};