class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lower = 0;
        int upper = 0;
        int maxProfit = 0;

        while (upper < prices.size()){
            if (prices[upper] < prices[lower]){
                lower = upper;
            }
            else if (prices[upper] - prices[lower] > maxProfit){
                maxProfit = prices[upper] - prices[lower];
            }
            upper++;
        }

        return maxProfit;
    }
};