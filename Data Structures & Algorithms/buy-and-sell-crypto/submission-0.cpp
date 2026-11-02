class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = 0;
        int sell = 0;
        int result = 0;
        for(; sell < n; sell++) {
            if(prices[sell] < prices[buy]) {
                buy = sell;
            }
            result = max(result, prices[sell] - prices[buy]);
        }
        return result;
    }
};
