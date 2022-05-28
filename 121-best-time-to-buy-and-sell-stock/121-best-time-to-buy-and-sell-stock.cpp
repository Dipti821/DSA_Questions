class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz=prices.size();
        int minPrice=prices[0];
        int maxProfit=0;
        for(int i=0;i<sz;i++){
            if(prices[i]<minPrice)
                minPrice=prices[i];
            else if(prices[i]-minPrice>maxProfit)
                maxProfit=prices[i]-minPrice;
        }
        return maxProfit;
    }
};