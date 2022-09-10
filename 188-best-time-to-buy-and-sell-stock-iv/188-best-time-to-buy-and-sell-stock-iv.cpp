class Solution {
public:
   int maxProfitInf(vector<int> &prices) {
    int buyin = INT_MAX, profit = 0;
    for(auto & price : prices) {
        if(price > buyin) profit += price - buyin;                
        buyin = price;
    }
    return profit;
}

int maxProfit(int k, vector<int> &prices) {
    if(k == 0 || prices.empty()) return 0;
    
    const int n = prices.size();        
    if(k >= n / 2) return maxProfitInf(prices);

    vector<int> balance(k + 1, INT_MIN), profit(k + 1);
    
    for(int i = 0; i < n; ++i) {
        for(int j = 1; j <= k; ++j) {
            balance[j] = max(profit[j - 1] - prices[i], balance[j]); 
            profit[j] = max(balance[j] + prices[i], profit[j]); 
        }
    }
    
    return profit[k];
}
};