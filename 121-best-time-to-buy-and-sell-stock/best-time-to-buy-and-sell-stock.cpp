class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // Minimum buying price seen so far
        int minimum_value = prices[0];

        int maxProfit = 0;

        for (int i = 0; i < prices.size(); i++) {

            // Profit if stock is sold today
            int cost = prices[i] - minimum_value;

            // Store best profit possible till current day
            maxProfit = max(maxProfit, cost);

            // Update minimum buying price for future transactions
            minimum_value = min(minimum_value, prices[i]);
        }

        return maxProfit;
    }
};