//BRUTEFORCE

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimum_value = prices[0];
        int maxProfit = 0;

        for(int i = 0;i<prices.size();i++){
           if(prices[i] > minimum_value){
            int cost =  prices[i]-minimum_value;
            maxProfit = max(maxProfit ,cost);
           }
           minimum_value = min(minimum_value , prices[i]);
        }

        return maxProfit;
    }
};