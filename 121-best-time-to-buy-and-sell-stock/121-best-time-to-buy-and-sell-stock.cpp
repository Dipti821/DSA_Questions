class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int sz=prices.size();
        int ans=0,st=prices[0];
      for(int i=0;i<sz;i++){
         if(prices[i]<st)
             st=prices[i];
          if(prices[i]>st)
              ans=max(ans,prices[i]-st);
      }
        return ans;
    }
};